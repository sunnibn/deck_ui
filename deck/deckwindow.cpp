#include "deckwindow.h"
#include "ui_deckwindow.h"

#include "deck/screenwidget.h"

DeckWindow::DeckWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeckWindow)
{
    ui->setupUi(this);
    ScreenWidget *sw = new ScreenWidget(0);
    this->layout()->addWidget(sw);
}

DeckWindow::~DeckWindow()
{
    delete ui;
}
