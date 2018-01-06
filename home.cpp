#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
}

Home::~Home()
{
    delete ui;
}

void Home::on_btn_quitter_clicked()
{
    this->close();
}



void Home::on_btn_jouer_clicked()
{
    hide();
    game = new Game();
    game->show();
    game->start();
}
