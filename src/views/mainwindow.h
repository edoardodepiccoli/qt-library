#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../models/library.h"
#include "components/sidebar.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Library *library;

    // Main window components
    Sidebar *sidebar;

public:
    MainWindow(Library *library, QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
