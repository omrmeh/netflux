#ifndef MOVIECARD_H
#define MOVIECARD_H

#include <QWidget>
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
    explicit MovieCard(QWidget *parent = nullptr);
    ~MovieCard();

    void newCard(); //done
    void displayCard(); //to do

private:
    Ui::Form *ui;
   QSqlTableModel* mMovieModel;

private slots:
    void enabledCard(); //done
    void editMovie(); //to do
    void saveMovie(); //to do
    void cancel(); //to do
    void downloadPoster();//To complete: save in db

};

#endif // MOVIECARD_H
