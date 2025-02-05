#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../models/library.h"
#include "navbar.h"
#include "indexpage.h"
#include "newitempage.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

private:
  Library *library;

  Navbar *navbar;
  IndexPage *indexPage;
  NewItemPage *newItemPage;

public:
  MainWindow(Library *library);

private slots:
  void displayIndexPage();
  void displayNewItemPage();
};

#endif