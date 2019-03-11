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
    connect(ui->pbEdit, SIGNAL(clicked()), this, SLOT(enabledCard()));

}






void Widget::initModel()
{
    QSqlDatabase db = QSqlDatabase::database("dbFilm");
    mMovieModel = new QSqlTableModel(this, db);

    initCustomSqlModel(db);

    mMovieModel->setTable("film");
    mMovieModel->select();
    mMovieModel->setHeaderData(1,Qt::Horizontal,"Genre");
    mMovieModel->setHeaderData(2,Qt::Horizontal,"Title");
    mMovieModel->setHeaderData(3,Qt::Horizontal,"Year");
    mMovieModel->setHeaderData(5,Qt::Horizontal,"Poster");

    //pour ajouter une securite et que les modif n'y vont pas direct en BDD avt de confirmer
    mMovieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);


    qDebug() << "interieur initModel";
}


void Widget::initCustomSqlModel(QSqlDatabase db)
{
    mCustomMovieModel = new CustomSQLModel(this, &db);
    mCustomMovieModel->setTable("film");
    mCustomMovieModel->setRelation(1, QSqlRelation("GENRE", "ID_GENRE", "G_NAME"));
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
    ui->pbDownload->hide();
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
}

void Widget::addMovie()
{
    newCard();
    enabledCard();
    QImage posterVide("C:/Users/Dell/Documents/netflux/posterVideView.png");
    ui->labPoster->setPixmap(QPixmap ::fromImage(posterVide));
    ui->pbDownload->show();

}

void Widget::editMovie()
{
    enabledCard();
}

void Widget::saveMovie()
{

    mMovieModel->submitAll();
    //newCard();
}

void Widget::deleteMovie()
{

    mMovieModel->removeRow(ui->tableView->currentIndex().row());
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
    ui->pbDownload->setStyleSheet("QPushButton { color: rgb(255, 255, 255); background : rgb(0, 0, 99);}");
    ui->pbEdit->setDisabled(true);
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
    ui->pbDownload->setStyleSheet("QPushButton { color: rgb(255, 255, 255); background : rgb(0, 0, 99);}");
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
    ui->pbDownload->setStyleSheet("QPushButton { color: rgb(255, 255, 255); background : rgb(0, 0, 99);}");
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




    QImage photoGauche("C:/Users/Dell/Documents/netflux/labelGauche.jpg");
    ui->labGauche->setPixmap(QPixmap ::fromImage(photoGauche));

    QImage photoDroite("C:/Users/Dell/Documents/netflux/labelDroit.ico");
    ui->labDroit->setPixmap(QPixmap ::fromImage(photoDroite));

    QImage loupe("C:/Users/Dell/Documents/netflux/loupe.png");
    ui->labSearch->setPixmap(QPixmap ::fromImage(loupe));

    QImage posterVide("C:/Users/Dell/Documents/netflux/posterVideView.png");
    ui->labPoster->setPixmap(QPixmap ::fromImage(posterVide));
    ui->pbDownload->show();
}
