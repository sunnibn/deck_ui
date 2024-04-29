#ifndef DECKDISPLAY_H
#define DECKDISPLAY_H

#include <QWidget>

#include "ui/musicplayerwidget.h"
#include "ui/musicfilesystemwidget.h"

#include "data/decksetting.h"

extern DeckSetting CONFIG;

// enum UiDisplay {
//     MUSIC_PLAYER_1,
//     MUSIC_LIST_1,
// };

namespace Ui {
class DeckDisplay;
}

class DeckDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit DeckDisplay(QWidget *parent = nullptr);
    explicit DeckDisplay(DisplayData d, QWidget *parent = nullptr);
    ~DeckDisplay();

    void setDisplayContent(int displayType);

private:
    Ui::DeckDisplay *ui;
};

#endif // DECKDISPLAY_H
