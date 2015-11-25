#include "TemplateWidget.h"

TemplateWidget::TemplateWidget(int width, int height) : QWidget()
{
    this->width = width;
    this->height = height;
    this->constructIHM();
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief TemplateWidget::setLabelText
//! \param text
//!
void TemplateWidget::setLabelText(QString text){

    this->typeLabel->setText(text);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief TemplateWidget::setTopThreeText
//! \param text1
//! \param tetx2
//! \param text3
//!
void TemplateWidget::setTopThreeText(QString text1,QString text2,QString text3){
    this->firstButton->setText(text1);
    this->secondButton->setText(text2);
    this->thirdButton->setText(text3);
}

//!-----------------------------------------------------------------------------------------
//!
//! \brief TemplateWidget::constructIHM
//!
void TemplateWidget::constructIHM(){
    this->typeLabel = new QLabel();
    this->typeLabel->setAlignment(Qt::AlignCenter);
    this->typeLabel->setFont(QFont("Segoe UI" , 40, QFont::Normal, false));
    this->typeLabel->setStyleSheet("background-color:aliceBlue;border: 0px;");
    this->typeLabel->setFixedSize(width/3.0, height*0.2);

    this->firstButton = new QPushButton();
    this->firstButton->setFixedSize(width/3.0, height*0.1);

    this->secondButton = new QPushButton();
    this->secondButton->setFixedSize(width/3.0, height*0.1);
    this->thirdButton = new QPushButton();
    this->thirdButton->setFixedSize(width/3.0, height*0.1);
    this->fourthButton = new QPushButton();
    this->fourthButton->setText("更多");
    this->fourthButton->setFixedSize(width/3.0, height*0.1);

    this->setFixedSize(width, height*0.2);
    this->thisWidgteLayout = new QGridLayout(this);
    this->thisWidgteLayout->addWidget(typeLabel, 0, 0, 2, 1);
    this->thisWidgteLayout->addWidget(firstButton, 0, 1);
    this->thisWidgteLayout->addWidget(secondButton, 0, 2);
    this->thisWidgteLayout->addWidget(thirdButton, 1, 1);
    this->thisWidgteLayout->addWidget(fourthButton, 1, 2);
    this->thisWidgteLayout->setMargin(0);
    this->thisWidgteLayout->setSpacing(0);
}
