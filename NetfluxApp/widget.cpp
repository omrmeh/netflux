#include "widget.h"
#include "ui_widget.h"




Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    initModel();//initier le model
    setupView();//la mise en place de la vue
    design();//la combobox pour le filtre et les icones pour la fenetre
    initFilteredModel();//initier le model filtré
    initMapper();//le mapper
    disabledCard();//desactiver les lineEdit sur le formulaire pour ne pas pouvoir les modifier que qd on clique sur Edit/modifier

    //Quitter
    connect(ui->pbExit_2,SIGNAL(clicked()),this,SLOT(close()));
    //Add
    connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(addMovie()));
    //save
    connect(ui->pbSave, SIGNAL(clicked()), this, SLOT(saveMovie()));
    connect(ui->pbSave, SIGNAL(clicked()), this, SLOT(newCard()));
    //remove
    connect(ui->pbRemove, SIGNAL(clicked()), this, SLOT(deleteMovie()));
    //edit
    connect(ui->pbEdit, SIGNAL(clicked()), this, SLOT(enabledCard()));
}
//initier le model sql
void Widget::initModel()
{
    QSqlDatabase db = QSqlDatabase::database("dbFilm");
    mMovieModel = new QSqlTableModel(this, db);

    initCustomSqlModel(db);

    mMovieModel->setTable("film");
    mMovieModel->select();
    //modifier les header de la table
    mMovieModel->setHeaderData(1,Qt::Horizontal,"Genre");
    mMovieModel->setHeaderData(2,Qt::Horizontal,"Title");
    mMovieModel->setHeaderData(3,Qt::Horizontal,"Year");
    mMovieModel->setHeaderData(5,Qt::Horizontal,"Poster");
    //pour ajouter une securite et que les modif n'y vont pas direct en BDD avt de confirmer
    mMovieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    qDebug() << "interieur initModel";
}

//le modele personnalisé qui herite de sqlModel
void Widget::initCustomSqlModel(QSqlDatabase db)
{
    mCustomMovieModel = new CustomSQLModel(this, &db);
    mCustomMovieModel->setTable("film");
    mCustomMovieModel->setRelation(1, QSqlRelation("GENRE", "ID_GENRE", "G_NAME"));
    mCustomMovieModel->select();
    mCustomMovieModel->fetchUrls();
    mCustomMovieModel->downloadPosters();
    mCustomMovieModel->setHeaderData(1,Qt::Horizontal,"Genre");
    mCustomMovieModel->setHeaderData(2,Qt::Horizontal,"Title");
    mCustomMovieModel->setHeaderData(3,Qt::Horizontal,"Year");
    mCustomMovieModel->setHeaderData(5,Qt::Horizontal,"Poster");
    //pour ajouter une securite et que les modif n'y vont pas direct en BDD avt de confirmer
    mCustomMovieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

}

//initialiser le mapper
void Widget::initMapper()
{
    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(mMovieFilteredModel);
    //connecter les lineEdit avec les colonnes de la BDD
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

    //pour ajouter une securite et que les modif n'y vont pas direct en BDD avt de confirmer
    mMovieModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
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
    //cacher le vertical header
    ui->tableView->verticalHeader()->hide();
}
//le model filtré
void Widget::initFilteredModel()
{
    mMovieFilteredModel = new QSortFilterProxyModel(this);
    mMovieFilteredModel->setDynamicSortFilter(true);
    mMovieFilteredModel->setSourceModel(mCustomMovieModel);
    mMovieFilteredModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    ui->tableView->setModel(mMovieFilteredModel);
    QObject::connect(ui->leSearch, SIGNAL(textChanged(QString)), this, SLOT(filter()));
}

//lier la combobox filtre et la barre de recherche avec le model filtré
void Widget::filter()
{    
    mMovieFilteredModel->setFilterWildcard(ui->leSearch->text());
    mMovieFilteredModel->setFilterKeyColumn(ui->comboBox->currentData().toInt());
}

