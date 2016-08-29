#include "boxmonitor.h"
#include "alarmdisplay.h"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QStackedWidget>
#include <QTimer>

BoxMonitor::BoxMonitor(int bird, int box, QWidget *parent) : QWidget(parent)
{
    birdID = bird;
    boxID = box;
    status = BOX_NORMAL;
    if(box==7)
    {
        status = BOX_ALARM;
    }

    nfeeds = 0;
    ntrials = 0;
    nerrors = 0;

    createStatusDisplay();
    createAlarmDisplay();

    alarmStack = new QStackedWidget(this);
    alarmStack->addWidget(statusDisplay);
    alarmStack->addWidget(alarmDisplay);

    CheckAlarms();

    setMinimumHeight(MINHEIGHT);
    setMinimumWidth(MINWIDTH);
    startTimer(1000);
}

void BoxMonitor::timerEvent(QTimerEvent *event)
{
    if(status==BOX_ALARM)
    {
        int newind = (alarmStack->currentIndex()+1) % 2;
        alarmStack->setCurrentIndex(newind);
    }
    else
    {
        alarmStack->setCurrentIndex(0);
    }
    CheckAlarms();
    update();
}

void BoxMonitor::Update(int newFeeds, int newTrials, int newErrors)
{
    nfeeds = newFeeds;
    ntrials = newTrials;
    nerrors = newErrors;
    update();
}

void BoxMonitor::CheckAlarms()
{

}

void BoxMonitor::createStatusDisplay()
{
    statusDisplay = new QWidget(this);
    QVBoxLayout *vbox = new QVBoxLayout(this);
    QHBoxLayout *hbox = new QHBoxLayout(this);
    QFormLayout *statusBox = new QFormLayout();

    feedDisplay = new QLabel(this);
    trialDisplay = new QLabel(this);
    errorDisplay = new QLabel(this);

    QFont statusDisplayFont = QFont("Helvetica", 18);

    feedDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    trialDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    errorDisplay->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    feedDisplay->setFont(statusDisplayFont);
    trialDisplay->setFont(statusDisplayFont);
    errorDisplay->setFont(statusDisplayFont);

    QLabel *boxLabel = new QLabel(this);
    QLabel *birdLabel = new QLabel(this);
    boxLabel->setFont(statusDisplayFont);
    birdLabel->setFont(statusDisplayFont);

    boxLabel->setNum(boxID);
    birdLabel->setNum(birdID);

    feedDisplay->setNum(nfeeds);
    trialDisplay->setNum(ntrials);
    errorDisplay->setNum(nerrors);

    feedDisplay->setScaledContents(1);

    statusBox->addRow("<h3>Feeds</h3>", feedDisplay);
    statusBox->addRow("<h3>Trials</h3>", trialDisplay);
    statusBox->addRow("<h3>Errors</h3>", errorDisplay);
    statusBox->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);

    hbox->addWidget(boxLabel);
    hbox->addWidget(birdLabel);
    vbox->addLayout(statusBox);
    vbox->addLayout(hbox);

    statusDisplay->setLayout(vbox);
}

void BoxMonitor::createAlarmDisplay()
{
    alarmDisplay = new AlarmDisplay(this);
}

void BoxMonitor::paintEvent(QPaintEvent *event)
{
    feedDisplay->setNum(nfeeds);
    trialDisplay->setNum(ntrials);
    errorDisplay->setNum(nerrors);
}

void BoxMonitor::mousePressEvent(QMouseEvent *event)
{
    status = BOX_NORMAL;
}
