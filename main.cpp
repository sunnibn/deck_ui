#include <string>

#include "playerwindow.h"

#include <QApplication>

// global vars
bool PLAY = false;
std::string PATH = "";
std::string FILENAME = "";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlayerWindow w;

    w.setTitle(FILENAME);



    w.show();
    return a.exec();
}
