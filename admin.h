//
// Created by hp on 1/14/2025.
//

#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Admin; }
QT_END_NAMESPACE

class Admin : public QMainWindow {
    Q_OBJECT

    public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin() override;

private:
    Ui::Admin *ui;

    private slots:
    void on_search_button_clicked();
    void on_insert_button_clicked();
    void on_displayall_button_clicked();
    void on_delete_button_clicked();
    void on_admin_exit_button_clicked();
};

#endif //ADMIN_H