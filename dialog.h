#ifndef DIALOG_H
#define DIALOG_H
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "materiels.h"
#include "arduino.h"


#include <QDialog>

namespace Ui {
class dialog;
}

class dialog : public QDialog
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();

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
     Ui::dialog *ui;
    materiels tmpmateriels;
    QByteArray data;
    arduino a;
signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);
};



#endif // DIALOG_H
