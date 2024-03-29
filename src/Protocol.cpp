// Copyright (c) 2019 All Rights Reserved WestBot

#include <WestBot/Core/Protocol.hpp>

using namespace WestBot::Core::Protocol;

uint16_t WestBot::Core::Protocol::protocolCrc( uint8_t* msg, uint16_t size )
{
    uint16_t crc = 0;

    while( --size > 4 )
    {
    	crc += msg[ size ];
    }

    return crc;
}
