#include "widget.h"
#include <QApplication>

#include <QSqlDatabase>
#include <QDebug>
#include <customwidget.h>
#include <QSettings>

int main(int argc, char *argv[])
{
    /*
     * configuration du fichier ini
     */

    QCoreApplication::setOrganizationName("Aelion");
    QCoreApplication::setOrganizationDomain("https://github.com/omrmeh/netflux");
    QCoreApplication::setApplicationName("Netflux");
    QSettings settings;

    settings.beginGroup("db"); //toutes les clés suivantes appartiendront à la même catégorie db
    settings.setValue("hostname", "localhost");
    settings.setValue("name", "netflux");
    settings.setValue("username", "cinemauser");
    settings.setValue("password", "0000");
    settings.setValue("port", 5432);

    settings.endGroup();

    /*
     * initialisation de l'application
     */

    QApplication a(argc, argv);

    //Création d'un objet base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "dbFilm");

    settings.beginGroup("db");
    db.setHostName(settings.value("hostname", "localhost"/*valeur par défaut si ini non trouvé*/).toString());
    db.setDatabaseName(settings.value("name", "netflux").toString());
    db.setUserName(settings.value("username", "cinemauser").toString());
    db.setPassword(settings.value("password", "postgres123").toString());
    db.setPort(settings.value("port",5432).toInt());

    settings.endGroup();

    qDebug() << db <<endl;

    bool ok = db.open();

            // si ok                    si !ok
    ok ? qDebug()<<"BDD ouvert" : qDebug()<<"non ouvert";

    Widget w;
    w.show();
    return a.exec();
}
