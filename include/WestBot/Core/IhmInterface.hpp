// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_IHMINTERFACE_HPP_
#define WESTBOT_CORE_IHMINTERFACE_HPP_

#include <QObject>

#include "Common.hpp"

namespace WestBot {
namespace Core {

/*!
 * \brief The Ihm interface manage interaction between humans and the robot.
 */
class IhmInterface : public QObject
{
    Q_OBJECT

public:
    virtual ~IhmInterface() = default;

signals:
    /*!
     * \brief Notify of a start request. (tirette)
     */
    void requestStart();

    /*!
     * \brief Notify of a hardstop request. (AU)
     */
    void requestHardStop();

    /*!
     * \brief Notify of a color changed. (Color button)
     */
    void colorChanged( Color color );
};

}
}

#endif // WESTBOT_CORE_IHMINTERFACE_HPP_
