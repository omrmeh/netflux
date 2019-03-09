#ifndef MOVIECARD_H
#define MOVIECARD_H

#include <QWidget>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include<QSqlQuery>


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

private:
    Ui::Form *ui;
    QSqlTableModel* mMovieModel;

private slots:

    void displayCard();
    void enabledCard();
    void editMovie();
    void saveMovie();
    void cancel();

};

#endif // MOVIECARD_H
