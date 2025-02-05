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

private:
  Library *library;

  QWidget *containerWidget;
  QScrollArea *scrollArea;

  WidgetVisitor visitor;

  QString activeSearchQuery;

public:
  explicit ItemsContainer(Library *library, QWidget *parent = nullptr);

  void refreshItems();
  void setActiveSearchQuery(QString &query);

private slots:
  void handleDeleteRequested(Item *item);
};

#endif // ITEMSCONTAINER_H
