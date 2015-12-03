#include "ConnectToServer.h"

ConnectToServer::ConnectToServer(){
    network_manager = new QNetworkAccessManager();
    url_str = "http://172.20.35.219:8080/daishangwo/";

    connect(network_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(reponse(QNetworkReply*)));
}


void getReponse();

//! -----------------------------------------------------------------------------------------------------
//!
//! \brief RegAndSignPage::reponse
//! \param reply
//!
//void ConnectToServer::reponse(QNetworkReply*reply){
//    reponse = QTextCodec::codecForMib(1015)->toUnicode(reply->readAll());
//}

//! -----------------------------------------------------------------------------------------------------
//!
//! \brief ConnectToServer::clear
//!
void ConnectToServer::clear(){
    post_data.clear();
}

//! -----------------------------------------------------------------------------------------------------
//!
//! \brief ConnectToServer::composeRequestMessage
//! \param msg
//!
void ConnectToServer::composeRequestMessage(QString msg){
    post_data.append(msg + "&");
}

//! -----------------------------------------------------------------------------------------------------
//!
//! \brief ConnectToServer::composeRequestFinalMessage
//! \param msg
//!
void ConnectToServer::composeRequestFinalMessage(QString msg){
    post_data.append(msg);
}

//! -----------------------------------------------------------------------------------------------------
//!
//! \brief ConnectToServer::connectera
//!
void ConnectToServer::connectera(QString typeAction){
    currentAction = typeAction;

    network_request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    network_request.setHeader(QNetworkRequest::ContentLengthHeader, post_data.length());
    network_request.setUrl(QUrl(url_str + typeAction));

    network_manager->post(network_request, post_data);

    this->clear();
}
