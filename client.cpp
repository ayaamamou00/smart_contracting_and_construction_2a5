#include "client.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QMessageBox>

client::client()
{
id_client=0;
nom_client="";
prenom_client="";
num_tel=0;
mail_client="";
}
client::client(int id_client,QString nom_client,QString prenom_client,int num_tel,QString mail_client)
{
    this->id_client=id_client;
    this->nom_client=nom_client;
    this->prenom_client=prenom_client;
      this->num_tel=num_tel;
    this->mail_client=mail_client;

}
int client::getid_client()
{return id_client;}


QString client::getnom_client(){return nom_client;}
QString client::getprenom_client(){return  prenom_client;}
int client::getnum_tel(){return num_tel;}
QString client::getmail_client(){return mail_client;}


void client::setnom_client(QString nom_client){
    this->nom_client=nom_client;
}
void client::setprenom_client(QString prenom_client){
    this->prenom_client=prenom_client;
}
void client::setnum_tel(int num_tel){
    this->num_tel=num_tel;
}
void client::setmail_client(QString mail_client){
    this->mail_client=mail_client;
}
void client::setid_client(int id_client){
    this->id_client=id_client;
}
QSqlQueryModel * client::triID()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from client order by ID_CLIENT");
    return model;
}
QSqlQueryModel * client::trinum()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from client order by NUM_DE_TEL");
    return model;
}
QSqlQueryModel * client::trinom()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from client order by NOM_CLIENT");
    return model;
}

bool client::ajouter_client(){



    QSqlQuery query;
    QString id_client_string= QString ::number(id_client);


          query.prepare("INSERT INTO client (ID_CLIENT,NOM_CLIENT,PRENOM_CLIENT,NUM_DE_TEL,MAIL_CLIENT) "
                        "VALUES (:ID_client, :NOM_client,:PRENOM_client,:TYPE_client,:MAIL_client)");


          query.bindValue(0, id_client_string);
          query.bindValue(1, nom_client);
          query.bindValue(2, prenom_client);
          query.bindValue(3, num_tel);
          query.bindValue(4, mail_client);




    return query.exec();
}


QSqlQueryModel * client::afficher_client()
{


    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM CLIENT");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CLIENT"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_CLIENT"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_DE_TEL"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL_CLIENT"));

    return model;

}
bool client::supprimer_client(int ID_CLIENT){

    QSqlQuery query;
    client c;


    query.prepare("Delete from CLIENT where ID_CLIENT=:ID_CLIENT");
    query.bindValue(":ID_CLIENT", ID_CLIENT);

    return query.exec();
                                        }


QSqlQueryModel * client::search(QString rech){

    QSqlQueryModel *model= new QSqlQueryModel();
      model->setQuery("SELECT * FROM CLIENT WHERE ID_CLIENT  LIKE'%"+rech+"%' or NOM_CLIENT  LIKE'%"+rech+"%' or PRENOM_CLIENT  LIKE'%"+rech+"%' or NUM_DE_TEL  LIKE'%"+rech+"%' ");
      return model;

}

QString client::searchid_mat(QString id_mat){

    QSqlQuery query;
    query.prepare("SELECT * FROM materiels WHERE ID_MAT=:id_mat ");
    query.bindValue(":id_mat",id_mat);
    if (query.exec()&&query.next())
       {
        return query.value(1).toString();
    }

      return "false";

}

bool client::modifier_client(int id_client){

    QSqlQuery query;





          query.prepare("UPDATE client SET ID_CLIENT=:ID_client,NOM_CLIENT=:NOM_CLIENT,PRENOM_CLIENT=:PRENOM_CLIENT,NUM_DE_TEL=:NUM_DE_TEL,MAIL_CLIENT=:MAIL_CLIENT WHERE ID_CLIENT=:ID_CLIENT");

          query.bindValue(":ID_CLIENT", id_client);
          query.bindValue(":NOM_CLIENT", nom_client);
          query.bindValue(":PRENOM_CLIENT", prenom_client);
          query.bindValue(":NUM_DE_TEL", num_tel);
          query.bindValue(":MAIL_CLIENT", mail_client);





          return query.exec();


}


