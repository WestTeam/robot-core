// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_PROTOCOL_HPP_
#define WESTBOT_CORE_PROTOCOL_HPP_

#define PROTOCOL_FANION 0xA5

#include <QtGlobal>

namespace WestBot {
namespace Core {
namespace Protocol {

typedef struct
{
    uint8_t     fanion;
    uint16_t    size;
    uint16_t    crc; // sum data + id
    uint16_t    id;
} __attribute__( ( packed ) ) ProtocolHeader;

uint16_t protocolCrc( uint8_t* msg, uint16_t size );

}
}
}

#endif // WESTBOT_CORE_PROTOCOL_HPP_
