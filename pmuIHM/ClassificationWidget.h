#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QApplication>
#include <QScreen>
#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QToolButton>
#include <QSpacerItem>
#include <QLabel>
#include <QIcon>
#include <QScrollArea>
#include <QScrollBar>
#include <QListWidget>
#include <QGridLayout>
#include <QFont>
#include "SearchWidget.h"
#include "TemplateWidget.h"
#include <QSwipeGesture>
#include <QEvent>
#include <QGestureEvent>

class ClassificationWidget : public QWidget
{
    Q_OBJECT

public:
    ClassificationWidget(QWidget *parent = 0);
    ~ClassificationWidget();

    void initial();
    void drawBackground();
    void constructIHM();
    void setConnections();
    void adjustScrollBar(QScrollBar *scrollBar);

    bool gestureEvent(QGestureEvent *event);
    void swipeTriggered(QSwipeGesture* gesture);

    void display(QString textOption);

protected:
    virtual bool event(QEvent *event);
private:
    QPixmap* pixmap;

    QScreen* screen;

    QFrame *titleBar;

    //---------------
    QVBoxLayout* mainLayout;
    TemplateWidget* firstWidget;
    TemplateWidget* secondWidget;
    TemplateWidget* thirdWidget;
    TemplateWidget* fourthWidget;
    TemplateWidget* fifthWidget;
    TemplateWidget* sixthWidget;
    //---------------

    //QScrollArea *contentWidget;
    QWidget *contentWidget;
    QWidget *adsWidget;
    QWidget *contentInfoChWidget;
    QWidget *contentInfoEnWidget;
    QWidget *contentInfoFrWidget;
    QWidget *contentInfoGeWidget;
    QWidget *contentInfoJaWidget;
    QWidget *contentInfoKoWidget;

    QWidget *contentChineseWidget;
    QWidget *contentEnglishWidget;
    QWidget *contentFrenchWidget;
    QWidget *contentDeutschWidget;
    QWidget *contentJapaneseWidget;
    QWidget *contentKoreanWidget;

//    QListWidget *contentListWindow;

    QVBoxLayout* mainWidgetLayout;
    QHBoxLayout* titleBarLayout;
    QVBoxLayout* contentWidgetLayout;
    QHBoxLayout* chineseWidgetLayout;
    QHBoxLayout* englishWidgetLayout;
    QHBoxLayout* frenchWidgetLayout;
    QHBoxLayout* deutschWidgetLayout;
    QHBoxLayout* japaneseWidgetLayout;
    QHBoxLayout* koreanWidgetLayout;

    QGridLayout* chineseGridLayout;
    QGridLayout* englishGridLayout;
    QGridLayout* frenchGridLayout;
    QGridLayout* deutschGridLayout;
    QGridLayout* japaneseGridLayout;
    QGridLayout* koreanGridLayout;
//    QGridLayout* testGridLayout;

//    QSpacerItem* tileBarSpacer;

    QPushButton* titleBarReturnButton;
    QPushButton* titleBarSearchButton;
    QPushButton* chineseGridButtonone;
    QPushButton* chineseGridButtontwo;
    QPushButton* chineseGridButtonthree;
    QPushButton* chineseGridButtonfour;
    QPushButton* chineseGridButtonfive;
    QPushButton* chineseGridButtonsix;
    QPushButton* englishGridButtonone;
    QPushButton* englishGridButtontwo;
    QPushButton* englishGridButtonthree;
    QPushButton* englishGridButtonfour;
    QPushButton* englishGridButtonfive;
    QPushButton* englishGridButtonsix;
    QPushButton* frenchGridButtonone;
    QPushButton* frenchGridButtontwo;
    QPushButton* frenchGridButtonthree;
    QPushButton* frenchGridButtonfour;
    QPushButton* frenchGridButtonfive;
    QPushButton* frenchGridButtonsix;
    QPushButton* deutschGridButtonone;
    QPushButton* deutschGridButtontwo;
    QPushButton* deutschGridButtonthree;
    QPushButton* deutschGridButtonfour;
    QPushButton* deutschGridButtonfive;
    QPushButton* deutschGridButtonsix;
    QPushButton* japaneseGridButtonone;
    QPushButton* japaneseGridButtontwo;
    QPushButton* japaneseGridButtonthree;
    QPushButton* japaneseGridButtonfour;
    QPushButton* japaneseGridButtonfive;
    QPushButton* japaneseGridButtonsix;
    QPushButton* koreanGridButtonone;
    QPushButton* koreanGridButtontwo;
    QPushButton* koreanGridButtonthree;
    QPushButton* koreanGridButtonfour;
    QPushButton* koreanGridButtonfive;
    QPushButton* koreanGridButtonsix;

    QFont *caracterStyle;

    QLabel* titleBarLabel;
    QLabel* chineseLabel;
    QLabel* englishLabel;
    QLabel* frenchLabel;
    QLabel* deutchLabel;
    QLabel* japaneseLabel;
    QLabel* koreanLabel;

    QScrollArea* contentWidgetScrollArea;

    SearchWidget *searchPage;
    int height;
    int width;
    int buttonWidth;
    int buttonHeight;

signals:

public slots:
    void signSearchPage();

};

#endif // WIDGET_H
