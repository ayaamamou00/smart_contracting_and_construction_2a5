#ifndef DIALOG_SERVICE_H
#define DIALOG_SERVICE_H
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include "service.h"
#include <QDialog>

namespace Ui {
class dialog_service;
}

class dialog_service : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_service(QWidget *parent = nullptr);
    ~dialog_service();


private slots:
    void on_pushButton45_clicked();

    void on_pushButton_4_clicked();
void on_pushButton_2_clicked();
    void on_tableView_activated(const QModelIndex &index);
void on_rechercher_clicked();
 void on_pushButton_5_clicked();
 void on_pushButton_3_clicked();

 void on_pushButton_clicked();

 void on_pushButton_6_clicked();

private:
    Ui::dialog_service *ui;
    service tmpservice;
};



#endif // DIALOG_SERVICE_H
