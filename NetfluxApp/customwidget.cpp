#include "customwidget.h"


CustomWidget::CustomWidget(QWidget *parent)
    : QWidget(parent)
{
    db = QSqlDatabase::database("netflux");

    tableView = nullptr;
    listView = nullptr;

    labels << "ID" << "GENRE" << "TITLE" << "YEAR" << "RATINGS" << "POSTER" << "SYNOPSIS" << "DURATION";

    initModel();

    initTableView();

    connect(addBtn, SIGNAL(clicked()), this, SLOT(addMovie()));
    connect(deleteBtn, SIGNAL(clicked()), this, SLOT(deleteMovie()));
    connect(refreshBtn, SIGNAL(clicked()), this, SLOT(refreshMovies()));
}

void CustomWidget::initModel()
{
    mFilmsModel = new QSqlTableModel(this, db);
    mFilmsModel->setTable("film");
    mFilmsModel->select();

    for(int i=0; i<labels.length(); i++)
         mFilmsModel->setHeaderData(i, Qt::Horizontal, labels[i]);
}


void CustomWidget::initTableView()
{
    externalLayout = new QHBoxLayout(this);

    tableView = new QTableView(this);
    tableView->setModel(mFilmsModel);
    tableView->setSortingEnabled(true);
    tableView->hideColumn(0);

  //  tableView->setSelectionMode(QAbstractItemView::MultiSelection);

    initIHMElements();
}

void CustomWidget::initListView()
{
    externalLayout = new QHBoxLayout(this);

    listView = new QListView(this);
    listView->setModel(mFilmsModel);
    listView->setModelColumn(1);
    listView->setSelectionMode(QAbstractItemView::MultiSelection);

    initIHMElements();
}


void CustomWidget::initIHMElements()
{
    initBtnPane();

    initMovieCard();

    externalLayout->addLayout(buttonsPane);
    externalLayout->addWidget(tableView);
    externalLayout->addLayout(movieCard);

    setLayout(externalLayout);

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(filteringModel);

    for(QString label: labels)
        /*on fait le mapping sur chaque QLineEdit de la QMap formFields */
         mapper->addMapping(formFields[label], labels.indexOf(label));

    connect(tableView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), mapper, SLOT(setCurrentModelIndex(QModelIndex)));
}

void CustomWidget::initMovieCard()
{
    /*créé un formulaire en générant un QLineEdit correspondant à
     * chaque label de la QStringList labels. */

    movieCard = new QFormLayout(this);

    movieCard->addWidget(new QLabel("MOVIE DETAILS"));
    for (QString label : labels)
    {
            formFields[label] = new QLineEdit;
            movieCard->addRow(label, formFields[label]);
    }

    QUrl imageUrl("http://image.tmdb.org/t/p/w300_and_h450_bestv2/4ucLGcXVVSVnsfkGtbLY4XAius8.jpg");
    m_pImgCtrl = new FileDownloader(imageUrl, this);

    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));

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

void CustomWidget::loadImage()
{
    QPixmap poster2(QSize(5, 5));

    poster2.loadFromData(m_pImgCtrl->downloadedData());

    posterLbl = new QLabel("poster");
    posterLbl->setPixmap(poster2);
    posterLbl->resize(2, 2);

    movieCard->addWidget(posterLbl);

    qDebug() << m_pImgCtrl->downloadedData() << " " << poster2 << " " << posterLbl << endl;
}

CustomWidget::~CustomWidget()
{

}
