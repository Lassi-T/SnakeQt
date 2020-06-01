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

    connect(&timer_, &QTimer::timeout, this, &Game::tick);
}

Game::~Game()
{
    delete ui;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_D && board_->moveDir.x == 0) board_->moveDir = { 1,  0};
    if (event->key() == Qt::Key_A && board_->moveDir.x == 0) board_->moveDir = {-1,  0};
    if (event->key() == Qt::Key_S && board_->moveDir.y == 0) board_->moveDir = { 0,  1};
    if (event->key() == Qt::Key_W && board_->moveDir.y == 0) board_->moveDir = { 0, -1};
}

void Game::draw()
{
    scene_->clear();

    for (Square* current = board_->head_; current != nullptr; current = current->next) {
        QColor color = current->color_;
        scene_->addRect((current->position.x * SQUARE_SIDE),
                        (current->position.y * SQUARE_SIDE),
                        SQUARE_SIDE, SQUARE_SIDE, QColor("black"), color);
    }
    scene_->addRect((board_->apple_->position.x * SQUARE_SIDE),
                    (board_->apple_->position.y * SQUARE_SIDE),
                    SQUARE_SIDE, SQUARE_SIDE, QColor("red"), board_->apple_->color_);
}

void Game::tick()
{
    draw();
    if (!board_->move()) {
        scene_->clear();
        timer_.stop();
        ui->gameStatusLabel->setText("Game Over!");
        ui->startButton->setDisabled(false);
        delete board_;
    }
}

void Game::on_startButton_clicked()
{
    // Initialize the game board
    board_ = new Board(WIDTH, HEIGTH);

    ui->gameStatusLabel->setText("");
    ui->startButton->setDisabled(true);

    timer_.setInterval(100);
    timer_.start();

    board_->moveDir = {1, 0};
}
