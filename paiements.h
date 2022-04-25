#ifndef PAIEMENT_H
#define PAIEMENT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class paiement
{
    int id_paiement;
    int montant;
    QString methode_paiement;

 public:
    //Constructeurs
     paiement();
     paiement(int,int,QString);
     //Getters
     int getid_paiement();
     int getmontant();
       QString getmethode_paiement();


       //Setters
       void setmontant(int montant);
       void setmethode_paiement(QString methode_paiement);
       void setid_paiement(int id );


         bool ajouter_paiement();
         QSqlQueryModel * afficher_paiement();

         bool modifier_paiement(int);
         bool supprimer_paiement(int);
         QSqlQueryModel * triID();
         QSqlQueryModel * trimethode();
         QSqlQueryModel *search(QString rech);
         QSqlQueryModel * trimontant();
};

#endif // PAIEMENT_H
