#include "widgetvisitor.h"

#include "../models/book.h"
#include "../models/movie.h"

WidgetVisitor::WidgetVisitor() : widget(nullptr) {}

void WidgetVisitor::visit(Book *book)
{
    widget = new QWidget();
    widget->setFixedHeight(150);

    QVBoxLayout *layout = new QVBoxLayout(widget);

    QLabel *titleLabel = new QLabel("Title: " + book->getTitle());
    QLabel *authorLabel = new QLabel("Author: " + book->getAuthor());

    layout->addWidget(titleLabel);
    layout->addWidget(authorLabel);

    widget->setLayout(layout);
}

void WidgetVisitor::visit(Movie *movie)
{
    widget = new QWidget();
    widget->setFixedHeight(150);

    QVBoxLayout *layout = new QVBoxLayout(widget);

    QLabel *titleLabel = new QLabel("Title: " + movie->getTitle());
    QLabel *yearLabel = new QLabel("Year: " + QString::number(movie->getReleaseYear()));

    layout->addWidget(titleLabel);
    layout->addWidget(yearLabel);

    widget->setLayout(layout);
}

QWidget *WidgetVisitor::getWidget() const
{
    return widget;
}