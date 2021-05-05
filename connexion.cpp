#include "connexion.h"
#include "ui_connexion.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTextEdit>
#include <QMessageBox>
#include <fstream>
#include <QByteArray>

connexion::connexion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::connexion)
{
    ui->setupUi(this);


    champP=new QLineEdit(this);
    champP->move(150,50);
    champP->show();

    champM=new QLineEdit(this);
    champM->move(150,90);
    champM->show();


}

connexion::~connexion()
{
    delete ui;
}




void connexion::on_pushButton_clicked()
{

    if(champP->text()=="leolamoureux" && champM->text()=="123"){
        MainWindow *m = new MainWindow;
        m->show();

        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "test de Léo :\n" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }


    }

    if(champP->text()=="lolapinto" && champM->text()=="456"){
        MainWindow *m = new MainWindow;
        m->show();
        ofstream monFlux("C:\\Users\\leosa\\OneDrive\\Bureau\\PROJETAVION\\test.txt",ios::app);
        if(monFlux)
        {
            monFlux << "test de Lola :\n" << endl;

        }
        else
        {
            cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }


    }

}
