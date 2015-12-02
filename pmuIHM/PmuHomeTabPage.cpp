#include "PmuHomeTabPage.h"

PmuHomeTabPage::PmuHomeTabPage(int width, int height, QFont *caracterStyle) : QTabWidget()
{
    this->width = width;
    this->height = height;
    this->caracterStyle = caracterStyle;

    this->initVariable();
    this->constructIHM();
    this->setConnections();
    this->drawBackground();
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuHomeTabPage::initVariable
//!
void PmuHomeTabPage::initVariable(){
    this->pmumainPage = new PmuMainPage(width, height);
    this->neighborPage = new QWidget();
    this->selectionPage = new QWidget();
    this->myOwnPage = new MyOwnPage(width, height);

    this->setStyleSheet("QTabWidget::pane{border:none;border: none} "
                        "QTabBar::tab{ border:none;background:rgb(135,209,199);color:aliceblue; width:" + QString::number(width*0.25) + ";height:" + QString::number(height*0.06) + "}"
                        "QTabBar::tab:selected{border:none; background:white; color:green;}");
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuHomeTabPage::constructIHM
//!
void PmuHomeTabPage::constructIHM(){
    this->insertTab(0,this->pmumainPage,"首頁");
    this->setTabIcon(0,QIcon(":/images/homePage.png"));
    this->setIconSize(QSize(width*0.25,height*0.06));
    this->insertTab(1,this->neighborPage,"附近");
    this->insertTab(2,this->selectionPage,"精選");
    this->insertTab(3,this->myOwnPage,"我的");
    this->setTabPosition(South);
    this->setFont(QFont("Segoe UI",15,QFont::Normal,false));
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuHomeTabPage::setConnections
//!
void PmuHomeTabPage::setConnections(){

}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuHomeTabPage::drawBackground
//!
void PmuHomeTabPage::drawBackground(){
    pixmap = new QPixmap(":/images/background.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(width, height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(p);
    this->setMask(pixmap->mask());
}

