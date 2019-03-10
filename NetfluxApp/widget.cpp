#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    initModel();
    setupView();
    design();
    initFilteredModel();

    //Quitter
    connect(ui->pbExit,SIGNAL(clicked()),this,SLOT(close()));
    //Add
    connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(addMovie()));
    //display
    //remove
    connect(ui->pbRemove, SIGNAL(clicked()), this, SLOT(deleteMovie()));
    //search
    connect(ui->pbGo, SIGNAL(clicked()), this, SLOT(filter()));

    //afficher la fiche d'un film
    connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(displayMovie()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::design()
{
    //comboBox filter
    ui->comboBox->addItem("Title",2);
    ui->comboBox->addItem("Year", 3);

    QImage photoGauche("C:/Users/Dell/Documents/netflux/labelGauche.jpg");
    ui->label_6->setPixmap(QPixmap ::fromImage(photoGauche));

    QImage photoDroite("C:/Users/Dell/Documents/netflux/labelDroit.ico");
    ui->label_10->setPixmap(QPixmap ::fromImage(photoDroite));

    QImage loupe("C:/Users/Dell/Documents/netflux/loupe.png");
    ui->label_3->setPixmap(QPixmap ::fromImage(loupe));
}

void Widget::initModel()
{
    QSqlDatabase db = QSqlDatabase::database("dbFilm");
    mMovieModel = new QSqlTableModel(this, db);

    mMovieModel->setTable("film");
    mMovieModel->select();
    mMovieModel->setHeaderData(2,Qt::Horizontal,"Title");
    mMovieModel->setHeaderData(3,Qt::Horizontal,"Year");
    mMovieModel->setHeaderData(5,Qt::Horizontal,"Poster");
    mMovieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    qDebug() << "interieur initModel";
}

void Widget::displayMovie()
{
   qDebug() << "Je suis dans le display movie";
    MovieCard *card = new MovieCard();
    card->displayCard();
    card->show();
}
void Widget::setupView()
{
    // A revoir

    ui->tableView->setModel(mMovieModel);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->setSortingEnabled(true);
    qDebug() << "interieur setupView";
}

/*void Widget::initFilteringModel()
{
    QSortFilterProxyModel* filteringModel = new QSortFilterProxyModel(this);
    filteringModel->setDynamicSortFilter(true);
    filteringModel->setSourceModel(mMovieModel);
    filteringModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    connect(ui->leSearch, SIGNAL(textChanged(QString)), this, SLOT(filter()));
    ui->tableView->setModel(filteringModel);
}*/

void Widget::filter()
{
    //mMovieFilteredModel = new QSortFilterProxyModel(this);
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

      mMovieModel->removeRow(ui->tableView->currentIndex().row());

//    QSqlDatabase db = QSqlDatabase::database("   ");
//        QSqlQuery query(db);
//      //  QSqlQuery prepare("DELETE FROM FILM WHERE pr_nom='"+ui->leNom->text()+"'");
//        query.exec();

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
    QObject::connect(ui->leSearch, SIGNAL(textChanged(QString)), this, SLOT(filter()));
}

