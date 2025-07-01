#ifndef CARTRACKER_H
#define CARTRACKER_H

#include <QWidget>
#include <QLabel>
#include "Subscriber.h"

class QLabel;
class QGraphicsScene;
class QGraphicsView;
class QGraphicsEllipseItem;

class CarTracker : public QWidget, public Subscriber {
Q_OBJECT

public:
    CarTracker(const std::string& name, const std::string& topic, QWidget *parent = nullptr);

    void update(const std::string& message) override;

private:
    // Componentes de la escena gráfica
    QLabel* telemetryLabel;
    QGraphicsScene* scene;
    QGraphicsView* view;
    QGraphicsEllipseItem* carCircle;
};

#endif //CARTRACKER_H