#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <random>
#include <time.h>

#include "square.h"
#include "vec2.h"

class Board
{
public:
    Board(const int &width, const int &height);
    ~Board();

    bool move();
    int getScore();

    Vec2 moveDir;
    Square *head_;
    Square *apple_;

private:
    bool collision(Vec2 newPos);
    void makeApple();
    void eatApple();
    void deleteSnake(Square *square);

    Vec2 lastPos_;

    std::default_random_engine randomEng_;
    std::uniform_int_distribution<int> distrX_;
    std::uniform_int_distribution<int> distrY_;

    int score_ = 0;

    const int width_;
    const int heigth_;
};

#endif // BOARD_H
