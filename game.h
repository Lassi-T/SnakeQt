#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>

#include "board.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

    void keyPressEvent(QKeyEvent *event);
    void draw();

private slots:
    void tick();
    void on_startButton_clicked();

private:
    Ui::Game *ui;

    QGraphicsScene *scene_;
    Board *board_;
    QTimer timer_;

    const int SQUARE_SIDE = 20;
    const int BORDER_DOWN = 520;
    const int BORDER_RIGTH = 680;

    const int WIDTH = BORDER_RIGTH / SQUARE_SIDE;
    const int HEIGTH = BORDER_DOWN / SQUARE_SIDE;

};
#endif // GAME_H
