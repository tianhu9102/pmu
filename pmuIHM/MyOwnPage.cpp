#include "MyOwnPage.h"

MyOwnPage::MyOwnPage(int width, int height)
    : QWidget()
{
    this->width = width;
    this->height = height;
    this->initial();
    this->constructIHM();
    this->setConnections();
}

MyOwnPage::~MyOwnPage()
{

}

void MyOwnPage::initial(){
    characterStyle = new QFont("Segoe UI" , 18, QFont::Normal, false);
    toolButtonStyle = "QToolButton{padding-top:" + QString::number(height*0.02) + ";padding-bottom:" + QString::number(height*0.02) + ";border:none;color:rgb(135,209,199);background-color:transparent;}";
    this->myRssCourse = new MyRssCourse(width, height);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MyOwnPage::constructIHM
//!
void MyOwnPage::constructIHM(){

    //idLabel = new QLabel("My Info");
    //idLabel->setFont(*caracterStyle);
    idAvatarLabel = new QLabel();
    idAvatarLabel->setPixmap(QPixmap(":/images/boduo.png"));

    idAccountLabel = new QLabel("姓名");
    idAccountLabel->setFont(*characterStyle);
    idAccountLabel->setAlignment(Qt::AlignCenter);

    idEmailLabel = new QLabel("电子邮件地址");
    idEmailLabel->setFont(*characterStyle);
    idEmailLabel->setAlignment(Qt::AlignCenter);


    idWidget = new QWidget();
    idWidget->setFixedHeight(0.556*height);
    idWidget->setStyleSheet("background-color:#9999CC");
    idLayout = new QVBoxLayout(idWidget);
    idLayout->setAlignment(Qt::AlignCenter);
    idLayout->addWidget(idAvatarLabel);
    idLayout->addWidget(idAccountLabel);
    idLayout->addWidget(idEmailLabel);

    fButton = new QToolButton(this);
    fButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    fButton->setIcon(QIcon(":/images/publishCourse.png"));
    fButton->setIconSize(QSize(0.25*width, 0.08*height));
    fButton->setText("我發布的課程");
    fButton->setStyleSheet(toolButtonStyle);
    fButton->setFixedSize(0.5*width, 0.192*height);

    sButton = new QToolButton(this);
    sButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    sButton->setIcon(QIcon(":/images/rss.png"));
    sButton->setIconSize(QSize(0.25*width, 0.08*height));
    sButton->setText("我訂閱的課程");
    sButton->setStyleSheet(toolButtonStyle);
    sButton->setFixedSize(0.5*width, 0.192*height);

    tButton = new QToolButton(this);
    tButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tButton->setIcon(QIcon(":/images/schedule.png"));
    tButton->setIconSize(QSize(0.25*width, 0.08*height));
    tButton->setText("我的課程表");
    tButton->setStyleSheet(toolButtonStyle);
    tButton->setFixedSize(0.5*width, 0.192*height);

    foButton = new QToolButton(this);
    foButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    foButton->setIcon(QIcon(":/images/history.png"));
    foButton->setIconSize(QSize(0.25*width, 0.08*height));
    foButton->setText("瀏覽歷史");
    foButton->setStyleSheet(toolButtonStyle);
    foButton->setFixedSize(0.5*width, 0.192*height);

    fWidget = new QWidget();
    fWidget->setStyleSheet("background-color:transparent;border-bottom:1px solid Gray;border-right:1px solid Gray");
    fLayout = new QVBoxLayout(fWidget);
    fLayout->setSpacing(0);
    fLayout->setMargin(0);
    fLayout->setAlignment(Qt::AlignCenter);
    fLayout->addWidget(fButton);

    sWidget = new QWidget();
    sWidget->setStyleSheet("background-color:transparent; border-bottom:1px solid Gray");
    sLayout = new QVBoxLayout(sWidget);
    sLayout->setSpacing(0);
    sLayout->setMargin(0);
    sLayout->addWidget(sButton);

    tWidget = new QWidget();
    tWidget->setStyleSheet("background-color:transparent; border-right:1px solid Gray");
    tLayout = new QVBoxLayout(tWidget);
    tLayout->setMargin(0);
    tLayout->setSpacing(0);
    tLayout->addWidget(tButton);

    foWidget = new QWidget();
    foWidget->setStyleSheet("background-color:transparent;");
    foLayout = new QVBoxLayout(foWidget);
    foLayout->setMargin(0);
    foLayout->setSpacing(0);
    foLayout->addWidget(foButton);

    courseInfoWidget = new QWidget();
    //courseInfoWidget->setStyleSheet("background-color:transparent");
    courseInfoWidget->setFixedHeight(0.384*height);
    coursesLayout =new QGridLayout(courseInfoWidget);
    coursesLayout->addWidget(fWidget,0,0);
    coursesLayout->addWidget(sWidget,0,1);
    coursesLayout->addWidget(tWidget,1,0);
    coursesLayout->addWidget(foWidget,1,1);
    coursesLayout->setSpacing(0);
    coursesLayout->setMargin(0);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(idWidget);
    mainLayout->addWidget(courseInfoWidget);
    mainLayout->setMargin(2);
    mainLayout->setSpacing(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MyOwnPage::setConnections
//!
void MyOwnPage::setConnections(){
    connect(this->sButton, SIGNAL(clicked()), this->myRssCourse, SLOT(show()));
}

//!-----------------------------------------------------------------------------------------
