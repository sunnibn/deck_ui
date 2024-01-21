#include <string>

#include "playerwindow.h"
#include "musicplayer.h"

#include <QApplication>

// global vars
MusicPlayer MP;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlayerWindow w;

    w.setTitle("");

    w.show();
    return a.exec();
}
