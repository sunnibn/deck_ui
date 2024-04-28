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

    // edit & user mode switching
    connect(deckBar, &DeckBar::editModeSignal, [this](){
        this->renderBar(true);
        this->renderScreen(true);
    });
    connect(deckConfigBar, &DeckConfigBar::userModeSignal, [this](){
        this->renderBar(false);
        this->renderScreen(false);
    });



    this->renderBar(false);
    this->renderScreen(false);
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
        deckConfigBar->renderScreensBtn();
        ui->bar->layout()->addWidget(deckConfigBar);
    } else {
        deckBar->renderScreensBtn();
        ui->bar->layout()->addWidget(deckBar);
    }
}

//=== screen functions
void DeckWindow::renderScreen(bool mode) {
    // empty screen
    if (!ui->screen->layout()->isEmpty()) {
        QLayoutItem *child;
        while ((child = ui->screen->layout()->takeAt(0)) != nullptr) {
            ui->screen->layout()->removeItem(child);
            child->widget()->setParent(nullptr);    // set parent to nullptr, removes visibility.
        }
    }
    // restore screen
    if (mode) {
        deckConfigScreen->renderConfigScreen();
        ui->screen->layout()->addWidget(deckConfigScreen);
    } else {
        deckScreen->renderScreen();
        ui->screen->layout()->addWidget(deckScreen);
    }
}
