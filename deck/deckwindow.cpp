#include "deckwindow.h"
#include "ui_deckwindow.h"

DeckWindow::DeckWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeckWindow)
{
    ui->setupUi(this);

    renderScreen(0);
}

DeckWindow::~DeckWindow()
{
    delete ui;
}

void DeckWindow::renderScreen(int screenIdx) {
    // remove old
    for (int i=0; i < SW.size(); i++) delete SW[i];
    if (!SW.empty()) SW.clear();
    // render new
    CONFIG.deckConfigRead();
    if (CONFIG.screens.size() > 0) {
        for (int i=0; i < CONFIG.screens[screenIdx].displays.size(); i++) {
            DisplayData d = CONFIG.screens[screenIdx].displays[i];
            ScreenWidget *sw = new ScreenWidget(0, d.x, d.y, d.w, d.h);
            SW.push_back(sw);
            this->layout()->addWidget(sw);
        }
    }
}
