#ifndef DECKSCREEN_H
#define DECKSCREEN_H

#include <QWidget>
#include <vector>

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

    std::vector<DeckDisplay*> DD;

    void renderScreen();

private:
    Ui::DeckScreen *ui;
};

#endif // DECKSCREEN_H
