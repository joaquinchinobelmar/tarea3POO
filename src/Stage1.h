#ifndef STAGE1_H
#define STAGE1_H

#include <QWidget>
#include "Broker.h"
#include "VideoPublisher.h"
#include "VideoFollower.h"

// La ventana principal que contiene y organiza los widgets de la simulación
class Stage1 : public QWidget {
    Q_OBJECT

public:
    explicit Stage1(QWidget *parent = nullptr);
    ~Stage1() override;

private:
    Broker* broker;
    VideoPublisher* videoPublisher;
    VideoFollower* videoFollower;
};

#endif //STAGE1_H