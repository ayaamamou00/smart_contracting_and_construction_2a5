#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class client
{
    int id_client,num_tel;
    QString nom_client,prenom_client,mail_client;

public:
    client();
    client(int,QString,QString,int,QString);
    //Getters
    int getid_client();
     int getnum_tel();
    QString getnom_client();
     QString getprenom_client();
      QString getmail_client();
      //Setters
      void setnom_client(QString nom);
      void setprenom_client(QString prenom);
      void setmail_client(QString mail);
      void setnum_tel(int num );
      void setid_client(int id );

      bool ajouter_client();
      QSqlQueryModel * afficher_client();

      bool modifier_client(int);
      bool supprimer_client(int);
      QSqlQueryModel * triID();
      QSqlQueryModel * trinum();
      QSqlQueryModel *search(QString rech);
      QString searchid_mat(QString rech);
      QSqlQueryModel * trinom();
};

#endif // CLIENT_H
