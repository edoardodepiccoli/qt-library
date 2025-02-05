#ifndef NAVBAR_H
#define NAVBAR_H

#include <QWidget>
#include <QPushButton>

class Navbar : public QWidget
{
  Q_OBJECT

private:
  QPushButton *indexButton;
  QPushButton *newButton;

public:
  Navbar(QWidget *parent);

signals:
  void indexButtonPressed();
  void newButtonPressed();

private slots:
  void colorIndexButton();
  void colorNewButton();
};

#endif