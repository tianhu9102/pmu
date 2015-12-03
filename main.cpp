#include "PmuEnterPage.h"
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QEventLoop>
#include <QTimer>
#include <QList>
#include <QGesture>
#include "ConnectToServer.h"


int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    ConnectToServer* connectToServer = new ConnectToServer();

    PmuEnterPage *pmuEnterPage = new PmuEnterPage(connectToServer);
    pmuEnterPage->show();

    return a.exec();
}
