#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../models/library.h"
#include "components/sidebar.h"
#include "components/searchview.h"
#include "components/formview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Library *library;
    Sidebar *sidebar;
    SearchView *searchView;
    FormView *formView;

private slots:
    void handleSearchView();
    void handleFormView();

public:
    MainWindow(Library *library, QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
