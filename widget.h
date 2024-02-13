#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
protected:
    QString a[5],b[5];
    int d=0;
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void addWord();
    void removeWord();
    void Static();
    void translate();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
