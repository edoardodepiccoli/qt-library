#ifndef WIDGETVISITOR_H
#define WIDGETVISITOR_H

#include "visitor.h"
#include "../models/movie.h"
#include "../models/book.h"

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class WidgetVisitor : public Visitor
{
private:
    QWidget *widget;

public:
    WidgetVisitor();
    void visit(Movie *movie) override;
    void visit(Book *book) override;
    QWidget *getWidget() const;
};

#endif // WIDGETVISITOR_H