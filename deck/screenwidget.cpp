#include <iostream>

#include "screenwidget.h"
#include "ui_screenwidget.h"

#include <QVBoxLayout>
// #include <QSizeGrip>

#include "ui/musicplayerwidget.h"
#include "ui/musicfilesystemwidget.h"

ScreenWidget::ScreenWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScreenWidget)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("border: 1px solid lightgray; background: black;");
    btn = new QPushButton(this);
    bar = new ScreenBar(this);

    screenResizable(true);
}

ScreenWidget::ScreenWidget(int displayNo, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScreenWidget)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("border: 1px solid lightgray; background: black;");
    btn = new QPushButton(this);
    bar = new ScreenBar(this);

    screenDisplay(displayNo);
    screenResizable(true);
}

ScreenWidget::~ScreenWidget()
{
    delete ui;
}

//=== screen display functions

bool ScreenWidget::eventFilter(QObject *o, QEvent *e) {
    if (o == btn) {
        QMouseEvent *mE = static_cast<QMouseEvent*>(e);
        switch(e->type()) {
        case QEvent::MouseButtonPress:
            if (mE->button() == Qt::LeftButton) {
                pw = this->width();
                ph = this->height();
                px = mE->scenePosition().x();
                py = mE->scenePosition().y();
            }
            break;
        case QEvent::MouseMove:
            x = mE->scenePosition().x();
            y = mE->scenePosition().y();
            this->resize(pw + x-px, ph + y-py);
            break;
        case QEvent::MouseButtonRelease:
            if (mE->button() == Qt::LeftButton) {
                this->resize(pw + x-px, ph + y-py);
            }
            break;
        }
    }
    return QWidget::eventFilter(o, e);
}

void ScreenWidget::screenResizable(bool enable) {
    if (enable) {
        btn->installEventFilter(this);
        // this->setWindowFlags(Qt::SubWindow);
        btn->setStyleSheet("width:20; height:20; border:1px solid lightgray; background: gray; margin:20;");
        ui->gridLayout->addWidget(btn, 0,0,1,1, Qt::AlignBottom | Qt::AlignRight);
        ui->gridLayout->addWidget(bar, 0,0,1,1, Qt::AlignBottom);
    } else {
        // this->setWindowFlags(Qt::Widget);
        bar->hide();
    }
}

void ScreenWidget::screenDisplay(int displayNo) {
    switch (displayNo) {
    case MUSIC_PLAYER_1:
        ui->widget->layout()->addWidget(new MusicPlayerWidget);
        break;
    case MUSIC_LIST_1:
        ui->widget->layout()->addWidget(new MusicFileSystemWidget);
        break;
    }
}
