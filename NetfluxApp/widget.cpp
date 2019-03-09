#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    design();

    QSqlDatabase db = QSqlDatabase::database("dbFilm");

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

    connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(addMovie()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::design()
{
    QImage photoGauche("C:/Users/Dell/Documents/netflux/labelGauche.jpg");
    ui->label_6->setPixmap(QPixmap ::fromImage(photoGauche));

    QImage photoDroite("C:/Users/Dell/Documents/netflux/labelDroit.ico");
    ui->label_10->setPixmap(QPixmap ::fromImage(photoDroite));

    QImage loupe("C:/Users/Dell/Documents/netflux/loupe.png");
    ui->label_3->setPixmap(QPixmap ::fromImage(loupe));
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

void Widget::addMovie()
{
    MovieCard* emptyCard= new MovieCard();
    emptyCard->newCard();
    emptyCard->show();
}



void Widget::deleteMovie()
{
    //    QSqlDatabase db = QSqlDatabase::database("   ");
    //    QSqlQuery query(db);
    //    QSqlQuery prepare("DELETE FROM produit WHERE pr_nom='"+ui->leNom->text()+"'");
    //    query.exec();

    //    QListWidgetItem* item = ui->listWidget->currentItem();
    //    ui->listWidget->removeItemWidget(item);
    //    delete item;
    //    refresh();
}



