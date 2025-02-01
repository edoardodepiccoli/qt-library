#include "book.h"
#include "movie.h"
#include "debugvisitor.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    DebugVisitor *debugVisitor = new DebugVisitor();
    Book *book = new Book("harry potter", "jk rowling");
    Movie *movie = new Movie("interstellar", 2015);

    Item *bookItem = book;
    Item *movieItem = movie;

    bookItem->accept(debugVisitor);
    movieItem->accept(debugVisitor);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
