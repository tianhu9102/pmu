#ifndef REGANDSIGNPAGE_H
#define REGANDSIGNPAGE_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QApplication>
#include <QScreen>
#include <QLineEdit>
#include <QDebug>
#include <QSpacerItem>
#include <QMenu>
#include <QMenuBar>
#include <QFont>

class RegAndSignPage : public QWidget
{
    Q_OBJECT

public:
    RegAndSignPage(int width, int height, bool flag);
    ~RegAndSignPage();

    void initVariable();
    void constructIHM();
    void drawBackground();
    void setConnections();
    void checkStates();
    void setState(bool flag);

private:
    int width;
    int height;
    bool flag;
    QPixmap* pixmap;

    QFont *caracterStyle;

    QPushButton* returnButton;
    QPushButton* moreInformationButton;
    QPushButton *loginButton;
    QPushButton *forgetButton;
    QPushButton *registrationButton;

    QLabel* mainWidgetName;

    QLineEdit *emailAddressLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *confirmPasswordLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QLineEdit *addressLineEdit;

    QVBoxLayout *statusBarLayout;
    QHBoxLayout* titleBarLayout;
    QVBoxLayout *mainWidgetLayout;
    QVBoxLayout *loginWindowLayout;
    QHBoxLayout *switchStatusWindowLayout;
    QVBoxLayout *signUpInformationWidgetLayout;

    QWidget *loginWindow;
    QWidget *titleBar;
    QWidget *statusBar;
    QWidget *switchStatusWindow;
    QWidget *switchStatusWindowRest;
    QWidget *signUpInformationWidget;

    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;

    QMenuBar *menuBar;

    QSpacerItem *loginWindowRest;
//    QWidget *loginButtonWindow;

public slots:
    void showSignUpInformation();

};


#endif // REGANDSIGNPAGE_H
