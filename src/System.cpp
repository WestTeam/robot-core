// Copyright (c) 2019 All Rights Reserved WestBot

#include <WestBot/HumanAfterAll/Category.hpp>

#include <WestBot/Core/System.hpp>

using namespace WestBot;
using namespace WestBot::Core;

namespace
{
    HUMANAFTERALL_LOGGING_CATEGORY( LOG, "WestBot.Core.System" )

    const int DEFAULT_TCP_PORT = 4242;
}

System::System( QObject* parent )
    : QObject( parent )
{
    connect(
        & _gameTimer,
        & QTimer::timeout,
        this,
        [ this ]()
        {
            tInfo( LOG ) << "Game ended";
            stop();
        } );

    connect(
        & _tcpServer,
        & TcpServer::onClientConnected,
        [ this ]( const TcpServer::SocketPtr& socket )
        {
            tInfo( LOG ) << "Client connected...";
            _tcpServer.send();

        } );

    if( ! _tcpServer.listen( QHostAddress::Any, DEFAULT_TCP_PORT ) )
    {
       tWarning( LOG )
           << "Unable to start the server:"
           << _tcpServer.errorString();
    }

    tInfo( LOG ) << "Tcp server started on port" << DEFAULT_TCP_PORT;
}

bool System::isSafe() const
{
    return true;
}
