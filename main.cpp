#include "mainclass.h"
#include <QApplication>
#include <QTextCodec>
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainClass w;

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("cp1251"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("cp1251"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("cp1251"));
    w.setMinimumSize(550, 300);
    w.setWindowIcon(QIcon(":/TLeater.jpg"));
    w.setWindowTitle("Текстовый редактор");
    w.setFocus();


   w.show();



    return a.exec();
}
