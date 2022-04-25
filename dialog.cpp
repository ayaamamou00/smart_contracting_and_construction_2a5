#include "dialog.h"
#include "ui_dialog.h"
#include "materiels.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <iostream>
#include <QTextDocument>
#include <QPainter>
using namespace std;

dialog::dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
}

dialog::~dialog()
{
    delete ui;
}


void dialog::on_pushButton_clicked()
{
    int id_mat,prix_mat,qt_ard=0;
            QString description_mat, nom_mat,fournisseur;
            data =a.read_from_arduino();
            if(data=="1")
            {qt_ard ++;}
            id_mat=ui->lineEdit->text().toInt();
            prix_mat=ui->lineEdit_3->text().toInt();
            description_mat=ui->lineEdit_4->text();
            nom_mat=ui->lineEdit_2->text();
            materiels m(id_mat,prix_mat,description_mat,nom_mat,fournisseur);
            bool test=m.ajouter_2(qt_ard);
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


void dialog::on_pushButton_4_clicked()
{
    ui->tableView->setModel(tmpmateriels.afficher());
}


void dialog::on_pushButton_20_clicked()
{
    int id_mat=ui->lineEdit_5->text().toInt();
        tmpmateriels.supprimer(id_mat);


         bool test=tmpmateriels.supprimer(id_mat);


        if(test)
        {

            ui->tableView->setModel(tmpmateriels.afficher());
            QMessageBox::critical(nullptr, QObject::tr("supprimer Validé"),
                        QObject::tr("DELETE successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("supprimer not Validé"),
                        QObject::tr("DELETE failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}

void dialog::on_pushButton_6_clicked()
{
    int id_mat,prix_mat;
            QString nom_mat,description_mat,fournisseur;

            id_mat=ui->lineEdit_10->text().toInt();
            nom_mat=ui->lineEdit_13->text();
            prix_mat=ui->lineEdit_12->text().toInt();

            description_mat=ui->lineEdit_11->text();

           tmpmateriels.modifier(id_mat,prix_mat,nom_mat,description_mat);


                 materiels M(id_mat,prix_mat,nom_mat,description_mat,fournisseur);


                   bool test=M.modifier(id_mat,prix_mat,nom_mat,description_mat);

                    if(test)
                    {
                        ui->tableView->setModel(tmpmateriels.afficher());
                        QMessageBox::critical(nullptr, QObject::tr("modifier Validé"),
                                    QObject::tr("MODIF successful.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

                }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("modifier not Validé"),
                                    QObject::tr("MODIF failed.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void dialog::on_pushButton_TriASC_clicked()
{
    ui->tableView_tri->setModel(tmpmateriels.trierAc());
}

void dialog::on_pushButton_TriDESC_clicked()
{
    ui->tableView_tri->setModel(tmpmateriels.trierDec());
}




void dialog::on_pushButton_2_clicked()
{
    QString nom_mat=ui->lineErechercher->text();
        ui->tableView_rechercher->setModel(tmpmateriels.rechercher_mat(nom_mat)) ;
}



void dialog::on_pushButton_3_clicked()
{






                     int id_mat,prix_mat;
                             QString description_mat, nom_mat,fournisseur;
                             id_mat=ui->lineEdit_id->text().toInt();
                             prix_mat=ui->lineEdit_date->text().toInt();
                             description_mat=ui->lineEdit_frn_vl->text();
                             nom_mat=ui->lineEdit_frn->text();
                             materiels m(id_mat,prix_mat,description_mat,nom_mat,fournisseur);
                             bool test=m.ajouter_frn();
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






void dialog::on_pushButton_5_clicked()
{
    ui->tableView_frn->setModel(tmpmateriels.afficher_frn());
}

