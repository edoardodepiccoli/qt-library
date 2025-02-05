#include "mainwindow.h"
#include <QHBoxLayout>
#include <QLineEdit>

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
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // Create search bar
    searchBox = new QLineEdit(centralWidget);
    searchBox->setPlaceholderText("Search...");
    searchBox->setMaximumHeight(50);
    searchBox->setStyleSheet("QLineEdit { padding: 10px; background-color: #2D2D2D; color: #FFFFFF; border: 1px solid #3D3D3D; }");
    connect(searchBox, &QLineEdit::textChanged, this, &MainWindow::handleSearch);

    // Create and add items container
    itemsContainer = new ItemsContainer(library);

    layout->addWidget(searchBox);
    layout->addWidget(itemsContainer);
    setCentralWidget(centralWidget);

    // Initial refresh
    itemsContainer->refreshItems();
}

void MainWindow::handleSearch()
{
    QString searchTerm = searchBox->text().toLower(); // Get the search term and convert to lowercase for case-insensitive comparison
    itemsContainer->setActiveSearchQuery(searchTerm);
    itemsContainer->refreshItems();
}

MainWindow::~MainWindow()
{
}
