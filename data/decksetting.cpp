#include <iostream>

#include "decksetting.h"

DeckSetting::DeckSetting(QObject *parent) : QObject(parent) {
    // directory & deck config init
    configDirectory();
    deckConfigRead();
}

DeckSetting::~DeckSetting() {

}



//=== config directory setup function
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



//=== file read & write
void DeckSetting::deckConfigRead() {
    // empty screens
    if (!screens.empty()) screens.clear();

    // read in deck_config file
    QFile *deckConfig = new QFile("./config/deck_config");
    if (!deckConfig->open(QIODevice::ReadOnly | QIODevice::Text))  // will create if not exist
        return;
    QTextStream in(deckConfig);
    while (!in.atEnd()) {
        QString screenPath = in.readLine();
        ScreenData s;
        screenFileRead(screenPath , &s);
        screens.push_back(s);
    }
    deckConfig->close();
}
void DeckSetting::deckConfigWrite() {
    // with current CONFIG data -> write out deck_config file
    QFile *deckConfig = new QFile("./config/deck_config");
    if (!deckConfig->open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))  // will create if not exist
        return;
    QTextStream out(deckConfig);
    for (int i=0; i<screens.size(); i++) {
        out << screens[i].path << '\n';
    }
    deckConfig->close();
}

void DeckSetting::screenFileRead(QString screenPath, ScreenData *s) {
    // empty screen data's displays
    if (!s->displays.empty()) s->displays.clear();
    // read in screen file data
    s->path = screenPath;
    QFile *screenFile = new QFile(screenPath);
    if (!screenFile->open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(screenFile);
    while (!in.atEnd()) {
        DisplayData d;
        QStringList coord = in.readLine().split(u' ', Qt::SkipEmptyParts);
        int *pCoord[4] = {&d.x, &d.y, &d.w, &d.h};
        for (int i=0; i < coord.size(); i++) { *pCoord[i] = coord[i].toInt(); }
        s->displays.push_back(d);
    }
    s->active = true;
    screenFile->close();
}
void DeckSetting::screenFileWrite(int screenIdx) {
    // write out screen file data
    QFile *screenFile = new QFile(screens[screenIdx].path);
    if (!screenFile->open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
        return;
    QTextStream out(screenFile);
    for (int i=0; i < screens[screenIdx].displays.size(); i++) {
        DisplayData d = screens[screenIdx].displays[i];
        out << d.x <<' '<< d.y <<' '<< d.w <<' '<< d.h << '\n';
    }
    screenFile->close();
}



//=== data manipulate functions
void DeckSetting::addScreenData() {
    // create new screen file ('s + number' format)
    QString screenFilePath = "./config/screens/s";
    int screenFileNo = 0;
    while (screenFileNo < 10) {
        QFile sfile(screenFilePath + QString::number(screenFileNo));
        if (!sfile.exists()) {
            screenFilePath = screenFilePath + QString::number(screenFileNo);
            break;
        }
        screenFileNo++;
    }
    if (screenFileNo >= 10) return;

    QFile *screenFile = new QFile(screenFilePath);
    if (!screenFile->open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text))
        return;
    screenFile->close();

    // add screen in vector:screens
    ScreenData s;
    s.path = screenFilePath;
    s.active = true;
    screens.push_back(s);

    // save & emit signals
    this->deckConfigWrite();
    currScreenIdx = screens.size() - 1;
    emit renderBarSignal();
    emit renderScreenSignal();
}
void DeckSetting::delScreenData(int screenIdx) {
    // remove screen file & data
    QFile *screenFile = new QFile(screens[screenIdx].path);
    screenFile->remove();
    screens.erase(screens.begin() + screenIdx);

    // save & emit signals
    this->deckConfigWrite();
    currScreenIdx = screens.size() - 1;
    emit renderBarSignal();
    emit renderScreenSignal();
}
void DeckSetting::switchScreen(int screenIdx) {
    currScreenIdx = screenIdx;
    emit renderScreenSignal();
}

void DeckSetting::addDisplayData(int screenIdx) {
    screens[screenIdx].displays.push_back({ 0,0,100,100 });

    this->screenFileWrite(screenIdx);
    emit renderScreenSignal();
}
void DeckSetting::delDisplayData(int screenIdx, int displayIdx) {
    screens[screenIdx].displays.erase(screens[screenIdx].displays.begin() + displayIdx);

    this->screenFileWrite(screenIdx);
    emit renderScreenSignal();
}
void DeckSetting::moveDisplay(int screenIdx, int displayIdx, DisplayData d) {
    screens[screenIdx].displays[displayIdx] = d;

    this->screenFileWrite(screenIdx);
    // emit renderScreenSignal();
}
