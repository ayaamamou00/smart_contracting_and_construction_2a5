#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{
    bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_projet2A");
db.setUserName("khaled");
db.setPassword("youba999");

if (db.open()) test=true;

return  test;
}
