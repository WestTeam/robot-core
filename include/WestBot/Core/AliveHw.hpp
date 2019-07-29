// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_ALIVEHW_HPP_
#define WESTBOT_CORE_ALIVEHW_HPP_

#include "Alive.hpp"
#include "OutputHW.hpp"

namespace WestBot {
namespace Core {

class AliveHW : public Alive
{
public:
    AliveHW( const OutputHW::Ptr& ledYellow, const OutputHW::Ptr& ledBlue );

private:
    void run() override;

private:
    const OutputHW::Ptr& _ledYellow;
    const OutputHW::Ptr& _ledBlue;
};

}
}

#endif // WESTBOT_CORE_ALIVEHW_HPP_
