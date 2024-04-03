#ifndef CLICKSLIDER_H
#define CLICKSLIDER_H

#include <QWidget>
#include <QSlider>
#include <QMouseEvent>

namespace Ui {
class ClickSlider;
}

class ClickSlider : public QSlider
{
    Q_OBJECT

public:
    explicit ClickSlider(QWidget *parent = nullptr);
    ~ClickSlider();

protected:
    void mousePressEvent(QMouseEvent *ev);

private:
    Ui::ClickSlider *ui;
};

#endif // CLICKSLIDER_H
