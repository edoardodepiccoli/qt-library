#ifndef ITEMSCONTAINER_H
#define ITEMSCONTAINER_H

#include <QWidget>
#include "../models/library.h"
#include "../visitors/widgetvisitor.h"

class QVBoxLayout;
class QScrollArea;

class ItemsContainer : public QWidget
{
  Q_OBJECT

public:
  explicit ItemsContainer(Library *library, QWidget *parent = nullptr);

  void refreshItems();

signals:
  void itemClicked(Item *item);

private:
  Library *library;

  QWidget *containerWidget;
  QScrollArea *scrollArea;

  WidgetVisitor visitor;
};

#endif // ITEMSCONTAINER_H
