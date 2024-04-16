#include "deckwindow.h"
#include "ui_deckwindow.h"

DeckWindow::DeckWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeckWindow)
{
    ui->setupUi(this);

    renderScreen(0);

    // DECK_CONF.deckConfigRead();

    // for (int i=0; i < DECK_CONF.screens.size(); i++) {
    //     ScreenData d = DECK_CONF.screens[i];
    //     ScreenWidget *sw = new ScreenWidget(d.displayNo, d.x, d.y, d.w, d.h);
    //     this->layout()->addWidget(sw);
    // }

    // ScreenWidget *sw = new ScreenWidget(0);
    // this->layout()->addWidget(sw);
}

DeckWindow::~DeckWindow()
{
    delete ui;
}

void DeckWindow::renderScreen(int screenIdx) {
    CONFIG.deckConfigRead();
    if (CONFIG.screens.size() > 0) {
        for (int i=0; i < CONFIG.screens[screenIdx].displays.size(); i++) {
            DisplayData d = CONFIG.screens[screenIdx].displays[i];
            ScreenWidget *sw = new ScreenWidget(0, d.x, d.y, d.w, d.h);
            this->layout()->addWidget(sw);
        }
    }
}
