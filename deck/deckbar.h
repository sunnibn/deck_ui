#ifndef DECKBAR_H
#define DECKBAR_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class DeckBar;
}

class DeckBar : public QWidget
{
    Q_OBJECT

public:
    explicit DeckBar(QWidget *parent = nullptr);
    ~DeckBar();

    void emptyBar();
    void basicMode();
    void editMode();

private:
    Ui::DeckBar *ui;
};

#endif // DECKBAR_H
