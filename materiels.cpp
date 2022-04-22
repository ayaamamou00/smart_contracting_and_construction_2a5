#include <QTabWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "materiels.h"
#include <QDebug>
#include <QSqlRecord>
#include <iostream>
#include <QTextDocument>
#include <QPainter>
#include <QDate>
materiels::materiels()
{
    id_mat=0;
 prix_mat=0;
             nom_mat="";
             description_mat="";

fournisseur="";
}
materiels::materiels(int id_mat,int prix_mat,QString description_mat,QString nom_mat,QString fournisseur )
{
            this->id_mat=id_mat;
            this->prix_mat=prix_mat;
            this->description_mat=description_mat;
            this->nom_mat=nom_mat;
this->fournisseur=fournisseur;



}
void materiels::setid_mat(int n){
   id_mat=n;

}
void materiels::setprix_mat(int n){
   prix_mat=n;

}
void materiels::setdescription_mat(QString n){
    description_mat=n;
}
    void materiels::setnom_mat(QString n){
        nom_mat=n;
}

    void materiels::setfournisseur(QString n){
        fournisseur=n;
}


    int materiels::getid_mat(){
        return id_mat;
    }
    int materiels::getprix_mat(){
        return prix_mat;
    }
    QString materiels::getdescription_mat(){
        return description_mat;
    }
    QString materiels::getnom_mat(){
        return nom_mat;
    }
    QString materiels::getfournisseur(){
        return fournisseur;
    }

bool materiels::ajouter()

{
    QSqlQuery query;

    QString res =QString::number(id_mat);
    QString i =QString::number(prix_mat);
          // prepare () prend la requete en parametre pour la preparer a l execution.
            query.prepare("insert into materiels (id_mat , nom_mat ,prix_mat ,description_mat)" "values(:id_mat ,:nom_mat ,:prix_mat ,:description_mat)");
    //creation des variables lieés
    query.bindValue (":id_mat",res);
     query.bindValue (":nom_mat",nom_mat);
      query.bindValue (":prix_mat",i);
            query.bindValue (":description_mat",description_mat);
            return query.exec();
}
bool materiels ::supprimer (int id_mat)
{
    QSqlQuery query;
    QString res =QString::number(id_mat);
    query.prepare("delete from materiels where id_mat=:id_mat ") ;
query.bindValue (":id_mat",res);
return query.exec();
}
QSqlQueryModel * materiels::afficher()
  {

            QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from materiels");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));

            return model;
        }


  bool materiels::modifier(int,int,QString,QString)


    {
        QSqlQuery query;

        QString res =QString::number(id_mat);
        QString i =QString::number(prix_mat);
              // prepare () prend la requete en parametre pour la preparer a l execution.
                query.prepare("update materiels set  nom_mat=:nom_mat ,prix_mat=:prix_mat ,description_mat=:description_mat where id_mat=:id_mat");
        //creation des variables lieés
        query.bindValue (":id_mat",res);
         query.bindValue (":nom_mat",nom_mat);
          query.bindValue (":prix_mat",i);
                query.bindValue (":description_mat",description_mat);
                return query.exec();
    }





  QSqlQueryModel * materiels::trierAc()
  {
      QSqlQuery * q = new  QSqlQuery ();
               QSqlQueryModel * model = new  QSqlQueryModel ();
               q->prepare("SELECT * FROM materiels order by nom_mat ASC");
               q->exec();
               model->setQuery(*q);
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_mat"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_mat"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_mat"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("description_mat"));

               return model;

  }

  QSqlQueryModel * materiels::trierDec()
  {
            QSqlQuery * q = new  QSqlQuery ();
                   QSqlQueryModel * model = new  QSqlQueryModel ();
                   q->prepare("SELECT * FROM materiels order by nom_mat DESC");
                   q->exec();
                   model->setQuery(*q);
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_mat"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_mat"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_mat"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("description_mat"));

                   return model;
  }







  QSqlQueryModel * materiels :: rechercher_mat(QString nom_mat)
   {
      QSqlQuery * q = new  QSqlQuery ();
   QSqlQueryModel * model= new QSqlQueryModel();

   q->prepare("SELECT * FROM materiels WHERE  nom_mat LIKE '"+nom_mat+"%'");
   q->exec();
   model->setQuery(*q);


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_mat"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_mat"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix_mat"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("description_mat"));


   return model ;
   }






bool materiels::ajouter_frn()
{

    QSqlQuery query;

    QString res =QString::number(id_mat);
    QString i =QString::number(prix_mat);
          // prepare () prend la requete en parametre pour la preparer a l execution.
            query.prepare("insert into materiels (id_mat , nom_mat ,prix_mat ,description_mat)" "values(:id_mat ,:nom_mat ,:prix_mat ,:description_mat)");
    //creation des variables lieés
    query.bindValue (":id_mat",res);
     query.bindValue (":nom_mat",nom_mat);
      query.bindValue (":prix_mat",i);
            query.bindValue (":description_mat",description_mat);
            return query.exec();
}


QSqlQueryModel * materiels::afficher_frn()

{

          QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("select * from materiels");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Fournisseur"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("ville_fournisseur"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_livraison"));

          return model;
      }


void materiels::maintenance(int id_mat,int prix_mat,QString nom_mat, QString description_mat,QString fournisseur)
{

    QSqlQuery query1;
    query1.prepare("select * from materiels where (TO_CHAR(DATE_ACTIVITE_HISTORIQUE,'dd/mm/yyyy') = TO_CHAR(sysdate,'dd/mm/yyyy'))");
    query1.exec();

    QSqlQuery query,qry;
    QString date=QDateTime::currentDateTime().toString("dddd, dd MMMM yyyy");
    QString date1=QDateTime::currentDateTime().toString("dd/MM/yy");
    QString time=QDateTime::currentDateTime().toString("hh:mm");
    QString activity;

    activity="\n    "+date1+"   -   "+time+" \t    "+ nom_mat+" "+prix_mat+"  "+description_mat+" d'identifiant:  "+id_mat+" \n";

          query.prepare("INSERT INTO history (activity) VALUES (:activity)");
          query.bindValue(":activity", activity);

    query.exec();

    activity="\n\t\t\t\t"+date+"\n";
}
