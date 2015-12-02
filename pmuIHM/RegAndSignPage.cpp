#include "RegAndSignPage.h"

RegAndSignPage::RegAndSignPage(int width, int height, bool flag, ConnectToServer* connectToServer)
    : QWidget(){



    this->width = width;
    this->height = height;
    this->flag = flag;
    this->connectToServer = connectToServer;


    this->initVariable();
    this->constructIHM();
    this->checkStates();
    this->setConnections();
    this->drawBackground();
    //this->setStyleSheet("background-color:rgb(135,209,199)");
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief RegAndSignPage::setState
//!
void RegAndSignPage::setState(bool flag){
    this->flag = flag;
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief RegAndSignPage::initVariable
//!
void RegAndSignPage::initVariable(){
    this->caracterStyle = new QFont("Segoe UI", 20, QFont::AnyStyle, false);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief RegAndSignPage::constructIHM
//!
void RegAndSignPage::constructIHM(){

    returnButton = new QPushButton();
    returnButton->setIcon(QIcon(":/images/return.png"));
    returnButton->setIconSize(QSize(0.15*width,0.05*height));
    returnButton->setFixedWidth(0.15*width);
    returnButton->setStyleSheet("QPushButton{border: 0px;background-color:transparent; color: AliceBlue}"
                                "QPushButton:focus{padding: -2;}");

    mainWidgetName = new QLabel();
    mainWidgetName = new QLabel("用郵箱登陸");
    mainWidgetName->setFont(*this->caracterStyle);
    mainWidgetName->setStyleSheet("border: 0px ;border-radius: 0px;padding: 22px;background-color: transparent; color: AliceBlue");

    moreInformationButton = new QPushButton("┇");
    moreInformationButton->setFixedWidth(0.15*width);
    moreInformationButton->setStyleSheet("QPushButton{border: 0px;background-color:transparent; color: AliceBlue}"
                                         "QPushButton:focus{padding: -2;}");

    titleBar = new QWidget();
    titleBar->setFixedHeight(0.1*height);
    titleBar->setStyleSheet("border: 0px;background-color:transparent");

    titleBarLayout = new QHBoxLayout(titleBar);
    titleBarLayout->addWidget(returnButton);
    titleBarLayout->addWidget(mainWidgetName);
    titleBarLayout->addWidget(moreInformationButton);
    //titleBarLayout->setMargin(0);

    forgetButton = new QPushButton("忘記密碼？");
    forgetButton->setFixedWidth(0.25*width);
    forgetButton->setStyleSheet("QPushButton{border: 0px;background-color:transparent; color: AliceBlue}"
                                "QPushButton:focus{padding: -2;}");

    switchStatusWindowRest = new QWidget();

    registrationButton =new QPushButton("註冊");
    registrationButton->setFixedWidth(0.1*width);
    registrationButton->setStyleSheet("QPushButton{border: 0px;background-color:transparent; color: AliceBlue}"
                                      "QPushButton:focus{padding: -2;}");

    switchStatusWindow = new QWidget();

    switchStatusWindowLayout = new QHBoxLayout(switchStatusWindow);
    switchStatusWindowLayout->addWidget(forgetButton);
    switchStatusWindowLayout->addWidget(switchStatusWindowRest);
    switchStatusWindowLayout->addWidget(registrationButton);

    emailAddressLineEdit = new QLineEdit("cheng.wang@siat.ac.cn");
    emailAddressLineEdit->setFixedHeight(0.071*height);

    //emailAddressLineEdit->setPlaceholderText("電子郵件地址");
    emailAddressLineEdit->setStyleSheet("border: 1px solid gray; background-color:aliceBlue; color:gray");

    passwordLineEdit = new QLineEdit("12345678");
    passwordLineEdit->setFixedHeight(0.071*height);
    //passwordLineEdit->setPlaceholderText("密碼");
    passwordLineEdit->setStyleSheet("border: 1px solid gray; background-color:aliceBlue; color:gray");

    confirmPasswordLineEdit = new QLineEdit("12345678");
    confirmPasswordLineEdit->setFixedHeight(0.071*height);
    //confirmPasswordLineEdit->setPlaceholderText("確認密碼");
    confirmPasswordLineEdit->setStyleSheet("border: 1px solid gray; background-color:aliceBlue; color:gray");

    phoneNumberLineEdit = new QLineEdit("18667654332");
    phoneNumberLineEdit->setFixedHeight(0.071*height);
    //phoneNumberLineEdit->setPlaceholderText("電話號碼");
    phoneNumberLineEdit->setStyleSheet("border: 1px solid gray; background-color:aliceBlue; color:gray");

    addressLineEdit = new QLineEdit("3 rue moret");
    addressLineEdit->setFixedHeight(0.071*height);
    //addressLineEdit->setPlaceholderText("地址");
    addressLineEdit->setStyleSheet("border: 1px solid gray; background-color:aliceBlue; color:gray");
    loginWindow = new QWidget();
    //loginWindow->setFixedHeight(0.213*height);
    loginWindow->setStyleSheet("background-color:transparent");

    loginWindowLayout = new QVBoxLayout(loginWindow);
    loginWindowLayout->addWidget(switchStatusWindow);
    loginWindowLayout->addWidget(emailAddressLineEdit);
    loginWindowLayout->addWidget(passwordLineEdit);
    loginWindowLayout->addWidget(confirmPasswordLineEdit);
    loginWindowLayout->addWidget(phoneNumberLineEdit);
    loginWindowLayout->addWidget(addressLineEdit);
    loginWindowLayout->setAlignment(Qt::AlignTop);
    loginWindowLayout->setSpacing(5);
    loginWindowLayout->setMargin(0);

//    signUpInformationWidget = new QWidget();
//    signUpInformationWidget->setFixedHeight();

    loginWindowRest = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);

    loginButton = new QPushButton("登  陸");
    loginButton->setFont(*this->caracterStyle);
    loginButton->setStyleSheet("QPushButton{border: 1px; background-color:rgb(63,188,255);color: AliceBlue}"
                               "QPushButton:focus{padding:-2}");
    loginButton->setFixedHeight(0.071*height);


    statusBar = new QWidget();
    statusBar->setStyleSheet("border: 0px;background-color:transparent");

    statusBarLayout = new QVBoxLayout(statusBar);
    statusBarLayout->addWidget(loginWindow);

    statusBarLayout->addWidget(loginButton);
    statusBarLayout->addItem(loginWindowRest);
    statusBarLayout->setSpacing(20);

    mainWidgetLayout = new QVBoxLayout(this);
    mainWidgetLayout->addWidget(titleBar);
    mainWidgetLayout->addWidget(statusBar);
    mainWidgetLayout->setSpacing(0);
    mainWidgetLayout->setMargin(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief RegAndSignPage::setConnections
//!
void RegAndSignPage::setConnections(){
    this->connect(registrationButton, SIGNAL(clicked()), this, SLOT(showSignUpInformation()));
    this->connect(returnButton, SIGNAL(clicked()), this, SLOT(close()));
    this->connect(loginButton, SIGNAL(clicked()), this, SLOT(sign()));
}

void RegAndSignPage::sign(){

    if(!flag){
        qDebug()<<"-------";
        QNetworkAccessManager *network_manager = new QNetworkAccessManager();
        QNetworkRequest network_request;
        QByteArray post_data;

        post_data.append("registerForm.email=" + emailAddressLineEdit->text()+ "&");
        post_data.append("registerForm.password="+passwordLineEdit->text()+"&");
        post_data.append("registerForm.conformPassword="+confirmPasswordLineEdit->text()+"&");
        post_data.append("registerForm.telephone="+phoneNumberLineEdit->text()+"&");
        post_data.append("registerForm.address="+addressLineEdit->text());


        network_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        network_request.setHeader(QNetworkRequest::ContentLengthHeader, post_data.length());
        network_request.setUrl(QUrl("http://172.20.35.211:8090/daishangwo/register.action"));

        connect(network_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(reponse(QNetworkReply*)));

        network_manager->post(network_request, post_data);
    }
    else{
        qDebug()<<"++++++++-";
        emailAddressLineEdit->text();
        passwordLineEdit->text();
    }
}

void RegAndSignPage::reponse(QNetworkReply*reply){
    qDebug()<<"repondu";//<<reply->readAll();
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief RegAndSignPage::drawBackground
//!
void RegAndSignPage::drawBackground(){


    pixmap = new QPixmap(":/images/background.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(width, height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(p);
    this->setMask(pixmap->mask());
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief RegAndSignPage::checkStates
//!
void RegAndSignPage::checkStates(){
    if(this->flag == true){
        confirmPasswordLineEdit->hide();
        phoneNumberLineEdit->hide();
        addressLineEdit->hide();
    }
    else{
        confirmPasswordLineEdit->show();
        phoneNumberLineEdit->show();
        addressLineEdit->show();
        registrationButton->setText("登錄");
        mainWidgetName->setText("用郵箱註冊");
        loginButton->setText("註冊");
    }
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief RegAndSignPage::showSignUpInformation
//!
void RegAndSignPage::showSignUpInformation(){
    if(this->flag){
        confirmPasswordLineEdit->show();
        phoneNumberLineEdit->show();
        addressLineEdit->show();
        registrationButton->setText("登錄");
        forgetButton->hide();
        mainWidgetName->setText("用郵箱註冊");
        loginButton->setText("註冊");
        this->flag = false;
    }
    else{
         confirmPasswordLineEdit->hide();
         phoneNumberLineEdit->hide();
         addressLineEdit->hide();
         registrationButton->setText("註冊");
         forgetButton->show();
         mainWidgetName->setText("用郵箱登錄");
         loginButton->setText("登錄");
         this->flag = true;
    }
}

RegAndSignPage::~RegAndSignPage()
{

}



