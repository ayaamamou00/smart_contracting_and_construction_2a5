#include "ouvrier.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

ouvrier::ouvrier()
{
    id_ouvrier=0;
    nom_o="";
    prenom_o="";
    adresse_o="";
    email_o="";
    salaire_o="";


}

ouvrier::ouvrier(int id_ouvrier,QString nom_o,QString prenom_o,QString adresse_o,QString email_o,QString salaire_o)
{
    this->id_ouvrier=id_ouvrier;
    this->nom_o=nom_o;
    this->prenom_o=prenom_o;
    this->adresse_o=adresse_o;
    this->email_o=email_o;
    this->salaire_o=salaire_o;


}
int ouvrier::getid_ouvrier(){return id_ouvrier;}
QString ouvrier::getnom_o(){return nom_o;}
QString ouvrier::getprenom_o(){return prenom_o;}
QString ouvrier::getadresse_o(){return adresse_o;}
QString ouvrier::getemail_o(){return email_o;}
QString ouvrier::getsalaire_o(){return salaire_o;}

void ouvrier::setid_ouvrier(int id_ouvrier){this->id_ouvrier=id_ouvrier;}
void ouvrier::setnom_o(QString nom_o){this->nom_o=nom_o;}
void ouvrier::setprenom_o(QString prenom_o){this->prenom_o=prenom_o;}
void ouvrier::setadresse_o(QString adresse_o){this->adresse_o=adresse_o;}
void ouvrier::setemail_o(QString email_o){this->email_o=email_o;}
void ouvrier::setsalaire_o(QString salaire_o){this->salaire_o=salaire_o;}



bool ouvrier::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id_ouvrier);

    query.prepare("INSERT INTO ouvrier (id_ouvrier,nom_o,prenom_o,adresse_o,email_o,salaire_o) "
                  "VALUES (:id_ouvrier,:nom_o,:prenom_o,:adresse_o,:email_o,:salaire_o)");
    query.bindValue(":id_ouvrier",id_string);
    query.bindValue(":nom_o", nom_o);
    query.bindValue(":prenom_o", prenom_o);
    query.bindValue(":adresse_o", adresse_o);
    query.bindValue(":email_o", email_o);
    query.bindValue(":salaire_o", salaire_o);


    return  query.exec();

}
QSqlQueryModel * ouvrier ::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM ouvrier");

        return model;
}
bool ouvrier::supprimer(QString selected)
{
    QSqlQuery query;
       query.prepare("Delete from ouvrier where id_ouvrier = :id_ouvrier ");
       query.bindValue(":id_ouvrier", selected);
       return    query.exec();

}

bool ouvrier ::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE ouvrier SET nom_o= :nom_o , prenom_o= :prenom_o , adresse_o= :adresse_o ,email_o= :email_o , salaire_o= :salaire_o  where id_ouvrier= :id_ouvrier");
    query.bindValue(":id_ouvrier", selected);
    query.bindValue(":nom_o", nom_o);
    query.bindValue(":prenom_o", prenom_o);
    query.bindValue(":adresse_o", adresse_o);
    query.bindValue(":email_o", email_o);
    query.bindValue(":salaire_o", salaire_o);


    return    query.exec();

}
QSqlQueryModel * ouvrier::trier(QString x){

            QSqlQueryModel *model= new QSqlQueryModel();
            qDebug()<<x<<endl;
            if(x=="id")
                model->setQuery("select * from ouvrier order by id_ouvrier ASC ");
            else if(x=="nom")
                model->setQuery("select * from ouvrier order by nom_o ASC ");
            else if (x=="salaire")
                model->setQuery("select * from ouvrier order by salaire_o ASC ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_ouvrier"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_o"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_o"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_o"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("email_o"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire_o"));
                return model;
}

