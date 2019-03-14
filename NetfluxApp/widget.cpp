#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    db = QSqlDatabase::database("dbFilm");

    /*
     * initialisation de l'IHM
     */
    ui->setupUi(this);

    /*
     * initialisation des 2 modèles
     */
    initCustomMovieSqlModel();
    initCustomPersonSqlModel();

    leId = new QLineEdit; //LineEdit caché pour pouvoir retrouver le poster correspondant à l'Id du film


   displayTableViewPersons();
   displayTableViewMovies();

}

/**
 * @brief initialisation du movieModel
 */
void Widget::initCustomMovieSqlModel()
{
    mCustomMovieModel = new CustomSQLModel(this, &db);
    mCustomMovieModel->setTable("film");
    mCustomMovieModel->printTable();

    //À maj en fonction de la base de donnée
    mCustomMovieModel->setRelation(3, QSqlRelation("GENRE", "ID_GENRE", "G_NAME"));
    mCustomMovieModel->setRelation(5, QSqlRelation("PERSONNE", "ID_PERSONNE", "P_SURNAME"));

    mCustomMovieModel->setHeaderData(3,Qt::Horizontal,"Genre");
    mCustomMovieModel->setHeaderData(1,Qt::Horizontal,"Title");
    mCustomMovieModel->setHeaderData(2,Qt::Horizontal,"Year");
    mCustomMovieModel->setHeaderData(4,Qt::Horizontal,"Ratings");
    //pose prob
    //mCustomMovieModel->setHeaderData(5,Qt::Horizontal,"Director");
    mCustomMovieModel->setHeaderData(6,Qt::Horizontal,"Url Poster");
    mCustomMovieModel->setHeaderData(7,Qt::Horizontal,"Synopsis");
    mCustomMovieModel->setHeaderData(8,Qt::Horizontal,"Length");
    mCustomMovieModel->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);

    mCustomMovieModel->select();
    mCustomMovieModel->fetchUrls(6);
    mCustomMovieModel->downloadPosters();
}

void Widget::initCustomPersonSqlModel()
{
    mCustomPersonModel = new CustomSQLModel(this, &db);
    mCustomPersonModel->setTable("personne");

    //À maj en fonction de la base de donnée
    mCustomPersonModel->setHeaderData(2,Qt::Horizontal,"Surname");
    mCustomPersonModel->setHeaderData(1,Qt::Horizontal,"Name");
    mCustomPersonModel->setHeaderData(3,Qt::Horizontal,"Birth");
    mCustomPersonModel->setHeaderData(4,Qt::Horizontal,"Country");
    mCustomPersonModel->setHeaderData(5,Qt::Horizontal,"Biography");

    mCustomPersonModel->select();
    //mCustomPersonModel->fetchUrls();
    // mCustomPersonModel->downloadPosters();
}

void Widget::initPersonMapper()
{
    QDataWidgetMapper *mapperPerson = new QDataWidgetMapper(this);
    mapperPerson->setModel(mPersonFilteredModel);


    mapperPerson->addMapping(ui->leName, 1);
    mapperPerson->addMapping(ui->leSurname,2);
    mapperPerson->addMapping(ui->leBirth, 3);
    mapperPerson->addMapping(ui->leCountry,4);
    mapperPerson->addMapping(ui->teBiography,5);



    connect(ui->tabViewPerson->selectionModel(),
            SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            mapperPerson, SLOT(setCurrentModelIndex(QModelIndex)));

//    connect(ui->tabViewPerson->selectionModel(),
//            SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
//            this, SLOT(changePoster()));

}

void Widget::initPersonFilter()
{
    mPersonFilteredModel = new QSortFilterProxyModel(this);
    mPersonFilteredModel->setDynamicSortFilter(true);
    mPersonFilteredModel->setSourceModel(mCustomPersonModel);
    mPersonFilteredModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(mPersonFilteredModel);
    QObject::connect(ui->leSearch, SIGNAL(textChanged(QString)), this, SLOT(filter()));


}


/**
 * @brief connecte la TableView au modèle des films
 */

void Widget::displayTableViewMovies()
{
    /*
     * mise en place de la view et du design
     */
    //index =0;

    setupViewMovies();
    design();

    leId = new QLineEdit; //LineEdit caché pour pouvoir retrouver le poster correspondant à l'Id du film

    /*
     * initialisation du FilteredModel et du mapper
     *      pour le modèle avec les films
     */
    initMovieFilter();
    initMovieMapper();

    disabledCard();  //afin qu'on ne puisse pas éditer les moviecard

    connect(ui->pbExit_2,SIGNAL(clicked()),this,SLOT(close())); //quitter

    connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(addMovie())); //ajouter film

    connect(ui->pbSave, SIGNAL(clicked()), this, SLOT(saveMovie())); //sauvegarder film

    connect(ui->pbRemove, SIGNAL(clicked()), this, SLOT(deleteMovie())); //supprimer film

}

