#include <string>

// #include "playerwindow.h"
#include "deck/deckwindow.h"
#include "data/musicplayer.h"

#include <QApplication>

// global vars
MusicPlayer MP;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // PlayerWindow wPlayer;
    DeckWindow w;

    // w.setTitle("");

    w.show();
    return a.exec();
}
