#include "mainwindow.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>

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

    // Create actions layout
    QHBoxLayout *actionsLayout = new QHBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // Create actions container
    QWidget *actionsContainer = new QWidget(centralWidget);
    actionsContainer->setLayout(actionsLayout);

    // Create search bar
    searchBox = new QLineEdit(centralWidget);
    searchBox->setPlaceholderText("Search...");
    searchBox->setMaximumHeight(30);
    searchBox->setStyleSheet("QLineEdit { padding: 5px; background-color: #2D2D2D; color: #FFFFFF; border: 1px solid #3D3D3D; }");
    connect(searchBox, &QLineEdit::textChanged, this, &MainWindow::handleSearch);

    // Create and add items container
    itemsContainer = new ItemsContainer(library);

    // Create new item page button
    QPushButton *newItemButton = new QPushButton(centralWidget);
    newItemButton->setText("NEW ITEM");
    newItemButton->setStyleSheet("QPushButton { padding: 10px; margin-bottom: 10px; margin-top: 10px; background-color: #3D3D3D; color: #D9D9D9; border: none; text-align: left } QPushButton::hover { background-color: #D9D9D9; color: #3D3D3D }");
    newItemButton->setCursor(Qt::PointingHandCursor);
    newItemButton->setFixedHeight(50);

    actionsLayout->addWidget(searchBox, 0);
    actionsLayout->addWidget(newItemButton, 0);
    layout->addWidget(actionsContainer);
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
