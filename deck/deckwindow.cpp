#include "deckwindow.h"
#include "ui_deckwindow.h"

DeckWindow::DeckWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeckWindow)
{
    ui->setupUi(this);

    deckScreen = new DeckScreen();
    deckBar = new DeckBar();
    deckConfigScreen = new DeckConfigScreen();
    deckConfigBar = new DeckConfigBar();

    // screen switching
    connect(deckBar, &DeckBar::screenSwitchSignal, [this](int screenIdx){
        this->renderScreen(false, screenIdx);
    });
    connect(deckConfigBar, &DeckConfigBar::screenSwitchSignal, [this](int screenIdx){
        this->renderScreen(true, screenIdx);
    });
    // edit & user mode switching
    connect(deckBar, &DeckBar::editModeSignal, [this](){
        this->renderBar(true);
        this->renderScreen(true, CONFIG.currScreenIdx);
    });
    connect(deckConfigBar, &DeckConfigBar::userModeSignal, [this](){
        this->renderBar(false);
        this->renderScreen(false, CONFIG.currScreenIdx);
    });

    renderBar(0);
}

DeckWindow::~DeckWindow()
{
    delete ui;
}



//=== bar functions
void DeckWindow::renderBar(bool mode) {
    // empty bar
    if (!ui->bar->layout()->isEmpty()) {
        QLayoutItem *child;
        while ((child = ui->bar->layout()->takeAt(0)) != nullptr) {
            ui->bar->layout()->removeItem(child);
            child->widget()->setParent(nullptr);    // set parent to nullptr, removes visibility.
        }
    }
    // restore bar
    if (mode) {
        ui->bar->layout()->addWidget(deckConfigBar);
    } else {
        ui->bar->layout()->addWidget(deckBar);
    }
}

//=== screen functions
void DeckWindow::renderScreen(bool mode, int screenIdx) {
    // empty screen
    if (!ui->screen->layout()->isEmpty()) {
        QLayoutItem *child;
        while ((child = ui->screen->layout()->takeAt(0)) != nullptr) {
            ui->screen->layout()->removeItem(child);
            child->widget()->setParent(nullptr);    // set parent to nullptr, removes visibility.
        }
    }
    // restore screen
    CONFIG.currScreenIdx = screenIdx;
    if (screenIdx == -1) {
        //
    } else if (mode) {
        deckConfigScreen->renderConfigDisplays(screenIdx);
        ui->screen->layout()->addWidget(deckConfigScreen);
    } else {
        deckScreen->renderDisplays(screenIdx);
        ui->screen->layout()->addWidget(deckScreen);
    }
}
