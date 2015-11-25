#ifndef PMUMAINPAGE_H
#define PMUMAINPAGE_H

#include <QWidget>
#include <QWidget>
#include <QPixmap>
#include <QScreen>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QTabWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QRect>
#include <QDesktopWidget>
#include <QListView>

#include "ClassificationWidget.h"
#include "HottipsWidget.h"
#include "PrivilegeWidget.h"
#include "InstitutionWidget.h"
#include "GuessULikeWidget.h"
#include <QStandardItemModel>
#include <QStandardItem>

class PmuMainPage : public QWidget
{
    Q_OBJECT
public:
    explicit PmuMainPage(int width, int height);
    ~PmuMainPage();

    void initial();
    void constructMainWidget();
    void setConnections();
    void drawBackground();

private:
    ClassificationWidget *classificationWidget;

    QPixmap* pixmap;
    QVBoxLayout* mainLayout;
    QHBoxLayout* listWidgetLayout;

    QFrame *titleBar;
    QHBoxLayout *searchingBarLayout;
    QLineEdit *searchingLineEdit;

    QPushButton *searchingButton;
    QPushButton* somethingElseButton1;

    QListView* optionListWidget;
    QTabWidget* choosenTableWidget;
    QComboBox* citySwitchComoBox;
    QLabel* cityLabel;

    QStandardItem* artItem;
    QStandardItem* sportItem;
    QStandardItem* lifeStyleItem;
    QStandardItem* bussinessItem;
    QStandardItem* accountingItem;
    QStandardItem* moreItem;
    QStandardItem* collegeItem;
    QStandardItem* educationItem;
    QStandardItem* beBetterManItem;
    QStandardItem* entertainmentItem;

    HottipsWidget* hottipsWidget;
    PrivilegeWidget* privilegeWidget;
    InstitutionWidget* institutionWidget;
    GuessULikeWidget* guessULikeWidget;

    QWidget* optionsWidget;

    QStandardItemModel* model;

    int width;
    int height;


signals:

public slots:
    void itemClicked(QModelIndex index);
};

#endif // PMUMAINPAGE_H
