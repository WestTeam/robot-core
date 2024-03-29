// Copyright (c) 2019 All Rights Reserved WestBot

#ifndef WESTBOT_MACROS_HPP_
#define WESTBOT_MACROS_HPP_

#include <math.h>

#define DEG(x) ((x) * (180.0 / M_PI))

#define RAD(x) ((x) * M_PI / 180.0)

#define WESTBOT_STR( name, value ) \
    const QString name = QStringLiteral( value )

#endif // WESTBOT_MACROS_HPP_
