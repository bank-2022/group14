QT -= gui
QT += network

TEMPLATE = lib
DEFINES += REST_API_DLL_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    api_engine.cpp \
    rest_api_dll.cpp

HEADERS += \
    api_engine.h \
    rest_api_dll_global.h \
    rest_api_dll.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
