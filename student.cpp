//
// Created by hp on 1/14/2025.
//

#include "student.h"
#include "ui_Student.h"
#include "Hash.h"
#include "mainwindow.h"
#include <QMessageBox> // For message box
#include <stdexcept>   // For exceptions

Student::Student(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Student) {
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,this, &Student::on_pushbutton_clicked);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&Student::on_pushbutton_2_clicked);
}

Student::~Student() {
    delete ui;
}
Hash obj2;

void Student::on_pushbutton_clicked() {
    QString idText = ui->lineEdit_3->text();

    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid ID.");
        return;
    }

    bool ok;
    int id = idText.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid numeric ID.");
        return;
    }

    try {
        // Call the search function
        struct data student = obj2.searchh(id); // Assuming searchh returns student data if found

        // Check if student data was found (you may need to modify this based on your actual implementation)
        if (student.ID == -1) { // Example check, adjust as necessary
            QMessageBox::information(this, "Not Found", "Student ID not found.");
            return;
        }

        // Display the details in a dialog box
        QString details = QString("ID: %1\nName: %2\nDepartment: %3\nCGPA: %4\nSemester: %5")
                              .arg(student.ID)
                              .arg(QString::fromStdString(student.Name))
                              .arg(QString::fromStdString(student.Department))
                              .arg(student.CGPA)
                              .arg(student.Semester);

        QMessageBox::information(this, "Student Details", details);
    } catch (const std::exception &e) {
        // Show an error message if any other exception occurs
        QMessageBox::critical(this, "Error", e.what());
    }
}

void Student::on_pushbutton_2_clicked() {
    // Open a new MainWindow
    MainWindow *mainWindow = new MainWindow(this);
    mainWindow->show();

    // Optionally, close the current Student window
    this->close();
}
