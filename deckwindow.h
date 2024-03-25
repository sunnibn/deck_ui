#ifndef DECKWINDOW_H
#define DECKWINDOW_H

#include <QMainWindow>

namespace Ui {
class DeckWindow;
}

class DeckWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeckWindow(QWidget *parent = nullptr);
    ~DeckWindow();

private:
    Ui::DeckWindow *ui;
};

#endif // DECKWINDOW_H
