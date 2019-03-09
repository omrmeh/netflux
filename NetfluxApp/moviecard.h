#ifndef MOVIECARD_H
#define MOVIECARD_H

#include <QWidget>

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

private slots:


    void enabledCard();
    void editMovie();
    void saveMovie();

};

#endif // MOVIECARD_H
