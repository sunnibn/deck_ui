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

    void initDeckBar();
    // void emptyBar();

    void editBtnClick();
    void addScreenBtnClick();
    void delScreenBtnClick();
    void addDisplayBtnClick();
    void editSaveBtnClick();
    void editQuitBtnClick();

signals:
    void editModeSignal();

private slots:
    void on_editBtn_clicked();

private:
    Ui::DeckBar *ui;

    QPushButton *editBtn;
    QPushButton *addScreenBtn;
    QPushButton *delScreenBtn;
    QPushButton *addDisplayBtn;
    QPushButton *editSaveBtn;
    QPushButton *editQuitBtn;
};

#endif // DECKBAR_H
