#include <QApplication>
#include <iostream>
#include <memory>

#include "src/models/item.h"
#include "src/models/book.h"
#include "src/models/movie.h"
#include "src/models/library.h"
#include "src/views/mainwindow.h"

void resetLibrary(Library &library)
{
    library.deleteAllItems();
    auto book1 = std::make_unique<Book>(1, "1984", "George Orwell");
    auto book2 = std::make_unique<Book>("Brave New World", "Aldous Huxley");
    auto movie1 = std::make_unique<Movie>(2, "Inception", 2010);
    auto movie2 = std::make_unique<Movie>("The Matrix", 1999);
    auto book3 = std::make_unique<Book>("The Hobbit", "J.R.R. Tolkien");
    auto book4 = std::make_unique<Book>("Dune", "Frank Herbert");
    auto book5 = std::make_unique<Book>("Foundation", "Isaac Asimov");
    auto book6 = std::make_unique<Book>("Neuromancer", "William Gibson");
    auto movie3 = std::make_unique<Movie>("Blade Runner", 1982);
    auto movie4 = std::make_unique<Movie>("The Shawshank Redemption", 1994);
    auto movie5 = std::make_unique<Movie>("Pulp Fiction", 1994);
    auto movie6 = std::make_unique<Movie>("Fight Club", 1999);
    library.addItem(std::move(book1));
    library.addItem(std::move(book2));
    library.addItem(std::move(movie1));
    library.addItem(std::move(movie2));
    library.addItem(std::move(book3));
    library.addItem(std::move(book4));
    library.addItem(std::move(book5));
    library.addItem(std::move(book6));
    library.addItem(std::move(movie3));
    library.addItem(std::move(movie4));
    library.addItem(std::move(movie5));
    library.addItem(std::move(movie6));
}

int main(int argc, char *argv[])
{
    system("clear");
    QApplication app(argc, argv);

    Library library;
    // resetLibrary(library);

    MainWindow window(&library);
    window.resize(800, 400);
    window.show();

    return app.exec();
}