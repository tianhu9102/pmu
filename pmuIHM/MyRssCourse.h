#ifndef MYRSSCOURSE_H
#define MYRSSCOURSE_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>

class MyRssCourse: public QWidget
{
public:
    MyRssCourse(int width, int height);
    void initVariable();
    void constructIHM();
    void setConnections();
private:
    int width;
    int height;

    QVBoxLayout *myRssCoursePageLayout;
    QHBoxLayout *titleBarLayout;

    QWidget *titleBarWidget;
    QLabel *titleBarLabel;
    QPushButton *returnButton;
    QListWidget *myRssCourseWidget;
private slots:

};

#endif // MYRSSCOURSE_H
