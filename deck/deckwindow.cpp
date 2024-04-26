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
        this->renderScreen(screenIdx);
    });
    // edit & user mode switching
    connect(deckBar, &DeckBar::editModeSignal, [this](){
        this->renderBar(-1);
        this->renderScreen(-1);
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
    if (barNo == -1) {
        ui->bar->layout()->addWidget(deckConfigBar);
    } else {
        ui->bar->layout()->addWidget(deckBar);
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
    if(screenIdx == -1) {
        ui->screen->layout()->addWidget(deckConfigScreen);
    } else {
        deckScreen->renderDisplays(screenIdx);
        ui->screen->layout()->addWidget(deckScreen);
    }
}
