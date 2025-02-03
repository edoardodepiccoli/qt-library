#include "movie.h"

Movie::Movie(int id, QString title, int releaseYear) : Item(id, title), releaseYear(releaseYear)
{
}

Movie::Movie(QString title, int releaseYear) : Item(title), releaseYear(releaseYear)
{
}

Movie::~Movie()
{
}

int Movie::getReleaseYear() const
{
    return releaseYear;
}

void Movie::setReleaseYear(int releaseYear)
{
    this->releaseYear = releaseYear;
}

void Movie::debug() const
{
    qDebug() << "Movie - ID:" << getId() << ", Title:" << getTitle() << ", Release Year:" << releaseYear;
}

void Movie::accept(Visitor *visitor)
{
    visitor->visit(this);
}
