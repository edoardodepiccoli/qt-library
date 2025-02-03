#include "mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(Library *library, QWidget *parent)
    : QMainWindow(parent), library(library)
{
    setWindowTitle("Qt Library");
    resize(800, 600);

    // Create central widget and layout
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);

    // Create and add sidebar
    sidebar = new Sidebar(this);
    sidebar->setFixedWidth(150);
    layout->addWidget(sidebar);

    // Add stretch to push sidebar to the left
    layout->addStretch();

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}
