// Copyright (c) 2019 All Rights Reserved WestBot

#include <WestBot/Core/Input.hpp>

using namespace WestBot;
using namespace WestBot::Core;

Input::Input( const QString& name )
    : _name( name )
    , _digitalValue( DigitalValue::OFF )
{
}

const QString& Input::name() const
{
    return _name;
}

DigitalValue Input::digitalRead()
{
	check();
	return _digitalValue;
}
