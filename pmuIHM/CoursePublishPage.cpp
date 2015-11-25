#include "CoursePublishPage.h"

CoursePublishPage::CoursePublishPage(int width, int height, QFont *caracterStyle) : QWidget()
{
    this->appWidth = width;
    this->appHeight = height;
    this->caracterStyle = caracterStyle;

    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->drawBackground();
    //this->setStyleSheet("background-color:rgb(135,209,199)");
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief CoursePublishPage::initVariable
//!
void CoursePublishPage::initVariable(){

}

//!-----------------------------------------------------------------------------------------
//!
//! \brief CoursePublishPage::constructIHM
//!
void CoursePublishPage::constructIHM(){
    this->returnButton = new QPushButton();
    this->returnButton->setFixedWidth(120);
    this->returnButton->setIcon(QIcon(":/images/back.png"));
    this->returnButton->setIconSize(QSize(120,100));
    this->returnButton->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");

    this->titleLabel = new QLabel("發布課程");
    this->titleLabel->setFixedHeight(100);
    this->titleLabel->setFont(QFont("Segoe UI", 18, QFont::AnyStyle, false));
    this->titleLabel->setStyleSheet("background-color:transparent; border: 0px; color: aliceblue");

    this->titleBar = new QWidget();
    this->titleBar->setFixedHeight(100);
    this->titleBar->setStyleSheet("background-color:transparent;  border: 2px solid white; color: aliceblue");
    this->titleBarLayout = new QHBoxLayout(titleBar);
    this->titleBarLayout->addWidget(returnButton);
    this->titleBarLayout->addWidget(titleLabel);
    this->titleBarLayout->setMargin(0);
    this->titleBarLayout->setSpacing(0);

    this->promptInfoLabel = new QLabel("妳 想 發 布 什 麽 類 型 的 課 程 ?");
    this->promptInfoLabel->setStyleSheet("background-color:transparent; color: black");
    this->promptInfoLabel->setFont(QFont("Segoe UI", 30, QFont::AnyStyle, false));
    this->promptInfoLabel->adjustSize();
    this->promptInfoLabel->setGeometry(QRect(328, 240, 329, 27*4));
    this->promptInfoLabel->setWordWrap(true);
    this->promptInfoLabel->setAlignment(Qt::AlignCenter);

    this->languageButton = new QPushButton("語言");
    this->languageButton->setFixedHeight(150);
    this->languageButton->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");
    this->sportButton = new QPushButton("運動");
    this->sportButton->setFixedHeight(150);
    this->sportButton->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");
    this->artButton = new QPushButton("藝術");
    this->artButton->setFixedHeight(150);
    this->artButton->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");
    this->moreOptionsButton = new QPushButton("更多");
    this->moreOptionsButton->setFixedHeight(150);
    this->moreOptionsButton->setStyleSheet("background-color:transparent; color:AliceBlue; border: 0px solid Gray;border-radius: 0px;padding: 08px;");

    this->coursePublishPageLayout = new QVBoxLayout(this);
    this->coursePublishPageLayout->addWidget(titleBar);
    this->coursePublishPageLayout->addWidget(promptInfoLabel);
    this->coursePublishPageLayout->addWidget(languageButton);
    this->coursePublishPageLayout->addWidget(sportButton);
    this->coursePublishPageLayout->addWidget(artButton);
    this->coursePublishPageLayout->addWidget(moreOptionsButton);
    this->coursePublishPageLayout->setMargin(0);
    this->coursePublishPageLayout->setSpacing(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief CoursePublishPage::setConnections
//!
void CoursePublishPage::setConnections(){
    this->connect(returnButton, SIGNAL(clicked()), this, SLOT(close()));
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief CoursePublishPage::drawBackground
//!
void CoursePublishPage::drawBackground(){
    this->pixmap = new QPixmap(":/images/background.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(appWidth, appHeight), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(p);
    this->setMask(pixmap->mask());
}
