#ifndef MATERIEL_H
#define MATERIEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>

class materiels
{
public:
    materiels(int,int,QString,QString,QString);
    void setprix_mat(int n);
    void setdescription_mat(QString n);
    void setnom_mat(QString n);
    void setid_mat(int n);
    void setfournisseur(QString n);

    int getprix_mat();
    QString getdescription_mat();
    QString getnom_mat();
    int getid_mat();
    QString getfournisseur();
bool ajouter_frn();
bool ajouter_2(int);
int rech_qt(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
   bool modifier(int,int,QString,QString);
   QSqlQueryModel * rechercher_mat(QString id_mat);
   QSqlQueryModel * trierAc();
   QSqlQueryModel * trierDec();
   QSqlQueryModel * afficher_frn();
   void maintenance(int id_mat,int prix_mat,QString nom_mat, QString description_mat,QString fournisseur);

   ~materiels(){}

    materiels();
private:
    QString  description_mat,nom_mat,fournisseur,ville_fournisseur,date_livraison;
    int prix_mat,id_mat;

};


#endif // SERVICE_H
