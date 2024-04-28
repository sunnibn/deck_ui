#ifndef DECKBAR_H
#define DECKBAR_H

#include <QWidget>
#include <QPushButton>
// #include <deck/deckwindow.h>

namespace Ui {
class DeckBar;
}

class DeckBar : public QWidget
{
    Q_OBJECT

public:
    explicit DeckBar(QWidget *parent = nullptr);
    ~DeckBar();

    void renderScreensBtn();

signals:
    void editModeSignal();

private slots:
    void on_editBtn_clicked();

private:
    Ui::DeckBar *ui;
};

#endif // DECKBAR_H
