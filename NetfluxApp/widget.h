#ifndef WIDGET_H
#define WIDGET_H
#include <moviecard.h>

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

private slots:
    void openNewCard();

};

#endif // WIDGET_H
