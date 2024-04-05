#include "deckwindow.h"
#include "ui_deckwindow.h"

#include "deck/screenwidget.h"
#include "data/decksetting.h"

extern DeckSetting DECK_CONF;

DeckWindow::DeckWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeckWindow)
{
    ui->setupUi(this);

    DECK_CONF.deckConfigRead();
    connect(ui->settingButton, &QPushButton::clicked, [](){ DECK_CONF.deckConfigWrite(); });

    for (int i=0; i < DECK_CONF.screens.size(); i++) {
        ScreenData d = DECK_CONF.screens[i];
        ScreenWidget *sw = new ScreenWidget(d.displayNo, d.x, d.y, d.w, d.h);
        this->layout()->addWidget(sw);
    }

    // ScreenWidget *sw = new ScreenWidget(0);
    // this->layout()->addWidget(sw);
}

DeckWindow::~DeckWindow()
{
    delete ui;
}
