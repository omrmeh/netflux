#ifndef WIDGET_H
#define WIDGET_H
#include <moviecard.h>
#include <QSqlTableModel>

#include <QSortFilterProxyModel>
#include <QModelIndex>
#include<QDataWidgetMapper>
#include<QDebug>
#include <QWidget>
#include <QSqlRelationalTableModel>


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


private:
    Ui::Widget *ui;
    QSqlRelationalTableModel* mMovieModel;
    QSortFilterProxyModel *mMovieFilteredModel;

private slots:

    void design();//fait
    void initModel();//fait
    void setupView();//A adapter (ordre des colonnes)

    void filter();//fait
    void displayMovie(); //to do
    void addMovie();//to do
    void deleteMovie();//to do




};

#endif // WIDGET_H
