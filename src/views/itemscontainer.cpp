#include "itemscontainer.h"
#include <QVBoxLayout>
#include <QScrollArea>

ItemsContainer::ItemsContainer(Library *library, QWidget *parent)
    : QWidget(parent), library(library)
{
  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->setContentsMargins(0, 0, 0, 0);
  mainLayout->setSpacing(0);

  // Create scroll area
  scrollArea = new QScrollArea();
  scrollArea->setWidgetResizable(true);
  scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

  // Create container for items
  containerWidget = new QWidget();
  QVBoxLayout *itemsLayout = new QVBoxLayout(containerWidget);
  itemsLayout->setAlignment(Qt::AlignTop);
  scrollArea->setWidget(containerWidget);

  mainLayout->addWidget(scrollArea);
  setLayout(mainLayout);
}

void ItemsContainer::refreshItems()
{
  // Clear existing widgets
  QLayout *layout = containerWidget->layout();
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
      containerWidget->layout()->addWidget(itemWidget);
    }
  }
}
