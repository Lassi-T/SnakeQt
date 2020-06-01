#include "board.h"

Board::Board(const int &width, const int &height)
    : width_(width), heigth_(height)
{
    head_ = new Square();
    head_->color_ = QColor("blue");
    head_->position = {width_ / 2 + 2, heigth_ / 2};

    int i = 0;
    for (Square* current = head_; current != nullptr; current = current->next) {
        if (i++ >= 3) break;
        current->next = new Square();
        current->next->color_ = QColor("green");

        current->next->position = current->position + Vec2({-1, 0});
    }
    makeApple();
}

Board::~Board()
{
    deleteSnake(head_);
}

bool Board::move()
{
    Vec2 oldPos = head_->position;

    eatApple();

    head_->position += moveDir;

    if (head_->position.x >= width_) {
        head_->position.x = 0;
    }
    if (head_->position.x < 0) {
        head_->position.x = width_ - 1;
    }
    if (head_->position.y >= heigth_) {
        head_->position.y = 0;
    }
    if (head_->position.y < 0) {
        head_->position.y = heigth_ - 1;
    }

    if (collision(head_->position)) {
        // Game over
        head_->position = oldPos;
        return false;
    }

    for (Square* current = head_->next; current != nullptr; current = current->next) {
        Vec2 curPos = current->position;
        lastPos_ = curPos;
        current->position = oldPos;
        oldPos = curPos;
    }
    return true;
}


bool Board::collision(Vec2 newPos)
{
    for (Square* current = head_->next; current != nullptr; current = current->next) {
        if (current->position == newPos) {
            return true;
        }
    }
    return false;
}

void Board::makeApple()
{
    int seed = time(0);
    randomEng_.seed(seed);

    distrX_ = std::uniform_int_distribution<int>(0, width_ - 1);
    distrX_(randomEng_);
    int appleX = distrX_(randomEng_);

    distrY_ = std::uniform_int_distribution<int>(0, heigth_ - 1);
    int appleY = distrY_(randomEng_);

    apple_ = new Square();
    apple_->color_ = QColor("red");
    apple_->position = {appleX, appleY};
}

void Board::eatApple()
{
    // Check for apple to eat
    if (apple_->position == head_->position) {
        delete apple_;
        makeApple();

        Square *current = head_;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Square();
        current->next->color_ = QColor("green");
        current->next->position = lastPos_;
    }
}

void Board::deleteSnake(Square *square)
{
    if (square == nullptr) return;
    deleteSnake(square->next);
    delete square;
}
