#ifndef DECKSETTING_H
#define DECKSETTING_H

#include <vector>

#include <QDir>
#include <QFile>
#include <QTextStream>

struct ScreenData {
    int displayNo;
    int x, y, w, h;
    int idx;
};

class DeckSetting
{
public:
    DeckSetting();
    ~DeckSetting();

    QDir *configDir;
    QFile *deckConfig;
    QFile *musicConfig;

    std::vector<ScreenData> screens;

    void deckConfigRead();
    void deckConfigWrite();
};

#endif // DECKSETTING_H
