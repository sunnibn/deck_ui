#include "playerwindow.h"

#include <QApplication>
#include <string>

std::string now;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlayerWindow w;

    now = "Current File";
    w.setTitle(now);



    w.show();
    return a.exec();
}
