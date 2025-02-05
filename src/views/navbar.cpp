#include "navbar.h"

#include <QHBoxLayout>
#include <QWidget>

Navbar::Navbar(QWidget *parent)
    : QWidget(parent)
{
  QHBoxLayout *navbarLayout = new QHBoxLayout(this);

  indexButton = new QPushButton();
  indexButton->setText("INDEX");

  newButton = new QPushButton();
  newButton->setText("NEW ITEM");

  navbarLayout->addWidget(indexButton);
  navbarLayout->addWidget(newButton);

  connect(indexButton, &QPushButton::click, this, &Navbar::indexButtonPressed);
  connect(newButton, &QPushButton::click, this, &Navbar::newButtonPressed);

  setLayout(navbarLayout);
}