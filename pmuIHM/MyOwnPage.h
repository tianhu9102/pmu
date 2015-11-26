#ifndef PERSONALINFORMATION_H
#define PERSONALINFORMATION_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QScreen>
#include <QFont>
#include <QToolButton>

class MyOwnPage : public QWidget
{
    Q_OBJECT

public:
    MyOwnPage(int width, int height);
    ~MyOwnPage();

    void initial();
    void constructIHM();
    void setConnections();
private:
    QLabel* idAvatarLabel;
    QLabel* idAccountLabel;
    QLabel* idEmailLabel;

    QWidget* idWidget;
    QWidget* courseInfoWidget;
    QWidget* fWidget;
    QWidget* sWidget;
    QWidget* tWidget;
    QWidget* foWidget;

    QToolButton* fButton;
    QToolButton* sButton;
    QToolButton* tButton;
    QToolButton* foButton;

    QVBoxLayout* mainLayout;
    QVBoxLayout* idLayout;
    QVBoxLayout* fLayout;
    QVBoxLayout* sLayout;
    QVBoxLayout* tLayout;
    QVBoxLayout* foLayout;
    QVBoxLayout* fBLayout;
    QGridLayout* coursesLayout;

    QFont *characterStyle;
    QString toolButtonStyle;
    int width;
    int height;
    QScreen* screen;

private slots:
   void lks();

};

#endif // PERSONALINFORMATION_H
