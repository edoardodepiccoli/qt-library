#include "searchview.h"

#include <QHBoxLayout>
#include <QPalette>

SearchView::SearchView(QWidget *parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    QWidget *testWidget = new QWidget(this);

    QPalette testPalette = testWidget->palette();
    testPalette.setColor(QPalette::Window, QColor(255, 182, 193)); // Light pink
    testWidget->setAutoFillBackground(true);
    testWidget->setPalette(testPalette);

    QWidget *secondTestWidget = new QWidget(this);

    QPalette secondTestPalette = secondTestWidget->palette();
    secondTestPalette.setColor(QPalette::Window, QColor(173, 216, 230)); // Light blue
    secondTestWidget->setAutoFillBackground(true);
    secondTestWidget->setPalette(secondTestPalette);

    layout->addWidget(testWidget, 1);       // Add stretch factor of 1
    layout->addWidget(secondTestWidget, 1); // Add stretch factor of 1

    setLayout(layout);
}

SearchView::~SearchView()
{
}