void Widget::displayTableViewPersons()
{
    /*
     * mise en place de la view et du design
     */

    setupViewPersons();
    design();

    /*
     * initialisation du FilteredModel et du mapper
     *      pour le modèle avec les films
     */
    initPersonFilter();


    //todo : création d'un formulaire de personne

//prk marche pas??
    initPersonMapper();



    /*
     * connects
     */
    connect(ui->pbExit_2,SIGNAL(clicked()),this,SLOT(close())); //quitter

    connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(addPerson())); //ajouter film

    connect(ui->pbSave, SIGNAL(clicked()), this, SLOT(savePerson())); //sauvegarder film

    connect(ui->pbRemove, SIGNAL(clicked()), this, SLOT(deletePerson())); //supprimer film
}

void Widget::initMovieMapper()
{
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(mMovieFilteredModel);

    mapper->addMapping(ui->labPoster, 6);
    mapper->addMapping(ui->teTitle, 1);
    mapper->addMapping(ui->leRating,4);
    mapper->addMapping(ui->leGenre, 3);
    mapper->addMapping(ui->leYear,2);
    mapper->addMapping(ui->leLength, 8);
    mapper->addMapping(ui->teSynopsis,7);

    mapper->addMapping(leId, 0); //l'id permettant de retrouver le poster adéquat

    ui->teTitle->setStyleSheet("QLineEdit { color : rgb(0, 0, 0);}");

    connect(ui->tableView->selectionModel(),
            SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            mapper, SLOT(setCurrentModelIndex(QModelIndex)));

    connect(ui->tableView->selectionModel(),
            SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            this, SLOT(changePoster()));
}

/**
 * @brief Methode qui met en place la tableView :
 *          - connecte la tableView au modèle
 *          - cache la colonne de l'id_film
 *          - resize les colonnes
 *          - applique le QSqlRelationalDelegate
 */
void Widget::setupViewMovies()
{
    qDebug() << "interieur setupViewMovies";
    ui->tableView->setModel(mCustomMovieModel);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(6);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    formatLength();
    ui->tableView->resizeColumnToContents(1);
    ui->tableView->resizeColumnToContents(2);
    ui->tableView->resizeColumnToContents(3);
    ui->tableView->resizeColumnToContents(4);
    ui->tableView->resizeColumnToContents(5);
    ui->tableView->resizeColumnToContents(8);

}

void Widget::setupViewPersons()
{
    qDebug() << "interieur setupViewPersons";
    ui->tabViewPerson->setModel(mCustomPersonModel);
    ui->tabViewPerson->hideColumn(0);
    ui->tabViewPerson->setSortingEnabled(true);

}


void Widget::initMovieFilter()
{
    mMovieFilteredModel = new QSortFilterProxyModel(this);
    mMovieFilteredModel->setDynamicSortFilter(true);
    mMovieFilteredModel->setSourceModel(mCustomMovieModel);
    mMovieFilteredModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(mMovieFilteredModel);
    QObject::connect(ui->leSearch, SIGNAL(textChanged(QString)), this, SLOT(filter()));
}

/**
 * @brief Méthode SLOT appelée lorsqu'on clique sur un élément de la TableView
 *        Elle récupère le int contenant l'id du film et situé dans la LineEdit leID
 *        Elle va chercher le poster correspondant à ce film dans le CustomMovieModel
 */
void Widget::changePoster()
{
    int idFilm = leId->text().toInt(); //récupération de l'id du film

    if(idFilm != 0)
        ui->labPoster->setPixmap(*(mCustomMovieModel->getPosterAtKey(idFilm)));
}

void Widget::filter()
{
    mMovieFilteredModel->setFilterWildcard(ui->leSearch->text());
    mMovieFilteredModel->setFilterKeyColumn(ui->comboBox->currentData().toInt());
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
    QMessageBox::information(this,"Save","Thank you for your contribution!");
}

void Widget::deleteMovie()
{
    // ouverture d'une fenetre modale q message box
    int reponse = QMessageBox::question(this,"Remove","Do you want to remove this movie?", QMessageBox::Yes | QMessageBox ::No);

    if (reponse == QMessageBox::Yes)
    {
        mCustomMovieModel->removeRow(ui->tableView->currentIndex().row());
        mCustomMovieModel->submitAll();
        ui->tableView->update();

        QMessageBox::information(this,"Remove","The movie has been deleted .");
    }
    else
        QMessageBox::critical (this, "Remove","The movie has not been deleted.");
}