void Widget::addMovie()
{
    newCard();//effacer les lineEdit pour pouvoir ecrire
    enabledCard();//activer les lineEdit qui sont desactivé par default

    //je remplit le label poster par une image provisoir en attendant de telecharger l'affiche du film
    QImage posterVide("C:/Users/Dell/Documents/netflux/posterVideView.png");
    ui->labPoster->setPixmap(QPixmap ::fromImage(posterVide));
    //je fais apparaitre le boutton telecharger affiche du film qui est caché quand il y a que l'affichage
    ui->pbDownload->show();

}
//pour modifier les infos d'un film, j'enleve le mode "lecture seule" de mes lineEdit
void Widget::editMovie()
{
    enabledCard();
}
//je sauvegarde un nouveau film ou des modif
void Widget::saveMovie()
{

    mCustomMovieModel->submitAll();

}

void Widget::deleteMovie()
{

    mCustomMovieModel->removeRow(ui->tableView->currentIndex().row());
}

void Widget::cancel()
{

}

void Widget::downloadPoster()
{
    //j'ouvre une fenetre de dialogue pour telecharger une image
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "c:/", tr("Image Files (*.png *.jpg *.bmp)"));
    QPixmap monImage(fileName);
    //et je la met dans le label
    ui->labPoster->setPixmap(monImage);
    //save in db
}
//un formulaire vide pour ajouter film et apres sauvegarde
void Widget::newCard()
{

    ui->leTitle->clear();
    ui->leRating->clear();
    ui->leYear->clear();
    ui->leGenre->clear();
    ui->leLength->clear();
    ui->teSynopsis->clear();
    ui->pbDownload->setStyleSheet("QPushButton { color: rgb(255, 255, 255); background : rgb(0, 0, 99);}");
    ui->pbEdit->setDisabled(true);
}

//lineEdit en mode lecture seule
void Widget::disabledCard()
{
    ui->leTitle->setEnabled(false);
    ui->leRating->setEnabled(false);
    ui->leYear->setEnabled(false);
    ui->leGenre->setEnabled(false);
    ui->leLength->setEnabled(false);
    ui->teSynopsis->setEnabled(false);
}
//j'enleve le mode lecture seule des lineEdit
void Widget::enabledCard()
{
    ui->leTitle->setEnabled(true);
    ui->leRating->setEnabled(true);
    ui->leYear->setEnabled(true);
    ui->leGenre->setEnabled(true);
    ui->leLength->setEnabled(true);
    ui->teSynopsis->setEnabled(true);
    ui->pbDownload->setStyleSheet("QPushButton { color: rgb(255, 255, 255); background : rgb(0, 0, 99);}");
     ui->pbDownload->show();
}


Widget::~Widget()
{
    delete ui;
}
void Widget::design()
{
    //comboBox filter le texte avec la colonne correspondante de la BDD
    ui->comboBox->addItem("Title",2);
    ui->comboBox->addItem("Year", 3);
    ui->comboBox->addItem("Genre",1);
    //enlever le header horizontale
    ui->tableView->verticalHeader()->setVisible(false);


    //les images des fenetres (pour le design)
    QImage photoGauche("C:/Users/Dell/Documents/netflux/labelGauche.jpg");
    ui->labGauche->setPixmap(QPixmap ::fromImage(photoGauche));

    QImage photoDroite("C:/Users/Dell/Documents/netflux/labelDroit.ico");
    ui->labDroit->setPixmap(QPixmap ::fromImage(photoDroite));

    QImage loupe("C:/Users/Dell/Documents/netflux/loupe.png");
    ui->labSearch->setPixmap(QPixmap ::fromImage(loupe));
    //le poster vide pour le formulaire vide
    QImage posterVide("C:/Users/Dell/Documents/netflux/posterVideView.png");
    ui->labPoster->setPixmap(QPixmap ::fromImage(posterVide));

}
