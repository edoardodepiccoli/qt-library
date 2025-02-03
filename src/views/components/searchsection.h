#ifndef SEARCHSECTION_H
#define SEARCHSECTION_H

#include <QWidget>

class SearchSection : public QWidget
{
    Q_OBJECT
private:
    QWidget *searchBar;


public:
    SearchSection(QWidget *parent = nullptr);
    ~SearchSection();
};

#endif // SEARCHSECTION_H