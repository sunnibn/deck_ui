#include "deckscreen.h"
#include "ui_deckscreen.h"

#include <iostream>

DeckScreen::DeckScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckScreen)
{
    ui->setupUi(this);
    connect(&CONFIG, &DeckSetting::renderScreenSignal, [this](){
        this->renderScreen();
    });
}

DeckScreen::~DeckScreen()
{
    delete ui;
}



//=== render displays
void DeckScreen::renderScreen() {
    // empty the screen
    for (int i=0; i < DD.size(); i++) {
        DD[i]->setParent(nullptr);
        delete DD[i];
    }
    if (!DD.empty()) { DD.clear(); }
    // show displays
    int idx = CONFIG.currScreenIdx;
    if(CONFIG.screens.size() > 0 && idx != -1) {
        for (int i=0; i < CONFIG.screens[idx].displays.size(); i++) {
            DisplayData d = CONFIG.screens[idx].displays[i];
            DeckDisplay *disp = new DeckDisplay(d);
            disp->setParent(this);
            disp->show();
            DD.push_back(disp);
        }
    }
}
