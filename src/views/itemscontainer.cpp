#include "itemscontainer.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QWidget>
#include <QPushButton>

ItemsContainer::ItemsContainer(QWidget *parent, Library *library)
    : QWidget(parent), library(library)
{

  refreshItems();
}

void ItemsContainer::refreshItems()
{
  // Remove and delete old layout if it exists
  if (layout())
  {
    QLayoutItem *itemInsideLayout;
    while ((itemInsideLayout = layout()->takeAt(0)) != nullptr)
    {
      delete itemInsideLayout->widget(); // Delete the widget inside the layout
      delete itemInsideLayout;           // Delete the layout item itself
    }
    delete layout();
  }

  QVBoxLayout *mainLayout = new QVBoxLayout(this);

  // Scroll area
  QScrollArea *scrollArea = new QScrollArea(this);
  scrollArea->setWidgetResizable(true);

  // Container widget for items
  QWidget *scrollWidget = new QWidget();
  QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);

  // add items
  // should replace this with a visitor
  // probably add a signal to the widget so you can still connect it to the
  // handleDeleteItem method
  for (auto item : library->getAllItems())
  {
    QWidget *itemWidget = new QWidget(scrollWidget);
    QHBoxLayout *itemWidgetLayout = new QHBoxLayout(itemWidget);

    QLabel *itemWidgetLabel = new QLabel(itemWidget);
    itemWidgetLabel->setText(item->getTitle());

    QPushButton *itemWidgetDeleteButton = new QPushButton(itemWidget);
    itemWidgetDeleteButton->setText("DELETE");

    connect(itemWidgetDeleteButton, &QPushButton::clicked, this, [this, id = item->getId()]()
            { handleDeleteItem(id); });

    itemWidgetLayout->addWidget(itemWidgetLabel);
    itemWidgetLayout->addWidget(itemWidgetDeleteButton);

    scrollLayout->addWidget(itemWidget);
  }

  scrollWidget->setLayout(scrollLayout);
  scrollArea->setWidget(scrollWidget);

  // Add scroll area to main layout
  mainLayout->addWidget(scrollArea);

  setLayout(mainLayout);
}

void ItemsContainer::handleDeleteItem(int id)
{
  library->removeItem(id);
  refreshItems();
}