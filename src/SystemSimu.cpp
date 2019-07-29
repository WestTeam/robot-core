// Copyright (c) 2019 All Rights Reserved WestBot

#include <WestBot/HumanAfterAll/Category.hpp>

#include <WestBot/Core/SystemSimu.hpp>

using namespace WestBot;
using namespace WestBot::Core;

namespace
{
    HUMANAFTERALL_LOGGING_CATEGORY( LOG, "WestBot.Core.SystemSimu" )
}

SystemSimu::SystemSimu( QObject* parent )
    : System( parent )
    , _alive( new AliveSimu() )
{
}

SystemSimu::~SystemSimu()
{
    stop();
}

//
// Public methods
//

bool SystemSimu::init()
{
    tDebug( LOG ) << "System manager initializing...";
    // TODO: Complete
    tDebug( LOG ) << "System manager initialized";

    return true;
}

void SystemSimu::start()
{
    tDebug( LOG ) << "System starting...";

    if( ! isSafe() )
    {
        tWarning( LOG )
            << "System not safe to start: Odometry check failed";
    }

    _alive->init( Color::Yellow );
    _alive->start();
}

void SystemSimu::stop()
{
    tDebug( LOG ) << "System stopping...";

    if( _alive )
    {
        _alive->stop();
    }
    // TODO
}

void SystemSimu::reset()
{
    tDebug( LOG ) << "System resetting...";

    // TODO
}

bool SystemSimu::isSafe() const
{
    // TODO: XXX
    return true;
}
