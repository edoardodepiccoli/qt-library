#include "navbar.h"

#include <QHBoxLayout>
#include <QWidget>

Navbar::Navbar(QWidget *parent)
    : QWidget(parent)
{
  QHBoxLayout *navbarLayout = new QHBoxLayout(this);
  navbarLayout->setContentsMargins(0, 0, 0, 0);

  indexButton = new QPushButton();
  indexButton->setText("INDEX");
  indexButton->setCursor(Qt::PointingHandCursor);

  newButton = new QPushButton();
  newButton->setText("NEW ITEM");
  newButton->setCursor(Qt::PointingHandCursor);

  colorIndexButton();

  navbarLayout->addWidget(indexButton);
  navbarLayout->addWidget(newButton);

  connect(indexButton, &QPushButton::clicked, this, &Navbar::indexButtonPressed);
  connect(newButton, &QPushButton::clicked, this, &Navbar::newButtonPressed);

  connect(indexButton, &QPushButton::clicked, this, &Navbar::colorIndexButton);
  connect(newButton, &QPushButton::clicked, this, &Navbar::colorNewButton);

  setLayout(navbarLayout);
}

void Navbar::colorIndexButton()
{
  indexButton->setStyleSheet("background-color: #D9D9D9; color: #323232;");
  newButton->setStyleSheet("background-color: #323232; color: #D9D9D9;");
}

void Navbar::colorNewButton()
{
  newButton->setStyleSheet("background-color: #D9D9D9; color: #323232;");
  indexButton->setStyleSheet("background-color: #323232; color: #D9D9D9;");
}