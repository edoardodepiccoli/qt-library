#include "searchsection.h"

#include <QVBoxLayout>
#include <QPalette>
#include <QWidget>
#include <QLineEdit>
#include <QScrollArea>

SearchSection::SearchSection(QWidget *parent)
{
    // Set background color
    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor("#1E1E1E"));
    setAutoFillBackground(true);
    setPalette(pal);

    // Create vertical layout
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setContentsMargins(8, 8, 8, 0);
    verticalLayout->setSpacing(8);

    // Create search bar
    searchBar = new QWidget(this);
    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Search...");

    // Style the line edit
    lineEdit->setStyleSheet(
        "QLineEdit {"
        "    padding: 8px 12px;"
        "    border-radius: 12px;"
        "    background-color: #383838;"
        "    color: #D9D9D9;"
        "    border: none;"
        "}"
        "QLineEdit::placeholder {"
        "    color: #808080;"
        "}");

    QVBoxLayout *searchBarLayout = new QVBoxLayout(searchBar);
    searchBarLayout->setContentsMargins(0, 0, 0, 0); // Remove margins
    searchBarLayout->addWidget(lineEdit);
    searchBar->setFixedHeight(50);

    // Add the serach bar to the layout
    verticalLayout->addWidget(searchBar);

    // Test widgets bottom
    QWidget *secondTestWidget = new QWidget(this);
    QPalette secondTestPalette = secondTestWidget->palette();
    secondTestPalette.setColor(QPalette::Window, QColor(173, 216, 230)); // Light blue
    secondTestWidget->setAutoFillBackground(true);
    secondTestWidget->setPalette(secondTestPalette);
    verticalLayout->addWidget(secondTestWidget);

    // Set layout for widgets at the bottom
    QVBoxLayout *secondTestWidgetLayout = new QVBoxLayout(secondTestWidget);
    secondTestWidgetLayout->setContentsMargins(0, 0, 0, 0);
    secondTestWidgetLayout->setSpacing(8);

    // Create a scroll area
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setStyleSheet("QScrollArea { border: none; }");

    // Create a container widget for the scroll area
    QWidget *scrollAreaContent = new QWidget(scrollArea);
    QVBoxLayout *scrollAreaLayout = new QVBoxLayout(scrollAreaContent);
    scrollAreaLayout->setContentsMargins(0, 0, 0, 0);
    scrollAreaLayout->setSpacing(8);

    // Add widgets to the scroll area layout
    for (int i = 0; i < 10; i++)
    {
        QWidget *widget = new QWidget(this);
        QPalette widgetPalette = widget->palette();
        widgetPalette.setColor(QPalette::Window, QColor(255, 182, 193)); // Light red
        widget->setAutoFillBackground(true);
        widget->setPalette(widgetPalette);
        widget->setFixedHeight(100);
        scrollAreaLayout->addWidget(widget);
    }

    // Set the scroll area content
    scrollAreaContent->setLayout(scrollAreaLayout);
    scrollArea->setWidget(scrollAreaContent);

    // Add the scroll area to the second test widget layout
    secondTestWidgetLayout->addWidget(scrollArea);

    // Set layout
    setLayout(verticalLayout);
}

SearchSection::~SearchSection()
{
}