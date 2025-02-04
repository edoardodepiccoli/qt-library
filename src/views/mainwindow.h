#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../models/library.h"
#include "../visitors/widgetvisitor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Library *library, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Library *library;

    QWidget *itemsContainer;
    WidgetVisitor visitor;

    void refreshItemsDisplay();
};

#endif // MAINWINDOW_H
