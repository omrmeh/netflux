#ifndef WIDGET_H
#define WIDGET_H
#include <moviecard.h>

#include <QSortFilterProxyModel>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QWidget>
#include <QDataWidgetMapper>
#include <QDebug>


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
    void setupView();
    void initFilteringModel();
    void initMapper();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    QSqlTableModel* mFilmsModel;
    QSortFilterProxyModel* filteringModel;
    QDataWidgetMapper *mapper;

private slots:
    void openNewCard();

};

#endif // WIDGET_H
