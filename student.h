//
// Created by hp on 1/14/2025.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class Student; }
QT_END_NAMESPACE

class Student : public QMainWindow {
Q_OBJECT

public:
    explicit Student(QWidget *parent = nullptr);
    ~Student() override;

private slots:
    void on_pushbutton_clicked ();
    void on_pushbutton_2_clicked();

private:
    Ui::Student *ui;

};


#endif //STUDENT_H
