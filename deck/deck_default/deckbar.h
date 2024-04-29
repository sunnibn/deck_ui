#ifndef DECKBAR_H
#define DECKBAR_H

#include <QWidget>
#include <QPushButton>
#include <vector>

#include "item/barscreenbutton.h"

namespace Ui {
class DeckBar;
}

class DeckBar : public QWidget
{
    Q_OBJECT

public:
    explicit DeckBar(QWidget *parent = nullptr);
    ~DeckBar();

    std::vector<BarScreenButton*> BB;

    void renderScreensBtn();

signals:
    void editModeSignal();

private slots:
    void on_editBtn_clicked();

private:
    Ui::DeckBar *ui;
};

#endif // DECKBAR_H
