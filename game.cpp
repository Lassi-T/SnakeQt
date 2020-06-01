#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    scene_ = new QGraphicsScene(this);

    ui->graphicsView->setGeometry(50, 100, BORDER_RIGTH + 2, BORDER_DOWN + 2);
    ui->graphicsView->setScene(scene_);

    scene_->setSceneRect(0, 0, BORDER_RIGTH - 1, BORDER_DOWN - 1);

    // Initialize the game board
    board_ = new Board(WIDTH, HEIGTH);

    connect(&timer_, &QTimer::timeout, this, &Game::tick);
}

Game::~Game()
{
    delete ui;
}

void Game::draw()
{
    scene_->clear();

    for (Square* current = board_->head_; current != nullptr; current = current->next) {
        QColor color = current->color_;
        scene_->addRect((current->x * SQUARE_SIDE), (current->y * SQUARE_SIDE),
                        SQUARE_SIDE, SQUARE_SIDE, QColor("black"), color);
    }
}

void Game::tick()
{
    draw();
    board_->move();
}

void Game::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    timer_.setInterval(1000);
    timer_.start();
    board_->moveRight = true;
}
