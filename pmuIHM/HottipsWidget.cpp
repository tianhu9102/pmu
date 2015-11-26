#include "HottipsWidget.h"

HottipsWidget::HottipsWidget(int width, int height){

    this->width = width;
    this->height = height;

    listWidget = new QListWidget();
    listWidget->setStyleSheet("QListWidget {show-decoration-selected: 2;background: transparent; border:1px solid gainsboro; color: skyBlue}"
                              "QListWidget::item:alternate { background: transparent;}"
                              "QListWidget::item:selected {border: 0px;}"
                              "QListWidget::item:selected:!active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 lightBlue, stop: 1 skyBlue);color:skyBlue}"
                              "QListWidget::item:selected:active {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 lightBlue, stop: 1 skyBlue);color:skyBlue}"
                              "QScrollBar:vertical {border: 0px; background: transparent; width: 20px;}"
                              "QScrollBar::handle:vertical {background: #8080FF; border-radius:10px;min-height: 10px;}"
                              "QScrollBar::add-line:vertical {height: 0px;subcontrol-position: bottom;}"
                              "QScrollBar::sub-line:vertical {height: 0px; subcontrol-position: top;}"
                              "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: transparent;}"
                              );
    listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    listWidget->setViewMode(QListWidget::ListMode);

    listWidget->setAcceptDrops(true);
    listWidget->setFont(QFont("Segoe UI", 25, QFont::AnyStyle, true));
    listWidget->setDragEnabled(false);
    listWidget->setIconSize(QSize(this->width*0.3,this->height*0.52*0.26));
    listWidget->setSpacing(height*0.001);
    sportItem = new QListWidgetItem(QIcon(QPixmap(":/images/sport.png").scaled(QSize(this->width*0.2,this->height*0.52*0.24))),"运动",listWidget);
    danceItem = new QListWidgetItem(QIcon(QPixmap(":/images/boduo.png").scaled(QSize(this->width*0.3,this->height*0.52*0.26))),"舞蹈",listWidget);
    musicItem = new QListWidgetItem(QIcon(QPixmap(":/images/boduo.png").scaled(QSize(this->width*0.3,this->height*0.52*0.26))),"音乐",listWidget);
    languageItem = new QListWidgetItem(QIcon(QPixmap(":/images/boduo.png").scaled(QSize(this->width*0.3,this->height*0.52*0.26))),"语言",listWidget);
    listWidget->insertItem(1,sportItem);
    listWidget->insertItem(2,danceItem);
    listWidget->insertItem(3,musicItem);
    listWidget->insertItem(4,languageItem);

    this->mainLayout = new QVBoxLayout(this);
    this->mainLayout->addWidget(listWidget);
    this->mainLayout->setSpacing(0);
    this->mainLayout->setMargin(0);

}




