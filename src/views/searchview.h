#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

#include <QWidget>

#include "components/searchsection.h"

class SearchView : public QWidget
{
    Q_OBJECT

private:
    QWidget *searchSection;

public:
    SearchView(QWidget *parent = nullptr);
    ~SearchView();
};

#endif // SEARCHVIEW_H