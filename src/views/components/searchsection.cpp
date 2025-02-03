#include "searchsection.h"

#include <QVBoxLayout>
#include <QPalette>
#include <QWidget>
#include <QLineEdit>

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

    // Test widgets right
    QWidget *secondTestWidget = new QWidget(this);
    QPalette secondTestPalette = secondTestWidget->palette();
    secondTestPalette.setColor(QPalette::Window, QColor(173, 216, 230)); // Light blue
    secondTestWidget->setAutoFillBackground(true);
    secondTestWidget->setPalette(secondTestPalette);
    verticalLayout->addWidget(secondTestWidget);

    // Set layout
    setLayout(verticalLayout);
}

SearchSection::~SearchSection()
{
}