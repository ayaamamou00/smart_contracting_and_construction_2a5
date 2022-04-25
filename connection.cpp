#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{
    bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("build_easy");
db.setUserName("ayaa");
db.setPassword("esprit18");

if (db.open()) test=true;

return  test;
}
