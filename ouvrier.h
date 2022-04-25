#ifndef OUVRIER_H
#define OUVRIER_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class ouvrier
{
public:
    ouvrier();
    ouvrier(int,QString,QString,QString,QString,QString);

    int getid_ouvrier();
    QString getnom_o ();
    QString getprenom_o();
    QString getadresse_o();
    QString getemail_o();
    QString getsalaire_o();

    bool ajouter();
    bool supprimer(QString);
    bool modifier(QString);
    bool recuperer(QString);
    QSqlQueryModel * afficher();

    void setid_ouvrier(int);
    void setnom_o(QString);
    void setprenom_o(QString);
    void setadresse_o(QString);
    void setemail_o(QString);
    void setsalaire_o(QString);
    QSqlQueryModel *trier(QString x);

private:
    int id_ouvrier;
    QString nom_o,prenom_o,adresse_o,email_o,salaire_o;

};



#endif // OUVRIER_H
