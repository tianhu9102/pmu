#ifndef HOTTIPSWIDGET_H
#define HOTTIPSWIDGET_H

#include <QtWidgets>

class HottipsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HottipsWidget(int width,int height);

private:
    QListWidget* listWidget;
    QListWidgetItem* sportItem;
    QListWidgetItem* danceItem;
    QListWidgetItem* musicItem;
    QListWidgetItem* languageItem;

    QVBoxLayout* mainLayout;

    int width;
    int height;

signals:

public slots:
};

#endif // HOTTIPSWIDGET_H
