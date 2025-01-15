//
// Created by hp on 1/14/2025.
//

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "admin.h"   // Include the Admin class
#include "student.h" // Include the Student class
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Connect buttons to their respective slots (if not already connected in Qt Designer)
    connect(ui->Admin_button, &QPushButton::clicked, this, &MainWindow::on_Admin_button_clicked);
    connect(ui->Student_name, &QPushButton::clicked, this, &MainWindow::on_Student_name_clicked);
    connect(ui->ExitMain_button, &QPushButton::clicked, this, &MainWindow::on_ExitMain_button_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Slot for Admin_button
void MainWindow::on_Admin_button_clicked() {
    // Create an instance of Admin UI
    Admin *adminWindow = new Admin(this);
    adminWindow->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete when closed
    adminWindow->show(); // Show the Admin window
}

// Slot for Student_button
void MainWindow::on_Student_name_clicked() {
    // Create an instance of Student UI
    Student *studentWindow = new Student(this);
    studentWindow->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete when closed
    studentWindow->show(); // Show the Student window
}

// Slot for ExitMain_button
void MainWindow::on_ExitMain_button_clicked() {
    QApplication::quit(); // Exit the program
}
