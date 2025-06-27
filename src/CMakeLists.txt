cmake_minimum_required(VERSION 3.16)
project(Tarea3_PubSubSimulator_Etapa1 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Encuentra las bibliotecas de Qt6
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Añade todos tus archivos fuente y de encabezado al ejecutable
add_executable(Tarea3_PubSubSimulator_Etapa1
        main.cpp
        Stage1.h Stage1.cpp
        Broker.h Broker.cpp
        Topic.h Topic.cpp
        Component.h Component.cpp
        Publisher.h Publisher.cpp
        VideoPublisher.h VideoPublisher.cpp
        VideoFollower.h VideoFollower.cpp
        Component.h
        Component.cpp
        Subscriber.h
        Topic.h
        Topic.cpp
        Broker.h
        Broker.cpp
        Publisher.h
        Publisher.cpp
        VideoPublisher.h
        VideoPublisher.cpp
        VideoFollower.h
        VideoFollower.cpp
        Stage1.h
        Stage1.cpp
)

# Enlaza las bibliotecas de Qt a tu ejecutable
target_link_libraries(Tarea3_PubSubSimulator_Etapa1 PRIVATE Qt6::Widgets)