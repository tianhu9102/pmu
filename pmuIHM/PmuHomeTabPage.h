#ifndef PMUHOMETABPAGE_H
#define PMUHOMETABPAGE_H

#include <QWidget>
#include <QFont>
#include <QTabWidget>
#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QBitmap>
#include "PmuMainPage.h"
#include "MyOwnPage.h"

class PmuHomeTabPage : public QTabWidget
{
    Q_OBJECT
public:
    PmuHomeTabPage(int width, int height, QFont *caracterStyle);
    void initVariable();
    void constructIHM();
    void setConnections();
    void drawBackground();
private:
    int width;
    int height;
    QPixmap* pixmap;
    QFont *caracterStyle;

    PmuMainPage *pmumainPage;
    QWidget *neighborPage;
    QWidget *selectionPage;
    MyOwnPage *myOwnPage;
signals:

public slots:
};

#endif // PMUHOMETABPAGE_H
