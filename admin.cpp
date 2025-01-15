#include "admin.h"
#include "ui_Admin.h"
#include "Hash.h"
#include <QMessageBox>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "display.h"

Admin::Admin(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Admin) {
    ui->setupUi(this);

    connect(ui->insert_button, &QPushButton::clicked, this, &Admin::on_insert_button_clicked);
    connect(ui->delete_button, &QPushButton::clicked, this, &Admin::on_delete_button_clicked);
    connect(ui->search_button, &QPushButton::clicked, this, &Admin::on_search_button_clicked);
    connect(ui->admin_exit_button,&QPushButton::clicked,this, &Admin::on_admin_exit_button_clicked);
    connect(ui->displayall_button,&QPushButton::clicked,this, &Admin::on_displayall_button_clicked);
}
Hash obj1;

Admin::~Admin() {
    delete ui;
}

void Admin::on_insert_button_clicked() {
    try {
        struct data student;
        student.ID = ui->ID_input->text().toInt();
        student.Name = ui->name_input->text().toStdString();
        student.Department = ui->department_input->text().toStdString();
        student.Semester = ui->semester_selection->currentText().toInt();
        student.CGPA = ui->cgpa_input->text().toDouble();

        bool success = obj1.insertdata(student);

        if (success==true) {
            QMessageBox::information(this, "Success", "Student inserted successfully!");
            return;
        } if (success==false) {
            QMessageBox::warning(this, "Duplicate Entry", "Student with this ID already exists.");
            return;
        }
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}


void Admin::on_delete_button_clicked() {
    int id = ui->ID_input->text().toInt();
    bool success = obj1.deletedata(id);

    if (success) {
        QMessageBox::information(this, "Success", "Student deleted successfully!");
    } else {
        QMessageBox::warning(this, "Error", "Student with this ID not found in the index.");
    }
}



void Admin::on_search_button_clicked() {
    try {
        int id = ui->ID_input->text().toInt();
        struct data student = obj1.searchh(id);

        QString result = QString("ID: %1\nName: %2\nDepartment: %3\nSemester: %4\nCGPA: %5")
                                 .arg(student.ID)
                                 .arg(QString::fromStdString(student.Name))
                                 .arg(QString::fromStdString(student.Department))
                                 .arg(student.Semester)
                                 .arg(student.CGPA);

        QMessageBox::information(this, "Student Found", result);
        return;
    } catch (const exception &e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}
void Admin::on_admin_exit_button_clicked() {
    MainWindow *mainwindow = new MainWindow(this);
    mainwindow->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete when closed
    mainwindow->show();
}

void Admin::on_displayall_button_clicked() {
    // Get all student IDs from your Hash class or data structure
    std::vector<int> studentIDs = obj1.getIDs();

    // Create and show the Display window
    Display *window = new Display(this);
    window->populateList(studentIDs);  // Pass the list of IDs to the window
    window->show();  // Show the window
}

