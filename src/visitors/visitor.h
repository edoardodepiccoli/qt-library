#ifndef VISITOR_H
#define VISITOR_H

class Item;
class Book;
class Movie;

class Visitor
{
public:
    virtual void visit(Movie *movie) = 0;
    virtual void visit(Book *book) = 0;
};

#endif // VISITOR_H