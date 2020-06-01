#include "board.h"

Board::Board(const int &width, const int &height)
    : width_(width), heigth_(height)
{
    for (int x = 0; x < width; x++) {
        grid_.push_back({});
        for (int y = 0; y < height; y++) {
            grid_.at(x).push_back(nullptr);
        }
    }
}

void Board::initSnake()
{
    for(int x = width_ / 2 - 2; x < width_ / 2 + 2; x++) {
        Square *square = new Square();
        square->color_ = QColor("green");
        grid_[x][heigth_ / 2] = square;
    }
}
