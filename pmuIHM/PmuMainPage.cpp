#include "PmuMainPage.h"

PmuMainPage::PmuMainPage(int width, int height)
    : QWidget(){
    this->width = width;
    this->height = height;

    this->initial();
    this->constructMainWidget();
    this->setConnections();
    this->drawBackground();
    //this->setStyleSheet("background-color:rgb(135,209,199)");
}

PmuMainPage::~PmuMainPage()
{

}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuMainPage::initial
//!
void PmuMainPage::initial(){
    this->classificationWidget = new ClassificationWidget();

}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuMainPage::constructMainWidget
//!
void PmuMainPage::constructMainWidget(){

    //! create seraching bar area
//    this->returnBackButton = new QPushButton();
//    this->returnBackButton->setFixedSize(width*0.11, height*0.05);
//    this->returnBackButton->setIcon(QIcon(":/images/return.png"));
//    this->returnBackButton->setIconSize(QSize(width*0.12, height*0.05));
//    this->returnBackButton->setStyleSheet("QPushButton{border: 0px;background-color:transparent; color: AliceBlue;}"
//                                          "QPushButton:focus{padding: -2;}");

    cityLabel = new QLabel("城市 :");
    cityLabel->setFixedHeight(height*0.05);
    //cityLabel->setAlignment(Qt::AlignCenter);
    cityLabel->setFont(QFont("Segoe UI",17,QFont::Normal,false));
    cityLabel->setStyleSheet("QLabel{background-color:transparent;color:aliceblue; border:0px solid Gray;padding-left: 20px;}");
    citySwitchComoBox = new QComboBox();
    citySwitchComoBox->setFixedSize(width*0.16,height*0.05);
    citySwitchComoBox->setFont(QFont("Segoe UI",16,QFont::Normal,false));
    citySwitchComoBox->addItem("珠海");
    citySwitchComoBox->addItem("澳門");
    citySwitchComoBox->setStyleSheet("QComboBox{color:gray;background-color:transparent;border:0px solid black;border-radius:5px;padding:1px;}"
                                      //"QComboBox QListView{ border-style: none; background-color: qlineargradient(x1:0, y1:0, x2:1,y2:0, stop: 1 rgba(228, 41, 81, 100), stop: 0 rgba(234, 107, 101, 100));}"
                                      "QComboBox::drop-down{width: 50px;border: 0px;border-color:transparent;border-left-style:solid;border-top-style: none;border-bottom-style: none;border-right-style: none;}"
                                      "QComboBox::down-arrow{image: url(:/images/down.png);width: 60px; height: 60px;}");

    searchingLineEdit = new QLineEdit();
    searchingLineEdit->setFixedSize(width*0.38,height*0.05);
    searchingLineEdit->setPlaceholderText("輸入學科");
    searchingLineEdit->setStyleSheet("QLineEdit{color:AliceBlue; border: 0px solid Gray; border-radius: 0px; color:rgb(0, 0, 0); background-color: azure;} "
                                     "QLineEdit:focus{border-style:outset; border-width:0px; border-radius: 0px; border-color: rgb(41, 237, 215); color:rgb(0, 0, 0); background-color: azure; } ");
    searchingButton = new QPushButton();
    searchingButton->setFixedSize(width*0.092,height*0.05);
    searchingButton->setIconSize(QSize(width*0.092,height*0.05));
    searchingButton->setStyleSheet("QPushButton{border-image: url(:/images/searchButton.png); background-color:AliceBlue;border: 0px;}"
                                   "QPushButton:pressed{border-image: url(:/images/searchButton1.png);background-color:AliceBlue;border: 0px;}"
                                   "QPushButton:focus{padding: -2;}");
    somethingElseButton1 = new QPushButton("購物車");
    somethingElseButton1->setFixedHeight(height*0.05);
    somethingElseButton1->setStyleSheet("QPushButton{background-color:transparent;color:aliceblue;border:0px solid Gray; padding-left: 20px; padding-right: 20px; }"
                                        "QPushButton:focus{padding: -2;}");
    titleBar = new QFrame();
    titleBar->setFixedHeight(height*0.08);
    titleBar->setStyleSheet("background-color:transparent");
    searchingBarLayout = new QHBoxLayout(titleBar);
    //searchingBarLayout->addWidget(returnBackButton);
    searchingBarLayout->addWidget(cityLabel);
    searchingBarLayout->addWidget(citySwitchComoBox);
    searchingBarLayout->addStretch();
    searchingBarLayout->addWidget(searchingLineEdit);
    searchingBarLayout->addWidget(searchingButton);
    searchingBarLayout->addWidget(somethingElseButton1);

    searchingBarLayout->setSpacing(0);
    searchingBarLayout->setMargin(0);

    //!create list widget


//    optionsWidget->setFixedHeight(height*0.3);

    optionListWidget = new QListView();
    optionListWidget->setFixedHeight(height*0.37);
    //optionListWidget->setMovement(QListView::Static);
    //optionListWidget->setResizeMode(QListView::Fixed);
    optionListWidget->setViewMode(QListView::IconMode);
    optionListWidget->setSpacing(width*0.101);
    optionListWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    optionListWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    model = new QStandardItemModel();

    optionListWidget->setStyleSheet("background-color:transparent");
    optionListWidget->setViewMode(QListView::IconMode);
    artItem = new QStandardItem(QIcon(":/images/Dance.png"), tr("艺术"));
    sportItem = new QStandardItem(QIcon(":/images/sport.png"), tr("体育"));
    lifeStyleItem = new QStandardItem(QIcon(":/images/life.png"), tr("生活"));
    bussinessItem = new QStandardItem(QIcon(":/images/bussiness.png"), tr("商务"));
    educationItem = new QStandardItem(QIcon(":/images/education.png"), tr("学科"));
    entertainmentItem = new QStandardItem(QIcon(":/images/games.png"), tr("游戏"));

    beBetterManItem = new QStandardItem(QIcon(":/images/bestman.png"), tr("做人"));
    //collegeItem =new QStandardItem(QIcon(":/images/lala.png"), tr("大学"));
    moreItem = new QStandardItem(QIcon(":/images/more.png"), tr("更多"));
    //accountingItem = new QStandardItem(QIcon(":/images/lala.png"), tr("会计"));

    model->appendRow(artItem);
    model->appendRow(sportItem);
    model->appendRow(lifeStyleItem);
    model->appendRow(bussinessItem);
    model->appendRow(educationItem);
    model->appendRow(entertainmentItem);
    model->appendRow(beBetterManItem);
    model->appendRow(moreItem);

    optionListWidget->setModel(model);
    optionListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    optionListWidget->setFlow(QListWidget::LeftToRight);
    optionListWidget->setLayoutMode(QListView::SinglePass);
    optionListWidget->setIconSize(QSize(width*0.5,height*0.072));
    optionListWidget->setDragEnabled(false);
    optionListWidget->setMovement(QListView::Static);
    optionListWidget->setResizeMode(QListView::Adjust);

    model = new QStandardItemModel();

    //!create tab widget-------------------------------------------------------------------------------
    choosenTableWidget = new QTabWidget();

    choosenTableWidget->setStyleSheet("QTabWidget::pane{border:none;border: none} "
                                      "QTabBar::tab{ background:rgb(135,209,199);color:black; width:"+QString::number(width*0.25)+";height:"+QString::number(height *0.05)+"}"
                                      "QTabBar::tab:selected{ border: none;background:white; color:blue;}");

    hottipsWidget = new HottipsWidget(this->width,this->height);
    hottipsWidget->setFocusPolicy(Qt::NoFocus);
    privilegeWidget = new PrivilegeWidget();
    privilegeWidget->setFocusPolicy(Qt::NoFocus);
    institutionWidget = new InstitutionWidget();
    institutionWidget->setFocusPolicy(Qt::NoFocus);
    guessULikeWidget = new GuessULikeWidget();
    institutionWidget->setFocusPolicy(Qt::NoFocus);
    choosenTableWidget->insertTab(0,hottipsWidget,"熱 門");
    choosenTableWidget->insertTab(1,privilegeWidget,"優 惠");
    choosenTableWidget->insertTab(2,institutionWidget,"機 構");
    choosenTableWidget->insertTab(3,guessULikeWidget,"猜妳喜歡");
    choosenTableWidget->setFont(QFont("Segoe UI",15,QFont::Normal,false));
    //!create main window
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleBar);
    mainLayout->addWidget(optionListWidget);
    mainLayout->addWidget(choosenTableWidget);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuMainPage::setConnections
//!
void PmuMainPage::setConnections(){
    this->connect(this->optionListWidget,SIGNAL(clicked(QModelIndex)),this,SLOT(itemClicked(QModelIndex)));
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuMainPage::drawBackground
//!
void PmuMainPage::drawBackground(){
    pixmap = new QPixmap(":/images/background.png");
    QPalette p =  this->palette();

    p.setBrush(QPalette::Background, QBrush(pixmap->scaled(QSize(width, height), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(p);
    this->setMask(pixmap->mask());
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief PmuMainPage::itemClicked
//! \param index
//!
void PmuMainPage::itemClicked(QModelIndex index){
    QAbstractItemModel* model = this->optionListWidget->model() ;
    QString text = model->index( index.row(), index.column() ).data( Qt::DisplayRole ).toString() ;
    this->classificationWidget->display(text);
}
