#include "mainwindow.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>

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

    // set current displayed page to index
    currentDisplayedPage = 0;

    // add widgets to the central widget layout
    centralWidgetLayout->addWidget(navbar);
    centralWidgetLayout->addStretch();

    // connect stuff
    connect(navbar, &Navbar::indexButtonPressed, this, &MainWindow::displayIndexPage);
    connect(navbar, &Navbar::newButtonPressed, this, &MainWindow::displayNewItemPage);
}

void MainWindow::displayIndexPage()
{
    qDebug() << "should now display index page";
}

void MainWindow::displayNewItemPage()
{
    qDebug() << "should now display new item page";
}