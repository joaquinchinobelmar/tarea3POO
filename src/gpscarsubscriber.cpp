#include "gpscarsubscriber.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QString>

gpscarsubscriber::gpscarsubscriber(QWidget *parent)
    : QWidget(parent),
    timeLabel(new QLabel(this)),
    positionLabel(new QLabel(this)),
    currentTime(0),
    currentPositionX(0),
    currentPositionY(0)
{
    // layout para organizar los widgets
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(timeLabel);
    layout->addWidget(positionLabel);

    setLayout(layout);


    timeLabel->setText("Time: 0");
    positionLabel->setText("Position: (0, 0)");
}

void gpscarsubscriber::updatePosition(int time, float x, float y) {     //actualiza el tiempo y la posicion
    currentTime = time;
    currentPositionX = x;
    currentPositionY = y;

    timeLabel->setText(QString("Time: %1").arg(currentTime));
    positionLabel->setText(QString("Position: (%1, %2)").arg(currentPositionX).arg(currentPositionY));
}

