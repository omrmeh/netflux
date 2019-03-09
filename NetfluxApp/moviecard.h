#ifndef MOVIECARD_H
#define MOVIECARD_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QSortFilterProxyModel>

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
    void setUpMapper();

    Ui::Form *getUi();

private:
    Ui::Form *ui;
    QDataWidgetMapper *mMapper;
    QSortFilterProxyModel *mSortingModel;

private slots:


    void enabledCard();
    void editMovie();
    void saveMovie();

};

#endif // MOVIECARD_H
