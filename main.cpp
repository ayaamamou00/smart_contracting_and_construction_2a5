#include "mainwindow.h"
#include<QtWidgets/QApplication>
#include "connection.h"
#include <QFile>
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //style sheet
        QFile styleSheetFile("C:/Users/Pc/Desktop/ouvrier2/ouvrier/Hookmark.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);
        //
        MainWindow w;

        w.show();
        return a.exec();
}
