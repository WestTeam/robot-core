// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_ALIVESIMU_HPP_
#define WESTBOT_CORE_ALIVESIMU_HPP_

#include "Alive.hpp"

namespace WestBot {
namespace Core {

class AliveSimu : public Alive
{
public:
    AliveSimu();

private:
    void run() override;
};

}
}

#endif // WESTBOT_CORE_ALIVESIMU_HPP_
