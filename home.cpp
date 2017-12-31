#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    QPixmap pix(":/Images/chrominologo.png");
    int w = ui->label_logo_chromino->width();
    int h = ui->label_logo_chromino->height();
    ui->label_logo_chromino->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Home::~Home()
{
    delete ui;
}

