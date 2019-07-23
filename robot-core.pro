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
    include/WestBot/Core/Odometry.hpp \
    include/WestBot/Core/OdometrySimu.hpp \
    include/WestBot/Core/Protocol.hpp \
    include/WestBot/Core/Pusher.hpp \
    include/WestBot/Core/System.hpp \
    include/WestBot/Core/SystemSimu.hpp \
    include/WestBot/Core/TcpServer.hpp

SOURCES += \
        src/main.cpp \
        src/Odometry.cpp \
        src/OdometrySimu.cpp \
        src/Protocol.cpp \
        src/Pusher.cpp \
        src/System.cpp \
        src/SystemSimu.cpp \
        src/TcpServer.cpp


INCLUDEPATH += \
    include \
    ./3rdparty/HumanAfterAll/include/


linux-g++*{
# your includes
}

linux-arm-g++{
    # your includes
}

macx {
    debug {
        message(Build for macos debug mode)

        LIBS += -L./libs/macos/debug -lHumanAfterAll
    }

    release {
        message(Build for macos release mode)

        LIBS += -L../robot-core/libs/macos/release -lHumanAfterAll
    }
}
