#ifndef MOVIE_H
#define MOVIE_H

#include <QString>
#include "item.h"

class Movie : public Item
{
private:
    int releaseYear;

public:
    Movie(int id, QString title, int releaseYear);
    Movie(QString title, int releaseYear);
    virtual ~Movie();

    int getReleaseYear() const;
    void setReleaseYear(int releaseYear);

    void debug() const override;
};

#endif // MOVIE_H
