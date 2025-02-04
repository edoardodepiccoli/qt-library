#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>

MainWindow::MainWindow(Library *library, QWidget *parent)
    : QMainWindow(parent), library(library)
{
    setWindowTitle("Qt Library");
    resize(800, 600);

    // Create central widget
    QWidget *centralWidget = new QWidget(this);

    // Create layout
    QHBoxLayout *layout = new QHBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // Create scroll area
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // Create container for items
    itemsContainer = new QWidget();
    QVBoxLayout *itemsLayout = new QVBoxLayout(itemsContainer);
    itemsLayout->setAlignment(Qt::AlignTop);
    scrollArea->setWidget(itemsContainer);

    // Add scroll area to layout
    layout->addWidget(scrollArea);
    setCentralWidget(centralWidget);

    // Refresh items display
    refreshItemsDisplay();
}

MainWindow::~MainWindow()
{
}

void MainWindow::refreshItemsDisplay()
{
    // Clear existing widgets
    QLayout *layout = itemsContainer->layout();
    while (layout->count() > 0)
    {
        QLayoutItem *item = layout->takeAt(0);
        delete item->widget();
        delete item;
    }

    // Add widgets for each library item
    for (Item *item : library->getAllItems())
    {
        item->accept(&visitor);
        QWidget *itemWidget = visitor.getWidget();
        if (itemWidget)
        {
            itemsContainer->layout()->addWidget(itemWidget);
        }
    }
}
