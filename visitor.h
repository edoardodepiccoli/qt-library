#ifndef VISITOR_H
#define VISITOR_H

class Item;
class Book;
class Movie;

class Visitor
{
private:
    Item *visitedItem;
public:
    Visitor();
};

#endif // VISITOR_H
