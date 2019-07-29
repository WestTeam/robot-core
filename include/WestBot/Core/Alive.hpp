// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_ALIVE_HPP_
#define WESTBOT_CORE_ALIVE_HPP_

#include <QThread>

#include "Common.hpp"

namespace WestBot {
namespace Core {

class Alive : public QThread
{
public:
    Alive();
    ~Alive() override = default;

    bool init( Color color );

    void stop();

private:
    void run() override;

protected:
    bool _isRunning;
    Color _color;
};

}
}

#endif // WESTBOT_CORE_ALIVE_HPP_
