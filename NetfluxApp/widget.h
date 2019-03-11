#ifndef WIDGET_H
#define WIDGET_H
#include <moviecard.h>
#include <QSqlTableModel>

#include <QSortFilterProxyModel>
#include <QModelIndex>
#include<QDataWidgetMapper>
#include<QDebug>
#include <QWidget>


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

private:
    Ui::Widget *ui;
    QDataWidgetMapper *mapper;
    QSqlTableModel* mMovieModel;
    QSortFilterProxyModel *mMovieFilteredModel;

private slots:

    void design();//fait
    void initModel();//fait
    void setupView();//A adapter (ordre des colonnes)

    void filter();//fait
    void displayMovie(); //to do
    void addMovie();//to do
    void editMovie();
    void deleteMovie();//to do
    void newCard();
    void disabledCard();
    void enabledCard();
    void saveMovie();
    void downloadPoster();
    void cancel();



};

#endif // WIDGET_H
