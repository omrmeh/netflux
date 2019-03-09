#include "moviecard.h"
#include "ui_moviecard.h"

MovieCard::MovieCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


    //Quitter
    connect(ui->pbExit,SIGNAL(clicked()),this,SLOT(close()));
    //Edit
    connect(ui->pbEdit,SIGNAL(clicked()),this,SLOT(enabledCard()));
    connect(ui->pbEdit,SIGNAL(clicked()),this,SLOT(EditMovie()));
}

MovieCard::~MovieCard()
{
    delete ui;
}

void MovieCard::newCard()
{
    ui->leTitle->clear();
    ui->leTitle->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leRating->clear();
    ui->leRating->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leYear->clear();
    ui->leYear->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leGenre->clear();
    ui->leGenre->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leLength->clear();
    ui->leLength->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->teSynopsis->clear();
    ui->teSynopsis->setStyleSheet("QTextEdit { background : rgb(255, 255, 255);}");
    ui->pbImage->setStyleSheet("QPushButton { color: rgb(255, 255, 255); background : rgb(0, 0, 99);}");

  //  ui->pbImage->hide();
}

void MovieCard::enabledCard()
{
    ui->leTitle->setEnabled(true);
    ui->leTitle->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leRating->setEnabled(true);
    ui->leRating->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leYear->setEnabled(true);
    ui->leYear->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leGenre->setEnabled(true);
    ui->leGenre->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leLength->setEnabled(true);
    ui->leLength->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->teSynopsis->setEnabled(true);
    ui->teSynopsis->setStyleSheet("QTextEdit { background : rgb(255, 255, 255);}");
    ui->pbImage->setStyleSheet("QPushButton { color: rgb(255, 255, 255); background : rgb(0, 0, 99);}");
}
void MovieCard::editMovie()
{
    enabledCard();
    //to do
}

void MovieCard::saveMovie()
{

}


