#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paiements.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   ui->setupUi(this);
    ui->lemethode->addItem("Select");
    ui->lemethode->addItem("espece");
    ui->lemethode->addItem("cheque");
    ui->lemethode2->addItem("Select");
    ui->lemethode2->addItem("espece");
    ui->lemethode2->addItem("cheque");
    ui->leid->setValidator(new QIntValidator(0, 99999999, this));
    ui->leid2->setValidator(new QIntValidator(0, 99999999, this));
    ui->lemontant->setValidator(new QIntValidator(0, 99999999, this));
    ui->lemontant2->setValidator(new QIntValidator(0, 99999999, this));
#define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);


    ui->lemethode->setValidator(valiNom);
    ui->lemethode2->setValidator(valiNom);
    ui->stackedWidget->setCurrentIndex(1);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ajouter_paiements_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow:: on_afficher_paiements_clicked()
{
paiement p;
    ui->stackedWidget->setCurrentIndex(2);
     ui->tableView->setModel(p.afficher_paiement());
}

void MainWindow::on_modifier_paiements_clicked()
{
    QSqlQuery qry;
    qry.prepare("select ID_PAIEMENT from PAIEMENTS");
    qry.exec();
    while(qry.next()){
    ui->leid2->addItem(qry.value(0).toString());
    }
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_supprimer_paiements_clicked()
{
        QSqlQuery qry;
        qry.prepare("select ID_PAIEMENT from PAIEMENTS");
        qry.exec();
        while(qry.next()){
        ui->leidsupp->addItem(qry.value(0).toString());
        }
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_retour_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_ajoute_paiement_clicked()
{
    int id_paiement=ui->leid->text().toInt();
    int montant=ui->lemontant->text().toInt();
    
    QString methode_paiement=ui->lemethode->currentText();
   

   paiement p(id_paiement,montant,methode_paiement);
bool test=p.ajouter_paiement();
test=true;
   if ((id_paiement==0) || (montant==0) || (ui->lemethode->currentIndex ()==0))
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Champs vides!!\n""Click Cancel to exit."),QMessageBox::Cancel);
               test=false;
           }





        QMessageBox msgbox;
        if(test)
        {msgbox.setText("Ajout avec succes.");
           ui->tableView->setModel(p.afficher_paiement());
           ui->leid->clear();
              ui->lemontant->clear();
              
              ui->lemethode->clear();
            


        }
        else
            msgbox.setText("Echec d'ajout");

        msgbox.exec();
         ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_supprimer_paiement_clicked()
{
    paiement p;

    int id_paiement=ui->leidsupp->currentText().toInt();
   bool test=p.supprimer_paiement(id_paiement);


    QMessageBox msgBox;
    if(test)
  {
    msgBox.setText("supprimer avec succée");
    ui->tableView->setModel(p.afficher_paiement());

    // Put the focus back into the input box so they can type again:
    ui->leidsupp->setFocus();

    }

    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}



void MainWindow::on_modifier_paiement_clicked()
{
    paiement p;

    QMessageBox msg;

 p.setid_paiement(ui->leid2->currentText().toInt());



//p.setmontant(ui->lemontant2->currentText());
p.setmethode_paiement(ui->lemethode2->currentText());



bool test=p.modifier_paiement(p.getid_paiement());


    if(test)
    {
        msg.setText("modification avec succès");
        ui->tableView->setModel(p.afficher_paiement());



    }
    else
        msg.setText("echec de modification");

    msg.exec();
}
void MainWindow::on_trier_clicked()
{  paiement p;
    QString choix = ui->tri->currentText();
        if (choix =="ID" ){
            ui->tableView->setModel(p.triID());
        }else if(choix=="montant") {

            ui->tableView->setModel(p.trimontant());

    }else if(choix=="methodepaiement") {
            ui->tableView->setModel(p.trimethode());
        }
}
void MainWindow::on_rech_textChanged(const QString &arg1)
{
    paiement p;
     ui->tableView->setModel(p.search(arg1));
}
