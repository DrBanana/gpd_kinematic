#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T11:51:28
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gepard_Kinematic
TEMPLATE = app

INCLUDEPATH += ../../includes
INCLUDEPATH += ../../includes/3rd_party/glew
INCLUDEPATH += ../../includes/3rd_party
INCLUDEPATH += ../../includes/3rd_party/freetype

INCLUDEPATH += ../../src

#ЗАМЕНИТЬ НА СВОЮ ПАПКУ С BOOST-ом
INCLUDEPATH += C:/BOOST
LIBS += -LC:/BOOST/lib

SOURCES += main.cpp\
        mainwindow.cpp\
        ../../src/QtGRenderWidget.cpp\
        ../../src/GRenderWin.cpp\
        ../../src/AddMovement/AddMovementDlg.cpp\
        ../../src/CMovements/CMovements.cpp\
        ../../src/CMovements/Mover.cpp\
        ../../src/ProgressBar/progressbardlg.cpp\
        ../../src/TimeLine/timeline.cpp\
        ../../src/TimeLine/tRunPrmWin.cpp


HEADERS  += mainwindow.h\
         ../../includes/gepard.h\
        ../../src/QtGRenderWidget.h\
        ../../src/GRenderWin.h\
        ../../src/AddMovement/AddMovementDlg.h\
        ../../src/CMovements/CMovements.h\
        ../../src/CMovements/Mover.h\
        ../../src/ProgressBar/progressbardlg.h\
        ../../src/TimeLine/timeline.h\
        ../../src/TimeLine/tRunPrmWin.h

#тип проекта
win32:contains(QMAKE_HOST.arch, x86_64) {
    CONFIG(debug, debug|release) {
        LIBS += -L../../Libs/x64_vs2013/Debug
    } else {
        LIBS += -L../../Libs/x64_vs2013/Release
    }

} else {
    CONFIG(debug, debug|release) {
        LIBS += -L../../Libs/x32_vs2010/Debug
    } else {
        LIBS += -L../../Libs/x32_vs2010/Release
    }
}


LIBS += -lGepard6_Core -lfreetype -lftgl_static -lglew32 -llibpng16 -lsdai_ap203 -lstepcore -lstepdai -lstepeditor -lsteputils

FORMS    += mainwindow.ui
FORMS    += ../../src/ProgressBar/progressbardlg.ui

CONFIG(debug, debug|release) {
    DESTDIR = ../../Build/Debug
} else {
    DESTDIR = ../../Build/Release
}
