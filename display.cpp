#include "display.h"
#include "ui_display.h"
#include "hash.h"  // Include your Hash class that contains the student data

Display::Display(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::Display) {  // Change QMainWindow to QWidget
    ui->setupUi(this);

    // Connect item selection in the list to the on_itemSelected slot
    connect(ui->listWidget, &QListWidget::itemSelectionChanged, this, &Display::on_itemSelected);
}

Display::~Display() {
    delete ui;
}

void Display::populateList(const std::vector<int>& studentIDs) {
    ui->listWidget->clear();  // Clear any existing items in the list

    // Populate the list with student IDs
    for (int id : studentIDs) {
        ui->listWidget->addItem(QString::number(id));  // Add each student ID to the list
    }
}

void Display::on_itemSelected() {
    QListWidgetItem* selectedItem = ui->listWidget->currentItem();
    if (selectedItem) {
        int studentID = selectedItem->text().toInt(); // Get the ID of the selected student

        try {
            // Fetch student details using the ID (you need to implement getStudentDetailsByID)
            struct data student = obj1.searchh(studentID);

            // Display the student details in a message box
            QString details = QString("ID: %1\nName: %2\nDepartment: %3\nCGPA: %4\nSemester: %5")
                                    .arg(student.ID)
                                    .arg(QString::fromStdString(student.Name))
                                    .arg(QString::fromStdString(student.Department))
                                    .arg(student.CGPA)
                                    .arg(student.Semester);

            // Show the details in a QMessageBox
            QMessageBox::information(this, "Student Details", details);
        } catch (const std::exception &e) {
            // Show an error if the student ID is not found
            QMessageBox::critical(this, "Error", e.what());
        }
    }
}