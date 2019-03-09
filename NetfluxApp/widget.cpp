#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
     ui->setupUi(this);

     db = QSqlDatabase::database("BDDProduits");

    //comboBox filter
    ui->comboBox->addItem("Title",1);
    ui->comboBox->addItem("Genre", 2);

    initModel(); //initialise le modèle à partir de la BDD
    setupView(); //applique le modèle à la view et configure la view
    initFilteringModel(); //initialisation du filter sur le modèle

    connect(ui->pbExit,SIGNAL(clicked()),this,SLOT(close()));

    connect(ui->pbAdd, SIGNAL(clicked()), this, SLOT(openNewCard()));
}

void Widget::initModel()
{
    mFilmsModel = new QSqlTableModel(this, db);
    mFilmsModel->setTable("film");
    mFilmsModel->select();
}

void Widget::setupView()
{

    ui->tableView->setModel(mFilmsModel);
    ui->tableView->hideColumn(0);
    ui->tableView->setSortingEnabled(true);
//    ui->tableView->update();
//    ui->tableView->show();

    qDebug() << ui->tableView;
    qDebug() << mFilmsModel;

}

void Widget::initFilteringModel()
{
    filteringModel = new QSortFilterProxyModel(this);
    filteringModel->setDynamicSortFilter(true);
    filteringModel->setSourceModel(mFilmsModel);
    filteringModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    connect(ui->leSearch, SIGNAL(textChanged(QString)), this, SLOT(search()));

    ui->tableView->setModel(filteringModel);
   // ui->tableView->show();
}

void Widget::initMapper()
{

}


void Widget::openNewCard()
{
    /* - génère un nouveau mapper et le passe au constructeur de MovieCard
     * - génère une nouvelle MovieCard */

   QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
   mapper->setModel(filteringModel);

   MovieCard* card= new MovieCard(nullptr, mapper, filteringModel);
   card->newCard();

   card->show();


}

Widget::~Widget()
{
    delete ui;
}



