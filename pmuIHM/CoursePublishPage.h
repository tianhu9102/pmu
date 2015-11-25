#ifndef COURSEPUBLISHPAGE_H
#define COURSEPUBLISHPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include <QFont>

class CoursePublishPage : public QWidget
{
    Q_OBJECT
public:
    CoursePublishPage(int width, int height, QFont *caracterStyle);
    void initVariable();
    void constructIHM();
    void setConnections();
    void drawBackground();
private:
    int appWidth;
    int appHeight;
    QFont *caracterStyle;

    QPixmap* pixmap;

    QVBoxLayout* coursePublishPageLayout;
    QHBoxLayout* titleBarLayout;

    QWidget *titleBar;

    QLabel *titleLabel;
    QLabel *promptInfoLabel;

    QPushButton* returnButton;
    QPushButton* languageButton;
    QPushButton* sportButton;
    QPushButton* artButton;
    QPushButton* moreOptionsButton;
signals:

public slots:
};

#endif // COURSEPUBLISHPAGE_H
