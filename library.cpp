#include "library.h"

#include "debugvisitor.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QIODevice>

#include "book.h"
#include "movie.h"

#include <QJsonDocument>
#include <QDebug>

Library::Library()
{
}

void Library::addItem(Item *item)
{
    items.push_back(item);
    saveItems();
}

void Library::debugItems() const
{
    for(auto i : items){
        i->accept(new DebugVisitor());
    }
}

void Library::saveItems() const
{
    QJsonArray jsonArray;

    for (auto i : items) {
        QJsonObject itemJsonObject;

        itemJsonObject["id"] = i->getId();
        itemJsonObject["title"] = i->getTitle();

        if (auto book = dynamic_cast<Book *>(i)) {
            itemJsonObject["type"] = "Book";
            itemJsonObject["author"] = book->getAuthor();
        }
        else if (auto movie = dynamic_cast<Movie *>(i)) {
            itemJsonObject["type"] = "Movie";
            itemJsonObject["year"] = movie->getYear();
        }

        jsonArray.append(itemJsonObject);
    }

    QJsonDocument jsonDoc(jsonArray);

    QFile storageFile("storage.json");
    if (!storageFile.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing:" << storageFile.errorString();
        return;
    }

    storageFile.resize(0);

    if (storageFile.write(jsonDoc.toJson()) == -1) {
        qDebug() << "Failed to write to file:" << storageFile.errorString();
    }

    storageFile.close();

    qDebug() << "JSON data written to storage";
    qDebug() << "Generated JSON data:" << jsonDoc.toJson();
}
