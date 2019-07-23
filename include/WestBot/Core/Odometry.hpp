// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_ODOMETRY_HPP_
#define WESTBOT_CORE_ODOMETRY_HPP_

#include <memory>

namespace WestBot {
namespace Core {

typedef struct
{
    double x; // mm
    double y; // mm
    double theta; // rad
} __attribute__( ( packed ) ) RobotPos;

bool operator==( RobotPos& lhs, RobotPos& rhs );

class Odometry
{
public:
    using Ptr = std::shared_ptr< Odometry >;

    virtual ~Odometry() = default;

    virtual RobotPos getPosition() = 0;
    virtual void setPosition( RobotPos pos ) = 0;
    virtual void addError( RobotPos error ) = 0;
};

}
}

#endif // WESTBOT_CORE_ODOMETRY_HPP_
