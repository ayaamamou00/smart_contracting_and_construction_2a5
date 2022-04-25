#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "service.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <iostream>
#include <QTextDocument>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>



using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton45_clicked()
{
    int id_serv,prix_serv;
            QString description_serv, nom_serv;
            id_serv=ui->lineEdit_5->text().toInt();
            prix_serv=ui->lineEdit_3->text().toInt();
            description_serv=ui->lineEdit_2->text();
            nom_serv=ui->lineEdit->text();
            service s(id_serv,prix_serv,description_serv, nom_serv);
            bool test=s.ajouter();
            cout<<test;
                     if(test)
                     {

                         QMessageBox::information(nullptr, QObject::tr("Ajout Validé"),
                                     QObject::tr("ADD successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

                 }
                     else
                         QMessageBox::critical(nullptr, QObject::tr("Ajout not Validé"),
                                     QObject::tr("ADD failed.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(tmpservice.afficher());
}



void MainWindow::on_pushButton_2_clicked()
{
    int id_serv=ui->lineEdit_4->text().toInt();
        tmpservice.supprimer(id_serv);


         bool test=tmpservice.supprimer(id_serv);


        if(test)
        {

            ui->tableView->setModel(tmpservice.afficher());
            QMessageBox::critical(nullptr, QObject::tr("supprimer Validé"),
                        QObject::tr("DELETE successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("supprimer not Validé"),
                        QObject::tr("DELETE failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_rechercher_clicked()
{
    QString nom_serv=ui->lineEdit_7->text() ;
        ui->tableView_2->setModel(tmpservice.rechercher_serv(nom_serv)) ;

}
void MainWindow::on_pushButton_5_clicked()
{
    QSqlDatabase db;
                    QTableView table_service;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT * FROM services ");
                     qry.exec();
                     Modal->setQuery(qry);
                     table_service.setModel(Modal);



                     db.close();


                     QString strStream;
                     QTextStream out(&strStream);


                     const int rowCount = table_service.model()->rowCount();
                     const int columnCount =  table_service.model()->columnCount();


                     const QString strTitle ="Document";


                     out <<  "<html>\n"
                             "<img src='C:/Users/ASUS/Documents/kiosqueK/logocin.png' height='120' width='120'/>"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             "<img src='e-care.png'>"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des services")
                        <<"<br>"

                        <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!table_service.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(table_service.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!table_service.isColumnHidden(column)) {
                                 QString data = table_service.model()->data(table_service.model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                             "<br><br>"
                             <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                         out << "<thead><tr bgcolor=#f0f0f0>";

                             out <<  "</table>\n"

                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);

                     QPrinter printer;
                     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                     if (dialog->exec() == QDialog::Accepted) {

                         QLabel lab;
                          QPixmap pixmap(":/img/aze.png");
                         lab.setPixmap(pixmap);
                         QPainter painter(&lab);
                         //QPrinter printer(QPrinter::PrinterResolution);

                         //pixmap.load("aze.png");
                         //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                         //painter.drawPixmap(10,10,50,50, pixmap);

                         document->print(&printer);
                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/produit.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                     delete document;
}


void MainWindow::on_pushButton_3_clicked()
{
    QString nom=ui->lineEdit_7->text() ;
        ui->tableView_2->setModel(tmpservice.rechercher_serv(nom)) ;
}

void MainWindow::on_pushButton_clicked()
{


        int id_serv,prix_serv;
            QString nom_serv,description_serv;

            id_serv=ui->lineEdit_6->text().toInt();
            nom_serv=ui->lineEdit_8->text();
            description_serv=ui->lineEdit_9->text();
            prix_serv=ui->lineEdit_10->text().toInt();
             tmpservice.modifier(id_serv,prix_serv,nom_serv,description_serv);
}


void MainWindow::on_pushButton_6_clicked()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("select* from services  order by prix_serv desc ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_serv"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_serv"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("description_serv"));

          ui->tableView_3->setModel(model);
}
