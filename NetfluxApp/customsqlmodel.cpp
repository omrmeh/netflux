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
         urls.append(this->index(i, 5).data().toString());
}


/**
 * @brief : - Lance les téléchargements des posters à partir de la liste des urls
 */
void CustomSQLModel::downloadPosters()
{
    for(QString url:urls)
    {
       QUrl imageUrl(url);
       FileDownloader *downloader = new FileDownloader(imageUrl, this);
       downloaders.append(downloader);
       connect(downloader, SIGNAL (downloaded()), this, SLOT (loadPosters()));
    }
}


QVector<QPixmap *> CustomSQLModel::getPxmBuffer()
{
    return pxmBuffer;
}

QPixmap *CustomSQLModel::getPosterAtRow(int row)
{
    qDebug() << pxmBuffer.at(row);
    return pxmBuffer.at(row);
}

QPixmap *CustomSQLModel::getPosterAtKey(int key)
{
    return pxmMapBuffer[key];
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
    pxmMapBuffer[pxmBuffer.indexOf(poster)]=poster; /* si on part du principe que les pixmaps seront téléchargés dans le même
                                                        ordre qu'ont été fetchées les urls */
}



