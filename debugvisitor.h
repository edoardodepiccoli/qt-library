#ifndef DEBUGVISITOR_H
#define DEBUGVISITOR_H

#include "visitor.h"

class DebugVisitor : public Visitor
{
public:
    DebugVisitor();

    void visitItem(Item *item) const;
    void visitBook(Book *book) const;
    void visitMovie(Movie *movie) const;
};

#endif // DEBUGVISITOR_H
