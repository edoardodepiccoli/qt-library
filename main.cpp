#include "book.h"
#include "library.h"
#include "movie.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Book *book = new Book("harry potter", "jk rowling");
    Movie *movie = new Movie("interstellar", 2015);

    Library *library = new Library();
    library->addItem(book);
    library->addItem(movie);
    library->debugItems();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
