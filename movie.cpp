#include "movie.h"

Movie::Movie(QString title, int year)
    : Item::Item(title), year(year)
{
}

int Movie::getYear() const
{
    return year;
}

void Movie::setYear(int newYear)
{
    year = newYear;
}
