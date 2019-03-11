#include "customsqlmodel.h"




CustomSQLModel::CustomSQLModel(QObject* parent, QSqlDatabase *db)
{
    QSqlTableModel(parent, *db);
    QUrl imageUrl("http://qt.digia.com/Documents/1/QtLogo.png");
    mFileDl = new FileDownloader(imageUrl, this);

    connect(mFileDl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

void CustomSQLModel::loadImage()
{
    QPixmap buttonImage;
    buttonImage.loadFromData(mFileDl->downloadedData());
}


