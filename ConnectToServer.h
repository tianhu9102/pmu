#ifndef CONNECTTOSERVER_H
#define CONNECTTOSERVER_H

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>


class ConnectToServer : public QObject{

    Q_OBJECT

public:
    ConnectToServer();

    void connectera(QString typeAction);

    void clear();

    void composeRequestMessage(QString msg);
    void composeRequestFinalMessage(QString msg);

    void getReponse();

private:
    QString url_str;
    QString currentAction;
    QNetworkAccessManager *network_manager;
    QNetworkReply *reply;
    QNetworkRequest network_request;
    QByteArray post_data;
    QString reponse;

public slots:
    //void reponse(QNetworkReply*reply);
};

#endif // CONNECTTOSERVER_H
