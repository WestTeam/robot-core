// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_SYSTEM_HPP_
#define WESTBOT_CORE_SYSTEM_HPP_

#include <QObject>
#include <QTimer>

#include "TcpServer.hpp"

namespace WestBot {
namespace Core {

class System : public QObject
{
public:
    System( QObject* parent = nullptr );

    ~System() override = default;

    virtual bool init() = 0;

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void reset() = 0;

    virtual bool isSafe() const;

protected:
    QTimer _gameTimer;
    TcpServer _tcpServer;

    // DeviceData_t _deviceDataStruct;
};

}
}

#endif // WESTBOT_CORE_SYSTEM_HPP_
