// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_SYSTEMSIMU_HPP_
#define WESTBOT_CORE_SYSTEMSIMU_HPP_

#include "AliveSimu.hpp"
#include "System.hpp"

namespace WestBot {
namespace Core {

class SystemSimu : public System
{
public:
    SystemSimu( QObject* parent = nullptr );

    ~SystemSimu() override;

    bool init() override;

    void start() override;
    void stop() override;
    void reset() override;

    bool isSafe() const override;

private:
    AliveSimu* _alive;
};

}
}

#endif // WESTBOT_CORE_SYSTEMSIMU_HPP_
