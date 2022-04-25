#include "mainwindow.h"
#include "materiels.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <iostream>
#include <QTextDocument>
#include "dialog.h"
#include "dialog_service.h"
#include <QPainter>
#include "ui_mainwindow.h"
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


void MainWindow::on_pushButton_clicked()
{
  dialog d;
hide();
d.exec();

}



void MainWindow::on_pushButton_2_clicked()
{
    dialog_service f;
    hide();
    f.exec();
}
