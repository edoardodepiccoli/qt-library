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
    widget = new QWidget();
    widget->setFixedHeight(150);
    widget->setStyleSheet("background-color: #D9D9D9;");

    QHBoxLayout *mainLayout = new QHBoxLayout(widget);

    // Icon part
    QLabel *iconLabel = new QLabel();
    QIcon icon(":/icons/src/assets/menu_book.svg");
    QPixmap pixmap = icon.pixmap(64, 64);
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(pixmap.rect(), QColor("#323232"));
    iconLabel->setPixmap(pixmap);
    iconLabel->setFixedSize(64, 64);
    mainLayout->addWidget(iconLabel);

    // Details part
    QWidget *detailsWidget = new QWidget();
    QVBoxLayout *detailsLayout = new QVBoxLayout(detailsWidget);
    QLabel *titleLabel = new QLabel("Title: " + book->getTitle());
    QLabel *authorLabel = new QLabel("Author: " + book->getAuthor());
    titleLabel->setStyleSheet("color: #222222;");
    authorLabel->setStyleSheet("color: #222222;");
    detailsLayout->addWidget(titleLabel);
    detailsLayout->addWidget(authorLabel);

    mainLayout->addWidget(detailsWidget);
    widget->setLayout(mainLayout);
}

void WidgetVisitor::visit(Movie *movie)
{
    widget = new QWidget();
    widget->setFixedHeight(150);
    widget->setStyleSheet("background-color: #D9D9D9;");

    QHBoxLayout *mainLayout = new QHBoxLayout(widget);

    // Icon part
    QLabel *iconLabel = new QLabel();
    QIcon icon(":/icons/src/assets/movie.svg");
    QPixmap pixmap = icon.pixmap(64, 64);
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(pixmap.rect(), QColor("#323232"));
    iconLabel->setPixmap(pixmap);
    iconLabel->setFixedSize(64, 64);
    mainLayout->addWidget(iconLabel);

    // Details part
    QWidget *detailsWidget = new QWidget();
    QVBoxLayout *detailsLayout = new QVBoxLayout(detailsWidget);
    QLabel *titleLabel = new QLabel("Title: " + movie->getTitle());
    QLabel *yearLabel = new QLabel("Year: " + QString::number(movie->getReleaseYear()));
    titleLabel->setStyleSheet("color: #222222;");
    yearLabel->setStyleSheet("color: #222222;");
    detailsLayout->addWidget(titleLabel);
    detailsLayout->addWidget(yearLabel);

    mainLayout->addWidget(detailsWidget);
    widget->setLayout(mainLayout);
}

QWidget *WidgetVisitor::getWidget() const
{
    return widget;
}