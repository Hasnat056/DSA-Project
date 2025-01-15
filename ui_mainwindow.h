/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *Admin_button;
    QPushButton *Student_name;
    QPushButton *ExitMain_button;
    QFrame *frame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(802, 526);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(230, 30, 451, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(18);
        font.setBold(false);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(390, 150, 141, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Poor Richard")});
        font1.setPointSize(14);
        lineEdit_2->setFont(font1);
        Admin_button = new QPushButton(centralwidget);
        Admin_button->setObjectName("Admin_button");
        Admin_button->setGeometry(QRect(410, 210, 121, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Stencil")});
        font2.setPointSize(14);
        Admin_button->setFont(font2);
        Student_name = new QPushButton(centralwidget);
        Student_name->setObjectName("Student_name");
        Student_name->setGeometry(QRect(410, 290, 121, 51));
        Student_name->setFont(font2);
        ExitMain_button = new QPushButton(centralwidget);
        ExitMain_button->setObjectName("ExitMain_button");
        ExitMain_button->setGeometry(QRect(410, 370, 121, 51));
        ExitMain_button->setFont(font2);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(120, 0, 671, 461));
        frame->setStyleSheet(QString::fromUtf8("border : 4px solid rgb(223,212,122)\n"
" qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        MainWindow->setCentralWidget(centralwidget);
        frame->raise();
        verticalLayoutWidget->raise();
        lineEdit_2->raise();
        Admin_button->raise();
        Student_name->raise();
        ExitMain_button->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 802, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(Admin_button, &QPushButton::clicked, Admin_button, qOverload<>(&QPushButton::show));
        QObject::connect(Student_name, &QPushButton::clicked, Student_name, qOverload<>(&QPushButton::show));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "WELCOME TO STUDENT DATABSE", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "Select Your Role:", nullptr));
        Admin_button->setText(QCoreApplication::translate("MainWindow", "ADMIN", nullptr));
        Student_name->setText(QCoreApplication::translate("MainWindow", "STUDENT", nullptr));
        ExitMain_button->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
