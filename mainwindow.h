#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "materiels.h"

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
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

       void  on_pushButton_20_clicked ();


       void on_pushButton_6_clicked();

       void on_pushButton_TriASC_clicked();
       void on_pushButton_TriDESC_clicked();





       void on_pushButton_2_clicked();

       void on_pushButton_3_clicked();


       void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    materiels tmpmateriels;


signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);
};
#endif // MAINWINDOW_H
