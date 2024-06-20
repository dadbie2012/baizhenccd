QT       += core gui
QT       += serialport
QT   +=     network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autofocusform.cpp \
    autofocusthread.cpp \
    cgxbitmap2.cpp \
    chuankou.cpp \
    client.cpp \
    computerinfothread.cpp \
    datevar.cpp \
    detectionresultform.cpp \
    expandform.cpp \
    exposetimesetting.cpp \
    fineline/CCaliperGUI.cpp \
    fineline/caliberline.cpp \
    fineline/controlline.cpp \
    fineline/drawline.cpp \
    fineline/edge.cpp \
    fineline/finelineform.cpp \
    fineline/mycorneritem.cpp \
    fineline/myqgraphicsview.cpp \
    fineline/shapematch.cpp \
    form.cpp \
    main.cpp \
    measurefunction.cpp \
    motioncontrol/app.cpp \
    motioncontrol/axis.cpp \
    motioncontrol/axis_status.cpp \
    motioncontrol/axisfunction.cpp \
    motioncontrol/axismotion.cpp \
    motioncontrol/axisthreadone.cpp \
    motioncontrol/axisthreadthree.cpp \
    motioncontrol/axisthreadtwo.cpp \
    motioncontrolform.cpp \
    setparameter.cpp \
    settingmeasureform.cpp \
    tcpserver.cpp \
    visiondahengcamera.cpp \
    visionmainwindow.cpp \
    visionmeasure.cpp

HEADERS += \
    autofocusform.h \
    autofocusthread.h \
    cgxbitmap2.h \
    chuankou.h \
    client.h \
    computerinfothread.h \
    datevar.h \
    detectionresultform.h \
    expandform.h \
    exposetimesetting.h \
    fineline/CCaliperGUI.h \
    fineline/caliberline.h \
    fineline/common.h \
    fineline/controlline.h \
    fineline/drawline.h \
    fineline/edge.h \
    fineline/finelineform.h \
    fineline/mycorneritem.h \
    fineline/myqgraphicsview.h \
    fineline/shapematch.h \
    form.h \
    inc/AdvDXFReader.h \
    inc/AdvMotApi.h \
    inc/AdvMotDev.h \
    inc/AdvMotDrv.h \
    inc/AdvMotErr.h \
    inc/AdvMotPropID.h \
    inc/bdaqctrl.h \
    measurefunction.h \
    motioncontrol/app.h \
    motioncontrol/axis.h \
    motioncontrol/axis_status.h \
    motioncontrol/axisfunction.h \
    motioncontrol/axismotion.h \
    motioncontrol/axisthreadone.h \
    motioncontrol/axisthreadthree.h \
    motioncontrol/axisthreadtwo.h \
    motioncontrolform.h \
    setparameter.h \
    settingmeasureform.h \
    tcpserver.h \
    visiondahengcamera.h \
    visionmainwindow.h \
    visionmeasure.h

FORMS += \
    autofocusform.ui \
    chuankou.ui \
    client.ui \
    detectionresultform.ui \
    expandform.ui \
    exposetimesetting.ui \
    fineline/finelineform.ui \
    form.ui \
    motioncontrol/axis_status.ui \
    motioncontrolform.ui \
    setparameter.ui \
    settingmeasureform.ui \
    tcpserver.ui \
    visionmainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
LIBS += ./release/ADVMOT.lib
INCLUDEPATH += \
               D:\opencv4.5.0\opencv\build\include\opencv2\
               D:\opencv4.5.0\opencv\build\include\
               D:\download\GalaxySDK\GalaxySDK\APIDll\Win64


LIBS += \
              D:\opencv4.5.0\opencv\build\x64\vc15\lib\opencv_world450.lib\
              D:\opencv4.5.0\opencv\build\x64\vc15\lib\opencv_world450d.lib\
              D:\opencv4.5.0\opencv\build\x64\vc15\lib\high_shape_match.lib








unix|win32: LIBS += -L'D:/download/GalaxySDK/Samples/C++ SDK/lib/x64/' -lGxIAPICPPEx

INCLUDEPATH += 'D:/download/GalaxySDK/Samples/C++ SDK/lib/x64/'
DEPENDPATH += 'D:/download/GalaxySDK/Samples/C++ SDK/lib/x64/'

INCLUDEPATH += 'D:/download/GalaxySDK/Samples/C++ SDK/inc'
DEPENDPATH += 'D:/download/GalaxySDK/Samples/C++ SDK/inc'



LIBS += -luser32

RESOURCES += \
    image.qrc \
    resourse.qrc

DISTFILES += \
    file \
    image/apple.png \
    image/caomei.png \
    inc/ADVMOT.lib \
    inc/AdvDXFReader.lib
