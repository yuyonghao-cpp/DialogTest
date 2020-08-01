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
    //����Ի���
    FontDialogBtn.setText("Font Dialog");
    FontDialogBtn.move(20, 20);
    FontDialogBtn.resize(160, 30);

    //���ȶԻ���
    ProgressDialogBtn.setText("Progress Dialog");
    ProgressDialogBtn.move(20, 70);
    ProgressDialogBtn.resize(160, 30);

    //��ӡ�Ի���
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
    dlg.setCurrentFont(QFont("Courier New", 10, QFont::Bold));  //���ó�ʼ���壬Font->���壡

    if(dlg.exec() == QFontDialog::Accepted)
    {
        qDebug() << dlg.selectedFont();
    }
}

//��ʾ���ȶԻ���
void Widget::ProgressDialogBtn_Clicked()
{
    QProgressDialog dlg(this);

    dlg.setWindowTitle("Updating...");
    dlg.setLabelText("Downloadng update from server..."); //������ʾ��Ϣ
    dlg.setMinimum(0);  //���ý��ȶԻ������Сֵ
    dlg.setMaximum(100);//���ý��ȶԻ�������ֵ
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

        QTextDocument td;   //��ʾһ���ı��ĵ�

        //td.setPlainText("Printer object test!");  //���ô�ӡ����
        td.setHtml("<h1>Print html object test</h1>");
        p->setOutputFileName("H:\\PrintDialogTest.xps");    //����ӡ���ݴ�ӡ����

        td.print(p);
    }
}


Widget::~Widget()
{
    
}
