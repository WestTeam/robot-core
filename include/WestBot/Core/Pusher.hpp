// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_PUSHER_HPP_
#define WESTBOT_CORE_PUSHER_HPP_

#include <chrono>

#include <QObject>
#include <QTimer>

namespace WestBot {
namespace Core {

class Pusher : public QObject
{
    Q_OBJECT

public:
    Pusher(
        const std::chrono::milliseconds& interval,
        QObject* parent = nullptr );

    void update();

signals:
    void updated();

private:
    void init();

private:
    QTimer _timer;
};

}
}

#endif // WESTBOT_CORE_PUSHER_HPP_
