#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include <square.h>

class Board
{
public:
    Board(const int &width, const int &height);
    void initSnake();

    std::vector<std::vector<Square*>> grid_;

private:
    const int width_;
    const int heigth_;
};

#endif // BOARD_H
