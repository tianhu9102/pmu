#ifndef CONNECTTOSERVER_H
#define CONNECTTOSERVER_H

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>


class ConnectToServer : public QObject{

    Q_OBJECT

public:
    ConnectToServer();

private:
    QUrl url;
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
};

#endif // CONNECTTOSERVER_H
