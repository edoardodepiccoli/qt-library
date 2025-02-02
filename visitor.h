#ifndef VISITOR_H
#define VISITOR_H

class Item;
class Book;
class Movie;

class Visitor
{
protected:
    Visitor();
    ~Visitor() = default;
public:
    virtual void visitItem(Item *item) const = 0;
    virtual void visitBook(Book *book) const = 0;
    virtual void visitMovie(Movie *movie) const = 0;
};

#endif // VISITOR_H
