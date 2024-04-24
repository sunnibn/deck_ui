#ifndef DECKCONFIGSCREEN_H
#define DECKCONFIGSCREEN_H

#include <QWidget>

#include "deck/deck_config/deckconfigdisplay.h"
#include "data/decksetting.h"

extern DeckSetting CONFIG;

namespace Ui {
class DeckConfigScreen;
}

class DeckConfigScreen : public QWidget
{
    Q_OBJECT

public:
    explicit DeckConfigScreen(QWidget *parent = nullptr);
    ~DeckConfigScreen();

    int screenIdx;

    void renderConfigDisplays(int screenNo);

private:
    Ui::DeckConfigScreen *ui;
};

#endif // DECKCONFIGSCREEN_H
