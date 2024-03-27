#include <iostream>

#include "musicfilesystemwidget.h"
#include "ui_musicfilesystemwidget.h"

#include <QDir>

MusicFileSystemWidget::MusicFileSystemWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MusicFileSystemWidget)
{
    ui->setupUi(this);
    this->setDirectory("../storage");
}

MusicFileSystemWidget::~MusicFileSystemWidget()
{
    delete ui;
}

//=== file system list display

void MusicFileSystemWidget::setDirectory(QString path) {
    QDir directory(path);
    ui->pathLabel->setText(directory.currentPath());

    QStringList fileFilter;
    fileFilter << "*.mp3" << "*.MP3";
    QStringList files = directory.entryList(fileFilter, QDir::Files);
    QStringList dirs = directory.entryList(QDir::Dirs);
    std::cout << files.size() << ' '<< dirs.size() << std::endl;

    foreach(QString filename, files) {
        std::cout << qPrintable(filename) << std::endl;
        ui->label->setText(filename);
    }
}
