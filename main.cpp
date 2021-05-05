
#include "reservoir.h"
#include "QPushButton"
#include "vanne.h"
#include <QApplication>
#include "connexion.h"
#include "mainwindow.h"

#include <QProgressBar>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTextEdit>
#include <QMessageBox>
#include <QByteArray>
#include <fstream>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);



    connexion c;
    c.show();


    return app.exec();

}
