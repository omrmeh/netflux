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
    db.setHostName("localhost");
    db.setDatabaseName("netflux");
    db.setUserName("postgres");
    db.setPassword("postgres123");
    db.setPort(5432);

    qDebug() << db <<endl;
    bool ok = db.open();

            // si ok                    si !ok
    ok ? qDebug()<<"BDD ouvert" : qDebug()<<"non ouvert";



    Widget w;
    w.show();
    return a.exec();

}
