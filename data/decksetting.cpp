#include <iostream>

#include "decksetting.h"

DeckSetting::DeckSetting() {
    // directory & deck config init
    configDirectory();
    deckConfigRead();
}

DeckSetting::~DeckSetting() {

}



//=== directory setting
void DeckSetting::configDirectory() {
    QDir *configDir = new QDir("./config/");
    QDir *screenDir = new QDir("./config/screens/");
    QDir *instDir = new QDir("./config/instances/");
    if (!configDir->exists())
        configDir->mkpath(".");
    if (!screenDir->exists())
        screenDir->mkpath(".");
    if (!instDir->exists())
        instDir->mkpath(".");
}

//=== deck config
void DeckSetting::deckConfigRead() {
    // empty vector screens
    if (!screens.empty()) screens.clear();
    // deck_config file open stream
    QFile *deckConfig = new QFile("./config/deck_config");
    if (!deckConfig->open(QIODevice::ReadWrite | QIODevice::Text))  // will create if not exist
        return;
    // read in deck_config data
    QTextStream in(deckConfig);
    while (!in.atEnd()) {
        QString screenPath = in.readLine();
        ScreenData s;
        s.path = screenPath;
        s.active = true;
        screenFileRead(screenPath , &s);
        screens.push_back(s);
    }
    // deck_config close file
    deckConfig->close();
}
void DeckSetting::deckConfigWrite() {
    QFile *deckConfig = new QFile("./config/deck_config");
    // deck_config file open stream
    if (!deckConfig->open(QIODevice::ReadWrite | QIODevice::Text))  // will create if not exist
        return;
    // write out deck_config data
    QTextStream out(deckConfig);
    for (int i=0; i<screens.size(); i++) {
        out << screens[i].path << '\n';
    }
    // deck_config close file
    deckConfig->close();
}

void DeckSetting::screenFileRead(QString filePath, ScreenData *s) {
    // empty screen data's displays
    if (!s->displays.empty()) s->displays.clear();
    // screen file open
    QFile *screenFile = new QFile(filePath);
    if (!screenFile->open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    // read in screen file data
    QTextStream in(screenFile);
    while (!in.atEnd()) {
        DisplayData d;
        // display coord data
        QStringList coord = in.readLine().split(u' ', Qt::SkipEmptyParts);
        int *pCoord[4] = {&d.x, &d.y, &d.w, &d.h};
        for (int i=0; i < coord.size(); i++) { *pCoord[i] = coord[i].toInt(); }
        // push display data -> screen
        s->displays.push_back(d);
    }
    screenFile->close();
}
void DeckSetting::screenFileWrite(int screenIdx) {
    // screen file open
    QFile *screenFile = new QFile(screens[screenIdx].path);
    if (!screenFile->open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    // write out screen file data
    QTextStream out(screenFile);
    for (int i=0; i < screens[screenIdx].displays.size(); i++) {
        DisplayData d = screens[screenIdx].displays[i];
        out << d.x <<' '<< d.y <<' '<< d.w <<' '<< d.h << '\n';
    }
    screenFile->close();
}



//=== functions of edit config data
void DeckSetting::addScreenData() {
    // create new screen file
    QString screenFilePath = "./config/screens/s";
    QFile *screenFile = new QFile(screenFilePath);
    if (!screenFile->open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    screenFile->close();
    // add screen in vector:screens
    ScreenData s;
    s.path = screenFilePath;
    s.active = true;
    screens.push_back(s);
    // renew deck_config
    this->deckConfigWrite();
}
void DeckSetting::delScreenData(int screenIdx) {
    // remove screen file
    QFile *screenFile = new QFile(screens[screenIdx].path);
    screenFile->remove();
    // remove screen from screens
    screens.erase(screens.begin() + screenIdx);
    // renew deck_config
    this->deckConfigWrite();
}
void DeckSetting::addDisplayData(int screenIdx) {
    screens[screenIdx].displays.push_back({ 0,0,100,100 });
    this->screenFileWrite(screenIdx);
}
void DeckSetting::delDisplayData(int screenIdx, int displayIdx) {
    screens[screenIdx].displays.erase(screens[screenIdx].displays.begin() + displayIdx);
    this->screenFileWrite(screenIdx);
}
