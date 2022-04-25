#include "connection.h"


//test tutoriel git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("dali");//inserer nom de l'utilisateur
db.setPassword("brik");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
