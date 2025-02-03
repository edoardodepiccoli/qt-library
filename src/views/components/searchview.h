#ifndef SEARCHVIEW_H
#define SEARCHVIEW_H

#include <QWidget>

class SearchView : public QWidget
{
    Q_OBJECT

public:
    SearchView(QWidget *parent = nullptr);
    ~SearchView();
};

#endif // SEARCHVIEW_H