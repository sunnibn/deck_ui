#ifndef DECKWINDOW_H
#define DECKWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <vector>

#include "deck/deck_default/deckscreen.h"
#include "deck/deck_default/deckbar.h"
#include "deck/deck_config/deckconfigscreen.h"
#include "deck/deck_config/deckconfigbar.h"

#include "data/decksetting.h"

extern DeckSetting CONFIG;
extern DeckSetting DECK_CONF;

namespace Ui {
class DeckWindow;
}

class DeckWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeckWindow(QWidget *parent = nullptr);
    ~DeckWindow();

    DeckScreen *deckScreen;
    DeckBar *deckBar;
    DeckConfigScreen *deckConfigScreen;
    DeckConfigBar *deckConfigBar;


    void renderBar(bool mode);
    void renderScreen(bool mode);

private:
    Ui::DeckWindow *ui;
};

#endif // DECKWINDOW_H
