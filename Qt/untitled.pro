QT       += core gui
QT +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    goods.cpp \
    inventory.cpp \
    login.cpp \
    main.cpp \
    order_detail.cpp \
    orders.cpp \
    purchase.cpp \
    storehouse.cpp \
    widget.cpp

HEADERS += \
    goods.h \
    inventory.h \
    login.h \
    order_detail.h \
    orders.h \
    purchase.h \
    storehouse.h \
    widget.h

FORMS += \
    goods.ui \
    inventory.ui \
    login.ui \
    order_detail.ui \
    orders.ui \
    purchase.ui \
    storehouse.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
