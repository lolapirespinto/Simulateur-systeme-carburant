#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>
#include <QtGui>
#include <QFormLayout>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include "mainwindow.h"



namespace Ui {
class connexion;
}

class connexion : public QMainWindow
{
    Q_OBJECT

public:
    explicit connexion(QWidget *parent = nullptr);
    ~connexion();
    QLineEdit *champP;
    QLineEdit *champM;
    void click();

private slots:
    void on_pushButton_clicked();

private:
    Ui::connexion *ui;
};

#endif // CONNEXION_H
