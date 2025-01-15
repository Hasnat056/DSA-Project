/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QWidget *centralwidget;
    QLineEdit *ID_input;
    QLineEdit *name_input;
    QLineEdit *department_input;
    QLineEdit *cgpa_input;
    QComboBox *semester_selection;
    QPushButton *insert_button;
    QPushButton *delete_button;
    QPushButton *search_button;
    QPushButton *displayall_button;
    QPushButton *admin_exit_button;
    QFrame *frame;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(796, 533);
        centralwidget = new QWidget(Admin);
        centralwidget->setObjectName("centralwidget");
        ID_input = new QLineEdit(centralwidget);
        ID_input->setObjectName("ID_input");
        ID_input->setGeometry(QRect(380, 30, 221, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(10);
        ID_input->setFont(font);
        name_input = new QLineEdit(centralwidget);
        name_input->setObjectName("name_input");
        name_input->setGeometry(QRect(380, 90, 221, 41));
        name_input->setFont(font);
        department_input = new QLineEdit(centralwidget);
        department_input->setObjectName("department_input");
        department_input->setGeometry(QRect(380, 150, 221, 41));
        department_input->setFont(font);
        cgpa_input = new QLineEdit(centralwidget);
        cgpa_input->setObjectName("cgpa_input");
        cgpa_input->setGeometry(QRect(380, 270, 221, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka")});
        font1.setPointSize(11);
        cgpa_input->setFont(font1);
        semester_selection = new QComboBox(centralwidget);
        semester_selection->addItem(QString());
        semester_selection->addItem(QString());
        semester_selection->addItem(QString());
        semester_selection->addItem(QString());
        semester_selection->addItem(QString());
        semester_selection->addItem(QString());
        semester_selection->addItem(QString());
        semester_selection->addItem(QString());
        semester_selection->setObjectName("semester_selection");
        semester_selection->setGeometry(QRect(380, 210, 221, 41));
        semester_selection->setFont(font);
        insert_button = new QPushButton(centralwidget);
        insert_button->setObjectName("insert_button");
        insert_button->setGeometry(QRect(20, 380, 101, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka")});
        font2.setPointSize(12);
        insert_button->setFont(font2);
        delete_button = new QPushButton(centralwidget);
        delete_button->setObjectName("delete_button");
        delete_button->setGeometry(QRect(170, 380, 91, 41));
        delete_button->setFont(font2);
        search_button = new QPushButton(centralwidget);
        search_button->setObjectName("search_button");
        search_button->setGeometry(QRect(320, 380, 91, 41));
        search_button->setFont(font2);
        displayall_button = new QPushButton(centralwidget);
        displayall_button->setObjectName("displayall_button");
        displayall_button->setGeometry(QRect(460, 380, 91, 41));
        displayall_button->setFont(font2);
        admin_exit_button = new QPushButton(centralwidget);
        admin_exit_button->setObjectName("admin_exit_button");
        admin_exit_button->setGeometry(QRect(590, 380, 91, 41));
        admin_exit_button->setFont(font2);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 711, 451));
        frame->setStyleSheet(QString::fromUtf8("border-color: 4px solid rgb(85, 170, 127);"));
        frame->setFrameShape(QFrame::Shape::Box);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame->setLineWidth(3);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 30, 171, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sitka")});
        font3.setPointSize(14);
        lineEdit->setFont(font3);
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(90, 90, 171, 41));
        lineEdit_2->setFont(font3);
        lineEdit_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(90, 150, 171, 41));
        lineEdit_3->setFont(font3);
        lineEdit_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_4 = new QLineEdit(frame);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(90, 210, 171, 41));
        lineEdit_4->setFont(font3);
        lineEdit_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEdit_5 = new QLineEdit(frame);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(90, 270, 171, 41));
        lineEdit_5->setFont(font3);
        lineEdit_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Admin->setCentralWidget(centralwidget);
        frame->raise();
        ID_input->raise();
        name_input->raise();
        department_input->raise();
        cgpa_input->raise();
        semester_selection->raise();
        insert_button->raise();
        delete_button->raise();
        search_button->raise();
        displayall_button->raise();
        admin_exit_button->raise();
        menubar = new QMenuBar(Admin);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 796, 33));
        Admin->setMenuBar(menubar);
        statusbar = new QStatusBar(Admin);
        statusbar->setObjectName("statusbar");
        Admin->setStatusBar(statusbar);

        retranslateUi(Admin);
        QObject::connect(ID_input, &QLineEdit::editingFinished, ID_input, qOverload<>(&QLineEdit::copy));
        QObject::connect(name_input, &QLineEdit::editingFinished, name_input, qOverload<>(&QLineEdit::copy));
        QObject::connect(department_input, &QLineEdit::editingFinished, department_input, qOverload<>(&QLineEdit::copy));
        QObject::connect(semester_selection, &QComboBox::activated, semester_selection, &QComboBox::setCurrentIndex);
        QObject::connect(cgpa_input, &QLineEdit::editingFinished, cgpa_input, qOverload<>(&QLineEdit::copy));
        QObject::connect(insert_button, &QPushButton::clicked, insert_button, qOverload<>(&QPushButton::show));
        QObject::connect(delete_button, &QPushButton::clicked, delete_button, qOverload<>(&QPushButton::show));
        QObject::connect(search_button, &QPushButton::clicked, search_button, qOverload<>(&QPushButton::show));
        QObject::connect(displayall_button, &QPushButton::clicked, displayall_button, qOverload<>(&QPushButton::show));

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Admin", nullptr));
        ID_input->setPlaceholderText(QCoreApplication::translate("Admin", "enter your ID", nullptr));
        name_input->setPlaceholderText(QCoreApplication::translate("Admin", "enter your name", nullptr));
        department_input->setPlaceholderText(QCoreApplication::translate("Admin", "enter your department", nullptr));
        cgpa_input->setPlaceholderText(QCoreApplication::translate("Admin", "enter your CGPA (0.00)", nullptr));
        semester_selection->setItemText(0, QCoreApplication::translate("Admin", "1", nullptr));
        semester_selection->setItemText(1, QCoreApplication::translate("Admin", "2", nullptr));
        semester_selection->setItemText(2, QCoreApplication::translate("Admin", "3", nullptr));
        semester_selection->setItemText(3, QCoreApplication::translate("Admin", "4", nullptr));
        semester_selection->setItemText(4, QCoreApplication::translate("Admin", "5", nullptr));
        semester_selection->setItemText(5, QCoreApplication::translate("Admin", "6", nullptr));
        semester_selection->setItemText(6, QCoreApplication::translate("Admin", "7", nullptr));
        semester_selection->setItemText(7, QCoreApplication::translate("Admin", "8", nullptr));

        semester_selection->setPlaceholderText(QCoreApplication::translate("Admin", "select semester", nullptr));
        insert_button->setText(QCoreApplication::translate("Admin", "INSERT", nullptr));
        delete_button->setText(QCoreApplication::translate("Admin", "DELETE", nullptr));
        search_button->setText(QCoreApplication::translate("Admin", "SEARCH", nullptr));
        displayall_button->setText(QCoreApplication::translate("Admin", "DISPLAY", nullptr));
        admin_exit_button->setText(QCoreApplication::translate("Admin", "EXIT", nullptr));
        lineEdit->setText(QCoreApplication::translate("Admin", "ID", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Admin", "Name", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Admin", "Department", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("Admin", "Semester", nullptr));
        lineEdit_5->setText(QCoreApplication::translate("Admin", "CGPA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
