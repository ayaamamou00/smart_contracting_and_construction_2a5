#ifndef CHANTIER_H
#define CHANTIER_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class commande
{
public:
    commande();
    commande(int,QString,QString,QString,QString);

    int getid_c();
    QString getnom_c();
    QString getnumero_c();
    QString getadresse_c();
    QString gettype_c();

    bool ajouter();
    bool supprimer(QString);
    bool modifier(QString);
    bool recuperer(QString);
    QSqlQueryModel * afficher();

    void setid_c(int);
    void setnom_c(QString);
    void setnumero_c(QString);
    void setadresse_c(QString);
    void settype_c(QString);

    QSqlQueryModel * recherche(QString,QString);

    QSqlQueryModel *trier(QString x);

private:
    int id_c;
    QString nom_c,numero_c,adresse_c,type_c;

};
#endif // CHANTIER_H

