#ifndef CLICKSLIDER_H
#define CLICKSLIDER_H

#include <QSlider>

class ClickSlider : public QSlider
{
public:
    ClickSlider(QWidget *parent = nullptr);
    ~ClickSlider();

protected:
    void mousePressEvent(QMouseEvent *ev);

};

#endif // CLICKSLIDER_H
