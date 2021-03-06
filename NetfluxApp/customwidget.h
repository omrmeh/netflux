#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H


#include <QWidget>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeView>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QSqlDatabase>
#include <QDebug>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialog>
#include <QTableView>
#include <QSqlTableModel>
#include <QListView>
#include <QLineEdit>
#include <QDataWidgetMapper>
#include <QSortFilterProxyModel>
#include <QComboBox>
#include <QAbstractItemDelegate>
#include <QLabel>
#include "filedownloader.h"
#include <QUrl>

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    CustomWidget(QWidget *parent = 0);
    ~CustomWidget();
    void initTableView();
    void initListView();
    void initBtnPane(); //génère la barre latérales des push buttons
    void initMovieCard(); //génère le formulaire contenant les détails du produit sélectionné

    void initFilteringModel();

    void initModel();

    void initIHMElements();

public slots:
    void deleteMovie();
    void addMovie();
    void refreshMovies();
    void search();
    void loadImage();

private:
    QSqlDatabase db;
    QSqlTableModel* mFilmsModel;
    QSortFilterProxyModel* filteringModel;

    QAbstractItemView *view;

    QHBoxLayout *externalLayout;
    QVBoxLayout *buttonsPane;
    QFormLayout *movieCard;

    QDialog *addPopup;
    QPushButton *addBtnForm;

    QTableView* tableView;
    QListView* listView;

    QMap <QString, QLineEdit*> formFields;

    QPushButton *addBtn, *deleteBtn, *editBtn, *clearBtn, *refreshBtn, *searchBtn;

    QLineEdit *searchBar;

    QComboBox *searchColumn;

    QLineEdit *idEdit, *nameEdit, *priceEdit, *codeEdit, *stockEdit, *condEdit;

    QPixmap *poster;
    QLabel *posterLbl;

    QVector<QLabel*> postersLbl;

    QStringList labels;

    FileDownloader *m_pImgCtrl;

    QDataWidgetMapper *mapper;

    QVector<QVariant> urls;
};

#endif // CUSTOMWIDGET_H
