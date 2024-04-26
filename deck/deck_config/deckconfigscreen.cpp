#include "deckconfigscreen.h"
#include "ui_deckconfigscreen.h"

DeckConfigScreen::DeckConfigScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigScreen)
{
    ui->setupUi(this);
}

DeckConfigScreen::~DeckConfigScreen()
{
    delete ui;
}



//=== render config displays
void DeckConfigScreen::renderConfigDisplays(int screenIdx) {
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
            DeckConfigDisplay *disp = new DeckConfigDisplay(d);
            disp->setParent(this);
            DD.push_back(disp);
        }
    }
}
