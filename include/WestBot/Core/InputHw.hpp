// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_INPUTHW_HPP_
#define WESTBOT_CORE_INPUTHW_HPP_

#include "Input.hpp"
#include "ItemRegister.hpp"

class QTimer;

namespace WestBot {
namespace Core {

/*!
 * \brief The Input class allow to create a proxy of an FPGA
 *        input. It use the layer registers mapping.
 */
class InputHw : public Input
{
public:
    /*!
     * \brief Constructor of Input.
     * \param inputRegister A reference to the input register.
     * \param name Name of the input object.
     */
    InputHw( const ItemRegister::Ptr& inputRegister, const QString& name );

private:
    /*!
     * \brief Check the input state and update it's internal state.
     */
    void check() override;

private:
    ItemRegister::Ptr _inputRegister;
    QTimer* _eventTimer;
};

}
}

#endif // WESTBOT_CORE_INPUTHW_HPP_
