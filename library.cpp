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

std::vector<Item *> Library::getItems() const
{
    return items;
}

void Library::addItem(Item *item)
{
    items.push_back(item);
    saveItems();
}

void Library::deleteItem(int id)
{
    // Use an iterator to find the item with the given ID
    auto it = items.begin();
    while (it != items.end()) {
        if ((*it)->getId() == id) {
            break; // Found the item with the matching ID
        }
        it++;
    }

    // Check if an item was found
    if (it != items.end()) {
        // Delete the item to free memory
        delete *it;
        // Remove the item from the vector
        items.erase(it); // Corrected: Erase only the single item at `it`
        // Save the updated list of items to the JSON file
        saveItems();
        qDebug() << "Item with ID" << id << "deleted successfully.";
    } else {
        qDebug() << "Item with ID" << id << "not found.";
    }
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

    // if (storageFile.open(QIODevice::ReadOnly)) {
    //     QByteArray existingData = storageFile.readAll();
    //     storageFile.close();

    //     qDebug() << "Existing content of storage.json:";
    //     qDebug() << existingData;
    // }

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
    // qDebug() << "Generated JSON data:" << jsonDoc.toJson();
}

void Library::loadItems()
{
    QFile storageFile("storage.json");

    if (!storageFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading:" << storageFile.errorString();
        return;
    }

    QByteArray jsonData = storageFile.readAll();
    storageFile.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull()) {
        qDebug() << "Failed to create JSON document.";
        return;
    }

    if (!jsonDoc.isArray()) {
        qDebug() << "JSON document is not an array.";
        return;
    }

    QJsonArray jsonArray = jsonDoc.array();

    for (const QJsonValue &value : jsonArray) {
        if (!value.isObject()) {
            qDebug() << "JSON value is not an object.";
            continue;
        }

        QJsonObject itemObject = value.toObject();

        QString type = itemObject["type"].toString();
        int id = itemObject["id"].toInt();
        QString title = itemObject["title"].toString();

        if (type == "Book") {
            QString author = itemObject["author"].toString();
            Book *book = new Book(id, title, author);
            items.push_back(book);
        } else if (type == "Movie") {
            int year = itemObject["year"].toInt();
            Movie *movie = new Movie(id, title, year);
            items.push_back(movie);
        } else {
            qDebug() << "Unknown item type:" << type;
        }
    }

    qDebug() << "Items loaded from storage.json";
}
