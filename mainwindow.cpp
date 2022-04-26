#include <QSystemTrayIcon>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include <QString>
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include <QPropertyAnimation>
#include "ouvrier.h"
#include "connection.h"
#include "hello.h"
#include <QDateTime>
#include <QDebug>
#include<QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("C:/Users/Pc/Desktop/ouvrier2/ouvrier/images/screen.jpg");
        bkgnd = bkgnd.scaled(1920,1080);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
        Connection c;
        c.createconnect();
            timer = new QTimer (this);
            connect(timer,SIGNAL (timeout()),this,SLOT (myfunction()));
              timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pb_ajouter_clicked()
{

    int id_ouvrier=ui->le_id_ouvrier->text().toInt();
    QString nom_o=ui->le_nom_o->text();
    QString prenom_o=ui->le_prenom_o->text();
    QString adresse_o=ui->le_adresse_o->text();
    QString email_o=ui->le_email_o->text();
    QString salaire_o=ui->le_salaire_o->text();


     ouvrier o (id_ouvrier,nom_o,prenom_o,adresse_o,email_o,salaire_o);
    bool test=o.ajouter();
    if (test)
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();


               notifyIcon->showMessage("Ajouter ","Vous avez Ajouté un  ouvrier ",QSystemTrayIcon::Information,15000);

        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué. \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



     show_tables();
        ui->le_id_ouvrier->clear();
        ui->le_nom_o->clear();
        ui->le_prenom_o->clear();
        ui->le_adresse_o->clear();
        ui->le_email_o->clear();
        ui->le_salaire_o->clear();

}
void MainWindow::show_tables(){


    proxytr = new QSortFilterProxyModel();


    proxytr->setSourceModel(tmptr.afficher());


    proxytr->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxytr->setFilterKeyColumn(selcoltr);

    ui->tv_afficher->setModel(proxytr);


}
void MainWindow::on_tv_afficher_clicked(const QModelIndex &index)
{
    //recuperation

  QString sel="test";
sel=ui->tv_afficher->model()->data(index).toString();

//affichage
  ui->le_supp->setText(sel);


}

void MainWindow::on_pb_afficher_clicked()
{
show_tables();
QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
        notifyIcon->show();


       notifyIcon->showMessage("Afficher","Vous avez affiché les  ouvriers ",QSystemTrayIcon::Information,15000);

}


void MainWindow::on_pb_supprimer_clicked()
{
    int id_ouvrier=ui->le_id_ouvrier->text().toInt();
    QString nom_o=ui->le_nom_o->text();
    QString prenom_o=ui->le_prenom_o->text();
    QString adresse_o=ui->le_adresse_o->text();
    QString email_o=ui->le_email_o->text();
    QString salaire_o=ui->le_salaire_o->text();

    ouvrier o (id_ouvrier,nom_o,prenom_o,adresse_o,email_o,salaire_o);
      o.supprimer(ui->le_supp->text());
  QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
          notifyIcon->show();


         notifyIcon->showMessage("Supprimer ","Vous avez supprimé un  ouvrier ",QSystemTrayIcon::Information,15000);

  ui->le_supp->clear();

 //refresh du tableau (affichage)
   show_tables();

}

void MainWindow::on_pb_modifier_clicked()
{
    //recuperation des donnees
    int id_ouvrier=ui->le_id_ouvrier->text().toInt();
    QString id_m=ui->le_id_ouvrier->text();
    QString nom_o=ui->le_nom_o->text();
    QString prenom_o=ui->le_prenom_o->text();
    QString adresse_o=ui->le_adresse_o->text();
    QString email_o=ui->le_email_o->text();
    QString salaire_o=ui->le_salaire_o->text();





      //modifier
    ouvrier o (id_ouvrier,nom_o,prenom_o,adresse_o,email_o,salaire_o);
      o.modifier(id_m);




  //refresh du tableau (affichage)
   show_tables();
   ui->le_id_ouvrier->clear();
   ui->le_nom_o->clear();
   ui->le_prenom_o->clear();
   ui->le_adresse_o->clear();
   ui->le_email_o->clear();
   ui->le_salaire_o->clear();


      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();


             notifyIcon->showMessage("Modifier ","Vous avez modifié un  ouvrier ",QSystemTrayIcon::Information,15000);

   }


void MainWindow::on_tv_afficher_activated(const QModelIndex &index)
{
    QString val=ui->tv_afficher->model()->data(index).toString();

        QSqlQuery query;


        query.prepare(" select * from  ouvrier where id_ouvrier='"+val+"'");
        query.bindValue(":id_ouvrier", val);

       if (query.exec())
       {
           while(query.next())
           {
               ui->le_id_ouvrier->setText(query.value(0).toString());
               ui->le_nom_o->setText(query.value(1).toString());
               ui->le_prenom_o->setText(query.value(5).toString());
               ui->le_adresse_o->setText(query.value(3).toString());
               ui->le_email_o->setText(query.value(2).toString());
               ui->le_salaire_o->setText(query.value(6).toString());


           }

       }
}

/*void MainWindow::on_trecherchec_currentIndexChanged(int index)
{
    selcoltr=ui->trecherchec->currentIndex();
    show_tables();
}
/*void MainWindow::on_trecherchec_2_currentIndexChanged(int index)
{
    selcoltr=ui->trecherchec_2->currentIndex();
    show_tables();
}*/

void MainWindow::on_trecherchelt_textChanged(const QString &arg1)
{
    proxytr->setFilterFixedString(arg1);
}
/*void MainWindow::on_trecherchelt_3_textChanged(const QString &arg2)
{
    proxytr->setFilterFixedString(arg2);
}
*/









void MainWindow::on_toolButton_clicked()
{

    QString l=ui->tri->currentText();

    int id_ouvrier=ui->le_id_ouvrier->text().toInt();
    QString nom_o=ui->le_nom_o->text();
    QString prenom_o=ui->le_prenom_o->text();
    QString adresse_o=ui->le_adresse_o->text();
    QString email_o=ui->le_email_o->text();
    QString salaire_o=ui->le_salaire_o->text();


    ouvrier o (id_ouvrier,nom_o,prenom_o,adresse_o,email_o,salaire_o);

       ui->tv_afficher->setModel(o.trier(l));
}



void MainWindow::myfunction()
{
    QTime time =QTime::currentTime();
       QString time_text=time.toString("hh : mm : ss");
       ui->label2 ->setText(time_text);
}









void MainWindow::on_le_salaire_o_editingFinished()
{
    int val=ui->le_salaire_o->text().toInt();
    if (val<=0)
      {  QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Salaire  NON VALID \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
