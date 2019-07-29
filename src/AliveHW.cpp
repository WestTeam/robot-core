// Copyright (c) 2019 All Rights Reserved WestBot

#include <WestBot/Core/AliveHW.hpp>

using namespace WestBot;
using namespace WestBot::Core;

AliveHW::AliveHW(
    const OutputHW::Ptr& ledYellow,
    const OutputHW::Ptr& ledBlue )
    : Alive()
    , _ledYellow( ledYellow )
    , _ledBlue( ledBlue )
{
}

void AliveHW::run()
{
    while( _isRunning )
    {
        if( _color == Color::Blue )
        {
            _ledBlue->digitalWrite( DigitalValue::OFF );
            QThread::msleep( 250 );
            _ledBlue->digitalWrite( DigitalValue::ON );
            QThread::msleep( 250 );
        }
        else
        {
            _ledYellow->digitalWrite( DigitalValue::OFF );
            QThread::msleep( 250 );
            _ledYellow->digitalWrite( DigitalValue::ON );
            QThread::msleep( 250 );
        }
    }
}
