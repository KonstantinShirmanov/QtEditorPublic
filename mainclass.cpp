#include "mainclass.h"
#include <QMainWindow>
#include <QTextEdit>
#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QSpinBox>
#include <QFontComboBox>
#include <QCheckBox>
#include <QTextCodec>
#include <QTextDocumentWriter>
#include <QPushButton>
#include <QFont>
#include <iostream>
MainClass::MainClass(QWidget* parent) : QMainWindow(parent){

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("cp1251"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("cp1251"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("cp1251"));

    QGridLayout *QMLayout = new QGridLayout;

    MainTextEdit = new QTextEdit(this);
    MainTextEdit->setMinimumSize(300, 300);

    SidePanel = new QGroupBox (this);
    SidePanel ->setGeometry(300,0, 220,300);

    vbox = new QVBoxLayout;

    groupFontBox = new QGroupBox(tr("Параметры"));

    QLabel *PLabel = new QLabel (this);
    PLabel->setText("Параметры");

    FontsizeSpin = new QSpinBox (this);
    FontsizeSpin->setRange(8, 20);
    FontsizeSpin->setSuffix(" пт");
    FontsizeSpin -> setSingleStep(2);

    QLabel *FLabel = new QLabel (this);
    FLabel->setText("Шрифт");

    FStyleList = new QFontComboBox(this);

    vbox->addWidget(PLabel);
    vbox ->addWidget(FLabel);
    vbox ->addWidget(FStyleList);


    QLabel *SLabel = new QLabel(this);
    SLabel -> setText("Размер");
    vbox ->addWidget(SLabel);
    vbox ->addWidget(FontsizeSpin);

    QLabel *FSLabel = new QLabel (this);
    FSLabel->setText("Начертание");
    vbox ->addWidget(FSLabel);

    ItalyStyle = new QCheckBox;
    ItalyStyle->setText("Курсив");

    BoldStyle = new QCheckBox;
    BoldStyle->setText("Полужирный");

    UnderLineStyle = new QCheckBox;
    UnderLineStyle->setText("Подчеркнутый");

    vbox -> addWidget(ItalyStyle);
    vbox -> addWidget(BoldStyle);
    vbox -> addWidget(UnderLineStyle);

    BLayout = new QHBoxLayout;
    ButtonGroup = new QGroupBox;
    ButtonGroup->setLayout(BLayout);
    vbox -> addWidget(ButtonGroup);

    QuitButton = new QPushButton("Выход");
    BLayout ->addWidget(QuitButton);


    SaveButton = new QPushButton("Сохранить");
    BLayout ->addWidget(SaveButton);

   groupFontBox->setLayout(vbox);
   SidePanel->setLayout(vbox);

   QMLayout -> addWidget(MainTextEdit, 0, 0, 3, 3);
   QMLayout -> addWidget(SidePanel, 1, 0,1,1);

    this->setLayout(QMLayout);


   // Для изменения размера или семейства шрифта
   connect(FontsizeSpin, SIGNAL(currentFontChanged(const QFont&)), this, SLOT(setTextEditFont()));
   connect(FStyleList, SIGNAL(valueChanged(int)), this, SLOT(setTextEditFont()));

   connect (FontsizeSpin, SIGNAL(valueChanged(int)), this, SLOT(SizeCh(int)));
   connect(FStyleList, SIGNAL(currentFontChanged(const QFont&)), MainTextEdit, SLOT(setCurrentFont(const QFont&)));
   // Для чекбоксов
   connect (ItalyStyle, SIGNAL(stateChanged(int)), this, SLOT(checkBoxChanged(int)));
   connect (BoldStyle, SIGNAL(stateChanged(int)), this, SLOT(checkBoxChanged(int)));
   connect (UnderLineStyle, SIGNAL(stateChanged(int)), this, SLOT(checkBoxChanged(int)));

   // Для кнопок
   connect (QuitButton, SIGNAL (clicked()), this, SLOT(Quit()));
   connect (SaveButton, SIGNAL (clicked()), this, SLOT(slotSaveClicked()));

}
void MainClass::SizeCh( int intSpinValue){

    MainTextEdit->selectAll();
    MainTextEdit->setFontPointSize(intSpinValue);
    QTextCursor cursor = MainTextEdit->textCursor();
    cursor.clearSelection();
}

void MainClass::checkBoxChanged(){
    MainTextEdit -> selectAll();
    MainTextEdit -> setFontWeight(BoldStyle->isChecked()? QFont::Bold:QFont::Normal);
    MainTextEdit->setFontItalic(ItalyStyle->isChecked());
    MainTextEdit ->setFontUnderline(UnderLineStyle->isChecked()? QFont::UnderlineResolved:QFont::Normal);
    QTextCursor cursor = MainTextEdit->textCursor();
    cursor.clearSelection();
}

void MainClass::slotSaveClicked(){

QTextDocumentWriter writer;
writer.setFormat("odf");
writer.setFileName("output.odf");
writer.write (MainTextEdit->document());
}
void MainClass::Quit(){
    QApplication::exit();
}

void MainClass::setTextEditFont(){
    QFont font = FStyleList->currentFont();
    font.setPixelSize( FontsizeSpin -> value());


    MainTextEdit->setFont(font);
}

MainClass::~MainClass()
{

}
