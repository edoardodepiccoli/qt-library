#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(Library *library, QWidget *parent)
    : QMainWindow(parent), library(library)
{
    setWindowTitle("Qt Library");
    resize(800, 600);

    // Set dark background color
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor("#1E1E1E"));
    setPalette(darkPalette);
    setAutoFillBackground(true);

    // Create central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setAutoFillBackground(true);
    centralWidget->setPalette(darkPalette);

    // Create layout
    QHBoxLayout *layout = new QHBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // Create and add items container
    itemsContainer = new ItemsContainer(library);
    layout->addWidget(itemsContainer);

    setCentralWidget(centralWidget);

    // Initial refresh
    itemsContainer->refreshItems();
}

MainWindow::~MainWindow()
{
}
