#include "paiements.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>

paiement::paiement()
{
id_paiement=0;
montant=0;
methode_paiement="";

}
paiement::paiement(int id_paiement,int montant,QString methode_paiement)
{
    this->id_paiement=id_paiement;
    this->montant=montant;

    this->methode_paiement=methode_paiement;


}
int paiement::getid_paiement()
{return id_paiement;}


int paiement::getmontant(){return montant;}
QString paiement::getmethode_paiement(){return methode_paiement;}


void paiement::setmontant(int montant){
    this->montant=montant;
}

void paiement::setmethode_paiement(QString methode_paiement){
    this->methode_paiement=methode_paiement;
}

void paiement::setid_paiement(int id_paiement){
    this->id_paiement=id_paiement;
}
QSqlQueryModel * paiement::triID()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from PAIEMENTS order by ID_PAIEMENT");
    return model;
}
QSqlQueryModel * paiement::trimethode()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from PAIEMENTS order by METHODE_PAIEMENT");
    return model;
}
QSqlQueryModel * paiement::trimontant()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from PAIEMENTS order by MONTANT");
    return model;
}

bool paiement::ajouter_paiement(){



    QSqlQuery query;
    QString id_paiement_string= QString ::number(id_paiement);


          query.prepare("INSERT INTO PAIEMENTS (ID_PAIEMENT,MONTANT,METHODE_PAIEMENT) "
                        "VALUES (:ID_PAIEMENT, :MONTANT,:METHODE_PAIEMENT)");


          query.bindValue(0, id_paiement_string);
          query.bindValue(1, montant);
          query.bindValue(2, methode_paiement);





    return query.exec();
}


QSqlQueryModel * paiement::afficher_paiement()
{


    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM PAIEMENTS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PAIEMENT"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("MONTANT"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("METHODE_PAIEMENT"));


    return model;

}
bool paiement::supprimer_paiement(int ID_PAIEMENT){

    QSqlQuery query;
    paiement p;


    query.prepare("Delete from PAIEMENTS where ID_PAIEMENT=:ID_PAIEMENT");
    query.bindValue(":ID_PAIEMENT",ID_PAIEMENT);

    return query.exec();
                                        }


QSqlQueryModel * paiement::search(QString rech){

    QSqlQueryModel *model= new QSqlQueryModel();
      model->setQuery("SELECT * FROM PAIEMENTS WHERE ID_PAIEMENT  LIKE'%"+rech+"%' or MONTANT  LIKE'%"+rech+"%' or METHODE_PAIEMENT  LIKE'%"+rech+"%'  ");
      return model;

}

bool paiement::modifier_paiement(int id_paiement) {

    QSqlQuery query;





          query.prepare("UPDATE PAIEMENTS SET ID_PAIEMENT=:ID_PAIEMENT,MONTANT=:MONTANT,METHODE_PAIEMENT=:METHODE_PAIEMENT WHERE ID_PAIEMENT=:ID_PAIEMENT");

          query.bindValue(":ID_PAIEMENT", id_paiement);
          query.bindValue(":MONTANT", montant);
          query.bindValue(":METHODE_PAIEMENT", methode_paiement);






          return query.exec();


}


