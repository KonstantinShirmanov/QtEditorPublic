#ifndef MAINCLASS_H
#define MAINCLASS_H


#include <QPushButton>
#include <QtGui>
#include <QPoint>


class MainClass : public QMainWindow
{
    Q_OBJECT

public:
    QTextEdit *MainTextEdit;

    QGroupBox *SidePanel;

    QVBoxLayout *vbox;
    QGroupBox *groupFontBox;

    QSpinBox *FontsizeSpin;

    QFontComboBox *FStyleList;

    QCheckBox *ItalyStyle;
    QCheckBox *BoldStyle;
    QCheckBox *UnderLineStyle;

    QHBoxLayout *BLayout;
    QGroupBox *ButtonGroup;

    QPushButton *QuitButton;
    QPushButton *SaveButton;

    QFont *font;
    QString *Fontstr;

private slots:

    void slotSaveClicked();
    void Quit();
    void setTextEditFont();

    void checkBoxChanged();
    void SizeCh(int FSize);
public:
    MainClass(QWidget *parent = 0);




    ~MainClass();
};


#endif // MAINCLASS_H
