/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidgetAirports;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *comboBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(409, 469);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton1 = new QPushButton(centralWidget);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton1->setFont(font);
        pushButton1->setStyleSheet(QStringLiteral("background-color: rgb(212, 255, 176);"));

        verticalLayout_2->addWidget(pushButton1);

        pushButton2 = new QPushButton(centralWidget);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setFont(font);
        pushButton2->setStyleSheet(QStringLiteral("background-color: rgb(255, 247, 203);"));

        verticalLayout_2->addWidget(pushButton2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(0);
        spinBox->setMaximum(1000000);
        spinBox->setSingleStep(25);
        spinBox->setValue(200);

        verticalLayout->addWidget(spinBox);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        tableWidgetAirports = new QTableWidget(centralWidget);
        tableWidgetAirports->setObjectName(QStringLiteral("tableWidgetAirports"));
        tableWidgetAirports->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidgetAirports->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(tableWidgetAirports);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton1->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">\320\222\321\213\320\262\320\276\320\264\320\270\321\202 \321\201\320\277\320\270\321\201\320\276\320\272 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\276\320\262 \320\262 \321\203\320\272\320\260\320\267\320\260\320\275\320\275\320\276\320\274 \321\200\320\260\320\264\320\270\321\203\321\201\320\265 \320\277\320\276\320\270\321\201\320\272\320\260 \320\276\321\202 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\263\320\276 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\320\265 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260.</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton1->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\276\320\262 \320\262 \321\200\320\260\320\264\320\270\321\203\321\201\320\265", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\222\321\213\320\262\320\276\320\264 \320\274\320\260\321\200\321\210\321\200\321\203\321\202 \320\274\320\265\320\266\320\264\321\203 \320\264\320\262\321\203\320\274\321\217 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\274\320\270 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\320\265 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\260\320\274\320\270 \321\201 \321\203\321\207\321\221\321\202\320\276\320\274 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \320\264\320\260\320\273\321\214\320\275\320\276\321\201\321\202\320\270 \320\277\320\276\320\273\321\221\321\202\320\260 \320\261\320\265\320\267 \320\277\320\276\321\201\320\260\320\264\320\272\320\270. <br>\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\262\321\202\320\276\321\200\320\276\320\271 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274 \320\274\320\276\320\266\320\275\320\276 \321\201 \320\277\320\276\320\274\320"
                        "\276\321\211\321\214\321\216 \320\272\320\273\320\260\320\262\320\270\321\210\320\270 Cntrl.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\272\321\200\320\260\321\202\321\207\320\260\320\271\321\210\320\265\320\263\320\276 \320\277\321\203\321\202\320\270", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217\n"
"\320\264\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214 (\320\232\320\274)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        spinBox->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#000000;\">\320\230\320\274\320\265\320\265\321\202 \320\264\320\262\320\260 \320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217:<br>1) \320\240\320\260\320\264\320\270\321\203\321\201 \320\262 \320\272\320\276\321\202\320\276\321\200\320\276\320\274 \320\262\320\265\320\264\321\221\321\202\321\201\321\217 \320\277\320\276\320\270\321\201\320\272 \320\260\321\215\321\200\320\276\320\264\321\200\320\276\320\274\320\276\320\262<br>2) \320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\277\320\276\320\273\321\221\321\202\320\260 \320\261\320\265\320\267 \320\277\320\276\321\201\320\260\320\264\320\272\320\270</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202 \320\272\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202:", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\223\321\200\320\260\320\264\321\203\321\201\321\213\302\260", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\223\321\200\320\260\320\264\321\203\321\201\321\213\302\260 \320\234\320\270\320\275\321\203\321\202\321\213' \320\241\320\265\320\272\321\203\320\275\320\264\321\213\"", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
