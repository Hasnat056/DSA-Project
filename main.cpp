#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Create a QApplication instance
    QApplication app(argc, argv);

    // Create an instance of MainWindow
    MainWindow mainWindow;

    // Show the MainWindow
    mainWindow.show();

    // Start the event loop
    return app.exec();
}
