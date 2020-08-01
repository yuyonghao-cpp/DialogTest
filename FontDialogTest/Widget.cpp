#include "Widget.h"
#include <QDebug>
#include <QPrinter>
#include <QTextDocument>
#include <QPrintDialog>
#include <QProgressDialog>
#include <QFontDialog>

Widget::Widget(QWidget *parent) : QWidget(parent),
    FontDialogBtn(this), ProgressDialogBtn(this), PrintDialogBtn(this)
{
    //字体对话框
    FontDialogBtn.setText("Font Dialog");
    FontDialogBtn.move(20, 20);
    FontDialogBtn.resize(160, 30);

    //进度对话框
    ProgressDialogBtn.setText("Progress Dialog");
    ProgressDialogBtn.move(20, 70);
    ProgressDialogBtn.resize(160, 30);

    //打印对话框
    PrintDialogBtn.setText("PrintDialog Dialog");
    PrintDialogBtn.move(20, 120);
    PrintDialogBtn.resize(160, 30);

    resize(200, 170);
    setFixedSize(200, 170);

    connect(&FontDialogBtn,SIGNAL(clicked()), this, SLOT(FontDialogBtn_Clicked()));
    connect(&ProgressDialogBtn,SIGNAL(clicked()), this, SLOT(ProgressDialogBtn_Clicked()));
    connect(&PrintDialogBtn,SIGNAL(clicked()), this, SLOT(PrintDialogBtn_Clicked()));
}

void Widget::FontDialogBtn_Clicked()
{
    QFontDialog dlg(this);

    dlg.setWindowTitle("Font Dialog Test");
    dlg.setCurrentFont(QFont("Courier New", 10, QFont::Bold));  //设置初始字体，Font->字体！

    if(dlg.exec() == QFontDialog::Accepted)
    {
        qDebug() << dlg.selectedFont();
    }
}

//显示进度对话框
void Widget::ProgressDialogBtn_Clicked()
{
    QProgressDialog dlg(this);

    dlg.setWindowTitle("Updating...");
    dlg.setLabelText("Downloadng update from server..."); //设置提示信息
    dlg.setMinimum(0);  //设置进度对话框的最小值
    dlg.setMaximum(100);//设置进度对话框的最大值
    dlg.setValue(35);

    dlg.exec();
}

void Widget::PrintDialogBtn_Clicked()
{
    QPrintDialog dlg(this);

    dlg.setWindowTitle("Print Dialog");

    if( dlg.exec() == QPrintDialog::Accepted)
    {
        QPrinter* p = dlg.printer();

        QTextDocument td;   //表示一个文本文档

        //td.setPlainText("Printer object test!");  //设置打印内容
        td.setHtml("<h1>Print html object test</h1>");
        p->setOutputFileName("H:\\PrintDialogTest.xps");    //将打印内容打印出来

        td.print(p);
    }
}


Widget::~Widget()
{
    
}
