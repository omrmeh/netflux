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

private:
    Ui::Form *ui;
};

#endif // MOVIECARD_H
