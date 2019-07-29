// Copyright (c) 2019 All Rights Reserved WestBot

#include <WestBot/Core/Alive.hpp>

using namespace WestBot;
using namespace WestBot::Core;

Alive::Alive()
    : _isRunning( false )
    , _color( Color::Unknown )
{
}

bool Alive::init( Color color )
{
    _color = color;
    start();

    return true;
}

void Alive::stop()
{
    _isRunning = false;
}

void Alive::run()
{
}
