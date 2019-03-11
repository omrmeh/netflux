#ifndef MOVIECARD_H
#define MOVIECARD_H

#include <QWidget>


#include <QSortFilterProxyModel>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include<QSqlQuery>
#include<QFileDialog>



namespace Ui {
class Form;
}

class MovieCard : public QWidget
{
    Q_OBJECT

public:
    explicit MovieCard(QWidget *parent = nullptr, QDataWidgetMapper *mapper=nullptr, QSortFilterProxyModel *sortingModel=nullptr);
    ~MovieCard();
    void newCard();

private:
    Ui::Form *ui;
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
