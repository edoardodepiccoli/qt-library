#ifndef MOVIEWIDGET_H
#define MOVIEWIDGET_H

#include <QWidget>
#include "../models/movie.h"

class MovieWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MovieWidget(Movie *movie, QWidget *parent = nullptr);

signals:
    void deleteRequested();

private slots:
    void handleDeleteClick();
};

#endif // MOVIEWIDGET_H