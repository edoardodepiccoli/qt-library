#include "searchview.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPalette>

SearchView::SearchView(QWidget *parent)
{
    // Create horizontal layout
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    // Create and add search section
    searchSection = new SearchSection(this);
    layout->addWidget(searchSection, 1);

    // Test widgets right
    QWidget *secondTestWidget = new QWidget(this);
    QPalette secondTestPalette = secondTestWidget->palette();
    secondTestPalette.setColor(QPalette::Window, QColor(173, 216, 230)); // Light blue
    secondTestWidget->setAutoFillBackground(true);
    secondTestWidget->setPalette(secondTestPalette);
    layout->addWidget(secondTestWidget, 1); // Add stretch factor of 1

    // Set layout
    setLayout(layout);
}

SearchView::~SearchView()
{
}