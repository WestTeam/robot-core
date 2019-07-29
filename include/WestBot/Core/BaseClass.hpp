// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_BASECLASS_HPP_
#define WESTBOT_CORE_BASECLASS_HPP_

#include <memory>

#include <QString>
#include <QMap>

namespace WestBot {
namespace Core {

class BaseClass
{
public:
    using Ptr = std::shared_ptr< BaseClass >;

    BaseClass( const QString& name );
    virtual ~BaseClass();

    virtual bool init() = 0;

private:
    QString _name;
};

}
}

#endif // WESTBOT_CORE_BASECLASS_HPP_
