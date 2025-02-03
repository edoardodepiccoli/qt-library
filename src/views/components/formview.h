#ifndef FORMVIEW_H
#define FORMVIEW_H

#include <QWidget>

class FormView : public QWidget
{
    Q_OBJECT

public:
    FormView(QWidget *parent = nullptr);
    ~FormView();
};

#endif // FORMVIEW_H