// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_ODOMETRYSIMU_HPP_
#define WESTBOT_CORE_ODOMETRYSIMU_HPP_

#include <QMutex>

#include "Odometry.hpp"

namespace WestBot {
namespace Core {

class OdometrySimu : public Odometry
{
public:
    OdometrySimu();

    RobotPos getPosition() override;
    void setPosition( RobotPos pos ) override;
    void addError( RobotPos error ) override;

private:
    RobotPos _posLatest;
    RobotPos _cumulatedError;

    QMutex _lock;
};

}
}

#endif // WESTBOT_CORE_ODOMETRYSIMU_HPP_
