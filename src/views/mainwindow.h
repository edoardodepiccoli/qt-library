#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../models/library.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

private:
  Library *library;

public:
  MainWindow(Library *library);
};

#endif