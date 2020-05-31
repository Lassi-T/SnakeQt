#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;

    QGraphicsScene *scene_;

    const int BORDER_DOWN = 520;
    const int BORDER_RIGTH = 680;
};
#endif // GAME_H
