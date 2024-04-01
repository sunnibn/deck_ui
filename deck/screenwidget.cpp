#include "screenwidget.h"
#include "ui_screenwidget.h"

#include <QVBoxLayout>
#include <QSizeGrip>

ScreenWidget::ScreenWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScreenWidget)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("border: 1px solid lightgray; background: black;");

    this->setWindowFlags(Qt::SubWindow);
    QSizeGrip *grip = new QSizeGrip(this);
    grip->setStyleSheet("margin:10;");
    ui->gridLayout->addWidget(grip, 0,0,1,1, Qt::AlignBottom | Qt::AlignRight);
}

ScreenWidget::~ScreenWidget()
{
    delete ui;
}
