// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_HEARTBEATINTERFACE_HPP_
#define WESTBOT_CORE_HEARTBEATINTERFACE_HPP_

#include <QThread>

#include "Common.hpp"

namespace WestBot {
namespace Core {

/*!
 * \brief The heartbeat interface inform external actors (humans, applications...)
 * that the robot is up and running properly.
 */
class HeartBeatInterface : public QThread
{
public:
    virtual ~HeartBeatInterface() = default;

    virtual void changeColor( Color color ) = 0;

    virtual void stop();

private:
    void run() override;

protected:
    bool _isRunning;
    Color _color;
};

}
}

#endif // WESTBOT_CORE_HEARTBEATINTERFACE_HPP_
