#ifndef MOVIECARD_H
#define MOVIECARD_H

#include <QWidget>

namespace Ui {
class MovieCard;
}

class MovieCard : public QWidget
{
    Q_OBJECT

public:
    explicit MovieCard(QWidget *parent = nullptr);
    ~MovieCard();

private:
    Ui::MovieCard *ui;
};

#endif // MOVIECARD_H
