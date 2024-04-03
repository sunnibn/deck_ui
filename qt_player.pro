QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clickslider.cpp \
    deck/screenbar.cpp \
    deckwindow.cpp \
    item/musiclistitem.cpp \
    main.cpp \
    data/musicplayer.cpp \
    playerwindow.cpp \
    deck/screenwidget.cpp \
    ui/musicfilesystemwidget.cpp \
    ui/musicplayerwidget.cpp

HEADERS += \
    clickslider.h \
    deck/screenbar.h \
    deckwindow.h \
    item/musiclistitem.h \
    data/musicplayer.h \
    playerwindow.h \
    deck/screenwidget.h \
    ui/musicfilesystemwidget.h \
    ui/musicplayerwidget.h

FORMS += \
    deck/screenbar.ui \
    deckwindow.ui \
    item/musiclistitem.ui \
    playerwindow.ui \
    deck/screenwidget.ui \
    ui/musicfilesystemwidget.ui \
    ui/musicplayerwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

INCLUDEPATH += \
    ui \
    item \
    data \
    deck \
