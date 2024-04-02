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
    ui->widget->setStyleSheet("border: 1px solid lightgray; background: transparent;");
    screenDisplay(MUSIC_PLAYER_1);
    screenResizable(true);
}

ScreenWidget::ScreenWidget(int displayNo, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScreenWidget)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("border: 1px solid lightgray; background: black;");
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
        // std::cout<< e->type() << std::endl;

        switch(e->type()) {
        case QEvent::MouseButtonPress:
            if (mE->button() == Qt::LeftButton) {
                pw = this->width();
                ph = this->height();
                px = mE->scenePosition().x();
                py = mE->scenePosition().y();
                // std::cout << px << ' ' << py  << std::endl;
                // std::cout << "pressed" << std::endl;
            }
            break;
        case QEvent::MouseMove:
            x = mE->scenePosition().x();
            y = mE->scenePosition().y();
            // std::cout << x << ' ' << y  << std::endl;
            this->resize(pw + x-px, ph + y-py);
            break;
        case QEvent::MouseButtonRelease:
            if (mE->button() == Qt::LeftButton) {
                this->resize(pw + x-px, ph + y-py);
                // std::cout << "released" << std::endl;
            }
            break;
        }
    }
    return QWidget::eventFilter(o, e);
}

void ScreenWidget::screenResizable(bool enable) {
    if (enable) {
        // grip = new QSizeGrip(thism);
        // grip->installEventFilter(this);
        btn = new QPushButton(this);
        btn->installEventFilter(this);

        // this->setWindowFlags(Qt::SubWindow);
        // grip->setStyleSheet("margin: 10;");
        // ui->gridLayout->addWidget(grip, 0,0,1,1, Qt::AlignBottom | Qt::AlignRight);
        btn->setStyleSheet("width:20; height:20; border:1px solid lightgray; background: gray; margin:20;");
        ui->gridLayout->addWidget(btn, 0,0,1,1, Qt::AlignBottom | Qt::AlignRight);
    } else {
        // this->setWindowFlags(Qt::Widget);
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
