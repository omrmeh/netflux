#include "widget.h"
#include <QApplication>

#include <QSqlDatabase>
#include <QDebug>
#include <customwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //Création d'un objet base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "dbFilm");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("netflux");
    db.setUserName("postgres");
    db.setPassword("");
    bool ok = db.open();

    //vérif à retirer après écriture du Gtest
    if (ok)
        qDebug()<<"BDD ouvert";
    if (!ok)
        qDebug()<<"non ouvert";
    Widget w;
    w.show();
    return a.exec();




}
