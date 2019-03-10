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

    void newCard();
    void displayCard();

private:
    Ui::Form *ui;
   QSqlTableModel* mMovieModel;



private slots:


    void enabledCard();
    void editMovie();
    void saveMovie();
    void cancel();
    void downloadPoster();

};

#endif // MOVIECARD_H
