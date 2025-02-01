#include "library.h"

#include "debugvisitor.h"

Library::Library()
{
}

void Library::addItem(Item *item)
{
    items.push_back(item);
}

void Library::debugItems() const
{
    for(auto i : items){
        i->accept(new DebugVisitor());
    }
}
