#include "library.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include "book.h"
#include "movie.h"

Library::Library()
    : jsonStoragePath("src/storage/items.json")
{
    loadItemsFromJsonStorage(jsonStoragePath);
}

void Library::addItem(std::unique_ptr<Item> item)
{
    items.push_back(std::move(item));
    saveItemsToJsonStorage(jsonStoragePath);
}

void Library::removeItem(int id)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            items.erase(it);
            break;
        }
    }
    saveItemsToJsonStorage(jsonStoragePath);
}

Item *Library::getItem(int id) const
{
    for (const auto &item : items)
    {
        if (item->getId() == id)
        {
            return item.get();
        }
    }
    return nullptr;
}

std::vector<Item *> Library::getAllItems() const
{
    std::vector<Item *> result;
    for (const auto &item : items)
    {
        result.push_back(item.get());
    }
    return result;
}

void Library::deleteAllItems()
{
    items.clear();
    saveItemsToJsonStorage(jsonStoragePath);
}

void Library::saveItemsToJsonStorage(const QString &filePath) const
{
    QJsonArray jsonArray;
    for (const auto &item : items)
    {
        QJsonObject jsonObject;
        jsonObject["id"] = item->getId();
        jsonObject["title"] = item->getTitle();

        if (dynamic_cast<Book *>(item.get()))
        {
            jsonObject["type"] = "book";
            jsonObject["author"] = static_cast<Book *>(item.get())->getAuthor();
        }
        else if (dynamic_cast<Movie *>(item.get()))
        {
            jsonObject["type"] = "movie";
            jsonObject["releaseYear"] = static_cast<Movie *>(item.get())->getReleaseYear();
        }

        jsonArray.append(jsonObject);
    }

    QJsonDocument jsonDoc(jsonArray);
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly))
    {
        // qDebug() << "File opened for writing:" << filePath;
        file.write(jsonDoc.toJson());
        file.close();
        // qDebug() << "File written and closed:" << filePath;
    }
    else
    {
        qDebug() << "Failed to open file for writing:" << filePath;
    }
}

void Library::loadItemsFromJsonStorage(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        // qDebug() << "Failed to open file for reading:" << filePath;
        return;
    }

    // qDebug() << "File opened for reading:" << filePath;
    QByteArray data = file.readAll();
    file.close();
    // qDebug() << "File read and closed:" << filePath;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QJsonArray jsonArray = jsonDoc.array();

    items.clear();
    for (const QJsonValue &value : jsonArray)
    {
        QJsonObject jsonObject = value.toObject();
        int id = jsonObject["id"].toInt();
        QString title = jsonObject["title"].toString();
        QString type = jsonObject["type"].toString();

        if (type == "book")
        {
            QString author = jsonObject["author"].toString();
            items.push_back(std::make_unique<Book>(id, title, author));
        }
        else if (type == "movie")
        {
            int releaseYear = jsonObject["releaseYear"].toInt();
            items.push_back(std::make_unique<Movie>(id, title, releaseYear));
        }
    }
}