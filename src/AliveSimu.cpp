// Copyright (c) 2019 All Rights Reserved WestBot

#include <WestBot/HumanAfterAll/Category.hpp>

#include <WestBot/Core/AliveSimu.hpp>

using namespace WestBot;
using namespace WestBot::Core;

namespace
{
    HUMANAFTERALL_LOGGING_CATEGORY( LOG, "WestBot.Core.AliveSimu" )
}

AliveSimu::AliveSimu()
    : Alive()
{
    tDebug( LOG ) << "Blink blue";
}

void AliveSimu::run()
{
    _isRunning = true;

    while( _isRunning )
    {
        if( _color == Color::Blue )
        {
            tDebug( LOG ) << "Blink blue";
            QThread::msleep( 250 );
        }
        else
        {
            tDebug( LOG ) << "Blink yellow";
            QThread::msleep( 250 );
        }
    }
}
