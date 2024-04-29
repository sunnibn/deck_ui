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
    deck/deck_config/deckconfigdisplay.cpp \
    deck/deck_config/deckconfigdisplaybar.cpp \
    deck/deck_config/deckconfigscreen.cpp \
    deck/deck_default/deckbar.cpp \
    deck/deck_default/deckdisplay.cpp \
    deck/deck_default/deckscreen.cpp \
    deck/deckwindow.cpp \
    item/barscreenbutton.cpp \
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
    deck/deck_config/deckconfigdisplay.h \
    deck/deck_config/deckconfigdisplaybar.h \
    deck/deck_config/deckconfigscreen.h \
    deck/deck_default/deckbar.h \
    deck/deck_default/deckdisplay.h \
    deck/deck_default/deckscreen.h \
    deck/deckwindow.h \
    item/barscreenbutton.h \
    item/clickslider.h \
    item/musiclistitem.h \
    data/musicplayer.h \
    playerwindow.h \
    ui/musicfilesystemwidget.h \
    ui/musicplayerwidget.h \
    ui/ui.h

FORMS += \
    deck/deck_config/deckconfigbar.ui \
    deck/deck_config/deckconfigdisplay.ui \
    deck/deck_config/deckconfigdisplaybar.ui \
    deck/deck_config/deckconfigscreen.ui \
    deck/deck_default/deckbar.ui \
    deck/deck_default/deckdisplay.ui \
    deck/deck_default/deckscreen.ui \
    deck/deckwindow.ui \
    item/barscreenbutton.ui \
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
    deck/deck_default \
