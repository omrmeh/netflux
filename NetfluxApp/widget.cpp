#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    //connexion DDB & TableView
//    ui->setupUi(this);
//    //on se connecte à la BDD
//    QSqlDatabase db = QSqlDatabase::database("     ");
//    //on fait un new model de table sql
//    mMovieModel= new QSqlTableModel(this, db);
//    //je set la table produit de la bdd
//    mMovieModel->setTable("   ");
//    //select pour selectionne toutes les donnees
//    mMovieModel->select();

    //on met dans notre tableview notre model
    ui->tableView->setModel(mMovieModel);

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

//Widget::initModel()
//{
//    mMovieModel = new QSqlTableModel(this, db);
//    mMovieModel->setTable("Movie");
//    mMovieModel->select();
//}

void Widget::setupView()
{
 ui->tableView->setModel(mMovieModel);
  //ui->tableView->hideColumn()
 ui->tableView->setSortingEnabled(true);
}

void Widget::initFilteringModel()
{
    QSortFilterProxyModel* filteringModel = new QSortFilterProxyModel(this);
    filteringModel->setDynamicSortFilter(true);
    filteringModel->setSourceModel(mMovieModel);
    filteringModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
}


void Widget::openNewCard()
{
    MovieCard* emptyCard= new MovieCard();
    emptyCard->newCard();

    emptyCard->show();
    //emptyCard->newCard();

}


