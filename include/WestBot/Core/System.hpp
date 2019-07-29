// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_SYSTEM_HPP_
#define WESTBOT_CORE_SYSTEM_HPP_

//#include <QMap>
#include <QObject>
#include <QTimer>

#include "TcpServer.hpp"

namespace WestBot {
namespace Core {

class System : public QObject
{
public:
    System( QObject* parent = nullptr );

    ~System() override = default;

    virtual bool init() = 0;

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void reset() = 0;

    virtual bool isSafe() const;

    //template < typename T >
    //void registerItem( const std::string& name )
    //{
    //    // Here is the main problem:
    //    // How I know the constructor specialisation here ???
    //    typename T::Ptr obj = std::make_shared< T >();
    //    _registry.insert(
    //        std::pair< std::string, BaseClass::Ptr >( name, obj ) );
    //}

    //template < typename T >
    //T getItem( const std::string& name )
    //{
    //    return reinterpret_cast< T >( _registry.at( "name" ) );
    //}

protected:
    QTimer _gameTimer;
    TcpServer _tcpServer;

    //QMap< QString, BaseClass::Ptr > _registry;

    // DeviceData_t _deviceDataStruct;
};

}
}

#endif // WESTBOT_CORE_SYSTEM_HPP_
