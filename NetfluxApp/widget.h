#ifndef WIDGET_H
#define WIDGET_H


#include <QSqlTableModel>

#include <QSortFilterProxyModel>
#include <QModelIndex>
#include <QDataWidgetMapper>
#include <QDebug>
#include <QWidget>
#include <QValidator>
#include <QSqlRecord>

#include <QSqlRelationalDelegate>

#include <QLineEdit>
#include <QMessageBox>

#include <moviecard.h>
#include <customsqlmodel.h>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void initFilteredModel();//fait


    void initMapper();

    void initCustomSqlModel();

    void initCustomPersonSqlModel();

private:
    Ui::Widget *ui;
    QDataWidgetMapper *mapper;
    CustomSQLModel* mCustomMovieModel;
    CustomSQLModel* mCustomPersonModel;
    QSortFilterProxyModel *mMovieFilteredModel;
    QLineEdit *leId;
    QSqlDatabase db;

private slots:

    void design();//fait
    void setupView();//A adapter (ordre des colonnes)

    void filter();//fait
    void addMovie();//to do
    void editMovie();
    void deleteMovie();//to do
    void newCard();
    void disabledCard();
    void enabledCard();
    void saveMovie();
    void downloadPoster();
    void cancel();
    void changePoster();
    void formatLength();


};

#endif // WIDGET_H
