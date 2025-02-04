#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../models/library.h"
#include "itemscontainer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Library *library, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Library *library;
    ItemsContainer *itemsContainer;
};

#endif // MAINWINDOW_H
