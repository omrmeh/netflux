#include "customwidget.h"


CustomWidget::CustomWidget(QWidget *parent)
    : QWidget(parent)
{
    db = QSqlDatabase::database("netflux");

    tableView = nullptr;
    listView = nullptr;

    labels << "id_film" << "id_genre" << "f_title" << "f_year" << "f_ratings" << "f_poster" << "f_synopsis" << "f_length";

    initModel();

    initIHMTableView();

    connect(addBtn, SIGNAL(clicked()), this, SLOT(addMovie()));
    connect(deleteBtn, SIGNAL(clicked()), this, SLOT(deleteMovie()));
    connect(refreshBtn, SIGNAL(clicked()), this, SLOT(refreshMovies()));


}

void CustomWidget::initModel()
{
    mFilmsModel = new QSqlTableModel(this, db);
    mFilmsModel->setTable("film");
    mFilmsModel->select();
    mFilmsModel->setEditStrategy((QSqlTableModel::OnManualSubmit));
}


void CustomWidget::initIHMTableView()
{
    externalLayout = new QHBoxLayout(this);

    tableView = new QTableView(this);
    tableView->setModel(mFilmsModel);
    tableView->setSortingEnabled(true);

  //  tableView->setSelectionMode(QAbstractItemView::MultiSelection);

    initBtnPane();

    initMovieCard();

    externalLayout->addLayout(buttonsPane);
    externalLayout->addWidget(tableView);
    externalLayout->addLayout(movieCard);

    setLayout(externalLayout);

    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(filteringModel);

    for(QString label: labels)
        /*on fait le mapping sur chaque QLineEdit de la QMap formFields */
         mapper->addMapping(formFields[label], labels.indexOf(label));

    connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), mapper, SLOT(setCurrentModelIndex(QModelIndex)));


   // tableView->show();


}

void CustomWidget::initIHMListView()
{
    externalLayout = new QHBoxLayout(this);

    listView = new QListView(this);
    listView->setModel(mFilmsModel);
    listView->setModelColumn(1);
    listView->setSelectionMode(QAbstractItemView::MultiSelection);

    initBtnPane();

    initMovieCard();

    externalLayout->addLayout(buttonsPane);
    externalLayout->addWidget(listView);
    externalLayout->addLayout(movieCard);

    setLayout(externalLayout);

    QDataWidgetMapper *mapper = new QDataWidgetMapper(this);
    mapper->setModel(filteringModel);

    for(QString label: labels)
        /*on fait le mapping sur chaque QLineEdit de la QMap formFields */
         mapper->addMapping(formFields[label], labels.indexOf(label));

    connect(listView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), mapper, SLOT(setCurrentModelIndex(QModelIndex)));

}

void CustomWidget::initMovieCard()
{
    /*créé un formulaire en générant un QLineEdit correspondant à
     * chaque label de la QStringList labels. */

    movieCard = new QFormLayout(this);

    for (QString label : labels)
    {
            formFields[label] = new QLineEdit;
            movieCard->addRow(label, formFields[label]);
    }
}


void CustomWidget::initBtnPane()
{
    buttonsPane = new QVBoxLayout(this);

    searchBtn = new QPushButton("SEARCH");
    searchBar = new QLineEdit;

    searchColumn = new QComboBox;
    searchColumn->addItems(labels);

    buttonsPane->addWidget(searchBtn);
    buttonsPane->addWidget(searchBar);
    buttonsPane->addWidget(searchColumn);

    addBtn = new QPushButton("ADD");
    buttonsPane->addWidget(addBtn);

    deleteBtn = new QPushButton("DELETE");
    buttonsPane->addWidget(deleteBtn);

    editBtn = new QPushButton("EDIT");
    buttonsPane->addWidget(editBtn);

    clearBtn = new QPushButton("CLEAR");
    buttonsPane->addWidget(clearBtn);

    refreshBtn = new QPushButton("LOAD");
    buttonsPane->addWidget(refreshBtn);

    initFilteringModel();

}

void CustomWidget::initFilteringModel()
{
    filteringModel = new QSortFilterProxyModel(this);
    filteringModel->setDynamicSortFilter(true);
    filteringModel->setSourceModel(mFilmsModel);
    filteringModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    connect(searchBar, SIGNAL(textChanged(QString)), this, SLOT(search()));

    tableView == nullptr? view = listView : view = tableView;
    view->setModel(filteringModel);
}

void CustomWidget::deleteMovie()
{
        for(QModelIndex product: view->selectionModel()->selectedIndexes())
            mFilmsModel->removeRow(product.row());
}

void CustomWidget::addMovie()
{
    mFilmsModel->insertRow(mFilmsModel->rowCount());
}

void CustomWidget::refreshMovies()
{
    mFilmsModel->submitAll();
}

void CustomWidget::search()
{

    int column = searchColumn->currentIndex();
    filteringModel->setFilterKeyColumn(column);
    filteringModel->setFilterWildcard("*" + searchBar->text() + "*");

}

CustomWidget::~CustomWidget()
{

}
