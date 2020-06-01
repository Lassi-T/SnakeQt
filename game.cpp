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

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGTH; y++) {
            if (board_->grid_[x][y] != nullptr) {
                QColor color = board_->grid_[x][y]->color_;
                scene_->addRect((x * SQUARE_SIDE), (y * SQUARE_SIDE),
                                SQUARE_SIDE, SQUARE_SIDE, QColor("black"), color);
            }
        }
    }
}

void Game::tick()
{
    qDebug() << "Working";
    draw();
}

void Game::on_startButton_clicked()
{
    ui->startButton->setDisabled(true);
    timer_.setInterval(1000);
    timer_.start();
    board_->initSnake();
}
