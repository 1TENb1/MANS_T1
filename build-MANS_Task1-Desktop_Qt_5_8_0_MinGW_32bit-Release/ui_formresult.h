/********************************************************************************
** Form generated from reading UI file 'formresult.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMRESULT_H
#define UI_FORMRESULT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormResult
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QTableWidget *tableWidgetAirports;

    void setupUi(QWidget *FormResult)
    {
        if (FormResult->objectName().isEmpty())
            FormResult->setObjectName(QStringLiteral("FormResult"));
        FormResult->resize(400, 306);
        verticalLayout = new QVBoxLayout(FormResult);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelTitle = new QLabel(FormResult);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitle);

        tableWidgetAirports = new QTableWidget(FormResult);
        tableWidgetAirports->setObjectName(QStringLiteral("tableWidgetAirports"));
        tableWidgetAirports->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetAirports->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableWidgetAirports);


        retranslateUi(FormResult);

        QMetaObject::connectSlotsByName(FormResult);
    } // setupUi

    void retranslateUi(QWidget *FormResult)
    {
        FormResult->setWindowTitle(QApplication::translate("FormResult", "Form", Q_NULLPTR));
        labelTitle->setText(QApplication::translate("FormResult", "Title", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormResult: public Ui_FormResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMRESULT_H
