#include "alarmdisplay.h"
#include <QPainter>

AlarmDisplay::AlarmDisplay(QWidget *parent) : QWidget(parent)
{

}

void AlarmDisplay::paintEvent(QPaintEvent *event)
{
    QPainter *alarmPainter = new QPainter(this);
    alarmPainter->setBrush(QColor(255, 0, 0));
    alarmPainter->drawRect(rect());
    alarmPainter->setFont(QFont("Helvetica", 28));
    alarmPainter->setPen(QColor(255, 255, 255));
    alarmPainter->drawText(rect(), Qt::AlignCenter, "ALERT");
}
