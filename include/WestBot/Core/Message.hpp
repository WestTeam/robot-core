// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_MESSAGE_HPP_
#define WESTBOT_CORE_MESSAGE_HPP_

#include "Protocol.hpp"

namespace WestBot {
namespace Core {
namespace Message {

// TODO: Here we can define different types of message
typedef struct
{
    // Base of each message
    ProtocolHeader header;

    // Specific stuff here
    uint8_t state;

} __attribute__( ( packed ) ) DeviceStatus;

}
}
}

#endif // WESTBOT_CORE_MESSAGE_HPP_
