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

    settings.setValue("db/hostname", "localhost");
    settings.setValue("db/name", "netflux");
    settings.setValue("db/username", "cinemauser");
    settings.setValue("db/password", "0000");
    settings.setValue("db/port", 5432);

    /*
     *
     */

    QApplication a(argc, argv);

    //Création d'un objet base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", "dbFilm");


    db.setHostName(settings.value("db/hostname", "localhost"/*valeur par défaut si ini non trouvé*/).toString());
    db.setDatabaseName(settings.value("db/name", "netflux").toString());
    db.setUserName(settings.value("db/username", "cinemauser").toString());
    db.setPassword(settings.value("db/password", "postgres123").toString());
    db.setPort(settings.value("db/port",5432).toInt());

    qDebug() << db <<endl;

    bool ok = db.open();

            // si ok                    si !ok
    ok ? qDebug()<<"BDD ouvert" : qDebug()<<"non ouvert";

    Widget w;
    w.show();
    return a.exec();
}
