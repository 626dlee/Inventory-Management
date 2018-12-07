#include <QApplication>
#include <QPushButton>
#include "window.h"
#include <string>

int main(int argc, char **argv){
    QApplication app (argc, argv);

    Window win;
    win.show();

    return app.exec();
}
