#ifndef BARSCREENBUTTON_H
#define BARSCREENBUTTON_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class BarScreenButton;
}

class BarScreenButton : public QPushButton
{
    Q_OBJECT

public:
    explicit BarScreenButton(QWidget *parent = nullptr);
    ~BarScreenButton();

    bool active;
    QString activeText;
    QString inactiveText;
    QString hoverText;
    QString pressText;

    void switchActive(bool active);

private:
    Ui::BarScreenButton *ui;
};

#endif // BARSCREENBUTTON_H
