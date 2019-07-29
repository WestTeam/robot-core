// Copyright (c) 2019 All Rights Reserved WestBot

#include <QThread>

#include <WestBot/HumanAfterAll/Category.hpp>

#include <WestBot/Core/WaitAction.hpp>

using namespace WestBot;
using namespace WestBot::Core;

namespace
{
    HUMANAFTERALL_LOGGING_CATEGORY( LOG, "WestBot.Core.WaitAction" )
}

WaitAction::WaitAction( int waitMs )
    : Action( "Wait" )
    , _waitMs( waitMs )
{
}

void WaitAction::execute()
{
    tDebug( LOG ) << "Running" << name() << "action";
    QThread::msleep( _waitMs );

    emit complete();
}
