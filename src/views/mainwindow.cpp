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

    // Create and add sidebar
    sidebar = new Sidebar(this);
    sidebar->setFixedWidth(66);
    layout->addWidget(sidebar);

    // Create views
    searchView = new SearchView(this);
    formView = new FormView(this);

    // Initially show search view and hide form view
    layout->addWidget(searchView);
    layout->addWidget(formView);
    formView->hide();

    // Connect sidebar signals
    connect(sidebar, &Sidebar::searchButtonClicked, this, &MainWindow::handleSearchView);
    connect(sidebar, &Sidebar::addButtonClicked, this, &MainWindow::handleFormView);

    setCentralWidget(centralWidget); // Set the central widget of the main window
}

void MainWindow::handleSearchView()
{
    searchView->show();
    formView->hide();
}

void MainWindow::handleFormView()
{
    searchView->hide();
    formView->show();
}

MainWindow::~MainWindow()
{
}
