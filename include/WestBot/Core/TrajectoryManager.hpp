// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_TRAJECTORYMANAGER_HPP_
#define WESTBOT_CORE_TRAJECTORYMANAGER_HPP_

#include <memory>

#include <QDebug>

namespace WestBot {
namespace Core {

class TrajectoryManager
{
public:
    using Ptr = std::shared_ptr< TrajectoryManager >;

    enum class TrajectoryType
    {
        TYPE_TRAJ_DISABLE = 0,
        TYPE_TRAJ_ENABLE = 1,
        TYPE_TRAJ_STOP = 2,
        TYPE_TRAJ_HARDSTOP = 3,
        TYPE_TRAJ_D_REL = 4,
        TYPE_TRAJ_ONLY_D_REL = 5,
        TYPE_TRAJ_A_REL = 6,
        TYPE_TRAJ_A_ABS = 7,
        TYPE_TRAJ_ONLY_A_REL = 8,
        TYPE_TRAJ_ONLY_A_ABS = 9,
        TYPE_TRAJ_D_A_REL = 10,
        TYPE_TRAJ_TURNTO_XY = 11,
        TYPE_TRAJ_TURNTO_XY_BEHIND = 12,
        TYPE_TRAJ_GOTO_XY_ABS = 13,
        TYPE_TRAJ_GOTO_FORWARD_XY_ABS = 14,
        TYPE_TRAJ_GOTO_BACKWARD_XY_ABS = 15,
        TYPE_TRAJ_GOTO_D_A_REL = 16,
        TYPE_TRAJ_GOTO_XY_REL = 17,

        DIST_CONFIG = 18,
        ANGLE_CONFIG = 19,
        WINDOW_CONFIG = 20,

        WAIT_TRAJ_READY = 21
    };

    // State of the trajectory manager.
    enum class TrajectoryState
    {
        READY, // Ready, waiting for a trajectory.

        // Simple trajectories
        RUNNING_A, // Turning without moving
        RUNNING_D, // Going straight
        RUNNING_AD, // Going forward and turning at the same time

        // Trajectories using events
        RUNNING_XY_START,      // A trajectory order was given, preparing to go
        RUNNING_XY_ANGLE,      // Doing a preliminary turn before starting to move
        RUNNING_XY_ANGLE_OK,   // Angle is now ok, move forward
        RUNNING_XY_F_START,    // Same as RUNNING_XY_START but forward only
        RUNNING_XY_F_ANGLE,    // Same as RUNNING_XY_ANGLE but forward only
        RUNNING_XY_F_ANGLE_OK, // Same as RUNNING_XY_ANGLE_OK but forward only
        RUNNING_XY_B_START,    // Same as RUNNING_XY_START but backward only
        RUNNING_XY_B_ANGLE,    // Same as RUNNING_XY_ANGLE but backward only
        RUNNING_XY_B_ANGLE_OK, // Same as RUNNING_XY_B_ANGLE_OK but backward only

        // Circle
        RUNNING_CIRCLE,          // Running a circle trajectory

        // Line
        RUNNING_LINE,            // Following a line

        // Clitoid
        RUNNING_CLITOID_LINE,    // Running a clitoid (line->circle->line) in the line part
        RUNNING_CLITOID_CURVE,   // Running a clitoid in the curve part
    };

//    virtual ~TrajectoryManager() = default;

    virtual void init() = 0;

    virtual void waitTrajReady() = 0;
    virtual bool isTrajReady() = 0;

    virtual void disable() = 0;
    virtual void enable() = 0;

    virtual void stop() = 0;
    virtual void hardStop() = 0;

    virtual void setAbort( bool abort ) = 0;

    virtual void setDistanceConfig( float speed, float acc ) = 0;
    virtual void setAngleConfig( float speed, float acc ) = 0;

    virtual void setWindow(
        float distance,
        float angleDeg,
        float startAngleDeg ) = 0;

    virtual void moveDRel(
        float distance,
        bool correction,
        bool doNotBlock = false ) = 0;

    virtual void moveOnlyDRel(
        float distance,
        bool correction,
        bool doNotBlock = false ) = 0;

    virtual void turnARel(
        float theta,
        bool correction,
        bool doNotBlock = false ) = 0;

    virtual void turnAAbs(
        float theta,
        bool correction,
        bool doNotBlock = false ) = 0;

