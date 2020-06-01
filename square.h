#ifndef SQUARE_H
#define SQUARE_H

#include <QColor>

struct Square
{
    QColor color_;
    int x;
    int y;
    Square *next;
};

#endif // SQUARE_H
