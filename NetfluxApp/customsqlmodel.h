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

    QVector<QPixmap *> getPxmBuffer();

    QPixmap* getPosterAtRow(int);

private:
    QVector<QPixmap*> pxmBuffer;
    QVector<FileDownloader*> downloaders;
    FileDownloader *mFileDl;
    QStringList urls;

private slots:
    void loadPosters();
};

#endif // CUSTOMSQLMODEL_H