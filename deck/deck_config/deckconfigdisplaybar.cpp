#include "deckconfigdisplaybar.h"
#include "ui_deckconfigdisplaybar.h"

DeckConfigDisplayBar::DeckConfigDisplayBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DeckConfigDisplayBar)
{
    ui->setupUi(this);

    ui->moveBtn->installEventFilter(this);
    ui->resizeBtn->installEventFilter(this);

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
                this->parentWidget()->move(pw + x-px, ph + y-py);
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
                this->parentWidget()->resize(pw + x-px, ph + y-py);
            }
            break;
        }
    }
    return QWidget::eventFilter(o, e);
}

//=== button slots
void DeckConfigDisplayBar::on_removeBtn_clicked() {

}
void DeckConfigDisplayBar::on_settingBtn_clicked() {

}
