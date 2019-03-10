#ifndef WIDGET_H
#define WIDGET_H
#include <moviecard.h>
#include <QSqlTableModel>

#include <QSortFilterProxyModel>

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
    void initModel();
  // void setupView();
    void design();
    void initFilteredModel();
private:
    Ui::Widget *ui;
    QSqlTableModel* mMovieModel;
    QSortFilterProxyModel *mMovieFilteredModel;




private slots:

    void filter();
    void initFilteringModel();
    void addMovie();
    void deleteMovie();




};

#endif // WIDGET_H
