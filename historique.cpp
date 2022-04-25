
#include "historique.h"

historique::historique()
{

}
void historique:: save_txt(QString id ,QString nom,QString prenom,QString num,QString mail)
{
    QFile file ("C:/Users/Pc/OneDrive/Documents/projet_2a/hist.txt");
         if (!file.open(QIODevice::WriteOnly|QIODevice::Append | QIODevice::Text))
          qDebug()<<"erreur";
         QTextStream out(&file);
         out << "id: "+id+"\ntype: "+nom+"\nprix: "+prenom+"\nnombre: "+num+"\n"+mail << "\n";
}
QString historique::hist()
{
    ch="";
       QFile file("C:/Users/Pc/OneDrive/Documents/projet_2a/hist.txt");
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         ch="";

       QTextStream in(&file);

      while (!in.atEnd()) {

            QString myString = in.readLine();
            ch+=myString+"\n";

      }
      return ch;
}
