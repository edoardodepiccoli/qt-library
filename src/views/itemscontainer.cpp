#include "itemscontainer.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>

ItemsContainer::ItemsContainer(QWidget *parent, Library *library)
    : QWidget(parent), library(library)
{
  QVBoxLayout *mainLayout = new QVBoxLayout(this);

  // scroll area
  QScrollArea *scrollArea = new QScrollArea(this);
  scrollArea->setWidgetResizable(true);

  // container widget for the items
  // apparently you cannot add items directly to the scrollbar
  QWidget *scrollWidget = new QWidget();
  QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);

  // add items to the container widget
  for (auto item : library->getAllItems())
  {
    QWidget *itemWidget = new QWidget(scrollWidget);
    QVBoxLayout *itemWidgetLayout = new QVBoxLayout(itemWidget);

    QLabel *itemWidgetLabel = new QLabel(itemWidget);
    itemWidgetLabel->setText(item->getTitle());

    itemWidgetLayout->addWidget(itemWidgetLabel);
    scrollLayout->addWidget(itemWidget);
  }

  scrollWidget->setLayout(scrollLayout);
  scrollArea->setWidget(scrollWidget);

  // add scroll area to main layout
  mainLayout->addWidget(scrollArea);

  setLayout(mainLayout);
}
