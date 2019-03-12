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

    leId = new QLineEdit; //LineEdit caché pour pouvoir retrouver le poster correspondant à l'Id du film

    initFilteredModel();
    initMapper();
    disabledCard();

    //Quitter
    connect(ui->pbExit_2,SIGNAL(clicked()),this,SLOT(close()));

    //Add
    connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(addMovie()));

    //save
    connect(ui->pbSave, SIGNAL(clicked()), this, SLOT(saveMovie()));

    //remove
    connect(ui->pbRemove, SIGNAL(clicked()), this, SLOT(deleteMovie()));


    //edit




}

/**
 * @brief Widget::initModel
 */
void Widget::initModel()
{
    QSqlDatabase db = QSqlDatabase::database("dbFilm");
    mMovieModel = new QSqlRelationalTableModel(this, db);

    initCustomSqlModel(db);

    mMovieModel->setTable("film");
    mMovieModel->select();


    //pour ajouter une securite et que les modif n'y vont pas direct en BDD avt de confirmer
    mCustomMovieModel->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);

    qDebug() << "interieur initModel";
}


void Widget::initCustomSqlModel(QSqlDatabase db)
{
    mCustomMovieModel = new CustomSQLModel(this, &db);
    mCustomMovieModel->setTable("film");
    mCustomMovieModel->setRelation(1, QSqlRelation("GENRE", "ID_GENRE", "G_NAME"));
    mCustomMovieModel->setHeaderData(1,Qt::Horizontal,"Genre");
    mCustomMovieModel->setHeaderData(2,Qt::Horizontal,"Title");
    mCustomMovieModel->setHeaderData(3,Qt::Horizontal,"Year");
    mCustomMovieModel->setHeaderData(5,Qt::Horizontal,"Poster");
    mCustomMovieModel->select();
    mCustomMovieModel->fetchUrls();
    mCustomMovieModel->downloadPosters();

}


void Widget::initMapper()
{
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(mMovieFilteredModel);

    mapper->addMapping(ui->labPoster, 5);
    mapper->addMapping(ui->leTitle, 2);
    mapper->addMapping(ui->leRating,4);
    mapper->addMapping(ui->leGenre, 1);
    mapper->addMapping(ui->leYear,3);
    mapper->addMapping(ui->leLength, 7);
    mapper->addMapping(ui->teSynopsis,6);
    mapper->addMapping(leId, 0); //l'id permettant de retrouver le poster adéquat


    connect(ui->tableView->selectionModel(),
            SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            mapper, SLOT(setCurrentModelIndex(QModelIndex)));
}


void Widget::setupView()
{
    // A revoir

    ui->tableView->setModel(mCustomMovieModel);
    ui->tableView->hideColumn(0);
    //ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(6);
    ui->tableView->hideColumn(7);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    qDebug() << "interieur setupView";
}


void Widget::initFilteredModel()
{
    mMovieFilteredModel = new QSortFilterProxyModel(this);
    mMovieFilteredModel->setDynamicSortFilter(true);
    mMovieFilteredModel->setSourceModel(mCustomMovieModel);
    mMovieFilteredModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(mMovieFilteredModel);
    QObject::connect(ui->leSearch, SIGNAL(textChanged(QString)), this, SLOT(filter()));
}


void Widget::filter()
{    
    mMovieFilteredModel->setFilterWildcard(ui->leSearch->text());
    mMovieFilteredModel->setFilterKeyColumn(ui->comboBox->currentData().toInt());

  // ui->labPoster->setPixmap(*(mCustomMovieModel->getPosterAtRow(4)));
    ui->labPoster->setPixmap(*(mCustomMovieModel->getPosterAtKey(leId->text().toInt())));
    qDebug() << leId->text();
    ui->labPoster->update();
}

void Widget::addMovie()
{
//    newCard();
//    enabledCard();
    QImage posterVide(":/posterVideView.png");
    ui->labPoster->setPixmap(QPixmap::fromImage(posterVide));

    mCustomMovieModel->insertRow(mCustomMovieModel->rowCount()); //ajouter une ligne à la fin

}

void Widget::editMovie()
{
    //enabledCard();
    ui->tableView->update();
}

void Widget::saveMovie()
{

    mCustomMovieModel->submitAll();
    //recuperer les infos des lineEdit

        //newCard();
}

void Widget::deleteMovie()
{

    mCustomMovieModel->removeRow(ui->tableView->currentIndex().row());
    mCustomMovieModel->submitAll();
    ui->tableView->update();

}


void Widget::cancel()
{

}


void Widget::downloadPoster()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "c:/", tr("Image Files (*.png *.jpg *.bmp)"));
    QPixmap monImage(fileName);
    ui->labPoster->setPixmap(monImage);
    //save in db
}


void Widget::newCard()
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

}


void Widget::disabledCard()
{
    ui->leTitle->setEnabled(false);
    ui->leTitle->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leRating->setEnabled(false);
    ui->leRating->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leYear->setEnabled(false);
    ui->leYear->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leGenre->setEnabled(false);
    ui->leGenre->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->leLength->setEnabled(false);
    ui->leLength->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
    ui->teSynopsis->setEnabled(false);
    ui->teSynopsis->setStyleSheet("QTextEdit { background : rgb(255, 255, 255);}");

}


void Widget::enabledCard()
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
    ui->comboBox->addItem("Genre",1);

    QImage photoGauche(":/images/labelGauche.jpg");
    ui->labGauche->setPixmap(QPixmap ::fromImage(photoGauche));

    QImage photoDroite(":/images/labelDroit.ico");
    ui->labDroit->setPixmap(QPixmap ::fromImage(photoDroite));

    QImage loupe(":/images/loupe.png");
    ui->labSearch->setPixmap(QPixmap ::fromImage(loupe));

    QImage posterVide(":/images/posterVideView.png");
    ui->labPoster->setPixmap(QPixmap ::fromImage(posterVide));

}
