#-------------------------------------------------
#
# Project created by QtCreator 2015-11-08T08:30:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pmu
TEMPLATE = app

INCLUDEPATH += pmuIHM

SOURCES += main.cpp\
    pmuIHM/GuessULikeWidget.cpp \
    pmuIHM/HottipsWidget.cpp \
    pmuIHM/InstitutionWidget.cpp \
    pmuIHM/PrivilegeWidget.cpp \
    pmuIHM/RegAndSignPage.cpp \
    pmuIHM/PmuHomeTabPage.cpp \
    pmuIHM/PmuMainPage.cpp \
    pmuIHM/PmuEnterPage.cpp \
    pmuIHM/SearchWidget.cpp \
    pmuIHM/CoursePublishPage.cpp \
    pmuIHM/MyOwnPage.cpp \
    ConnectToServer.cpp \
    pmuIHM/TemplateWidget.cpp \
    AndroidGestureEvent.cpp \
    pmuIHM/ClassificationWidget.cpp \
    pmuIHM/MyRssCourse.cpp \
    pmuIHM/MySchedulePage.cpp \
    ReponseDecodage.cpp \
    ReponseReceiver.cpp \
    CurrentAction.cpp

HEADERS  += \
    pmuIHM/GuessULikeWidget.h \
    pmuIHM/HottipsWidget.h \
    pmuIHM/InstitutionWidget.h \
    pmuIHM/PrivilegeWidget.h \
    pmuIHM/RegAndSignPage.h \
    pmuIHM/PmuHomeTabPage.h \
    pmuIHM/PmuEnterPage.h \
    pmuIHM/PmuMainPage.h \
    pmuIHM/SearchWidget.h \
    pmuIHM/CoursePublishPage.h \
    pmuIHM/MyOwnPage.h \
    ConnectToServer.h \
    pmuIHM/TemplateWidget.h \
    AndroidGestureEvent.h \
    pmuIHM/ClassificationWidget.h \
    pmuIHM/MyRssCourse.h \
    pmuIHM/MySchedulePage.h \
    ReponseDecodage.h \
    ReponseReceiver.h \
    CurrentAction.h

RESOURCES += \
    imageresources.qrc

CONFIG += mobility
MOBILITY = 

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

