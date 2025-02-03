#include "mainwindow.h"

MainWindow::MainWindow(Library *library, QWidget *parent)
    : QMainWindow(parent), library(library)
{
    setWindowTitle("Qt Library");
    resize(800, 600);
}

MainWindow::~MainWindow()
{
}
