#include "mainwindow.h"
#include "boxmonitor.h"
#include <QGridLayout>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    w = new QWidget();
    operantBoxPanel = new QGridLayout();
    w->setLayout(operantBoxPanel);

    int initBird = 999;
    int row, col;
    for (int box = 0; box < NBOX; box++)
    {
        BoxMonitor *mon = new BoxMonitor(initBird, box+1, this);

        row = box / NROW;
        col = box % NROW;
        operantBoxPanel->addWidget(mon, row, col);
    }

    setCentralWidget(w);
    setWindowTitle("Operant Monitor");

}


MainWindow::~MainWindow()
{

}


void MainWindow::drawGrid()
{
    int rows, cols;
    rows = operantBoxPanel->rowCount();
    cols = operantBoxPanel->columnCount();

    QPainter *gridPainter = new QPainter(w);
    gridPainter->setPen(Qt::blue);
    gridPainter->setRenderHint(QPainter::Antialiasing);

    for(int row=0; row<rows; row++)
    {
        for (int col=0; col<cols; col++)
        {
            gridPainter->drawRect(operantBoxPanel->cellRect(row, col));
        }
    }

}
