#ifndef DECKCONFIGDISPLAY_H
#define DECKCONFIGDISPLAY_H

#include <QWidget>

#include "deck/deck_config/deckconfigdisplaybar.h"

#include "ui/musicplayerwidget.h"
#include "ui/musicfilesystemwidget.h"

#include "data/decksetting.h"

extern DeckSetting CONFIG;

namespace Ui {
class DeckConfigDisplay;
}

class DeckConfigDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit DeckConfigDisplay(int displayIdx, QWidget *parent = nullptr);
    explicit DeckConfigDisplay(int displayIdx, DisplayData d, QWidget *parent = nullptr);
    ~DeckConfigDisplay();

    int displayIdx;
    DeckConfigDisplayBar *bar;

    void setDisplayContent(int displayType);

private:
    Ui::DeckConfigDisplay *ui;
};

#endif // DECKCONFIGDISPLAY_H
