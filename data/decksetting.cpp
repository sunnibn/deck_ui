#include <iostream>

#include "decksetting.h"

DeckSetting::DeckSetting() {
    // directory
    configDir = new QDir("./config/");
    if (!configDir->exists()) {
        configDir->mkpath(".");
    }
    // config files
    deckConfig = new QFile("./config/deck_config");
    musicConfig = new QFile("./config/music_config");
}

DeckSetting::~DeckSetting() {

}

//=== deck config
void DeckSetting::deckConfigRead() {
    if (!deckConfig->open(QIODevice::ReadWrite | QIODevice::Text))  // will create if not exist
        return;
    QTextStream in(deckConfig);
    while (!in.atEnd()){
        QStringList l = in.readLine().split(u' ', Qt::SkipEmptyParts);
        ScreenData d;
        int *p[6] = {&d.displayNo, &d.x, &d.y, &d.w, &d.h, &d.idx};
        for (int i=0; i < l.size(); i++) {
            *p[i] = l[i].toInt();
            // std::cout << *p[i] << std::endl;
        }
        screens.push_back(d);
    }
    deckConfig->close();
}
void DeckSetting::deckConfigWrite() {
    if (!deckConfig->open(QIODevice::ReadWrite | QIODevice::Text))  // will create if not exist
        return;
    QTextStream out(deckConfig);
    out << "0 50 50 200 200 0\n";
    out << "1 50 200 200 200 0\n";

    deckConfig->close();
}

//=== music config
