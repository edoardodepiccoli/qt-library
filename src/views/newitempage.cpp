#include "newitempage.h"

#include <QVBoxLayout>

NewItemPage::NewItemPage(QWidget *parent)
    : QWidget(parent)
{
  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  setLayout(mainLayout);
}
