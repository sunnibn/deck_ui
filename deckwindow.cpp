#include "deckwindow.h"
#include "ui_deckwindow.h"

DeckWindow::DeckWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeckWindow)
{
    ui->setupUi(this);
}

DeckWindow::~DeckWindow()
{
    delete ui;
}
