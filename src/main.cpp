#include <QApplication>
#include "Stage1.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Stage1 main_window;
    main_window.show();

    return app.exec();
}