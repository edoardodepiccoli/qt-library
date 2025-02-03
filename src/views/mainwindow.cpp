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

    setCentralWidget(centralWidget);
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
