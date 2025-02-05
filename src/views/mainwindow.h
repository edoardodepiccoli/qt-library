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

public:
  MainWindow(Library *library);
};

#endif