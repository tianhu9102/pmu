#include "ClassificationWidget.h"
#include <QDebug>

ClassificationWidget::ClassificationWidget(QWidget *parent): QWidget(parent){
    this->initial();
    this->constructIHM();
    this->setConnections();
    //this->setStyleSheet("background-color:rgb(135,209,199)");
    this->drawBackground();
}

bool ClassificationWidget::event(QEvent *event){
    if (event->type() == QEvent::Gesture)
            return gestureEvent(static_cast<QGestureEvent*>(event));
        return QWidget::event(event);
}

bool ClassificationWidget::gestureEvent(QGestureEvent *event){
    if (QGesture *swipe = event->gesture(Qt::SwipeGesture))
            swipeTriggered(static_cast<QSwipeGesture *>(swipe));
    return true;
}

void ClassificationWidget::swipeTriggered(QSwipeGesture* gesture){
    if (gesture->state() == Qt::GestureUpdated) {
            if (gesture->verticalDirection() == QSwipeGesture::Down
                || gesture->verticalDirection() == QSwipeGesture::Up) {
                qDebug() << "swipeTriggered(): swipe to previous";
            } else {
                qDebug() << "swipeTriggered(): swipe to next";
            }
        }
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
    this->grabGesture(Qt::SwipeGesture);
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
    //chineseLabel = new QLabel("中文");
//    chineseLabel->setFont(QFont("Segoe UI" , 40, QFont::Normal, false));
//    chineseLabel->setAlignment(Qt::AlignCenter);
//    chineseLabel->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    chineseLabel->setFixedWidth(0.3 * width);

//    chineseGridButtonone = new QPushButton("杜月1");
//    chineseGridButtonone->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    chineseGridButtonone->setFont(*caracterStyle);
//    chineseGridButtonone->setFixedSize(buttonWidth,buttonHeight);
//    chineseGridButtontwo = new QPushButton("杜月2");
//    chineseGridButtontwo->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    chineseGridButtontwo->setFont(*caracterStyle);
//    chineseGridButtontwo->setFixedSize(buttonWidth,buttonHeight);
//    chineseGridButtonthree = new QPushButton("杜月3");
//    chineseGridButtonthree->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    chineseGridButtonthree->setFont(*caracterStyle);
//    chineseGridButtonthree->setFixedSize(buttonWidth,buttonHeight);
//    chineseGridButtonfour = new QPushButton("更多");
//    chineseGridButtonfour->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    chineseGridButtonfour->setFont(*caracterStyle);
//    chineseGridButtonfour->setFixedSize(buttonWidth,buttonHeight);

//    contentInfoChWidget = new QWidget();
//    contentInfoChWidget->setFixedWidth(0.7 * width);
//    contentInfoChWidget->setStyleSheet("background-color:transparent;border: 0px;");

//    chineseGridLayout = new QGridLayout(contentInfoChWidget);
//    chineseGridLayout->addWidget(chineseGridButtonone,0,0,1,1);
//    chineseGridLayout->addWidget(chineseGridButtontwo,0,1,1,1);
//    chineseGridLayout->addWidget(chineseGridButtonthree,1,0,1,1);
//    chineseGridLayout->addWidget(chineseGridButtonfour,1,1,1,1);
//    chineseGridLayout->setHorizontalSpacing(width *0.02);
//    chineseGridLayout->setVerticalSpacing(height*0.012);
//    chineseGridLayout->setMargin(0);

//    contentChineseWidget = new QWidget();
//    contentChineseWidget->setFixedSize(width,0.24 * 0.8 *height);
//    contentChineseWidget->setStyleSheet("background-color:transparent");
//    chineseWidgetLayout = new QHBoxLayout(contentChineseWidget);
//    chineseWidgetLayout->addStretch(0);
    //chineseWidgetLayout->addWidget(chineseLabel);
//    chineseWidgetLayout->addWidget(contentInfoChWidget);
//    chineseWidgetLayout->addStretch(0);
//    chineseWidgetLayout->setAlignment(Qt::AlignCenter);
//    chineseWidgetLayout->setSpacing(width *0.01);
//    chineseWidgetLayout->setMargin(0);

    //!second window english
//    englishLabel = new QLabel("英語");
//    englishLabel->setFont(QFont("Segoe UI" , 40, QFont::Normal, false));
//    englishLabel->setAlignment(Qt::AlignCenter);
//    englishLabel->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    englishLabel->setFixedWidth(0.3 * width);

//    englishGridButtonone = new QPushButton("杜月1");
//    englishGridButtonone->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    englishGridButtonone->setFont(*caracterStyle);
//    englishGridButtonone->setFixedSize(buttonWidth,buttonHeight);
//    englishGridButtontwo = new QPushButton("杜月2");
//    englishGridButtontwo->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    englishGridButtontwo->setFont(*caracterStyle);
//    englishGridButtontwo->setFixedSize(buttonWidth,buttonHeight);
//    englishGridButtonthree = new QPushButton("杜月3");
//    englishGridButtonthree->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    englishGridButtonthree->setFont(*caracterStyle);
//    englishGridButtonthree->setFixedSize(buttonWidth,buttonHeight);
//    englishGridButtonfour = new QPushButton("更多");
//    englishGridButtonfour->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    englishGridButtonfour->setFont(*caracterStyle);
//    englishGridButtonfour->setFixedSize(buttonWidth,buttonHeight);

//    contentInfoEnWidget = new QWidget();
//    contentInfoEnWidget->setFixedWidth(0.7 * width);
//    contentInfoEnWidget->setStyleSheet("background-color:transparent;");

//    englishGridLayout = new QGridLayout(contentInfoEnWidget);
//    englishGridLayout->addWidget(englishGridButtonone,0,0,1,1);
//    englishGridLayout->addWidget(englishGridButtontwo,0,1,1,1);
//    englishGridLayout->addWidget(englishGridButtonthree,1,0,1,1);
//    englishGridLayout->addWidget(englishGridButtonfour,1,1,1,1);
//    englishGridLayout->setHorizontalSpacing(width *0.02);
//    englishGridLayout->setVerticalSpacing(height*0.012);
//    englishGridLayout->setMargin(0);

//    contentEnglishWidget = new QWidget();
//    contentEnglishWidget->setFixedHeight(0.24 * 0.8 * height);
//    contentEnglishWidget->setStyleSheet("background-color:transparent");

//    englishWidgetLayout = new QHBoxLayout(contentEnglishWidget);
//    englishWidgetLayout->addWidget(englishLabel);
//    englishWidgetLayout->addWidget(contentInfoEnWidget);
//    englishWidgetLayout->setSpacing(width *0.01);
//    englishWidgetLayout->setMargin(0);

//    //!thrid french window
//    frenchLabel = new QLabel("法語");
//    frenchLabel->setFont(QFont("Segoe UI" , 40, QFont::Normal, false));
//    frenchLabel->setAlignment(Qt::AlignCenter);
//    frenchLabel->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    frenchLabel->setFixedWidth(0.3 * width);

//    frenchGridButtonone = new QPushButton("杜月1");
//    frenchGridButtonone->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    frenchGridButtonone->setFont(*caracterStyle);
//    frenchGridButtonone->setFixedSize(buttonWidth,buttonHeight);
//    frenchGridButtontwo = new QPushButton("杜月2");
//    frenchGridButtontwo->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    frenchGridButtontwo->setFont(*caracterStyle);
//    frenchGridButtontwo->setFixedSize(buttonWidth,buttonHeight);
//    frenchGridButtonthree = new QPushButton("杜月3");
//    frenchGridButtonthree->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    frenchGridButtonthree->setFont(*caracterStyle);
//    frenchGridButtonthree->setFixedSize(buttonWidth,buttonHeight);
//    frenchGridButtonfour = new QPushButton("更多");
//    frenchGridButtonfour->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    frenchGridButtonfour->setFont(*caracterStyle);
//    frenchGridButtonfour->setFixedSize(buttonWidth,buttonHeight);

//    contentInfoFrWidget = new QWidget();
//    contentInfoFrWidget->setFixedWidth(0.7 * width);
//    contentInfoFrWidget->setStyleSheet("background-color:transparent;");

//    frenchGridLayout = new QGridLayout(contentInfoFrWidget);
//    frenchGridLayout->addWidget(frenchGridButtonone,0,0,1,1);
//    frenchGridLayout->addWidget(frenchGridButtontwo,0,1,1,1);
//    frenchGridLayout->addWidget(frenchGridButtonthree,1,0,1,1);
//    frenchGridLayout->addWidget(frenchGridButtonfour,1,1,1,1);
//    frenchGridLayout->setHorizontalSpacing(width *0.02);
//    frenchGridLayout->setVerticalSpacing(height*0.012);
//    frenchGridLayout->setMargin(0);

//    contentFrenchWidget = new QWidget();
//    contentFrenchWidget->setFixedHeight(0.24 * 0.8 * height);
//    contentFrenchWidget->setStyleSheet("background-color:transparent");

//    frenchWidgetLayout = new QHBoxLayout(contentFrenchWidget);
//    frenchWidgetLayout->addWidget(frenchLabel);
//    frenchWidgetLayout->addWidget(contentInfoFrWidget);
//    frenchWidgetLayout->setSpacing(width *0.01);
//    frenchWidgetLayout->setMargin(0);


//    //!forth deutsch window
//    deutchLabel = new QLabel("德語");
//    deutchLabel->setFont(QFont("Segoe UI" , 40, QFont::Normal, false));
//    deutchLabel->setAlignment(Qt::AlignCenter);
//    deutchLabel->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    deutchLabel->setFixedWidth(0.3 * width);

//    deutschGridButtonone = new QPushButton("杜月1");
//    deutschGridButtonone->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    deutschGridButtonone->setFont(*caracterStyle);
//    deutschGridButtonone->setFixedSize(buttonWidth,buttonHeight);
//    deutschGridButtontwo = new QPushButton("杜月2");
//    deutschGridButtontwo->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    deutschGridButtontwo->setFont(*caracterStyle);
//    deutschGridButtontwo->setFixedSize(buttonWidth,buttonHeight);
//    deutschGridButtonthree = new QPushButton("杜月3");
//    deutschGridButtonthree->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    deutschGridButtonthree->setFont(*caracterStyle);
//    deutschGridButtonthree->setFixedSize(buttonWidth,buttonHeight);
//    deutschGridButtonfour = new QPushButton("更多");
//    deutschGridButtonfour->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    deutschGridButtonfour->setFont(*caracterStyle);
//    deutschGridButtonfour->setFixedSize(buttonWidth,buttonHeight);

//    contentInfoGeWidget = new QWidget();
//    contentInfoGeWidget->setFixedWidth(0.7 * width);
//    contentInfoGeWidget->setStyleSheet("background-color:transparent;");

//    deutschGridLayout = new QGridLayout(contentInfoGeWidget);
//    deutschGridLayout->addWidget(deutschGridButtonone,0,0,1,1);
//    deutschGridLayout->addWidget(deutschGridButtontwo,0,1,1,1);
//    deutschGridLayout->addWidget(deutschGridButtonthree,1,0,1,1);
//    deutschGridLayout->addWidget(deutschGridButtonfour,1,1,1,1);
//    deutschGridLayout->setHorizontalSpacing(width *0.02);
//    deutschGridLayout->setVerticalSpacing(height*0.012);
//    deutschGridLayout->setMargin(0);

//    contentDeutschWidget = new QWidget();
//    contentDeutschWidget->setFixedHeight(0.24 * 0.8 * height);
//    contentDeutschWidget->setStyleSheet("background-color:transparent");

//    deutschWidgetLayout = new QHBoxLayout(contentDeutschWidget);
//    deutschWidgetLayout->addWidget(deutchLabel);
//    deutschWidgetLayout->addWidget(contentInfoGeWidget);
//    deutschWidgetLayout->setSpacing(width *0.01);
//    deutschWidgetLayout->setMargin(0);
//    //!

//    japaneseLabel = new QLabel("日語");
//    japaneseLabel->setFont(QFont("Segoe UI" , 40, QFont::Normal, false));
//    japaneseLabel->setAlignment(Qt::AlignCenter);
//    japaneseLabel->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    japaneseLabel->setFixedWidth(0.3 * width);

//    japaneseGridButtonone = new QPushButton("杜月1");
//    japaneseGridButtonone->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    japaneseGridButtonone->setFont(*caracterStyle);
//    japaneseGridButtonone->setFixedSize(buttonWidth,buttonHeight);
//    japaneseGridButtontwo = new QPushButton("杜月2");
//    japaneseGridButtontwo->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    japaneseGridButtontwo->setFont(*caracterStyle);
//    japaneseGridButtontwo->setFixedSize(buttonWidth,buttonHeight);
//    japaneseGridButtonthree = new QPushButton("杜月3");
//    japaneseGridButtonthree->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    japaneseGridButtonthree->setFont(*caracterStyle);
//    japaneseGridButtonthree->setFixedSize(buttonWidth,buttonHeight);
//    japaneseGridButtonfour = new QPushButton("更多");
//    japaneseGridButtonfour->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    japaneseGridButtonfour->setFont(*caracterStyle);
//    japaneseGridButtonfour->setFixedSize(buttonWidth,buttonHeight);


//    contentInfoJaWidget = new QWidget();
//    contentInfoJaWidget->setFixedWidth(0.7 * width);
//    contentInfoJaWidget->setStyleSheet("background-color:transparent;");

//    japaneseGridLayout = new QGridLayout(contentInfoJaWidget);
//    japaneseGridLayout->addWidget(japaneseGridButtonone,0,0,1,1);
//    japaneseGridLayout->addWidget(japaneseGridButtontwo,0,1,1,1);
//    japaneseGridLayout->addWidget(japaneseGridButtonthree,1,0,1,1);
//    japaneseGridLayout->addWidget(japaneseGridButtonfour,1,1,1,1);
//    japaneseGridLayout->setHorizontalSpacing(width *0.02);
//    japaneseGridLayout->setVerticalSpacing(height*0.012);
//    japaneseGridLayout->setMargin(0);

//    contentJapaneseWidget = new QWidget();
//    contentJapaneseWidget->setFixedHeight(0.24 * 0.8 * height);
//    japaneseWidgetLayout = new QHBoxLayout(contentJapaneseWidget);
//    japaneseWidgetLayout->addWidget(japaneseLabel);
//    japaneseWidgetLayout->addWidget(contentInfoJaWidget);
//    japaneseWidgetLayout->setSpacing(width *0.01);
//    japaneseWidgetLayout->setMargin(0);

//    koreanLabel = new QLabel("韓語");
//    koreanLabel->setFont(QFont("Segoe UI" , 40, QFont::Normal, false));
//    koreanLabel->setAlignment(Qt::AlignCenter);
//    koreanLabel->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    koreanLabel->setFixedWidth(0.3 * width);

//    koreanGridButtonone = new QPushButton("杜月1");
//    koreanGridButtonone->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    koreanGridButtonone->setFont(*caracterStyle);
//    koreanGridButtonone->setFixedSize(buttonWidth,buttonHeight);
//    koreanGridButtontwo = new QPushButton("杜月2");
//    koreanGridButtontwo->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    koreanGridButtontwo->setFont(*caracterStyle);
//    koreanGridButtontwo->setFixedSize(buttonWidth,buttonHeight);
//    koreanGridButtonthree = new QPushButton("杜月3");
//    koreanGridButtonthree->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    koreanGridButtonthree->setFont(*caracterStyle);
//    koreanGridButtonthree->setFixedSize(buttonWidth,buttonHeight);
//    koreanGridButtonfour = new QPushButton("更多");
//    koreanGridButtonfour->setStyleSheet("background-color:aliceBlue;border: 0px;");
//    koreanGridButtonfour->setFont(*caracterStyle);
//    koreanGridButtonfour->setFixedSize(buttonWidth,buttonHeight);


//    contentInfoKoWidget = new QWidget();
//    contentInfoKoWidget->setFixedWidth(0.7 * width);
//    contentInfoKoWidget->setStyleSheet("background-color:transparent;");

//    koreanGridLayout = new QGridLayout(contentInfoKoWidget);
//    koreanGridLayout->addWidget(koreanGridButtonone,0,0,1,1);
//    koreanGridLayout->addWidget(koreanGridButtontwo,0,1,1,1);
//    koreanGridLayout->addWidget(koreanGridButtonthree,1,0,1,1);
//    koreanGridLayout->addWidget(koreanGridButtonfour,1,1,1,1);
//    koreanGridLayout->setHorizontalSpacing(width *0.02);
//    koreanGridLayout->setVerticalSpacing(height*0.012);
//    koreanGridLayout->setMargin(0);

//    contentKoreanWidget = new QWidget();
//    contentKoreanWidget->setFixedHeight(0.24 * 0.8 * height);
//    koreanWidgetLayout = new QHBoxLayout(contentKoreanWidget);
//    koreanWidgetLayout->addWidget(koreanLabel);
//    koreanWidgetLayout->addWidget(contentInfoKoWidget);
//    koreanWidgetLayout->setSpacing(width *0.01);
//    koreanWidgetLayout->setMargin(0);

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
    //!--------------------
//    contentWidgetLayout = new QVBoxLayout(contentWidget);
//    contentWidgetLayout->addWidget(contentChineseWidget);
//    contentWidgetLayout->addWidget(contentEnglishWidget);
//    contentWidgetLayout->addWidget(contentFrenchWidget);
//    contentWidgetLayout->addWidget(contentDeutschWidget);
//    contentWidgetLayout->addWidget(contentJapaneseWidget);
//    contentWidgetLayout->addWidget(contentKoreanWidget);
//    contentWidgetLayout->setSpacing(5);
//    contentWidgetLayout->setMargin(0);

    contentWidgetScrollArea = new QScrollArea();
    contentWidgetScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    contentWidgetScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    contentWidgetScrollArea->setStyleSheet("QScrollBar:vertical {border: 0px; background: transparent; width: 20px;}"
                                           "QScrollBar::handle:vertical {background: #8080FF; border-radius:10px;min-height: 10px;}"
                                           "QScrollBar::add-line:vertical {height: 0px;subcontrol-position: bottom;}"
                                           "QScrollBar::sub-line:vertical {height: 0px; subcontrol-position: top;}"
                                           "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: transparent;}"
                                           );
    contentWidgetScrollArea->viewport()->setBackgroundRole(QPalette::Light);
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
//!
//! \brief LanguageWidget::adjustScrollBar
//! \param scrollBar
//!
void ClassificationWidget::adjustScrollBar(QScrollBar *scrollBar){
    scrollBar->setValue(int(0.1 * scrollBar->value() + + ((0.8 - 1) * scrollBar->pageStep()/2)));
}
