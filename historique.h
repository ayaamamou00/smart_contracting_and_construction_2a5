#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>


class historique
{
public:

    historique();
    void save_txt(QString,QString,QString,QString,QString);
    QString hist();


private:
    QString ch;
};

#endif // HISTORIQUE_H
