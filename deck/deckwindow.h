#ifndef DECKWINDOW_H
#define DECKWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <vector>
#include "deck/screenwidget.h"

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

    std::vector<ScreenWidget*> SW;
    DeckScreen *deckScreen;
    DeckBar *deckBar;
    DeckConfigScreen *deckConfigScreen;
    DeckConfigBar *deckConfigBar;


    void renderBar(int barNo);
    void renderScreen(int screenIdx);

private:
    Ui::DeckWindow *ui;
};

#endif // DECKWINDOW_H
