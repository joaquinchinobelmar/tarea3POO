#include <QApplication>
#include "Stage1.h"

int main(int argc, char *argv[]) {
    // Crear la instancia de la aplicación Qt
    QApplication app(argc, argv);

    // Ventana principal de nuestra simulación para la Etapa 1
    Stage1 main_window;
    main_window.setWindowTitle("Simulador Publicador-Suscriptor (Etapa 4.3)");
    main_window.show();

    // Se inicia el bucle de eventos de la aplicación
    return app.exec();
}
