#include "deckwindow.h"
#include "ui_deckwindow.h"

#include <QThread>

DeckWindow::DeckWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeckWindow)
{
    ui->setupUi(this);

    deckScreen = new DeckScreen();
    deckBar = new DeckBar();
    deckConfigScreen = new DeckConfigScreen();
    deckConfigBar = new DeckConfigBar();

    connect(deckBar, &DeckBar::editModeSignal, [this](){
        this->renderBar(1);
        this->renderScreen(1);
    });
    connect(deckConfigBar, &DeckConfigBar::userModeSignal, [this](){
        this->renderBar(0);
        this->renderScreen(0);
    });

    renderBar(0);
    renderScreen(0);
}

DeckWindow::~DeckWindow()
{
    delete ui;
}



//=== bar functions
void DeckWindow::renderBar(int barNo) {
    // empty bar
    if (!ui->bar->layout()->isEmpty()) {
        QLayoutItem *child;
        while ((child = ui->bar->layout()->takeAt(0)) != nullptr) {
            ui->bar->layout()->removeItem(child);
            child->widget()->setParent(nullptr);    // set parent to nullptr, removes visibility.
        }
    }
    // restore bar
    if (barNo == 0) {
        ui->bar->layout()->addWidget(deckBar);
    } else {
        ui->bar->layout()->addWidget(deckConfigBar);
    }
}

//=== screen functions
void DeckWindow::renderScreen(int screenIdx) {
    // empty screen
    if (!ui->screen->layout()->isEmpty()) {
        QLayoutItem *child;
        while ((child = ui->screen->layout()->takeAt(0)) != nullptr) {
            ui->screen->layout()->removeItem(child);
            child->widget()->setParent(nullptr);    // set parent to nullptr, removes visibility.
        }
    }
    // restore screen
    if(screenIdx == 0) {
        ui->screen->layout()->addWidget(deckScreen);
    } else {
        ui->screen->layout()->addWidget(deckConfigScreen);
    }
    // // remove old
    // for (int i=0; i < SW.size(); i++) {
    //     delete SW[i];
    // }
    // if (!SW.empty()) SW.clear();
    // // render new
    // CONFIG.deckConfigRead();
    // if (CONFIG.screens.size() > 0) {
    //     for (int i=0; i < CONFIG.screens[screenIdx].displays.size(); i++) {
    //         DisplayData d = CONFIG.screens[screenIdx].displays[i];
    //         ScreenWidget *sw = new ScreenWidget(0, d.x, d.y, d.w, d.h);
    //         sw->screenIdx = screenIdx;
    //         sw->displayIdx = i;
    //         sw->bar->screenIdx = screenIdx;
    //         sw->bar->displayIdx = i;
    //         SW.push_back(sw);
    //         this->layout()->addWidget(sw);
    //     }
    // }
}
