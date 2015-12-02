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
    void grabGestures(const QList<Qt::GestureType> &gestures);
    bool gestureEvent(QGestureEvent *event);
    void swipeTriggered(QSwipeGesture* gesture);
    void panTriggered(QPanGesture *gesture);
    void pinchTriggered(QPinchGesture *gesture);
    void tapTriggered(QTapGesture *gesture);
    void tapAndHoldTriggered(QTapAndHoldGesture *gesture);

    void display(QString textOption);

protected:
    virtual bool event(QEvent *event);
private:
    QPixmap* pixmap;
    QScreen* screen;
    QFrame *titleBar;

    QVBoxLayout* mainLayout;
    TemplateWidget* firstWidget;
    TemplateWidget* secondWidget;
    TemplateWidget* thirdWidget;
    TemplateWidget* fourthWidget;
    TemplateWidget* fifthWidget;
    TemplateWidget* sixthWidget;

    QWidget *contentWidget;
    QWidget *adsWidget;

    QVBoxLayout* mainWidgetLayout;
    QHBoxLayout* titleBarLayout;

    QPushButton* titleBarReturnButton;
    QPushButton* titleBarSearchButton;

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

    qreal horizontalOffset;
    qreal verticalOffset;
    qreal rotationAngle;
    qreal scaleFactor;
    qreal currentStepScaleFactor;

    int height;
    int width;
    int buttonWidth;
    int buttonHeight;

signals:

public slots:
    void signSearchPage();

};

#endif // WIDGET_H
