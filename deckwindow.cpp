#include "deckwindow.h"
#include "ui_deckwindow.h"
#include "ui/musicplayerwidget.h"

DeckWindow::DeckWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DeckWindow)
{
    ui->setupUi(this);
    // ui->tempWidget->setStyleSheet("QWidget#MusicPlayerWidget{ background: black; }");
}

DeckWindow::~DeckWindow()
{
    delete ui;
}
