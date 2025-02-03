#include <QApplication>
#include <iostream>
#include <memory>

#include "src/models/item.h"
#include "src/models/book.h"
#include "src/models/movie.h"
#include "src/models/library.h"
#include "src/views/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    system("clear");

    Library library;

    // Delete all items in the library
    // library.deleteAllItems();

    // // Create and add items to the library
    // auto book1 = std::make_unique<Book>(1, "1984", "George Orwell");
    // auto book2 = std::make_unique<Book>("Brave New World", "Aldous Huxley");
    // auto movie1 = std::make_unique<Movie>(2, "Inception", 2010);
    // auto movie2 = std::make_unique<Movie>("The Matrix", 1999);

    // library.addItem(std::move(book1));
    // library.addItem(std::move(book2));
    // library.addItem(std::move(movie1));
    // library.addItem(std::move(movie2));

    // Test getAllItems and debug
    // std::cout << "All items in the library:" << std::endl;
    // for (const auto &item : library.getAllItems())
    // {
    //     item->debug();
    // }

    // // Test getItem
    // std::cout << "\nGet item with ID 1:" << std::endl;
    // Item *item = library.getItem(1);
    // if (item)
    // {
    //     item->debug();
    // }
    // else
    // {
    //     std::cout << "Item not found." << std::endl;
    // }

    // // Test removeItem
    // std::cout << "\nRemoving item with ID 1." << std::endl;
    // library.removeItem(1);

    // std::cout << "\nAll items in the library after removal:" << std::endl;
    // for (const auto &item : library.getAllItems())
    // {
    //     item->debug();
    // }

    // Create and show the main window
    MainWindow window(&library);
    window.show();

    return app.exec();
}