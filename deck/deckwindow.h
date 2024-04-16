#ifndef DECKWINDOW_H
#define DECKWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <vector>
#include "deck/screenwidget.h"
#include "data/decksetting.h"

extern DeckSetting CONFIG;
extern DeckSetting DECK_CONF;

namespace Ui {
class DeckWindow;
}

class DeckWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeckWindow(QWidget *parent = nullptr);
    ~DeckWindow();

    std::vector<ScreenWidget*> SW;

    void renderScreen(int screenIdx);

private:
    Ui::DeckWindow *ui;
};

#endif // DECKWINDOW_H
