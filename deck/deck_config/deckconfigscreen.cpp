#include "deckconfigscreen.h"
#include "ui_deckconfigscreen.h"

DeckConfigScreen::DeckConfigScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigScreen)
{
    ui->setupUi(this);
    renderConfigDisplays(0);
}

DeckConfigScreen::~DeckConfigScreen()
{
    delete ui;
}



//=== render config displays
void DeckConfigScreen::renderConfigDisplays(int screenNo) {
    if(CONFIG.screens.size() > 0) {
        for (int i=0; i < CONFIG.screens[screenNo].displays.size(); i++) {
            DisplayData d = CONFIG.screens[screenNo].displays[i];
            DeckConfigDisplay *disp = new DeckConfigDisplay(d);
            disp->setParent(this);
        }
    }
}