void Widget::downloadPoster()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "c:/", tr("Image Files (*.png *.jpg *.bmp)"));
    QPixmap monImage(fileName);
    ui->labPoster->setPixmap(monImage);
    //save in db
}


void Widget::formatLength()
{
    for(int i=0 ; i<mCustomMovieModel->rowCount();i++)
    {
        //on fait une boucle pour recuperer ligne par ligne le model, grâce à
        //qsqlRecord qui permet d'enregistrer les lignes du model
        QSqlRecord recor = mCustomMovieModel->record(i);
        //on recupere la valeur du f_length (data) et on la met en int(apprmnt c un qvariant)
        int t = recor.value("f_length").toInt();
        //fromTime_t prend des secondes d'où la multiplication par 60
        QString time  = QDateTime::fromTime_t(t*60).toUTC().toString("hh'h'mm'min'");

        //pour envoyer à la BDD
        QVariant v;
        v.setValue(time);
        recor.setValue("f_length",v);
        mCustomMovieModel->setRecord(i,recor);

    }
}
//void Widget::newCard()
//{
//    ui->teTitle->clear();
//    ui->teTitle->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
//    ui->leRating->clear();
//    ui->leRating->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
//    ui->leYear->clear();
//    ui->leYear->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
//    ui->leGenre->clear();
//    ui->leGenre->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
//    ui->leLength->clear();
//    ui->leLength->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
//    ui->teSynopsis->clear();
//    ui->teSynopsis->setStyleSheet("QTextEdit { background : rgb(255, 255, 255);}");
//}


void Widget::disabledCard()
{
    ui->teTitle->setEnabled(false);
    ui->teTitle->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
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


//void Widget::enabledCard()
//{
//    ui->teTitle->setEnabled(true);
//    ui->teTitle->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
//    ui->leRating->setEnabled(true);
//    ui->leRating->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
//    ui->leYear->setEnabled(true);
//    ui->leYear->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
//    ui->leGenre->setEnabled(true);
//    ui->leGenre->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
//    ui->leLength->setEnabled(true);
//    ui->leLength->setStyleSheet("QLineEdit { background : rgb(255, 255, 255);}");
//    ui->teSynopsis->setEnabled(true);
//    ui->teSynopsis->setStyleSheet("QTextEdit { background : rgb(255, 255, 255);}");
//}


Widget::~Widget()
{
    delete ui;
}
void Widget::design()
{
    //comboBox filter


    ui->comboBox->addItem("Title",1);
    ui->comboBox->addItem("Year", 2);
    ui->comboBox->addItem("Genre",3);

    QImage photoGauche(":/images/labelGauche.jpg");
    ui->labGauche->setPixmap(QPixmap ::fromImage(photoGauche));

    QImage photoDroite(":/images/labelDroit.ico");
    ui->labDroit->setPixmap(QPixmap ::fromImage(photoDroite));

    QImage loupe(":/images/loupe.png");
    ui->labSearch->setPixmap(QPixmap ::fromImage(loupe));

    QImage posterVide(":/images/posterVideView.png");
    ui->labPoster->setPixmap(QPixmap ::fromImage(posterVide));

    QImage posterVide2(":/images/posterVideView.png");
    ui->labPoster_2->setPixmap(QPixmap ::fromImage(posterVide));

    ui->tableView->verticalHeader()->hide();
    ui->tableView->setStyleSheet("QHeaderView::section { background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5, stop: 0 blue, stop: 1 indigo); font: bold 14px; color:white; }");

    ui->tabViewPerson->verticalHeader()->hide();
    ui->tabViewPerson->setStyleSheet("QHeaderView::section { background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5, stop: 0 blue, stop: 1 indigo); font: bold 14px; color:white; }");


    // ui->pbAdd->setStyleSheet("QPushButton#pbAdd:hover {background-color: gray;}");
    // ui->pbSave->setStyleSheet("QPushButton#pbAdd:hover {background-color: gray;}");
    // ui->pbExit->setStyleSheet("QPushButton#pbAdd:hover {background-color: gray;}");
    // ui->pbRemove->setStyleSheet("QPushButton#pbAdd:hover {background-color: gray;}");


}

void Widget::cancel()
{

}

//connect entre tabWidget movie/star et les stackedWidget
void Widget::on_tabWidget_tabBarClicked(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}
