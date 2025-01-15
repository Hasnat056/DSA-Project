/********************************************************************************
** Form generated from reading UI file 'display.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Display
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Display)
    {
        if (Display->objectName().isEmpty())
            Display->setObjectName("Display");
        Display->resize(871, 653);
        centralwidget = new QWidget(Display);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(210, 30, 261, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(14);
        lineEdit->setFont(font);
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(210, 110, 261, 531));
        listWidget->setItemAlignment(Qt::AlignmentFlag::AlignHCenter);
        listWidget->setSortingEnabled(false);
        Display->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Display);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 871, 33));
        Display->setMenuBar(menubar);
        statusbar = new QStatusBar(Display);
        statusbar->setObjectName("statusbar");
        Display->setStatusBar(statusbar);

        retranslateUi(Display);
        QObject::connect(listWidget, &QListWidget::itemClicked, listWidget, qOverload<>(&QListWidget::show));

        listWidget->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(Display);
    } // setupUi

    void retranslateUi(QMainWindow *Display)
    {
        Display->setWindowTitle(QCoreApplication::translate("Display", "Display", nullptr));
        lineEdit->setText(QCoreApplication::translate("Display", "Select ID to see details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Display: public Ui_Display {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAY_H
