#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QPushButton>

class Sidebar : public QWidget
{
    Q_OBJECT
private:
    QPushButton *searchButton;
    QPushButton *addButton;

    QPushButton *selectedButton;

    void styleButton(QPushButton *button, bool selected);
    void setupButton(QPushButton *button, const QString &iconPath);

signals:
    void searchButtonClicked();
    void addButtonClicked();

private slots:
    void handleButtonClick();

public:
    Sidebar(QWidget *parent = nullptr);
    ~Sidebar();
};

#endif // SIDEBAR_H