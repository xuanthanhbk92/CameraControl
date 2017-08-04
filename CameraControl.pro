#-------------------------------------------------
#
# Project created by QtCreator 2017-08-01T20:49:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CameraControl
TEMPLATE = app
CONFIG += c++11
#redirect qmakeinput to logfile

#DEFINES += REDIRECT_DEBUG_TO_LOG=0

# To build a time-limited version without using the license server
# uncomment the line below. Dont forget to update the expiry date
# in main.cpp !

#DEFINES += USE_OLD_TIME_LIMIT_LICENSE

#Icon on window
RC_ICONS = icon\icon.ico


VERSION = 1.0.0

QMAKE_TARGET_COMPANY = "Xuan ThanhCOR"
QMAKE_TARGET_PRODUCT = "Camera Control"
QMAKE_TARGET_DESCRIPTION = "Camera control via canbus"
QMAKE_TARGET_COPYRIGHT = "All Rights Reserved 2017 Xuan Thanh COR"


SOURCES += main.cpp\
        mainwindow.cpp \
    common.cpp

HEADERS  += mainwindow.h \
    common.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc \
    style.qrc

DISTFILES += \
    style.qss

