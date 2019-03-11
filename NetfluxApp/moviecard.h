#ifndef MOVIECARD_H
#define MOVIECARD_H

#include <QWidget>
#include <QDebug>

#include <QSortFilterProxyModel>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include<QSqlQuery>
#include<QFileDialog>
#include <QTableView>



namespace Ui {
class MovieCard;
}

class MovieCard : public QWidget
{
    Q_OBJECT

public:

    explicit MovieCard(QWidget *parent = nullptr, QSortFilterProxyModel *sortingModel=nullptr, QTableView* tableview = nullptr);

    ~MovieCard();
    void newCard();
    void displayCard();

private:

    Ui::MovieCard *ui;
    QTableView* mTableView;

    QDataWidgetMapper *mMapper;
    QSortFilterProxyModel *mSortingModel;
    QSqlTableModel* mMovieModel;
    
private slots:
    void enabledCard(); //done
    void editMovie(); //to do
    void saveMovie(); //to do
    void cancel(); //to do
    void downloadPoster();//To complete: save in db

};

#endif // MOVIECARD_H
