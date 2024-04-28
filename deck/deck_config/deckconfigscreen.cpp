#include "deckconfigscreen.h"
#include "ui_deckconfigscreen.h"

#include <iostream>

DeckConfigScreen::DeckConfigScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigScreen)
{
    ui->setupUi(this);
    connect(&CONFIG, &DeckSetting::renderScreenSignal, [this](){
        this->renderConfigScreen();
    });
}

DeckConfigScreen::~DeckConfigScreen()
{
    delete ui;
}



//=== render config displays
void DeckConfigScreen::renderConfigScreen() {
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
            DeckConfigDisplay *disp = new DeckConfigDisplay(i, d);
            disp->setParent(this);
            disp->show();
            DD.push_back(disp);
        }
    }
}
