#ifndef GPSCARPUBLISHER_H
#define GPSCARPUBLISHER_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "Publisher.h"
#include <QFile>
#include <QTextStream>

// Publicador que simula un GPS
class GPSCarPublisher : public QWidget, public Publisher {
Q_OBJECT

public:
    GPSCarPublisher(const std::string& name, Broker& broker, const std::string& topic, QWidget *parent = nullptr);
    ~GPSCarPublisher() override;

    // Inicia el proceso de lectura de archivo y la temporización.
    bool loadFileAndStart(const QString& filePath);

private slots:
    void reportPosition();

private:
    bool readNextPointFromFile();

    QLabel* gpsDataLabel;
    QTimer* timer;

    QFile dataFile;
    QTextStream fileStream;

    double prevTime = 0, currentTime = 0, nextTime = 0;
    double prevX = 0, nextX = 0;
    double prevY = 0, nextY = 0;

    bool secondDataPointAvailable = false;
};

#endif //GPSCARPUBLISHER_H