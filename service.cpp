

#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "service.h"
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>

service::service()
{
    id_serv=0;
 prix_serv=0;
             nom_serv="";
             description_serv="";

}
service::service(int id_serv,int prix_serv,QString description_serv,QString nom_serv)
{
            this->id_serv=id_serv;
            this->prix_serv=prix_serv;
            this->description_serv=description_serv;
          this->nom_serv=nom_serv;
}
void service::setid_serv(int n){
   id_serv=n;

}
void service::setprix_serv(int n){
   prix_serv=n;

}
void service::setdescription_serv(QString n){
    description_serv=n;
}
    void service::setnom_serv(QString n){
        nom_serv=n;
}

    int service::getid_serv(){
        return id_serv;
    }
    int service::getprix_serv(){
        return prix_serv;
    }
    QString service::getdescription_serv(){
        return description_serv;
    }
    QString service::getnom_serv(){
        return nom_serv;
    }
    bool service::ajouter()

    {
        QSqlQuery query;

        QString res =QString::number(id_serv);
        QString i =QString::number(prix_serv);
              // prepare () prend la requete en parametre pour la preparer a l execution.
                query.prepare("insert into services (id_serv , nom_serv ,prix_serv,description_serv)" "values(:id_serv ,:nom_serv ,:prix_serv ,:description_serv)");
        //creation des variables lieés
        query.bindValue (":id_serv",id_serv);
         query.bindValue (":nom_serv",nom_serv);
          query.bindValue (":prix_serv",prix_serv);
                query.bindValue (":description_serv",description_serv);
                return query.exec();
    }
    bool service ::supprimer (int id_serv)
    {
        QSqlQuery query;
        QString res =QString::number(id_serv);
        query.prepare("delete from services where id_serv=:id_serv ") ;
    query.bindValue (":id_serv",res);
    return query.exec();

    }
    QSqlQueryModel * service::afficher()
      {

                QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from services");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_serv"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
             model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));

                return model;
            }


      bool service::modifier(int prix_serv,int id_serv,QString nom_serv,QString description_serv)


        {
            QSqlQuery query;


                  // prepare () prend la requete en parametre pour la preparer a l execution.
                    query.prepare("update services set  nom_serv=:nom_serv ,prix_serv=:prix_serv ,description_serv=:description_serv where id_serv=:id_serv");
            //creation des variables lieés
            query.bindValue (":id_serv",id_serv);
             query.bindValue (":nom_serv",nom_serv);
              query.bindValue (":prix_serv",prix_serv);
                    query.bindValue (":description_serv",description_serv);
                    return query.exec();
        }
      QSqlQueryModel * service::rechercher_serv(QString nom_serv)
       {
          QSqlQuery * q = new  QSqlQuery ();
       QSqlQueryModel * model= new QSqlQueryModel();

       q->prepare("SELECT * FROM services WHERE  nom_serv LIKE '"+nom_serv+"%'");
       q->exec();
       model->setQuery(*q);


       model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom_serv"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_serv"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_serv"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("description_serv"));


       return model ;
       }


