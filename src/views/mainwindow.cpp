#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(Library *library, QWidget *parent)
    : QMainWindow(parent), library(library)
{
    setWindowTitle("Qt Library");
    resize(800, 600);

    // Create central widget
    QWidget *centralWidget = new QWidget(this);

    // Create layout
    QHBoxLayout *layout = new QHBoxLayout(centralWidget); // Add a layout to the central widget
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    setCentralWidget(centralWidget); // Set the central widget of the main window
}

MainWindow::~MainWindow()
{
}
