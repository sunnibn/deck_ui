#ifndef DECKSCREEN_H
#define DECKSCREEN_H

#include <QWidget>

#include "deck/deck_default/deckdisplay.h"
#include "data/decksetting.h"

extern DeckSetting CONFIG;

namespace Ui {
class DeckScreen;
}

class DeckScreen : public QWidget
{
    Q_OBJECT

public:
    explicit DeckScreen(QWidget *parent = nullptr);
    ~DeckScreen();

    void renderDisplays(int screenNo);

private:
    Ui::DeckScreen *ui;
};

#endif // DECKSCREEN_H
