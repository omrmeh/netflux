#ifndef CUSTOMSQLMODEL_H
#define CUSTOMSQLMODEL_H

#include <QSqlTableModel>
#include <QPixmap>
#include "filedownloader.h"
#include <QDebug>

class CustomSQLModel : public QSqlTableModel
{
public:
    CustomSQLModel(QObject* parent = nullptr, QSqlDatabase* =nullptr);
    void fetchUrls();
    void downloadPosters();

private:
    QVector<QPixmap*> pxmBuffer;
    QVector<FileDownloader*> downloaders;
    FileDownloader *mFileDl;
    QStringList urls;

private slots:
    void loadPosters();
};

#endif // CUSTOMSQLMODEL_H
