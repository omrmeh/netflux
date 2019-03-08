#include "widget.h"
#include <QApplication>

#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    //Création d'un objet base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "dbFilm");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("Netflux");
    db.setUserName("postgres");
    db.setPassword("");
    bool ok = db.open();

    //vérif à retirer après écriture du Gtest
    if (ok)
        qDebug()<<"ouvert";
    if (!ok)
        qDebug()<<"non ouvert";
    return a.exec();
}
