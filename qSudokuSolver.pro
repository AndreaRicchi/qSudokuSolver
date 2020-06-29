QT += quick

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    src/sudokuboard.hpp

SOURCES += \
    src/main.cpp \
    src/sudokuboard.cpp

RESOURCES += \
    resources/qml.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


