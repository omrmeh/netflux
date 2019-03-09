#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //comboBox filter
    ui->comboBox->addItem("Title",1);
    ui->comboBox->addItem("Genre", 2);



    //Quitter
    connect(ui->pbExit,SIGNAL(clicked()),this,SLOT(close()));

    connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(openNewCard()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::openNewCard()
{
   MovieCard* emptyCard= new MovieCard();
   emptyCard->newCard();

   emptyCard->show();
   //emptyCard->newCard();

}


