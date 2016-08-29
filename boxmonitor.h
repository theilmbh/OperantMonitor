#ifndef BOXMONITOR_H
#define BOXMONITOR_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QStackedWidget>


#define MINHEIGHT 100
#define MINWIDTH 100

enum BoxStatus
{
    BOX_NORMAL,
    BOX_ALARM
};

class BoxMonitor : public QWidget
{
    Q_OBJECT
public:
    explicit BoxMonitor(int bird_id, int box_id, QWidget *parent = 0);
    void Update(int newFeeds, int newTrials, int newErrors);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    int birdID;
    int boxID;
    int nfeeds;
    int ntrials;
    int nerrors;

    BoxStatus status;

    QLabel *feedDisplay;
    QLabel *trialDisplay;
    QLabel *errorDisplay;

    QWidget *statusDisplay;
    QWidget *alarmDisplay;

    void CheckAlarms();
    void createStatusDisplay();
    void createAlarmDisplay();
    QStackedWidget *alarmStack;

};

#endif // BOXMONITOR_H
