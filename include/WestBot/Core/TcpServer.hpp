// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_CORE_TCPSERVER_HPP_
#define WESTBOT_CORE_TCPSERVER_HPP_

#include <memory>

#include <QHash>
#include <QList>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

namespace WestBot {
namespace Core {

class TcpServer : public  QTcpServer
{
    Q_OBJECT

public:
    using SocketPtr = std::shared_ptr< QTcpSocket >;

    TcpServer( QObject* parent = nullptr );
    ~TcpServer() override = default;

    void disconnectClient( const SocketPtr& socket );

    void showConnectionInformation() const;

    //void updateClients( SimData& data );

    //void sendSimData( const SocketPtr& socket, SimData &data); // TODO: XXX
    //void sendSimData( const SocketPtr& socket, QList< SimData > datas ); // TODO: XXX

    void send();

signals:
    void error( QTcpSocket::SocketError socketError );
    void onClientConnected( const SocketPtr& socket );

    //void startStrat();
    //void stop();
    //void changeColor( DigitalValue value );

protected:
    void incomingConnection( qintptr socketDescriptor ) override;

private:
    QHash< QObject*, SocketPtr > _clients;
    //SimData _data;
};

}
}

#endif // WESTBOT_CORE_TCPSERVER_HPP_

