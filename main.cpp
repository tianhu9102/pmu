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


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConnectToServer* connectToServer = new ConnectToServer();

    PmuEnterPage *pmuEnterPage = new PmuEnterPage(connectToServer);

    pmuEnterPage->show();

    return a.exec();
}


/*
    //! --------------------------------------------------------
    //!
    //! \brief w
    //!
    //! --------------------------------------------------------
    QNetworkAccessManager m_WebCtrl;

    QNetworkReply *reply;

    QUrl url("http://172.20.35.211:8090/daishangwo");

    QNetworkRequest request = QNetworkRequest(url);

    reply = m_WebCtrl.get(request);

    while (1) {

        QEventLoop eventloop;

        QTimer::singleShot(1000, &eventloop, SLOT(quit()));

        eventloop.exec();

        qDebug()<< "Data! " << reply->readAll();
        break;

    }
*/
