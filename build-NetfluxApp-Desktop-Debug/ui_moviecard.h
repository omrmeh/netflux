/********************************************************************************
** Form generated from reading UI file 'moviecard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIECARD_H
#define UI_MOVIECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *leTitle;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QPushButton *pbImage;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *leGenre;
    QLabel *label_3;
    QLineEdit *leYear;
    QLabel *label_4;
    QLineEdit *leLength;
    QLabel *label_5;
    QTextEdit *teSynopsis;
    QLabel *label_6;
    QLineEdit *leRating;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbEdit;
    QPushButton *pbSave;
    QPushButton *pbCancel;
    QPushButton *pbExit;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(572, 760);
        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 3, 550, 779));
        QFont font;
        font.setFamily(QString::fromUtf8("Harrington"));
        font.setPointSize(18);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(75, 70, 214);\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(85, 85, 255);"));
        groupBox->setAlignment(Qt::AlignCenter);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 42, 531, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(8);
        label_2->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, label_2);

        leTitle = new QLineEdit(formLayoutWidget);
        leTitle->setObjectName(QString::fromUtf8("leTitle"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        leTitle->setFont(font2);
        leTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, leTitle);

        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 106, 531, 361));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        verticalLayout->addWidget(label_7);

        pbImage = new QPushButton(verticalLayoutWidget);
        pbImage->setObjectName(QString::fromUtf8("pbImage"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(10);
        pbImage->setFont(font3);

        verticalLayout->addWidget(pbImage);

        formLayoutWidget_2 = new QWidget(groupBox);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(9, 469, 531, 232));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label);

        leGenre = new QLineEdit(formLayoutWidget_2);
        leGenre->setObjectName(QString::fromUtf8("leGenre"));
        leGenre->setFont(font2);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, leGenre);

        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        leYear = new QLineEdit(formLayoutWidget_2);
        leYear->setObjectName(QString::fromUtf8("leYear"));
        leYear->setFont(font2);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, leYear);

        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        leLength = new QLineEdit(formLayoutWidget_2);
        leLength->setObjectName(QString::fromUtf8("leLength"));
        leLength->setFont(font2);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, leLength);

        label_5 = new QLabel(formLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_5);

        teSynopsis = new QTextEdit(formLayoutWidget_2);
        teSynopsis->setObjectName(QString::fromUtf8("teSynopsis"));
        teSynopsis->setFont(font3);
        teSynopsis->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, teSynopsis);

        label_6 = new QLabel(formLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        leRating = new QLineEdit(formLayoutWidget_2);
        leRating->setObjectName(QString::fromUtf8("leRating"));
        leRating->setFont(font1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, leRating);

        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 706, 531, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pbEdit = new QPushButton(horizontalLayoutWidget);
        pbEdit->setObjectName(QString::fromUtf8("pbEdit"));
        pbEdit->setFont(font3);

        horizontalLayout_2->addWidget(pbEdit);

        pbSave = new QPushButton(horizontalLayoutWidget);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        pbSave->setFont(font3);

        horizontalLayout_2->addWidget(pbSave);

        pbCancel = new QPushButton(horizontalLayoutWidget);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));
        pbCancel->setFont(font3);

        horizontalLayout_2->addWidget(pbCancel);

        pbExit = new QPushButton(horizontalLayoutWidget);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));
        pbExit->setFont(font3);

        horizontalLayout_2->addWidget(pbExit);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("Form", "NETFLUX", nullptr));
        label_2->setText(QApplication::translate("Form", "Title", nullptr));
        label_7->setText(QApplication::translate("Form", "TextLabel", nullptr));
        pbImage->setText(QApplication::translate("Form", "Download poster", nullptr));
        label->setText(QApplication::translate("Form", "Genre", nullptr));
        label_3->setText(QApplication::translate("Form", "Year", nullptr));
        label_4->setText(QApplication::translate("Form", "Length", nullptr));
        label_5->setText(QApplication::translate("Form", "Synopsis", nullptr));
        label_6->setText(QApplication::translate("Form", "Rating", nullptr));
        pbEdit->setText(QApplication::translate("Form", "Edit", nullptr));
        pbSave->setText(QApplication::translate("Form", "Save", nullptr));
        pbCancel->setText(QApplication::translate("Form", "Cancel", nullptr));
        pbExit->setText(QApplication::translate("Form", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIECARD_H
