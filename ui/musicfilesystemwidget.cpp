#include <iostream>

#include "musicfilesystemwidget.h"
#include "ui_musicfilesystemwidget.h"

#include "data/musicplayer.h"
#include "item/musiclistitem.h"

#include <QDir>

extern MusicPlayer MP;

MusicFileSystemWidget::MusicFileSystemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicFileSystemWidget)
{
    ui->setupUi(this);
    this->setDirectory();
}

MusicFileSystemWidget::~MusicFileSystemWidget()
{
    delete ui;
}

//=== current directory in list display

void MusicFileSystemWidget::setDirectory() {
    // clear layout first
    QLayoutItem *child;
    while ((child = ui->listLayout->takeAt(0)) != nullptr) {
        delete child->widget();
    }
    // setup path
    ui->pathLabel->setText(MP.dirPath);
    // directories
    for (int i=0; i<MP.dirList.size(); i++) {
        MusicListItem *item = new MusicListItem();
        item->setItem(MP.dirPathList[i], MP.dirList[i], "", i);
        // connect(item, SIGNAL(clicked()), item, SLOT(selectDirSlot()));
        connect(item, &QPushButton::clicked, [i, this]() { this->selectDirectory(i); });
        ui->listLayout->addWidget(item);
    }
    // files
    for (int i=0; i<MP.fileList.size(); i++) {
        MusicListItem *item = new MusicListItem();
        item->setItem(MP.filePathList[i], MP.fileList[i], "", i);
        // connect(item, SIGNAL(clicked()), item, SLOT(selectMusicSlot()));
        connect(item, &QPushButton::clicked, [i, this]() { this->selectFile(i); });
        ui->listLayout->addWidget(item);
    }
}

//=== slot / slot related functions
void MusicFileSystemWidget::on_backButton_clicked() {
    QString path = MP.dirPath + QString("/") + "..";
    QDir directory(path);
    MP.loadList(directory.absolutePath());
    this->setDirectory();
}
void MusicFileSystemWidget::selectFile(int idx) {
    QString path = MP.filePathList[idx];
    MP.loadMusic(path);
    MP.fileIdx = idx;

    // std::cout<< idx << std::endl;
}
void MusicFileSystemWidget::selectDirectory(int idx) {
    QString path = MP.dirPathList[idx];
    MP.loadList(path);
    this->setDirectory();

    // std::cout<< idx << std::endl;
}
