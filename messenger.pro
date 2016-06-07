#-------------------------------------------------
#
# Project created by QtCreator 2016-05-08T19:28:39
#
#-------------------------------------------------

HEADERS       = chatdialog.h \
                client.h \
                connection.h \
                peermanager.h \
                server.h \
    username.h
SOURCES       = chatdialog.cpp \
                client.cpp \
                connection.cpp \
                main.cpp \
                peermanager.cpp \
                server.cpp \
    username.cpp
FORMS         = chatdialog.ui \
                username.ui
QT           += network widgets

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/network-chat
INSTALLS += target
