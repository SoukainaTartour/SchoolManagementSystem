QT       += core gui sql

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
    ajouteretudiant.cpp \
    ajoutermatiere.cpp \
    ajouterprof.cpp \
    etudiants.cpp \
    main.cpp \
    login.cpp \
    matieres.cpp \
    menu.cpp \
    modifieretu.cpp \
    modifierma.cpp \
    modifierprof.cpp \
    professeurs.cpp \
    supprimeretu.cpp \
    supprimerma.cpp \
    supprimerprof.cpp

HEADERS += \
    ajouteretudiant.h \
    ajoutermatiere.h \
    ajouterprof.h \
    etudiants.h \
    login.h \
    matieres.h \
    menu.h \
    modifieretu.h \
    modifierma.h \
    modifierprof.h \
    professeurs.h \
    supprimeretu.h \
    supprimerma.h \
    supprimerprof.h


FORMS += \
    ajouteretudiant.ui \
    ajoutermatiere.ui \
    ajouterprof.ui \
    etudiants.ui \
    login.ui \
    matieres.ui \
    menu.ui \
    modifieretu.ui \
    modifierma.ui \
    modifierprof.ui \
    professeurs.ui \
    supprimeretu.ui \
    supprimerma.ui \
    supprimerprof.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
