#include "widget.h"
#include "ui_widget.h"
#include "QString"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(addWord()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(translate()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(Static()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(removeWord()));
}
void Widget::addWord(){
    if (d <5){
    a[d]=ui->lineEdit_1->text();
    b[d]=ui->lineEdit_2->text();
    ui->listWidget_1->addItem(a[d] + " - "+b[d]);
    ui->listWidget_1->update();
    }
    d++;
}
void Widget::removeWord(){
    int row = ui->listWidget_1->currentRow();
    swap(a[row],a[4]);
    swap(b[row],b[4]);
    a[4] = "_";
    b[4] = "_";
    ui->listWidget_1->takeItem(row);
    ui->listWidget_1->update();
    d--;
}
void Widget::Static(){
    ui->listWidget_2->clear();
    ui->listWidget_2->addItem(QString::number(d));
    int y=0;
    for (int f=0;f<d;f++) {
        y=y+a[f].size();
    }
    ui->listWidget_2->addItem(QString::number(y/d));
    ui->listWidget_2->addItem(QString::number(y));
    update();
}
void Widget::translate(){
QString y;
bool p=0;
    y=ui->lineEdit_3->text();
    for (int i=0;i<d;++i) {
        if (a[i]==y){
        ui->lineEdit_4->setText(b[i]);
        p=1;
        }
    }
    if(!p){
        ui->lineEdit_4->setText("ERROR");
    }
}
Widget::~Widget()
{
    delete ui;
}
