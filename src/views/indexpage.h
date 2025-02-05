#ifndef INDEXPAGE_H
#define INDEXPAGE_H

#include <QWidget>

#include "../models/library.h"
#include "itemscontainer.h"

class IndexPage : public QWidget
{
  Q_OBJECT

private:
  Library *library;

  ItemsContainer *itemsContainer;

public:
  IndexPage(QWidget *parent, Library *library);
};

#endif