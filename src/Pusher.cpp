// Copyright (c) 2019 All Rights Reserved WestBot

#include <WestBot/HumanAfterAll/Category.hpp>

#include <WestBot/Core/Pusher.hpp>

using namespace WestBot::Core;

namespace
{
    HUMANAFTERALL_LOGGING_CATEGORY( LOG, "WestBot.Core.Pusher" )
}

Pusher::Pusher( const std::chrono::milliseconds& interval, QObject* parent )
    : QObject( parent )
{
    _timer.setInterval( interval );
    _timer.setSingleShot( false );

    init();
}

void Pusher::update()
{
    tDebug( LOG ) << ">>>> Update";
    emit updated();
}

//
// Private methods
//
void Pusher::init()
{
    connect(
        & _timer,
        & QTimer::timeout,
        this,
        & Pusher::update );

    _timer.start();
}