    virtual void turnOnlyARel(
        float theta,
        bool correction,
        bool doNotBlock = false ) = 0;

    virtual void turnOnlyAAbs(
        float theta,
        bool correction,
        bool doNotBlock = false ) = 0;

    virtual void turnToXY(
        float x,
        float y,
        bool doNotBlock = false ) = 0;

    virtual void turnToXYBehind(
        float x,
        float y,
        bool doNotBlock = false ) = 0;

    virtual void moveToXYAbs(
        float theta,
        float x,
        float y,
        bool doNotBlock = false ) = 0;

    virtual void moveForwardToXYAbs(
        float theta,
        float x,
        float y,
        bool doNotBlock = false ) = 0;

    virtual void moveBackwardToXYAbs(
        float theta,
        float x,
        float y,
        bool doNotBlock = false ) = 0;

    virtual void moveToDARel(
        float theta,
        float distance,
        bool correction,
        bool doNotBlock = false ) = 0;

    virtual void moveToXYRel( float x, float y, bool doNotBlock = false ) = 0;
};

    /*!
     * \brief Overload stream operator for trajectory state enum class.
     */
    inline QDebug operator<<(
        QDebug debug,
        const TrajectoryManager::TrajectoryType& type )
    {
        switch( type )
        {
        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_DISABLE:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_ENABLE:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_STOP:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_HARDSTOP:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_D_REL:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_ONLY_D_REL:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_A_REL:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_A_ABS:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_ONLY_A_REL:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_ONLY_A_ABS:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_D_A_REL:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_TURNTO_XY:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_TURNTO_XY_BEHIND:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_GOTO_XY_ABS:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_GOTO_FORWARD_XY_ABS:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_GOTO_BACKWARD_XY_ABS:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_GOTO_D_A_REL:
            break;

        case TrajectoryManager::TrajectoryType::TYPE_TRAJ_GOTO_XY_REL:
            break;

        case TrajectoryManager::TrajectoryType::DIST_CONFIG:
            break;

        case TrajectoryManager::TrajectoryType::ANGLE_CONFIG:
            break;

        case TrajectoryManager::TrajectoryType::WINDOW_CONFIG:
            break;

        case TrajectoryManager::TrajectoryType::WAIT_TRAJ_READY:
            break;
        }
        return debug;
    }

    /*!
     * \brief Overload stream operator for trajectory state enum class.
     */
    inline QDebug operator<<(
        QDebug debug,
        const TrajectoryManager::TrajectoryState& state )
    {
        switch( state )
        {
        case TrajectoryManager::TrajectoryState::READY:
            debug << "Trajectory: READY";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_A:
            debug << "Trajectory: RUNNING_A";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_D:
            debug << "Trajectory: RUNNING_D";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_AD:
            debug << "Trajectory: RUNNING_AD";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_XY_START:
            debug << "Trajectory: RUNNING_XY_START";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_XY_ANGLE:
            debug << "Trajectory: RUNNING_XY_ANGLE";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_XY_ANGLE_OK:
            debug << "Trajectory: RUNNING_XY_ANGLE_OK";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_XY_F_START:
            debug << "Trajectory: RUNNING_XY_F_START";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_XY_F_ANGLE:
            debug << "Trajectory: RUNNING_XY_F_ANGLE";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_XY_F_ANGLE_OK:
            debug << "Trajectory: RUNNING_XY_F_ANGLE_OK";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_XY_B_START:
            debug << "Trajectory: RUNNING_XY_B_START";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_XY_B_ANGLE:
            debug << "Trajectory: RUNNING_XY_B_ANGLE";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_XY_B_ANGLE_OK:
            debug << "Trajectory: RUNNING_XY_B_ANGLE_OK";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_CIRCLE:
            debug << "Trajectory: RUNNING_CIRCLE";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_LINE:
            debug << "Trajectory: RUNNING_LINE";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_CLITOID_LINE:
            debug << "Trajectory: RUNNING_CLITOID_LINE";
            break;

        case TrajectoryManager::TrajectoryState::RUNNING_CLITOID_CURVE:
            debug << "Trajectory: RUNNING_CLITOID_CURVE";
            break;
        }

        return debug;
    }
}
}

#endif // WESTBOT_CORE_TRAJECTORYMANAGER_HPP_
