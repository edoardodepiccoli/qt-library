#include "mainwindow.h"

#include <QWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(Library *library)
    : library(library)
{
    // create required central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // create layout for central widget
    QVBoxLayout *centralWidgetLayout = new QVBoxLayout(centralWidget);

    // create navbar
    navbar = new Navbar(centralWidget);

    // add widgets to the central widget layout
    centralWidgetLayout->addWidget(navbar);
    centralWidgetLayout->addStretch();

    // connect stuff
}