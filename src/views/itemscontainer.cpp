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
  itemsLayout->setContentsMargins(0, 0, 0, 0);
  itemsLayout->setSpacing(8);
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
      // I know, this sucks and I should fix it, maybe creating a parent class ItemWidget
      // I'll do it later
      if (dynamic_cast<BookWidget *>(itemWidget))
      {
        connect(static_cast<BookWidget *>(itemWidget), &BookWidget::deleteRequested,
                this, [this](Book *book)
                { handleDeleteRequested(book); });
      }
      else if (dynamic_cast<MovieWidget *>(itemWidget))
      {
        connect(static_cast<MovieWidget *>(itemWidget), &MovieWidget::deleteRequested,
                this, [this](Movie *movie)
                { handleDeleteRequested(movie); });
      }
      containerWidget->layout()->addWidget(itemWidget);
    }
  }
}

void ItemsContainer::handleDeleteRequested(Item *item)
{
  library->removeItem(item->getId());
  refreshItems();
}