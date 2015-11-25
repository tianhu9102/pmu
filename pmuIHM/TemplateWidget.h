#ifndef TEMPLATEWIDGET_H
#define TEMPLATEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class TemplateWidget : public QWidget
{
    Q_OBJECT
public:
    TemplateWidget(int width, int height);
    void constructIHM();
    void setLabelText(QString text);
    void setTopThreeText(QString text1, QString text2, QString text3);
private:
    int width;
    int height;

    QGridLayout* thisWidgteLayout;
    QLabel* typeLabel;
    QPushButton* firstButton;
    QPushButton* secondButton;
    QPushButton* thirdButton;
    QPushButton* fourthButton;
signals:

public slots:
};

#endif // TEMPLATEWIDGET_H
