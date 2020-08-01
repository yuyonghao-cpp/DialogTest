#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
protected:
    QPushButton FontDialogBtn;
    QPushButton ProgressDialogBtn;
    QPushButton PrintDialogBtn;
protected slots:
    void FontDialogBtn_Clicked();
    void ProgressDialogBtn_Clicked();
    void PrintDialogBtn_Clicked();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
