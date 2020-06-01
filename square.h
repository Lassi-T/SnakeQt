#ifndef SQUARE_H
#define SQUARE_H

#include <QColor>

#include "vec2.h"

struct Square
{
    QColor color_;
    Vec2 position;
    Square *next;
};

#endif // SQUARE_H
