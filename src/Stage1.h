#ifndef STAGE1_H
#define STAGE1_H

#include <QWidget>
#include "Broker.h"
#include "VideoPublisher.h"
#include "VideoFollower.h"
#include "GPSCarPublisher.h"
#include "CarTracker.h"

class Stage1 : public QWidget {
    Q_OBJECT

public:
    explicit Stage1(QWidget *parent = nullptr);
    ~Stage1() override;

private:
    Broker* broker;
    VideoPublisher* videoPublisher;
    VideoFollower* videoFollower;
    GPSCarPublisher* gpsPublisher;
    CarTracker* carTracker;
};

#endif //STAGE1_H