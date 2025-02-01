#include "debugvisitor.h"

#include "item.h"
#include "book.h"
#include "movie.h"

#include <QDebug>

DebugVisitor::DebugVisitor() {}

void DebugVisitor::visitItem(Item *item) const
{
    qDebug()
        << "ID: " << item->getId()
        << "TITLE: " << item->getTitle();
}

void DebugVisitor::visitBook(Book *book) const
{
    qDebug()
        << "ID: " << book->getId()
        << "TITLE: " << book->getTitle()
        << "ID: " << book->getAuthor();
}

void DebugVisitor::visitMovie(Movie *movie) const
{
    qDebug()
        << "ID: " << movie->getId()
        << "TITLE: " << movie->getTitle()
        << "ID: " << movie->getYear();
}
