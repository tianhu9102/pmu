#include "ClassificationWidget.h"
#include <QDebug>
#include <QtWidgets>

Q_LOGGING_CATEGORY(lcExample, "qt.examples.imagegestures")

ClassificationWidget::ClassificationWidget(QWidget *parent): QWidget(parent){
    this->initial();
    this->constructIHM();
    this->setConnections();
    //this->setStyleSheet("background-color:rgb(135,209,199)");
    this->drawBackground();
}

void ClassificationWidget::grabGestures(const QList<Qt::GestureType> &gestures)
{
    //! [enable gestures]
    foreach (Qt::GestureType gesture, gestures)
        grabGesture(gesture);
    //! [enable gestures]
}

bool ClassificationWidget::event(QEvent *event){
    if (event->type() == QEvent::Gesture)
            return gestureEvent(static_cast<QGestureEvent*>(event));
        return QWidget::event(event);
}

bool ClassificationWidget::gestureEvent(QGestureEvent *event){
    if (QGesture *swipe = event->gesture(Qt::SwipeGesture))
            swipeTriggered(static_cast<QSwipeGesture *>(swipe));
    else if (QGesture *pan = event->gesture(Qt::PanGesture))
           panTriggered(static_cast<QPanGesture *>(pan));
       else if (QGesture *tap = event->gesture(Qt::TapGesture))
           tapTriggered(static_cast<QTapGesture *>(tap));
       else if (QGesture *tapAndHold = event->gesture(Qt::TapAndHoldGesture))
           tapAndHoldTriggered(static_cast<QTapAndHoldGesture *>(tapAndHold));
       if (QGesture *pinch = event->gesture(Qt::PinchGesture))
           pinchTriggered(static_cast<QPinchGesture *>(pinch));
       return true;
}

void ClassificationWidget::swipeTriggered(QSwipeGesture *gesture)
{
    if (gesture->state() == Qt::GestureFinished) {
        if (gesture->horizontalDirection() == QSwipeGesture::Down
            || gesture->verticalDirection() == QSwipeGesture::Up) {
            contentWidgetScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
            qDebug()<<"sb";
            qCDebug(lcExample) << "swipeTriggered(): swipe to previous";
        } else {
            qCDebug(lcExample) << "swipeTriggered(): swipe to next";
        }
    }
}

void ClassificationWidget::panTriggered(QPanGesture *gesture)
{
#ifndef QT_NO_CURSOR
    switch (gesture->state()) {
        case Qt::GestureStarted:
        case Qt::GestureUpdated:
            setCursor(Qt::SizeAllCursor);
            break;
        default:
            setCursor(Qt::ArrowCursor);
    }
#endif
    QPointF delta = gesture->delta();
    qCDebug(lcExample) << "panTriggered():" << delta;
    horizontalOffset += delta.x();
    verticalOffset += delta.y();
}

void ClassificationWidget::pinchTriggered(QPinchGesture *gesture)
{
    QPinchGesture::ChangeFlags changeFlags = gesture->changeFlags();
    if (changeFlags & QPinchGesture::RotationAngleChanged) {
        const qreal value = gesture->property("rotationAngle").toReal();
        const qreal lastValue = gesture->property("lastRotationAngle").toReal();
        const qreal rotationAngleDelta = value - lastValue;
        rotationAngle += rotationAngleDelta;
        qCDebug(lcExample) << "pinchTriggered(): rotation by" << rotationAngleDelta << rotationAngle;
    }
    if (changeFlags & QPinchGesture::ScaleFactorChanged) {
        qreal value = gesture->property("scaleFactor").toReal();
        currentStepScaleFactor = value;
        qCDebug(lcExample) << "pinchTriggered(): " << currentStepScaleFactor;
    }
    if (gesture->state() == Qt::GestureFinished) {
        scaleFactor *= currentStepScaleFactor;
        currentStepScaleFactor = 1;
    }
    update();
}


void ClassificationWidget::tapTriggered(QTapGesture *gesture)
{
    qCDebug(lcExample) << "tapTriggered():" ;
}

void ClassificationWidget::tapAndHoldTriggered(QTapAndHoldGesture *gesture)
{
    qCDebug(lcExample) << "tapAndHoldTriggered():";
}



