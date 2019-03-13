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

#include <QFormLayout>
#include <QLineEdit>

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

    void initMovieFilter();//fait


    void initMovieMapper();

    void initCustomSqlModel();

    void initCustomPersonSqlModel();

    void initPersonMapper();

    void initPersonFilter();

    void displayPersonCard();

private:
    Ui::Widget *ui;
    QDataWidgetMapper *mapper;
    CustomSQLModel* mCustomMovieModel;
    CustomSQLModel* mCustomPersonModel;
    QSortFilterProxyModel *mMovieFilteredModel;
    QLineEdit *leId;
    QSqlDatabase db;
    QFormLayout* personForm;
    QSortFilterProxyModel* mPersonFilteredModel;

private slots:

    void design();//fait
    void setupViewMovies();//A adapter (ordre des colonnes)

    void setupViewPersons();

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

    void displayTableViewMovies();
    void displayTableViewPersons();


};

#endif // WIDGET_H
