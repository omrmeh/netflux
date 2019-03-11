#include "widget.h"
#include "ui_widget.h"

#include "stardelegate.h"
#include "StarRating.h"

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
    //connect(****************************************)

    //remove
    connect(ui->pbRemove, SIGNAL(clicked()), this, SLOT(deleteMovie()));

    //search
    connect(ui->pbGo, SIGNAL(clicked()), this, SLOT(filter()));
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

    QImage photoGauche(":/labelGauche.jpg");
    ui->label_6->setPixmap(QPixmap ::fromImage(photoGauche));

    QImage photoDroite(":/labelDroit.ico");
    ui->label_10->setPixmap(QPixmap ::fromImage(photoDroite));

    QImage loupe(":/loupe.png");
    ui->label_3->setPixmap(QPixmap ::fromImage(loupe));
}

void Widget::initModel()
{
    QSqlDatabase db = QSqlDatabase::database("netflux");
    mMovieModel = new QSqlRelationalTableModel(this, db);

    mMovieModel->setTable("film");
    mMovieModel->select();
    mMovieModel->setHeaderData(2,Qt::Horizontal,"Title");
    mMovieModel->setHeaderData(3,Qt::Horizontal,"Year");
    mMovieModel->setHeaderData(5,Qt::Horizontal,"Poster");
    mMovieModel->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);

    //Ajout de la relation entre la table film et la table Genre
    mMovieModel->setRelation(1, QSqlRelation("GENRE", "ID_GENRE", "G_NAME"));

    qDebug() << "interieur initModel";
}

void Widget::displayMovie()
{

    MovieCard *card = new MovieCard();
    card->displayCard();
    card->show();

    //voir ou connecter les 2 fenetres
    //    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    //    mapper->setModel(mProduitsModel);
    //    mapper->addMapping(ui->leNom, 1);
    //    mapper->addMapping(ui->leCode,2);
    //    mapper->addMapping(ui->lePrix,3);
    //    mapper->addMapping(ui->leQtite,4);

    //    //selectionModel: quel model est selectionné
    //    //current row changed va renseigner (un signal) qu'on a changer de ligne

    //    connect(ui->listView->selectionModel(),
    //            SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
    //            mapper, SLOT(setCurrentModelIndex(QModelIndex)));
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

    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView)); //Permet d'avoir une combobox des genres. Doit ajouter possibilité de rentrer un genre.

    //************mettre en place de la starDelegate ici *****************************
    //ui->tableView->setItemDelegate(StarRating());

    qDebug() << "interieur setupView";
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
