
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ControlCenter
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    MatToQImageConverter.cpp \
    ImageProcessor.cpp \
    CameraCapture.cpp \
    PointerManager.cpp \
    MousePointerManager.cpp \
    ConfigurationWindow.cpp \
    SystemConfiguration.cpp \
    rocket.cpp \
    bullet.cpp

HEADERS  += MainWindow.h \
    MatToQImageConverter.h \
    ImageProcessor.h \
    CameraCapture.h \
    PointerManager.h \
    MousePointerManager.h \
    ConfigurationWindow.h \
    SystemConfiguration.h \
    rocket.h \
    bullet.h

FORMS    += MainWindow.ui \
    ConfigurationWindow.ui

CONFIG += link_pkgconfig
PKGCONFIG += opencv

RESOURCES += \
    resources.qrc
