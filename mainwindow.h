#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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




    void on_ajouter_paiements_clicked();


    void on_afficher_paiements_clicked();

    void on_modifier_paiements_clicked();

    void on_supprimer_paiements_clicked();


    void on_retour_clicked();



    void on_retour_2_clicked();

    void on_retour_3_clicked();

    void on_retour_4_clicked();

    void on_ajoute_paiement_clicked();

    void on_supprimer_paiement_clicked();

    void on_modifier_paiement_clicked();

    void on_trier_clicked();
    void on_rech_textChanged(const QString &arg1);
private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
