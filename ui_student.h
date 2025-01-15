/********************************************************************************
** Form generated from reading UI file 'student.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_H
#define UI_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Student
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Student)
    {
        if (Student->objectName().isEmpty())
            Student->setObjectName("Student");
        Student->resize(730, 534);
        Student->setTabShape(QTabWidget::TabShape::Rounded);
        centralwidget = new QWidget(Student);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(150, 140, 161, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sitka")});
        font.setPointSize(16);
        lineEdit->setFont(font);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(150, 230, 161, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka")});
        font1.setPointSize(14);
        lineEdit_2->setFont(font1);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(390, 140, 171, 41));
        lineEdit_3->setEchoMode(QLineEdit::EchoMode::Password);
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(390, 230, 171, 41));
        lineEdit_4->setEchoMode(QLineEdit::EchoMode::Normal);
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(250, 40, 221, 41));
        lineEdit_5->setFont(font1);
        lineEdit_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 0, 621, 441));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::Shape::Box);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame->setLineWidth(5);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 340, 101, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sitka")});
        font2.setPointSize(12);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(350, 340, 91, 41));
        pushButton_2->setFont(font2);
        Student->setCentralWidget(centralwidget);
        frame->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        lineEdit_4->raise();
        lineEdit_5->raise();
        menubar = new QMenuBar(Student);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 730, 33));
        Student->setMenuBar(menubar);
        statusbar = new QStatusBar(Student);
        statusbar->setObjectName("statusbar");
        Student->setStatusBar(statusbar);

        retranslateUi(Student);
        QObject::connect(pushButton, &QPushButton::clicked, pushButton, qOverload<>(&QPushButton::show));
        QObject::connect(pushButton_2, &QPushButton::clicked, pushButton_2, qOverload<>(&QPushButton::show));

        QMetaObject::connectSlotsByName(Student);
    } // setupUi

    void retranslateUi(QMainWindow *Student)
    {
        Student->setWindowTitle(QCoreApplication::translate("Student", "Student", nullptr));
        lineEdit->setText(QCoreApplication::translate("Student", "Enter ID", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Student", "Enter Name", nullptr));
        lineEdit_4->setText(QString());
        lineEdit_5->setText(QCoreApplication::translate("Student", "Retrive your Data", nullptr));
        pushButton->setText(QCoreApplication::translate("Student", "Retrive", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Student", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Student: public Ui_Student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_H
