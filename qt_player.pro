QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data/decksetting.cpp \
    deck/deck_config/deckconfigbar.cpp \
    deck/deckbar.cpp \
    deck/deckwindow.cpp \
    deck/screenbar.cpp \
    deck/screenwidget.cpp \
    item/clickslider.cpp \
    item/musiclistitem.cpp \
    main.cpp \
    data/musicplayer.cpp \
    playerwindow.cpp \
    ui/musicfilesystemwidget.cpp \
    ui/musicplayerwidget.cpp

HEADERS += \
    data/decksetting.h \
    deck/deck_config/deckconfigbar.h \
    deck/deckbar.h \
    deck/deckwindow.h \
    deck/screenbar.h \
    deck/screenwidget.h \
    item/clickslider.h \
    item/musiclistitem.h \
    data/musicplayer.h \
    playerwindow.h \
    ui/musicfilesystemwidget.h \
    ui/musicplayerwidget.h

FORMS += \
    deck/deck_config/deckconfigbar.ui \
    deck/deckbar.ui \
    deck/deckwindow.ui \
    deck/screenbar.ui \
    deck/screenwidget.ui \
    item/clickslider.ui \
    item/musiclistitem.ui \
    playerwindow.ui \
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
    deck/deck_config \
