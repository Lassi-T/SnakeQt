#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "square.h"
#include "vec2.h"

class Board
{
public:
    Board(const int &width, const int &height);
    ~Board();

    bool move();

    Square *head_;
    Vec2 moveDir;

private:
    bool collision(Vec2 newPos);
    void deleteSnake(Square *square);

    const int width_;
    const int heigth_;
};

#endif // BOARD_H
