#include "widgetvisitor.h"
#include "../models/book.h"
#include "../models/movie.h"

#include <QPainter>
#include <QIcon>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

WidgetVisitor::WidgetVisitor() : widget(nullptr) {}

void WidgetVisitor::visit(Book *book)
{
    widget = new BookWidget(book);
    visitedItem = book;
}

void WidgetVisitor::visit(Movie *movie)
{
    widget = new MovieWidget(movie);
    visitedItem = movie;
}

QWidget *WidgetVisitor::getWidget() const
{
    return widget;
}

Item *WidgetVisitor::getVisitedItem() const
{
    return visitedItem;
}