QT       += core gui

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
    CompteManager.cpp \
    CompteRacine.cpp \
    CompteReel.cpp \
    CompteVirtuel.cpp \
    Operation.cpp \
    Transaction.cpp \
    TransactionManager.cpp \
    fen_cloture.cpp \
    fen_modifiertransaction.cpp \
    fen_newcompte.cpp \
    fen_newtransaction.cpp \
    fen_releves.cpp \
    fen_supprimercompte.cpp \
    fen_supprimertransaction.cpp \
    fen_touslescomptes.cpp \
    main.cpp \
    mainwindow.cpp \
    timing.cpp

HEADERS += \
    Compte.h \
    CompteManager.h \
    CompteRacine.h \
    CompteReel.h \
    CompteVirtuel.h \
    Erreur.h \
    Operation.h \
    Transaction.h \
    TransactionManager.h \
    fen_cloture.h \
    fen_modifiertransaction.h \
    fen_newcompte.h \
    fen_newtransaction.h \
    fen_releves.h \
    fen_supprimercompte.h \
    fen_supprimertransaction.h \
    fen_touslescomptes.h \
    mainwindow.h \
    timing.h

FORMS += \
    fen_cloture.ui \
    fen_modifiertransaction.ui \
    fen_newcompte.ui \
    fen_newtransaction.ui \
    fen_releves.ui \
    fen_supprimercompte.ui \
    fen_supprimertransaction.ui \
    fen_touslescomptes.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Projet_lo21.pro.user
