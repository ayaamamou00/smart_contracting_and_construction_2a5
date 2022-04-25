#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTcpSocket>
#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajoute_client_clicked();

    void on_ajouter_clients_clicked();

    void on_afficher_clients_clicked();

    void on_modifier_clients_clicked();

    void on_supprimer_clients_clicked();

    void on_chatbox_clicked();

    void on_retour_2_clicked();

    void on_modifier_client_clicked();

    void on_retour_3_clicked();

    void on_supprimer_client_clicked();

    void on_retour_4_clicked();

    void on_retour_5_clicked();

    void on_retour_6_clicked();

    void on_pushButton_clicked();

    void on_connecter_clicked();

    void on_retour_1_clicked();

    void on_hist_clicked();

    void on_rech_textChanged(const QString &arg1);

    void on_trier_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *mSocket;

    QByteArray data;


    arduino A;

    QString res="";
};
#endif // MAINWINDOW_H
