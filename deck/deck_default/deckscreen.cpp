#include "deckscreen.h"
#include "ui_deckscreen.h"

#include <iostream>

DeckScreen::DeckScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckScreen)
{
    ui->setupUi(this);
}

DeckScreen::~DeckScreen()
{
    delete ui;
}



//=== render displays
void DeckScreen::renderDisplays(int screenIdx) {
    // empty the screen
    for (int i=0; i < DD.size(); i++) {
        DD[i]->setParent(nullptr);
        delete DD[i];
    }
    if (!DD.empty()) { DD.clear(); }
    // show displays
    if(CONFIG.screens.size() > 0) {
        for (int i=0; i < CONFIG.screens[screenIdx].displays.size(); i++) {
            DisplayData d = CONFIG.screens[screenIdx].displays[i];
            DeckDisplay *disp = new DeckDisplay(d);
            disp->setParent(this);
            DD.push_back(disp);
        }
    }
}
