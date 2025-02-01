#include "movie.h"

Movie::Movie(QString title, int year)
    : Item::Item(title), year(year)
{
}

void Movie::accept(Visitor *visitor)
{
    visitor->visitMovie(this);
}

int Movie::getYear() const
{
    return year;
}

void Movie::setYear(int newYear)
{
    year = newYear;
}
