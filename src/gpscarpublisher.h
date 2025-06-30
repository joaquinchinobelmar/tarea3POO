#ifndef GPSCARPUBLISHER_H
#define GPSCARPUBLISHER_H

#include "Publisher.h"
#include <QObject>
#include <QTimer>
#include <QString>
#include <QVector>




struct GPSPosition {
    int time;
    float x, y;
};

class GPSCarPublisher : public QObject, public Publisher{
    Q_OBJECT

public:
    GPSCarPublisher(const QString& name, const QString& topicName, Broker& broker);
    void loadPositionsFromFile(const QString& filePath);

signals:
    void positionPublished(int time, float x, float y);


private slots:
    void publishNextPosition();

private:
    QTimer timer;
    QVector<GPSPosition> positions;
    int currentIndex;
    float timeAccumulator;
};

#endif
