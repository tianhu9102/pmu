#include "MyRssCourse.h"

MyRssCourse::MyRssCourse(int width, int height): QWidget()
{
    this->width = width;
    this->height = height;
    this->constructIHM();
    this->setConnections();
    this->setStyleSheet("background-color:rgb(135,209,199)");
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MyRssCourse::constructIHM
//!
void MyRssCourse::constructIHM(){

    this->returnButton = new QPushButton();
    this->returnButton->setIcon(QIcon(":/images/return.png"));
    this->returnButton->setIconSize(QSize(width*0.1, height*0.05));
    this->returnButton->setFixedSize(width*0.08, height*0.04);
    this->returnButton->setStyleSheet("QPushButton{border: 0px;background-color:transparent; color: AliceBlue; Alignment:AlignCenter}"
                                      "QPushButton:focus{padding: -2;}");

    this->titleBarLabel = new QLabel("我訂閱的課程");
    this->titleBarLabel->setFont(QFont("Segoe UI",18,QFont::Normal,false));
    this->titleBarLabel->setAlignment(Qt::AlignVCenter);
    this->titleBarLabel->setStyleSheet("border: 0px ;border-radius: 0px;padding: 22px;background-color: transparent; color: AliceBlue");

    this->titleBarWidget = new QWidget();
    this->titleBarWidget->setFixedSize(width, height*0.06);
    //this->titleBarWidget->setStyleSheet("border:0px; border-bottom:1px solid aliceblue");

    this->titleBarLayout = new QHBoxLayout(titleBarWidget);
    this->titleBarLayout->addWidget(returnButton);
    this->titleBarLayout->addWidget(titleBarLabel);
    this->titleBarLayout->setMargin(0);
    this->titleBarLayout->setSpacing(0);

    this->myRssCourseWidget = new QListWidget();

    this->myRssCoursePageLayout = new QVBoxLayout(this);
    this->myRssCoursePageLayout->addWidget(titleBarWidget);
    this->myRssCoursePageLayout->addWidget(myRssCourseWidget);
    this->myRssCoursePageLayout->setMargin(0);
    this->myRssCoursePageLayout->setSpacing(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MyRssCourse::setConnections
//!
void MyRssCourse::setConnections(){
    this->connect(this->returnButton, SIGNAL(clicked()), this, SLOT(close()));
}