ClassificationWidget::~ClassificationWidget(){

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief LanguageWidget::display
//! \param textOption
//!
void ClassificationWidget::display(QString textOption){
    //! --------request data from server---------
    //!
    this->titleBarLabel->setText(textOption);
    if(textOption.contains("艺术")){
        this->firstWidget->setLabelText("舞蹈");
    }
    else if(textOption.contains("体育")){
        this->firstWidget->setLabelText("篮球");
    }
    else if(textOption.contains("生活")){
        this->firstWidget->setLabelText("健身");
    }

    this->show();
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief LanguageWidget::initial
//!
void ClassificationWidget::initial(){
    this->screen = QApplication::screens().at(0);
    this->height = screen->availableSize().height();
    this->width = screen->availableSize().width();
    this->caracterStyle = new QFont("Segoe UI" , 18, QFont::Normal, false);
    this->buttonHeight = 0.5 * 0.24 * 0.8 * height;
    this->buttonWidth = 0.5 * 0.7 * width;
    this->searchPage = new SearchWidget();
    qDebug()<<"height = "<<this->height<<"width = "<<this->width;

    QList<Qt::GestureType> gestures;
    gestures << Qt::PanGesture;
    gestures << Qt::PinchGesture;
    gestures << Qt::SwipeGesture;
    gestures << Qt::TapGesture;
    gestures << Qt::TapAndHoldGesture;
    this->grabGestures(gestures);
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief LanguageWidget::constructIHM
//!
void ClassificationWidget::constructIHM(){
    //! create tile bar area
    titleBar = new QFrame();
    titleBar->setFixedHeight(0.06 * height);
//    tileBar->setStyleSheet("background-color:red;border: 0px;");

    titleBarReturnButton = new QPushButton("＜");
    titleBarReturnButton->setFont(QFont("Segoe UI" , 25, QFont::Normal, false));
    titleBarReturnButton->setFixedSize(0.1 * width,0.06 * height);
    titleBarReturnButton->setStyleSheet("background-color:transparent;border: 0px;");

    titleBarLabel = new QLabel();
    titleBarLabel->setFont(QFont("Segoe UI" , 25, QFont::Normal, false));
    titleBarLabel->setAlignment(Qt::AlignCenter);
    titleBarLabel->setStyleSheet("background-color:transparent;border: 0px");

    titleBarSearchButton = new QPushButton();
    titleBarSearchButton->setFixedSize(0.1 * width,0.06 * height);
    titleBarSearchButton->setIcon(QIcon(":/images/searchButton1.png"));
    titleBarSearchButton->setIconSize(QSize(0.1 * width,0.06 * height));
    titleBarSearchButton->setStyleSheet("background-color:transparent;border: 0px;");

    titleBarLayout = new QHBoxLayout(titleBar);
    titleBarLayout->addWidget(titleBarReturnButton);
    titleBarLayout->addWidget(titleBarLabel);
    titleBarLayout->addWidget(titleBarSearchButton);
    titleBarLayout->setSpacing(0);
    titleBarLayout->setMargin(0);


    //! first window chinese
    this->firstWidget = new TemplateWidget(width, height);
    this->secondWidget = new TemplateWidget(width, height);
    this->thirdWidget = new TemplateWidget(width, height);
    this->fourthWidget = new TemplateWidget(width, height);
    this->fifthWidget = new TemplateWidget(width, height);
    this->sixthWidget = new TemplateWidget(width, height);

    //!create content bar area
    contentWidget = new QWidget();
    //!--------------------
    this->mainLayout = new QVBoxLayout(contentWidget);
    mainLayout->addWidget(firstWidget);
    mainLayout->addWidget(secondWidget);
    mainLayout->addWidget(thirdWidget);
    mainLayout->addWidget(fourthWidget);
    mainLayout->addWidget(fifthWidget);
    mainLayout->addWidget(sixthWidget);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    contentWidgetScrollArea = new QScrollArea();
//    contentWidgetScrollArea->setFixedHeight(0.8*height);
    contentWidgetScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    contentWidgetScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    contentWidgetScrollArea->setStyleSheet("QScrollBar:vertical {border: 0px; background: transparent; width: 20px;}"
                                           "QScrollBar::handle:vertical {background: #8080FF; border-radius:10px;min-height: 10px;}"
                                           "QScrollBar::add-line:vertical {height: 0px;subcontrol-position: bottom;}"
                                           "QScrollBar::sub-line:vertical {height: 0px; subcontrol-position: top;}"
                                           "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: transparent;}"
                                           );
    contentWidgetScrollArea->viewport()->setBackgroundRole(QPalette::Light);
    contentWidgetScrollArea->setWidgetResizable(false);

    //contentWidgetScrollArea->setBackgroundRole(QPalette::Dark);
    contentWidgetScrollArea->setWidget(contentWidget);
    
    //! advertisement area
    adsWidget = new QWidget();
    adsWidget->setStyleSheet("background-color:aliceblue;border: 0px");
    adsWidget->setFixedHeight(0.12 * height);

    mainWidgetLayout = new QVBoxLayout(this);
    mainWidgetLayout->addWidget(titleBar);
    mainWidgetLayout->addWidget(contentWidgetScrollArea);
    mainWidgetLayout->addWidget(adsWidget);
    mainWidgetLayout->setSpacing(5);
    mainWidgetLayout->setMargin(0);

}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief LanguageWidget::drawBackground
//!
void ClassificationWidget::drawBackground(){
    pixmap = new QPixmap(":/images/background.png");
    QPalette p = this->palette();
    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(width, height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(p);
    this->setMask(pixmap->mask());
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief LanguageWidget::setConnections
//!
void ClassificationWidget::setConnections(){
    this->connect(titleBarSearchButton, SIGNAL(clicked()), this, SLOT(signSearchPage()));
    this->connect(titleBarReturnButton, SIGNAL(clicked()), this, SLOT(close( )));
}

//!----------------------------------------------------------------------------------------------------
//!
//! \brief LanguageWidget::signSearchPage
//!
void ClassificationWidget::signSearchPage(){

    searchPage->show();
}

//!----------------------------------------------------------------------------------------------------

