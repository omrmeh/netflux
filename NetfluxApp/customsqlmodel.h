#ifndef CUSTOMSQLMODEL_H
#define CUSTOMSQLMODEL_H

#include <QSqlTableModel>
#include <QPixmap>
#include "filedownloader.h"

class CustomSQLModel : public QSqlTableModel
{
public:
    CustomSQLModel(QObject* parent = nullptr, QSqlDatabase* =nullptr);

private:
    QVector<QPixmap*> pxmBuffer;
    FileDownloader *mFileDl;

private slots:
    void loadImage();
};

#endif // CUSTOMSQLMODEL_H
