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

    //Quitter
    connect(ui->pbExit,SIGNAL(clicked()),this,SLOT(close()));

    //Add
    connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(addMovie()));

    //display

    //connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(displayMovie()));
    //connect(mTableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), mapper, SLOT(setCurrentModelIndex(QModelIndex)));

    //connect(****************************************)

    //remove
    connect(ui->pbRemove, SIGNAL(clicked()), this, SLOT(deleteMovie()));



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

    QPixmap photoGauche(":/labelGauche.jpg");
    ui->label_6->setPixmap(photoGauche);

    QImage photoDroite(":/labelDroit.ico");
    ui->label_10->setPixmap(QPixmap ::fromImage(photoDroite));

    QImage loupe(":/loupe.png");
    ui->label_3->setPixmap(QPixmap ::fromImage(loupe));

    QImage posterVide(":/posterVideView.png");
    ui->labPoster->setPixmap(QPixmap ::fromImage(posterVide));
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
    //pour ajouter une securite et que les modif n'y vont pas direct en BDD avt de confirmer
    //mMovieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    qDebug() << "interieur initModel";
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
void Widget::displayMovie()
{

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(mMovieModel);

    //selectionModel: quel model est selectionné
    //current row changed va renseigner (un signal) qu'on a changer de ligne

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
    newCard();
//    MovieCard* emptyCard= new MovieCard();
//    emptyCard->newCard();
//    emptyCard->show();
}

void Widget::editMovie()
{
    enabledCard();
    //to do
}

void Widget::saveMovie()
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
