#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "boxmonitor.h"

#define NBOX 16
#define NROW 4

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    BoxMonitor *boxes;
    QGridLayout *operantBoxPanel;
    QWidget *w;

    void drawGrid();
};

#endif // MAINWINDOW_H
