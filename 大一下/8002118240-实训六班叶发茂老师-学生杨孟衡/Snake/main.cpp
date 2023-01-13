#include "snake.h"
#include <QApplication>
#include"mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    snake w;
    MainWindow m;
    m.show();

    QObject::connect(&m, SIGNAL(StartGame()), &w, SLOT(ReceiveGame()));

    return a.exec();
}
