// gpscarsubscriber.h
#ifndef GPSCARSUBSCRIBER_H
#define GPSCARSUBSCRIBER_H

#include <QWidget>
#include <QLabel>
//#include "Subscriber.h"
//#include "Broker.h"

class gpscarsubscriber : public QWidget
{
    Q_OBJECT

public:
    explicit gpscarsubscriber(QWidget *parent = nullptr);

public slots:
    void updatePosition(int time, float x, float y);

private:
    QLabel* timeLabel;
    QLabel* positionLabel;
    int currentTime;
    float currentPositionX;
    float currentPositionY;
};

#endif // GPSCARSUBSCRIBER_H
