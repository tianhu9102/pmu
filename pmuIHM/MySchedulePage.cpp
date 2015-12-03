#include "MySchedulePage.h"

MySchedulePage::MySchedulePage(int width, int height) : QWidget()
{
    this->width = width;
    this->height = height;
    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->setStyleSheet("background-color:rgb(135,209,199)");
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MySchedulePage::initVariable
//!
void MySchedulePage::initVariable(){

}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MySchedulePage::constructIHM
//!
void MySchedulePage::constructIHM(){
    this->returnButton = new QPushButton();
    this->returnButton->setIcon(QIcon(":/images/return.png"));
    this->returnButton->setIconSize(QSize(0.15*width,0.05*height));
    this->returnButton->setFixedWidth(0.15*width);
    this->returnButton->setStyleSheet("QPushButton{border: 0px;background-color:transparent; color: AliceBlue}"
                                      "QPushButton:focus{padding: -2;}");

    this->titleLabel = new QLabel("我的課程表");
    this->titleLabel->setFont(QFont("Segoe UI",18,QFont::Normal,false));
    this->titleLabel->setAlignment(Qt::AlignVCenter);
    this->titleLabel->setStyleSheet("border: 0px ;border-radius: 0px;padding: 22px;background-color: transparent; color: AliceBlue");

    this->titleBarWidget = new QWidget();
    this->titleBarWidget->setFixedSize(width, height*0.06);
    this->titleBarLayout = new QHBoxLayout(titleBarWidget);
    this->titleBarLayout->addWidget(returnButton);
    this->titleBarLayout->addWidget(titleLabel);
    this->titleBarLayout->setMargin(0);
    this->titleBarLayout->setSpacing(0);

    this->searchLineEdit = new QLineEdit();
    this->searchLineEdit->setFixedHeight(height*0.053);
    this->searchLineEdit->setPlaceholderText("srgjz");
    this->searchLineEdit->setStyleSheet("QLineEdit{color:AliceBlue; border: 0px solid Gray; border-radius: 0px; color:rgb(0, 0, 0); background-color: azure; padding:0} "
                                        "QLineEdit:focus{border-style:outset; border-width:0px; border-radius: 0px; border-color: rgb(41, 237, 215); color:rgb(0, 0, 0); background-color: azure; } ");

    this->searchButton = new QPushButton();
    this->searchButton->setFixedSize(width*0.092,height*0.053);
    this->searchButton->setIconSize(QSize(width*0.092,height*0.053));
    this->searchButton->setStyleSheet("QPushButton{border-image: url(:/images/searchButton.png); background-color:AliceBlue;border: 0px;}"
                                      "QPushButton:pressed{border-image: url(:/images/searchButton1.png);background-color:AliceBlue;border: 0px;}"
                                      "QPushButton:focus{padding: -2;}");

    this->sortComboBox = new QComboBox();
    this->sortComboBox->setFixedSize(width*0.18, height*0.053);
    this->sortComboBox->insertItem(0,"1");
    this->sortComboBox->insertItem(1,"2");
    this->sortComboBox->insertItem(2,"3");
    this->sortComboBox->setStyleSheet( "QComboBox{color:gray;background-color:aliceblue;border:0px;border-radius:0px;padding:0px;}"
                                       //"QComboBox QListView{ border-style: none; background-color: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));}"
                                       "QComboBox::drop-down{width: 88px;border: 0px;border-color:trantransparent;border-left-style:solid;border-top-style: none;border-bottom-style: none;border-right-style: none;}"
                                       "QComboBox::down-arrow{image: url(:/images/down.png);}"
                                       "QComboBox::down-arrow{width:72; height:72}"
                                       "QComboBox::down-arrow:on { top: 1px;left: 1px;}");

    this->searchBarWidget = new QWidget();
    this->searchBarWidget->setFixedSize(width, height*0.07);
    this->searchBarLayout = new QHBoxLayout(searchBarWidget);
    this->searchBarLayout->addStretch();
    this->searchBarLayout->addWidget(searchLineEdit);
    this->searchBarLayout->addWidget(searchButton);
    this->searchBarLayout->addStretch();
    this->searchBarLayout->addWidget(sortComboBox);
    this->searchBarLayout->addStretch();
    this->searchBarLayout->setMargin(0);
    this->searchBarLayout->setSpacing(0);

    this->scheduleWidget = new QWidget();

    this->mySchedulePageLayout = new QVBoxLayout(this);
    this->mySchedulePageLayout->addWidget(titleBarWidget);
    this->mySchedulePageLayout->addWidget(searchBarWidget);
    this->mySchedulePageLayout->addWidget(scheduleWidget);
    this->mySchedulePageLayout->setMargin(0);
    this->mySchedulePageLayout->setSpacing(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MySchedulePage::setConnections
//!
void MySchedulePage::setConnections(){

}
