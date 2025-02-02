#ifndef MOVIE_H
#define MOVIE_H

#include "item.h"

class Movie : public Item
{
private:
    int year;
public:
    Movie(QString title, int year);
    Movie(int id, QString title, int year);

    virtual void accept(Visitor *visitor);

    int getYear() const;
    void setYear(int newYear);
};

#endif // MOVIE_H
