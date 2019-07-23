// Copyright (c) 2019 All Rights Reserved WestBot

#include <signal.h>

#include <QCoreApplication>
#include <QObject>

#include <WestBot/HumanAfterAll/Category.hpp>
#include <WestBot/HumanAfterAll/ConsoleAppender.hpp>
#include <WestBot/HumanAfterAll/Handler.hpp>

#include <WestBot/Core/Pusher.hpp>
#include <WestBot/Core/SystemSimu.hpp>

using namespace WestBot;
using namespace WestBot::Core;

using namespace WestBot::HumanAfterAll::Logging;

namespace
{
    HUMANAFTERALL_LOGGING_CATEGORY( LOG, "WestBot.Core.Main" )
}

int main( int argc, char *argv[] )
{
    QCoreApplication app( argc, argv );

    signal( SIGINT, []( int ) { QCoreApplication::quit(); } );

    signal( SIGKILL, []( int ) { QCoreApplication::quit(); } );

    Handler handler( app.instance() );
    ConsoleAppender consoleAppender;
    handler.addAppender( & consoleAppender );

#ifdef DEBUG
    handler.setEnableDebugLevel( true );
#endif

    SystemSimu sys;

    if( ! sys.init() )
    {
        tDebug( LOG ) << "Failed to init system";
        return -1;
    }

    // Test a simple pusher object
    Pusher push( std::chrono::milliseconds( 500 ) );

    QObject::connect(
    & push,
    & Pusher::updated,
    []()
    {
        tDebug( LOG ) << "RCV UPDATE";
    });

    return app.exec();
}
