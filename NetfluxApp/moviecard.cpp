#include "moviecard.h"
#include "ui_moviecard.h"

MovieCard::MovieCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

MovieCard::~MovieCard()
{
    delete ui;
}
