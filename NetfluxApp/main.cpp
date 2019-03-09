#include "widget.h"
#include "customwidget.h"
#include <QApplication>

#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //Création d'un objet base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "netflux");
    db.setHostName("localhost");
    db.setDatabaseName("netflux");
    db.setUserName("postgres");
    db.setPassword("postgres123");
    bool ok = db.open();

    ok ? qDebug() << db : qDebug() << "probleme d'ouverture de la db" ;

    CustomWidget w;
    w.show();

    return a.exec();
}
