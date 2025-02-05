#ifndef ITEMSCONTAINER_H
#define ITEMSCONTAINER_H

#include <QWidget>

#include "../models/library.h"

class ItemsContainer : public QWidget
{
  Q_OBJECT

private:
  Library *library;

public:
  ItemsContainer(QWidget *parent, Library *library);
};

#endif
