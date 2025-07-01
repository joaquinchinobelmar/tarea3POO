cmake_minimum_required(VERSION 3.16)
project(Tarea3_PubSubSimulator_Etapa1 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Encuentra las bibliotecas de Qt6 y las nuevas para la reproducción de multimedia
find_package(Qt6 COMPONENTS Widgets Multimedia MultimediaWidgets REQUIRED)

# Añade todos tus archivos fuente y de encabezado al ejecutable
add_executable(Tarea3_PubSubSimulator_Etapa1
        main.cpp
        Stage1.h Stage1.cpp
        Broker.h Broker.cpp
        Topic.h Topic.cpp
        Component.h Component.cpp
        Publisher.h Publisher.cpp
        Subscriber.h
        VideoPublisher.h VideoPublisher.cpp
        VideoFollower.h VideoFollower.cpp
        GPSCarPublisher.h GPSCarPublisher.cpp
        CarTracker.h CarTracker.cpp
        CarTracker.h
        CarTracker.cpp
        GPSCarPublisher.h
        GPSCarPublisher.cpp
)
# Modificado para enlazar las bibliotecas QT (incluyendo las nuevas) al ejecutable
target_link_libraries(Tarea3_PubSubSimulator_Etapa1 PRIVATE Qt6::Widgets Qt6::Multimedia Qt6::MultimediaWidgets)