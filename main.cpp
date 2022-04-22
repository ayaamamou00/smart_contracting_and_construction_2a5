#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c; // une seule instance de la classe connection
    bool test=c.createconnect(); //etablir la connexion
    MainWindow w;

    if(test) //si la connexion est établie
    {
        w.show();

        QMessageBox::information(nullptr, QObject::tr("database is open"),
        QObject::tr("connection seccessful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                          QObject::tr("connection failed.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
