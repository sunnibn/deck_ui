#include "deck/deckwindow.h"

#include "data/decksetting.h"
#include "data/musicplayer.h"

#include <QApplication>

// global vars
DeckSetting DECK_CONF;
MusicPlayer MP;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DeckWindow w;

    w.show();
    return a.exec();
}
