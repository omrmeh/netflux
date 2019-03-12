#ifndef WIDGET_H
#define WIDGET_H
#include <moviecard.h>
#include <QSqlTableModel>

#include <QSortFilterProxyModel>
#include <QModelIndex>
#include<QDataWidgetMapper>
#include<QDebug>
#include <QWidget>

#include <QSqlRelationalDelegate>

#include <QLineEdit>


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

    void initCustomSqlModel(QSqlDatabase db);

private:
    Ui::Widget *ui;
    QDataWidgetMapper *mapper;
    QSqlTableModel* mMovieModel;
    CustomSQLModel* mCustomMovieModel;
    QSortFilterProxyModel *mMovieFilteredModel;
    QLineEdit *leId;

private slots:

    void design();//fait
    void initModel();//fait
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



};

#endif // WIDGET_H
