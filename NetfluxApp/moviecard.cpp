#include "moviecard.h"
#include "ui_moviecard.h"

MovieCard::MovieCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::database("dbFilm");
    mMovieModel= new QSqlTableModel(this, db);
    mMovieModel->setTable("dbFilm");

    //Quitter
    connect(ui->pbExit,SIGNAL(clicked()),this,SLOT(close()));
    //Edit
    connect(ui->pbEdit,SIGNAL(clicked()),this,SLOT(enabledCard()));
    connect(ui->pbEdit,SIGNAL(clicked()),this,SLOT(editMovie()));
    //save
    connect(ui->pbSave, SIGNAL(clicked()),this,SLOT(saveMovie()));
    //dwonload poster
    connect(ui->pbPoster, SIGNAL(clicked()),this,SLOT(downloadPoster()));
}

MovieCard::~MovieCard()
{
    delete ui;
}
void MovieCard::displayCard()
{
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(mMovieModel);

    mapper->addMapping(ui->labPoster, 5);
    mapper->addMapping(ui->leTitle, 2);
    mapper->addMapping(ui->leRating,4);
    mapper->addMapping(ui->leGenre, 1);
    mapper->addMapping(ui->leYear,3);
    mapper->addMapping(ui->leLength, 7);
    mapper->addMapping(ui->teSynopsis,6);
    ui->pbPoster->hide();
}

void MovieCard::newCard()
{
    QImage posterVide("C:/Users/Dell/Documents/netflux/posterVideView.png");
    ui->labPoster->setPixmap(QPixmap ::fromImage(posterVide));

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
    ui->pbPoster->setStyleSheet("QPushButton { color: rgb(255, 255, 255); background : rgb(0, 0, 99);}");
    ui->pbEdit->setDisabled(true);
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
    ui->pbPoster->setStyleSheet("QPushButton { color: rgb(255, 255, 255); background : rgb(0, 0, 99);}");
}
void MovieCard::editMovie()
{
    enabledCard();
    //to do
}

void MovieCard::saveMovie()
{   

    mMovieModel->submitAll();


//    QSqlQuery query(db);
//    query.prepare("INSERT INTO film (f_title, f_ratings, f_year, f_length) VALUES (?, ?, ?, ?)");

//    query.addBindValue(ui->leTitle->text());
//    query.addBindValue(ui->leRating->text().toInt());
//    query.addBindValue(ui->leYear->text().toInt());
//    query.addBindValue(ui->leLength->text().toInt());
    //query.addBindValue(ui->teSynopsis->text());
    // query.addBindValue(ui->labPoster->text());

//    query.exec();

    //    qDebug() << query.lastQuery() << query.lastError().text();
    //upDate la 1ere fenetre
    //    QListWidgetItem* item = new QListWidgetItem(ui->leNom->text());
    //    ui->listWidget->addItem(item);
}

void MovieCard::cancel()
{

}

void MovieCard::downloadPoster()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "c:/", tr("Image Files (*.png *.jpg *.bmp)"));
    QPixmap monImage(fileName);
    ui->labPoster->setPixmap(monImage);
}


