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

    int currScreenIdx = -1;
    std::vector<ScreenData> screens;


    //=== config directory setup function
    void configDirectory();

    //=== file read & write
    void deckConfigRead();
    void deckConfigWrite();
    void screenFileRead(QString filePath, ScreenData *s);
    void screenFileWrite(int screenIdx);

    //=== data manipulate functions
    void addScreenData();
    void delScreenData(int screenIdx);
    void addDisplayData(int screenIdx);
    void delDisplayData(int screenIdx, int displayIdx);
};

#endif // DECKSETTING_H
