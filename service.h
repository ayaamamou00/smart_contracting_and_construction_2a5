#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>

class service
{
public:
    service(int,int,QString,QString);
    void setprix_serv(int n);
    void setdescription_serv(QString n);
    void setnom_serv(QString n);
    void setid_serv(int n);
    int getprix_serv();
    QString getdescription_serv();
    QString getnom_serv();
    int getid_serv();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
   bool modifier(int,int,QString,QString);
    QSqlQueryModel * rechercher_serv(QString nom_serv);
   ~service(){}

    service();
private:
    QString  description_serv,nom_serv;
    int prix_serv,id_serv;

};


#endif // SERVICE_H
