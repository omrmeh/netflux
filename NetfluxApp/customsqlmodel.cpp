#include "customsqlmodel.h"


CustomSQLModel::CustomSQLModel(QObject* parent, QSqlDatabase *db):QSqlRelationalTableModel(parent, *db)
{
     qDebug() << "constructor" << endl;
}

/**
 * @brief : - Récupère les url de la BDD et les stocks dans urls
 */
void CustomSQLModel::fetchUrls()
{
    qDebug() << "fetching urls ..." << endl;
    urls.clear();

    for(int i=0; i<this->rowCount(); i++)
    {
         urls.append(this->index(i, 5).data().toString());
         qDebug() << this->index(i, 5).data().toString() << endl;
    }
}


/**
 * @brief : - Lance les téléchargements des posters à partir de la liste des urls
 */
void CustomSQLModel::downloadPosters()
{
    for(QString url:urls)
    {
       QUrl imageUrl(url);
       qDebug() << url;
       FileDownloader *downloader = new FileDownloader(imageUrl, this);
       downloaders.append(downloader);
       connect(downloader, SIGNAL (downloaded()), this, SLOT (loadPosters()));
    }
}

/**
 * @brief : -Génère les pixmaps correspondant aux posters téléchargés
 *          -Les stocke dans pxmBuffer
 */
void CustomSQLModel::loadPosters()
{
    qDebug() << "loading posters... " << endl;
    FileDownloader* downloader = (FileDownloader*)sender(); //on récupère le downloader ayant émis le signal
    QPixmap* poster = new QPixmap;
    poster->loadFromData(downloader->downloadedData());
    pxmBuffer.append(poster);
}



