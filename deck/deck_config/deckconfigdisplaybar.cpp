#include "deckconfigdisplaybar.h"
#include "ui_deckconfigdisplaybar.h"

#include <iostream>

DeckConfigDisplayBar::DeckConfigDisplayBar(int displayIdx, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigDisplayBar)
{
    ui->setupUi(this);

    ui->moveBtn->installEventFilter(this);
    ui->resizeBtn->installEventFilter(this);
    this->displayIdx = displayIdx;
    ui->settingWidget->setVisible(this->settingFlag);

    this->setStyleSheet("border:1px solid lightgray; background: gray;");
}

DeckConfigDisplayBar::~DeckConfigDisplayBar()
{
    delete ui;
}



//=== event filter
bool DeckConfigDisplayBar::eventFilter(QObject *o, QEvent *e) {
    if (o == ui->moveBtn) {
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
                QWidget *q = this->parentWidget();
                q->move(pw + x-px, ph + y-py);
                CONFIG.moveDisplay(CONFIG.currScreenIdx, this->displayIdx, {q->x(), q->y(), q->width(), q->height()});
            }
            break;
        }
    }
    if (o == ui->resizeBtn) {
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
                QWidget *q = this->parentWidget();
                q->resize(pw + x-px, ph + y-py);
                CONFIG.moveDisplay(CONFIG.currScreenIdx, this->displayIdx, {q->x(), q->y(), q->width(), q->height()});
            }
            break;
        }
    }
    return QWidget::eventFilter(o, e);
}

//=== button slots
void DeckConfigDisplayBar::on_removeBtn_clicked() {
    CONFIG.delDisplayData(CONFIG.currScreenIdx, this->displayIdx);
}
void DeckConfigDisplayBar::on_settingBtn_clicked() {
    this->settingFlag = !this->settingFlag;
    ui->settingWidget->setVisible(this->settingFlag);
}
