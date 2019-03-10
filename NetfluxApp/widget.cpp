#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::database("dbFilm");
    mMovieModel = new QSqlTableModel(this, db);
    mMovieModel->setTable("film");
    mMovieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    mMovieModel->select();

     qDebug() << "interieur initModel";



    ui->tableView->setModel(mMovieModel);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);

    ui->tableView->setSortingEnabled(true);
    ui->tableView->show();

    qDebug() << "interieur setupView";
    //QSqlDatabase db = QSqlDatabase::database("bdFilm");
//    initModel();
//    qDebug()<<"initModel";
//    setupView();
//    qDebug()<<"BDD setupView";
    design();

    //Quitter
    QObject::connect(ui->pbExit,SIGNAL(clicked()),this,SLOT(close()));
    //Add
    QObject::connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(addMovie()));
    //display
    //remove
    QObject::connect(ui->pbRemove, SIGNAL(clicked()), this, SLOT(deleteMovie()));
    //search
    QObject::connect(ui->pbGo, SIGNAL(clicked()), this, SLOT(filter()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::design()
{
    //comboBox filter
    ui->comboBox->addItem("Title",1);
    ui->comboBox->addItem("Genre", 2);

    QImage photoGauche("C:/Users/Dell/Documents/netflux/labelGauche.jpg");
    ui->label_6->setPixmap(QPixmap ::fromImage(photoGauche));

    QImage photoDroite("C:/Users/Dell/Documents/netflux/labelDroit.ico");
    ui->label_10->setPixmap(QPixmap ::fromImage(photoDroite));

    QImage loupe("C:/Users/Dell/Documents/netflux/loupe.png");
    ui->label_3->setPixmap(QPixmap ::fromImage(loupe));
}

//void Widget::initModel()
//{
//    QSqlDatabase db = QSqlDatabase::database("bdFilm");
//    mMovieModel = new QSqlTableModel(this, db);
//    mMovieModel->setTable("film");
//    mMovieModel->select();
//    mMovieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
//     qDebug() << "interieur initModel";

//    ui->tableView->setModel(mMovieModel);
//    ui->tableView->hideColumn(0);
//    ui->tableView->setSortingEnabled(true);

//    qDebug() << "interieur setupView";
//}

void Widget::initFilteringModel()
{
    QSortFilterProxyModel* filteringModel = new QSortFilterProxyModel(this);
    filteringModel->setDynamicSortFilter(true);
    filteringModel->setSourceModel(mMovieModel);
    filteringModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
}

void Widget::filter()
{
    mMovieFilteredModel->setFilterWildcard(ui->leSearch->text());
    mMovieFilteredModel->setFilterKeyColumn(ui->comboBox->currentData().toInt());
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

void Widget::initFilteredModel()
{
    mMovieFilteredModel = new QSortFilterProxyModel(this);
    mMovieFilteredModel->setDynamicSortFilter(true);
    mMovieFilteredModel->setSourceModel(mMovieModel);
    mMovieFilteredModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(mMovieFilteredModel);
}

