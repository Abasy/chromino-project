#ifndef MAINWINDOWCHROMINO_H
#define MAINWINDOWCHROMINO_H

#include <QMainWindow>

namespace Ui {
class MainWindowChromino;
}

class MainWindowChromino : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowChromino(QWidget *parent = 0);
    ~MainWindowChromino();

private:
    Ui::MainWindowChromino *ui;
};

#endif // MAINWINDOWCHROMINO_H
