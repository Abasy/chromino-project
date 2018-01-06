#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "game.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = 0);
    ~Home();

private slots:
    void on_btn_quitter_clicked();
    void on_btn_jouer_clicked();

private:
    Ui::Home *ui;
    Game *game;
};

#endif // HOME_H
