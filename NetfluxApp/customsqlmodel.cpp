#include "customsqlmodel.h"


CustomSQLModel::CustomSQLModel(QObject* parent, QSqlDatabase *db):QSqlRelationalTableModel(parent, *db)
{
     qDebug() << "constructor" << endl;
}

/**
 * @brief : - Récupère les url de la BDD et les stocks dans urls
 *          - urls est un QMap associant une clé correspondant à
 * l'id du film avec l'url du film correspondant
 */
void CustomSQLModel::fetchUrls()
{
    qDebug() << "fetching urls ..." << endl;
    urls.clear();

    for(int i=0; i<this->rowCount(); i++)
         urls[this->index(i,0/*colonne de l'id_film dans le modèle*/).data().toInt()]=this->index(i,9/*colonne de l'url dans le modèle*/).data().toString();

}


/**
 * @brief : - Lance les téléchargements des posters à partir de la liste des urls
 *          - chaque Url va construire sa propre requête, qui servira à créer son
 * propre objet de type FileDownloader
 *          - Ce FileDownloader sera stocké dans le QMap downloaders à la même clé
 * que celle correspondant à son url dans le QMap urls
 */
void CustomSQLModel::downloadPosters()
{
    qDebug() << "downloading posters..." <<endl;
    for(int key:urls.keys())
    {
       QUrl imageUrl(urls[key]);
       qDebug() << urls[key];
       FileDownloader *downloader = new FileDownloader(imageUrl, this);
       downloaders[key] = downloader;  //la key correspond à l'id_film et la valeur à un ptr sur un downloader
       connect(downloader, SIGNAL (downloaded()), this, SLOT (loadPosters()));
    }
}


QPixmap *CustomSQLModel::getPosterAtKey(int key)
{
    return pixmapBuffer[key];
}

/**
 * @brief affiche pixmapBuffer dans le qDebug()
 */
void CustomSQLModel::printBufferMap()
{
    qDebug() << pixmapBuffer << endl;
}

void CustomSQLModel::printTable()
{
    for(int i=0; i<this->rowCount(); i++)
       {
        for(int j=0; j<this->columnCount(); j++)
           qDebug() << this->index(i, j).data().toString() <<endl;
        }
}

/**
 * @brief : - Méthode SLOT appelée lorsque un downloader a terminé de télécharger
 * l'image
 *          - Elle génère un pixmap à partir de la donnée téléchargée
 *          - La pixmap est stockée dans le pixmapBuffer, à la même clé que la clé
 * à laquelle était stockée le FileDownloader correspondant dans downloaders
 */
void CustomSQLModel::loadPosters()
{
    qDebug() << "loading posters :))... " << endl;

    FileDownloader* downloader = (FileDownloader*)sender();//on récupère le downloader ayant émis le signal

    QPixmap* poster = new QPixmap;

    poster->loadFromData(downloader->downloadedData());

    for(int key:downloaders.keys())
    {/*
     * on cherche à quelle id de film correspond le downloader ayant
     * émis le signal
     */
        if(downloaders[key]==downloader)
            pixmapBuffer[key]=poster;  //la key correspond à l'id_film, la valeur à la pixmap
    }
}



