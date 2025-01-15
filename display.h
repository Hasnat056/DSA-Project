#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMessageBox>
#include "hash.h"  // Include your header that contains the Hash class

QT_BEGIN_NAMESPACE
namespace Ui { class Display; }
QT_END_NAMESPACE

class Display : public QMainWindow {  // Ensure it inherits QMainWindow
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display() override;

    // Method to populate the list with student IDs
    void populateList(const std::vector<int>& studentIDs);

    private slots:
        // Slot to handle item selection
        void on_itemSelected();

private:
    Ui::Display *ui;
    Hash obj1;  // Assuming you have a Hash object (if it is elsewhere, adjust accordingly)
};

#endif // DISPLAY_H