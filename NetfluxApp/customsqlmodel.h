#ifndef CUSTOMSQLMODEL_H
#define CUSTOMSQLMODEL_H

#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QPixmap>
#include "filedownloader.h"
#include <QDebug>
#include <QObject>

class CustomSQLModel : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    CustomSQLModel(QObject* parent = nullptr, QSqlDatabase* =nullptr);
    void fetchUrls();
    void downloadPosters();

    QPixmap *getPosterAtKey(int title);

    void printBufferMap();

private:

    QMap<int, FileDownloader*> downloaders;

    QMap<int, QPixmap*> pixmapBuffer;

    FileDownloader *mFileDl;

    QMap<int, QString> urls;

private slots:
    void loadPosters();
};

#endif // CUSTOMSQLMODEL_H
