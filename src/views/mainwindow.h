#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../models/library.h"
#include "navbar.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

private:
  Library *library;

  Navbar *navbar;
  int currentDisplayedPage; // index page = 0, new item page = 1

public:
  MainWindow(Library *library);

private slots:
  void displayIndexPage();
  void displayNewItemPage();
};

#endif