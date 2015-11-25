#include "MyOwnPage.h"

MyOwnPage::MyOwnPage(int width, int height)
    : QWidget()
{
    this->width = width;
    this->height = height;
    this->initial();
    this->constructIHM();
    //this->setConnections();
}

MyOwnPage::~MyOwnPage()
{

}

void MyOwnPage::initial(){

    caracterStyle = new QFont("Segoe UI" , 18, QFont::Normal, false);
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
    idAccountLabel->setFont(*caracterStyle);
    idAccountLabel->setAlignment(Qt::AlignCenter);

    idEmailLabel = new QLabel("电子邮件地址");
    idEmailLabel->setFont(*caracterStyle);
    idEmailLabel->setAlignment(Qt::AlignCenter);


    idWidget = new QWidget();
    idWidget->setFixedHeight(0.558*height);
    idWidget->setStyleSheet("background-color:#9999CC");
    idLayout = new QVBoxLayout(idWidget);
    idLayout->setAlignment(Qt::AlignCenter);
    idLayout->addWidget(idAvatarLabel);
    idLayout->addWidget(idAccountLabel);
    idLayout->addWidget(idEmailLabel);

    fButton = new QToolButton(this);
    fButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    fButton->setIcon(QIcon(":/images/lala.png"));
    fButton->setIconSize(QSize(0.25*width, 0.08*height));
    fButton->setText("已选");
    fButton->setStyleSheet("QToolButton{border:1px;color:blue;background-color:transparent;}");
    
    fButton->setFixedSize(0.5*width, 0.192*height);

    sButton = new QPushButton(tr("待选"));
    sButton->setFont(*caracterStyle);
    sButton->setStyleSheet("QPushButton{border:none;color:blue;background-color:transparent;}");
    sButton->setFixedHeight(0.192*height);

    tButton = new QPushButton(tr("浏览"));
    tButton->setFont(*caracterStyle);
    tButton->setStyleSheet("QPushButton{ border:none;color:blue;background-color:transparent;}");
    tButton->setFixedHeight(0.192*height);

    foButton = new QPushButton(tr("历史"));
    foButton->setFont(*caracterStyle);
    foButton->setStyleSheet("QPushButton{ border:none;color:blue;background-color:transparent;}");
    foButton->setFixedHeight(0.192*height);

    fWidget = new QWidget();
    fWidget->setStyleSheet("background-color:transparent");
    fLayout = new QVBoxLayout(fWidget);
    fLayout->setSpacing(0);
    fLayout->setMargin(0);
    fLayout->addWidget(fButton);

    sWidget = new QWidget();
    sWidget->setStyleSheet("background-color:transparent");
    sLayout = new QVBoxLayout(sWidget);
    sLayout->setSpacing(0);
    sLayout->setMargin(0);
    sLayout->addWidget(sButton);

    tWidget = new QWidget();
    tWidget->setStyleSheet("background-color:transparent");
    tLayout = new QVBoxLayout(tWidget);
    tLayout->setMargin(0);
    tLayout->setSpacing(0);
    tLayout->addWidget(tButton);

    foWidget = new QWidget();
    foWidget->setStyleSheet("background-color:transparent");
    foLayout = new QVBoxLayout(foWidget);
    foLayout->setMargin(0);
    foLayout->setSpacing(0);
    foLayout->addWidget(foButton);

    courseInfoWidget = new QWidget();
    courseInfoWidget->setStyleSheet("background-color:transparent");
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
    connect(fButton,SIGNAL(pressed()),this,SLOT(lks()));
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief MyOwnPage::lks
//!
void MyOwnPage::lks(){
    this->close();
}
