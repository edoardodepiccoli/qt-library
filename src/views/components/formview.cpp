#include "formview.h"

#include <QHBoxLayout>
#include <QPalette>

FormView::FormView(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    QWidget *testWidget = new QWidget(this);

    QPalette testPalette = testWidget->palette();
    testPalette.setColor(QPalette::Window, QColor(144, 238, 144)); // Light green
    testWidget->setAutoFillBackground(true);
    testWidget->setPalette(testPalette);

    layout->addWidget(testWidget, 1); // Add stretch factor of 1

    setLayout(layout);
}

FormView::~FormView()
{
}