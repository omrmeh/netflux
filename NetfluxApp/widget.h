#ifndef WIDGET_H
#define WIDGET_H
#include <moviecard.h>
#include <QSqlTableModel>
#include<QDataWidgetMapper>
#include <QSortFilterProxyModel>


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

private:
    Ui::Widget *ui;
    QSqlTableModel* mMovieModel;


private slots:

    //void initModel();
    void design();
    void setupView();
    void initFilteringModel();
    void addMovie();
    void deleteMovie ();



};

#endif // WIDGET_H
