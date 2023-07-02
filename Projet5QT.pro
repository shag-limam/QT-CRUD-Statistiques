QT       += core gui sql
QT += charts



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authentification.cpp \
    controller.cpp \
    dbaccess.cpp \
    edit.cpp \
    etudiant.cpp \
    etudiantmodel.cpp \
    main.cpp \
    mainwindow.cpp \
    themewidget.cpp \
    uilistepersonnemodel.cpp \
    uilistpersonn.cpp \
    uimain.cpp \
    uiparcour.cpp \
    user.cpp \
    usermodel.cpp

HEADERS += \
    edit.h \
    etudiant.h \
    etudiantmodel.h \
    authentification.h \
    controller.h \
    dbaccess.h \
    mainwindow.h \
    themewidget.h \
    uilistepersonnemodel.h \
    uilistpersonn.h \
    uimain.h \
    uiparcour.h \
    user.h \
    usermodel.h

FORMS += \
    authentification.ui \
    mainwindow.ui \
    themewidget.ui \
    uilistpersonn.ui \
    uiparcour.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QXLSX_PARENTPARH=./
QXLSX_HEADERPATH=./header/
QXLSX_SOURCEPATH=./source/
include(./QXlsx.pri)
