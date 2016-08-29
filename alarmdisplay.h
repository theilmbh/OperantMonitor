#ifndef ALARMDISPLAY_H
#define ALARMDISPLAY_H

#include <QWidget>

class AlarmDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit AlarmDisplay(QWidget *parent = 0);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // ALARMDISPLAY_H
