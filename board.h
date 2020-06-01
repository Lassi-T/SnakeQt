#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include <square.h>

class Board
{
public:
    Board(const int &width, const int &height);

    void move();

    Square *head_;

    bool moveRight = false;
    bool moveLeft = false;
    bool moveDown = false;
    bool moveUp = false;

private:
    const int width_;
    const int heigth_;
};

#endif // BOARD_H
