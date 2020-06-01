#include "board.h"

Board::Board(const int &width, const int &height)
    : width_(width), heigth_(height)
{
    head_ = new Square();
    head_->color_ = QColor("blue");
    head_->x = width_ / 2 + 2;
    head_->y = heigth_ / 2;

    int i = 0;
    for (Square* current = head_; current != nullptr; current = current->next) {
        if (i++ >= 3) break;
        current->next = new Square();
        current->next->color_ = QColor("green");
        current->next->x = current->x - 1;
        current->next->y = current->y;
    }
}

void Board::move()
{
    int oldX = head_->x;
    int oldY = head_->y;

    if (moveRight) {
        head_->x == width_ ? head_->x = 0 : head_->x += 1;
    } else if (moveLeft) {
        head_->x == 0 ? head_->x = width_ : head_->x -= 1;
    } else if (moveDown) {
        head_->y == heigth_ ? head_->y = 0 : head_->y += 1;
    } else {
        head_->y == 0 ? head_->y = heigth_ : head_->y -= 1;
    }

    for (Square* current = head_->next; current != nullptr; current = current->next) {
        int curX = current->x;
        int curY = current->y;
        current->x = oldX;
        current->y = oldY;
        oldX = curX;
        oldY = curY;
    }
}
