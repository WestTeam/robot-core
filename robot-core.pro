# Copyright (c) 2019 All Rights Reserved WestBot

QT += core network serialport
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    include/Macros.hpp \
    include/WestBot/Core/Action.hpp \
    include/WestBot/Core/Alive.hpp \
    include/WestBot/Core/Input.hpp \
    include/WestBot/Core/Odometry.hpp \
    include/WestBot/Core/OdometrySimu.hpp \
    include/WestBot/Core/Output.hpp \
    include/WestBot/Core/Protocol.hpp \
    include/WestBot/Core/Pusher.hpp \
    include/WestBot/Core/System.hpp \
    include/WestBot/Core/SystemSimu.hpp \
    include/WestBot/Core/TcpServer.hpp \
    include/WestBot/Core/TrajectoryManager.hpp \
    include/WestBot/Core/TrajectoryManagerSimu.hpp \
    include/WestBot/Core/WaitAction.hpp

SOURCES += \
        src/main.cpp \
        src/Action.cpp \
        src/Alive.cpp \
        src/Input.cpp \
        src/Odometry.cpp \
        src/OdometrySimu.cpp \
        src/Output.cpp \
        src/Protocol.cpp \
        src/Pusher.cpp \
        src/System.cpp \
        src/SystemSimu.cpp \
        src/TcpServer.cpp \
        src/TrajectoryManagerSimu.cpp \
        src/WaitAction.cpp

INCLUDEPATH += \
    include \
    ./3rdparty/HumanAfterAll/include/

linux-g++*{
    # your includes
    HEADERS += \
    include/WestBot/Core/AliveSimu.hpp

    SOURCES += \
        src/AliveSimu.cpp
}

linux-arm-g++{
    # your includes
    HEADERS += \
        include/WestBot/Core/AliveHW.hpp \
        include/WestBot/Core/InputHW.hpp \
        include/WestBot/Core/ItemRegister.hpp \
        include/WestBot/Core/Layer.hpp \
        include/WestBot/Core/Memory.hpp \
        include/WestBot/Core/MemoryManager.hpp \
        include/WestBot/Core/OutputHW.hpp

    SOURCES += \
        src/AliveHW.cpp \
        src/InputHW.cpp \
        src/ItemRegister.cpp \
        src/Memory.cpp \
        src/MemoryManager.cpp \
        src/OutputHW.cpp
}

macx {
    # your includes
    HEADERS += \
    include/WestBot/Core/AliveSimu.hpp

    SOURCES += \
        src/AliveSimu.cpp

    debug {
        message(Build for macos debug mode)

        LIBS += -L./libs/macos/debug -lHumanAfterAll
    }

    release {
        message(Build for macos release mode)

        LIBS += -L../robot-core/libs/macos/release -lHumanAfterAll
    }
}
