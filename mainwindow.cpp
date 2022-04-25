#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "arduino.h"
#include "historique.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QRegExpValidator>
#include <QSqlQuery>
#include <QSystemTrayIcon>
#include <QDebug>
#include <QUrl>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->leid->setValidator(new QIntValidator(0, 99999999, this));
    ui->leid2->setValidator(new QIntValidator(0, 99999999, this));
#define NOM_RX "^([a-z]+[,.]?[ ]?|[A-Z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->lenomclient2->setValidator(valiNom);
    ui->leprenomclient2->setValidator(valiNom);
    ui->lenomclient->setValidator(valiNom);
    ui->leprenomclient->setValidator(valiNom);
    ui->lenumtel->setValidator(new QIntValidator(0, 99999999, this));
    ui->lenumtel2->setValidator(new QIntValidator(0, 99999999, this));
    ui->stackedWidget->setCurrentIndex(0);
    historique hs;
    ui->hist->setText(hs.hist());
    mSocket= new QTcpSocket(this);
    connect(mSocket,&QTcpSocket::readyRead,[&]()
    {
        QTextStream T(mSocket);
        auto text =T.readAll();
        ui->textEdit->append(text);
    });
int ret=A.connect_arduino();
switch (ret) {
case(0):qDebug() << "arduino is available and connected to :" << A.getarduino_port_name();
    break;
case(1):qDebug() << "arduino is available but not connected to :" << A.getarduino_port_name();
    break;
case(-1):qDebug() << "arduino is not available ";

}
QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajoute_client_clicked()
{
    int id_client=ui->leid->text().toInt();
    QString nom_client=ui->lenomclient->text();
    QString prenom_client=ui->leprenomclient->text();
   int num_tel=ui->lenumtel->text().toInt();
   QString mail_client=ui->lemailclient->text();

   client c(id_client,nom_client,prenom_client,num_tel,mail_client);
bool test=c.ajouter_client();
test=true;
historique hs;
hs.save_txt(ui->leid->text(),nom_client,prenom_client,ui->lenumtel->text(),mail_client);
ui->historique->setText(hs.hist());
   if ((id_client==0) || (nom_client=="") || (prenom_client=="")|| (mail_client=="")|| (num_tel==0))
           {
               QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Champs vides!!\n""Click Cancel to exit."),QMessageBox::Cancel);
               test=false;
           }





        QMessageBox msgbox;
        if(test)
        {msgbox.setText("Ajout avec succes.");
           ui->tableView->setModel(c.afficher_client());
           ui->leid->clear();
              ui->lenomclient->clear();
              ui->leprenomclient->clear();
              ui->lenumtel->clear();
              ui->lemailclient->clear();


        }
        else
            msgbox.setText("Echec d'ajout");

        msgbox.exec();

}

void MainWindow::on_ajouter_clients_clicked()
{
ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_afficher_clients_clicked()
{
   client c;
        ui->stackedWidget->setCurrentIndex(1);
         ui->tableView->setModel(c.afficher_client());
}

void MainWindow::on_modifier_clients_clicked()
{
    QSqlQuery qry;
    qry.prepare("select ID_CLIENT from CLIENT");
    qry.exec();
    while(qry.next()){
    ui->leid2->addItem(qry.value(0).toString());
    }
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_supprimer_clients_clicked()
{
    QSqlQuery qry;
    qry.prepare("select ID_CLIENT from CLIENT");
    qry.exec();
    while(qry.next()){
    ui->leidsupp->addItem(qry.value(0).toString());
    }
ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_chatbox_clicked()
{
ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_retour_2_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_modifier_client_clicked()
{
   client c;

    QMessageBox msg;

 c.setid_client(ui->leid2->currentText().toInt());

c.setprenom_client(ui->leprenomclient2->text());
c.setnom_client(ui->lenomclient2->text());
c.setnum_tel(ui->lenumtel2->text().toInt());
c.setmail_client(ui->lemailclient2->text());


bool test=c.modifier_client(c.getid_client());


    if(test)
    {
        msg.setText("modification avec succès");
        ui->tableView->setModel(c.afficher_client());



    }
    else
        msg.setText("echec de modification");

    msg.exec();
}

void MainWindow::on_retour_3_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_supprimer_client_clicked()
{
    client c;

    int id_client=ui->leidsupp->currentText().toInt();
   bool test=c.supprimer_client(id_client);


    QMessageBox msgBox;
    if(test)
  {
    msgBox.setText("supprimer avec succée");
    ui->tableView->setModel(c.afficher_client());

    // Put the focus back into the input box so they can type again:
    ui->leidsupp->setFocus();

    }

    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void MainWindow::on_retour_4_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_5_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_retour_6_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked()
{
    QTextStream T(mSocket);
    T << ui->username->text()<<": "<<ui->line_message->text();
    mSocket->flush();
    ui->line_message->clear();
}

void MainWindow::on_connecter_clicked()
{
 mSocket->connectToHost("localhost",3333);
}

void MainWindow::on_retour_1_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_hist_clicked()
{
ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_rech_textChanged(const QString &arg1)
{
   client c;
     ui->tableView->setModel(c.search(arg1));
}

void MainWindow::on_trier_clicked()
{
   client c;
        QString choix = ui->tri->currentText();
            if (choix =="ID" ){
                ui->tableView->setModel(c.triID());
            }else if(choix=="NUM") {

                ui->tableView->setModel(c.trinum());

        }else if(choix=="NOM") {
                ui->tableView->setModel(c.trinom());
            }
}
