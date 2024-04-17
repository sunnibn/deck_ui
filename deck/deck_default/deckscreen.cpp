#include "deckscreen.h"
#include "ui_deckscreen.h"

#include <iostream>

DeckScreen::DeckScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckScreen)
{
    ui->setupUi(this);
    renderDisplays(0);
}

DeckScreen::~DeckScreen()
{
    delete ui;
}



//=== render displays
void DeckScreen::renderDisplays(int screenNo) {
    if(CONFIG.screens.size() > 0) {
        for (int i=0; i < CONFIG.screens[screenNo].displays.size(); i++) {
            DisplayData d = CONFIG.screens[screenNo].displays[i];
            DeckDisplay *disp = new DeckDisplay(d);
            disp->setParent(this);
        }
    }
}
