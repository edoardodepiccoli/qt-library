#ifndef BOOKWIDGET_H
#define BOOKWIDGET_H

#include <QWidget>
#include "../models/book.h"

class BookWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BookWidget(Book *book, QWidget *parent = nullptr);
};

#endif // BOOKWIDGET_H
