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

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    CustomWidget(QWidget *parent = 0);
    ~CustomWidget();
    void initIHMTableView();
    void initIHMListView();
    void initBtnPane(); //génère la barre latérales des push buttons
    void initMovieCard(); //génère le formulaire contenant les détails du produit sélectionné

    void initFilteringModel();

    void initModel();

public slots:
    void deleteMovie();
    void addMovie();
    void refreshMovies();
    void search();

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

    QStringList labels;
};

#endif // CUSTOMWIDGET_H
