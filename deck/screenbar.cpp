#include <iostream>

#include "screenbar.h"
#include "ui_screenbar.h"

ScreenBar::ScreenBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScreenBar)
{
    ui->setupUi(this);
    ui->moveButton->installEventFilter(this);
    ui->resizeButton->installEventFilter(this);

    this->setStyleSheet("border:1px solid lightgray; background: gray;");
}

ScreenBar::~ScreenBar()
{
    delete ui;
}

//=== event filter -> adjust ScreenWidget(parent)

bool ScreenBar::eventFilter(QObject *o, QEvent *e) {
    if (o == ui->moveButton) {
        QMouseEvent *mE = static_cast<QMouseEvent*>(e);
        switch(e->type()) {
        case QEvent::MouseButtonPress:
            if (mE->button() == Qt::LeftButton) {
                pw = this->parentWidget()->x();
                ph = this->parentWidget()->y();
                px = mE->scenePosition().x();
                py = mE->scenePosition().y();
            }
            break;
        case QEvent::MouseMove:
            x = mE->scenePosition().x();
            y = mE->scenePosition().y();
            this->parentWidget()->move(pw + x-px, ph + y-py);
            break;
        case QEvent::MouseButtonRelease:
            if (mE->button() == Qt::LeftButton) {
                this->parentWidget()->move(pw + x-px, ph + y-py);
            }
            break;
        }
    }
    if (o == ui->resizeButton) {
        QMouseEvent *mE = static_cast<QMouseEvent*>(e);
        switch(e->type()) {
        case QEvent::MouseButtonPress:
            if (mE->button() == Qt::LeftButton) {
                pw = this->parentWidget()->width();
                ph = this->parentWidget()->height();
                px = mE->scenePosition().x();
                py = mE->scenePosition().y();
            }
            break;
        case QEvent::MouseMove:
            x = mE->scenePosition().x();
            y = mE->scenePosition().y();
            this->parentWidget()->resize(pw + x-px, ph + y-py);
            break;
        case QEvent::MouseButtonRelease:
            if (mE->button() == Qt::LeftButton) {
                this->parentWidget()->resize(pw + x-px, ph + y-py);
            }
            break;
        }
    }
    return QWidget::eventFilter(o, e);
}

//=== bar buttons click slots

void ScreenBar::on_removeButton_clicked() {
    CONFIG.delDisplayData(screenIdx, displayIdx);
    //delete this->parent();
    //std::cout << qPrintable(this->parent()->parent()->objectName());
}
void ScreenBar::on_settingButton_clicked() {

}

