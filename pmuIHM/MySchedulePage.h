#ifndef MYSCHEDULEPAGE_H
#define MYSCHEDULEPAGE_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>

class MySchedulePage : public QWidget
{
    Q_OBJECT
public:
    MySchedulePage(int width, int height);
    void initVariable();
    void constructIHM();
    void setConnections();
    //void drawBackground();
private:
    int width;
    int height;

    QVBoxLayout *mySchedulePageLayout;
    QHBoxLayout *titleBarLayout;
    QHBoxLayout *searchBarLayout;

    QWidget *titleBarWidget;
    QWidget *searchBarWidget;
    QWidget *scheduleWidget;

    QPushButton *returnButton;
    QLabel *titleLabel;

    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QComboBox *sortComboBox;
signals:

public slots:
};

#endif // MYSCHEDULEPAGE_H
