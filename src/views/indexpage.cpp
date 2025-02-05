#include "indexpage.h"

#include <QVBoxLayout>

IndexPage::IndexPage(QWidget *parent, Library *library)
    : QWidget(parent), library(library)
{
  QVBoxLayout *mainLayout = new QVBoxLayout(this);

  itemsContainer = new ItemsContainer(this, library);
  itemsContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  QPalette itemsContainerPalette;
  itemsContainerPalette.setColor(QPalette::Window, "#383838");
  itemsContainer->setPalette(itemsContainerPalette);
  itemsContainer->setAutoFillBackground(true);

  mainLayout->addWidget(itemsContainer);

  setLayout(mainLayout);
}