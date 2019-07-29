// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_WAITACTION_HPP_
#define WESTBOT_CORE_WAITACTION_HPP_

#include "Action.hpp"

namespace WestBot {
namespace Core {

class WaitAction : public Action
{
public:
    using Ptr = std::shared_ptr< WaitAction >;

    WaitAction( int waitMs );

    void execute() override;

private:
    int _waitMs;
};

}
}

#endif // WESTBOT_CORE_WAITACTION_HPP_
