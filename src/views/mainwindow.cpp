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

    // create index page and give it fixed dimensions
    indexPage = new IndexPage(this, library);
    indexPage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // set background color
    QPalette indexPagePalette;
    indexPagePalette.setColor(QPalette::Window, "#D9D9D9");
    indexPage->setPalette(indexPagePalette);
    indexPage->setAutoFillBackground(true);
    indexPage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // create new item page and give it fixed dimensions
    newItemPage = new NewItemPage(this);
    newItemPage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // set background color
    QPalette newItemPagePalette;
    newItemPagePalette.setColor(QPalette::Window, "#5F3D3D");
    newItemPage->setPalette(newItemPagePalette);
    newItemPage->setAutoFillBackground(true);

    // add widgets to the central widget layout
    centralWidgetLayout->addWidget(navbar);
    centralWidgetLayout->addWidget(indexPage);
    centralWidgetLayout->addWidget(newItemPage);

    // display index page
    displayIndexPage();

    // connect stuff
    connect(navbar, &Navbar::indexButtonPressed, this, &MainWindow::displayIndexPage);
    connect(navbar, &Navbar::newButtonPressed, this, &MainWindow::displayNewItemPage);
}

void MainWindow::displayIndexPage()
{
    indexPage->show();
    newItemPage->hide();
}

void MainWindow::displayNewItemPage()
{
    newItemPage->show();
    indexPage->hide();
}