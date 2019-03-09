/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QLineEdit *leSearch;
    QComboBox *comboBox_2;
    QLabel *label;
    QPushButton *pbGo;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbAdd;
    QPushButton *pbCancel;
    QPushButton *pbExit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(863, 589);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"background-color: rgb(0, 0, 0);"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 841, 561));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Harrington"));
        font.setPointSize(18);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 255);"));
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        leSearch = new QLineEdit(groupBox);
        leSearch->setObjectName(QString::fromUtf8("leSearch"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        leSearch->setFont(font1);
        leSearch->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(leSearch, 0, 2, 1, 1);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setFont(font1);
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(comboBox_2, 0, 5, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(8);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label, 0, 3, 1, 2);

        pbGo = new QPushButton(groupBox);
        pbGo->setObjectName(QString::fromUtf8("pbGo"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(12);
        pbGo->setFont(font3);
        pbGo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"color: rgb(75, 70, 214);\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(pbGo, 0, 6, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(55, 32));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Desktop/Magnifier2.png")));
        label_3->setScaledContents(true);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pbAdd = new QPushButton(groupBox);
        pbAdd->setObjectName(QString::fromUtf8("pbAdd"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(14);
        pbAdd->setFont(font4);
        pbAdd->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 75);"));

        horizontalLayout->addWidget(pbAdd);

        pbCancel = new QPushButton(groupBox);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setFont(font4);
        pbCancel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 75);"));

        horizontalLayout->addWidget(pbCancel);

        pbExit = new QPushButton(groupBox);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));
        pbExit->setFont(font4);
        pbExit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(25, 25, 75);"));

        horizontalLayout->addWidget(pbExit);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "NETFLUX", nullptr));
        label->setText(QApplication::translate("Widget", "search by", nullptr));
        pbGo->setText(QApplication::translate("Widget", "GO", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        pbAdd->setText(QApplication::translate("Widget", "Add", nullptr));
        pbCancel->setText(QApplication::translate("Widget", "Cancel", nullptr));
        pbExit->setText(QApplication::translate("Widget", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
