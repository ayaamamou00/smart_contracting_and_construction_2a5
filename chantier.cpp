#include "chantier.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>

commande::commande()
{
    id_c=0;
    nom_c="";
    numero_c="";
    adresse_c="";
    type_c="";

}

commande::commande(int id_c,QString nom_c,QString numero_c,QString adresse_c,QString type_c)
{
    this->id_c=id_c;
    this->nom_c=nom_c;
    this->numero_c=numero_c;
    this->adresse_c=adresse_c;
    this->type_c=type_c;




}
int commande::getid_c(){return id_c;}
QString commande::getnom_c(){return nom_c;}
QString commande::getnumero_c(){return numero_c;}
QString commande::getadresse_c(){return adresse_c;}
QString commande::gettype_c(){return type_c;}


void commande::setid_c(int id_c){this->id_c=id_c;}
void commande::setnom_c(QString nom_c){this->nom_c=nom_c;}
void commande::setnumero_c(QString numero_c){this->numero_c=numero_c;}
void commande::setadresse_c(QString adresse_c){this->adresse_c=adresse_c;}
void commande::settype_c(QString type_c){this->type_c=type_c;}




bool commande::ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(id_c);

    query.prepare("INSERT INTO commande (id_c,nom_c,numero_c,adresse_c,type_c) "
                  "VALUES (:id_c,:nom_c,:numero_c,:adresse_c,:type_c)");
    query.bindValue(":id_c",id_string);
    query.bindValue(":nom_c", nom_c);
    query.bindValue(":numero_c", numero_c);
    query.bindValue(":adresse_c", adresse_c);
    query.bindValue(":type_c", type_c);



    return  query.exec();

}
QSqlQueryModel * commande ::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM commande");

        return model;
}
QSqlQueryModel * commande::recherche(QString rech,QString rech1)
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from commande where adresse_c like ('%"+rech+"%') AND nom like ('%"+rech1+"%')  ");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));

model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_c"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("numero_c"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse_c"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_c"));


return model;
}
bool commande::supprimer(QString selected)
{
    QSqlQuery query;
       query.prepare("Delete from commande where id_c = :id_c ");
       query.bindValue(":id_c", selected);
       return    query.exec();

}

bool commande ::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE commande SET adresse_c= :adresse_c , surface_c= :surface_c , budget_c= :budget_c ,nbre_etage= :nbre_etage , nbre_chambre= :nbre_chambre , jardin= :jardin where id_c= :id_c");
    query.bindValue(":id_c", selected);
    query.bindValue(":nom_c", nom_c);
    query.bindValue(":numero_c", numero_c);
    query.bindValue(":adresse_c", adresse_c);
    query.bindValue(":type_c", type_c);



    return    query.exec();

}
QSqlQueryModel *commande::trier(QString x){

            QSqlQueryModel *model= new QSqlQueryModel();
            qDebug()<<x<<endl;
            if(x=="id")
                model->setQuery("select * from commande order by id_c ASC ");
            else if(x=="nom")
                model->setQuery("select * from commande order by nom_c ASC ");
            else if (x=="type_c")
                model->setQuery("select * from commande order by type_c ASC ");

            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_c"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_c"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero_c"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_c"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("type_c"));

                return model;
}

