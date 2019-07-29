// Copyright (c) 2019 All Rights Reserved WestBot

#include <WestBot/Core/Output.hpp>

using namespace WestBot;
using namespace WestBot::Core;

Output::Output( const QString& name )
    : _name( name )
    , _digitalValue( DigitalValue::OFF )
{
}

const QString& Output::name() const
{
    return _name;
}
