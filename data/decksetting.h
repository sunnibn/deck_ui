#ifndef DECKSETTING_H
#define DECKSETTING_H

#include <vector>

#include <QDir>
#include <QFile>
#include <QTextStream>

struct InstData {       // instance data
    int type;
};
struct DisplayData {    // each displays on screen
    int x, y, w, h;
};
struct ScreenData {     // screen to show on deck
    QString path;
    bool active;
    std::vector<DisplayData> displays;
};


class DeckSetting
{
public:
    DeckSetting();
    ~DeckSetting();

    int currScreenIdx;
    std::vector<ScreenData> screens;


    void configDirectory();

    void deckConfigRead();
    void deckConfigWrite();
    void screenFileRead(QString filePath, ScreenData *s);
    void screenFileWrite(int screenIdx);

    void addScreenData();
    void delScreenData();
    void addDisplayData();
    void delDisplayData();
};

#endif // DECKSETTING_H
