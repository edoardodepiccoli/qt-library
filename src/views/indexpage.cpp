#include "indexpage.h"

#include <QVBoxLayout>

IndexPage::IndexPage(QWidget *parent)
    : QWidget(parent)
{
  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  setLayout(mainLayout);
}