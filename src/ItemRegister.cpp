// Copyright (c) 2019 All Rights Reserved WestBot

#include <WestBot/Core/ItemRegister.hpp>

using namespace WestBot;
using namespace WestBot::Core;

ItemRegister::ItemRegister( Memory& layer, int offset, int size )
    : _layer( layer )
    , _offset( offset )
    , _size( size )
{
}

void ItemRegister::write( uint32_t data )
{
    _layer.write( _offset, _size, data );
}

void ItemRegister::write( float data )
{
    uint32_t* tmp = ( uint32_t* )( & data );
    _layer.write( _offset, _size, *tmp );
}

void ItemRegister::write( int32_t data )
{
    uint32_t* tmp = ( uint32_t* )( & data );
    _layer.write( _offset, _size, *tmp );
}

int ItemRegister::offset()
{
    return _offset;
}
