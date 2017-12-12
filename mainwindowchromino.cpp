#include "mainwindowchromino.h"
#include "ui_mainwindowchromino.h"

MainWindowChromino::MainWindowChromino(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowChromino)
{
    ui->setupUi(this);
}

MainWindowChromino::~MainWindowChromino()
{
    delete ui;
}
