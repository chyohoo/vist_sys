#include "hilfe_window.h"
#include <QLayout>
#include <QFont>
#include <QSize>
#include <QDebug>

hilfe_window::hilfe_window(QWidget *parent)
    : QWidget(parent),
      Kontrast(new QPushButton(this)),
      Aufschliessen(new QPushButton(this)),
      Hilfe(new QToolButton(this)),
      ZweiFingerTap(new QLabel(this)),
      Normal(new QPushButton(this)),
      SaW(new QPushButton(this)),
      GaS(new QPushButton(this)),
      SaG(new QPushButton(this)),
      Zahlen(new QPushButton(this)),
      Symbol(new QPushButton(this)),
      Gesicht(new QPushButton(this)),
      return_to_main(new QPushButton(this)),
      Kontrast_btn(new QButtonGroup(this)),
      Aufschliessen_btn(new QButtonGroup(this)),
      Sprach(new QPushButton(this))
{
    this->setFixedSize(800,480);



    QFont font_5,font_6,font_7;
    font_5.setPixelSize(30);
    font_6.setPixelSize(50);
    font_7.setPixelSize(40);

    QLabel *bar = new QLabel(this);
    bar->setGeometry(100,0,600,90);
    bar->setStyleSheet("QLabel{background-color:rgb(79,148,205);border: None}");

    return_to_main->setStyleSheet("QPushButton{background-color:rgb(79,148,205);border-image:url(:/icons/arrow.png);padding: -1}");
    return_to_main->setGeometry(0,0,100,90);

    connect(return_to_main,&QPushButton::clicked,[&]{
        emit return_to_main_s();
        this->hide();

    });


    Hilfe->setText("Hilfe");
    Hilfe->setFont(font_5);
    Hilfe->setIcon(QIcon(":/icons/question"));
    Hilfe->setIconSize(QSize(60,60));
    Hilfe->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Hilfe->setGeometry(700,0,100,90);
    Hilfe->setStyleSheet("QToolButton{background-color:rgb(79,148,205);border: None}");
    Hilfe->setFocusPolicy(Qt::NoFocus);

    Kontrast->setText("Kontrast");
    Kontrast->setIcon(QIcon(":/icons/contrast"));
    Kontrast->setIconSize(QSize(50,50));
    Kontrast->setFont(font_6);
    Kontrast->setGeometry(0,100,390,76);
    Kontrast->setStyleSheet("QPushButton{background-color:rgb(79,148,205);border: None;text-align: left;}");
    Kontrast->setFocusPolicy(Qt::NoFocus);

    Aufschliessen->setText("Aufschließen");
    Aufschliessen->setIcon(QIcon(":/icons/lock"));
    Aufschliessen->setIconSize(QSize(50,50));
    Aufschliessen->setFont(font_6);
    Aufschliessen->setGeometry(410,100,400,76);
    Aufschliessen->setStyleSheet("QPushButton{background-color:rgb(79,148,205);border: None;text-align: left;}");
    Aufschliessen->setFocusPolicy(Qt::NoFocus);

    Normal->setIcon(QIcon(":/icons/a(1).png"));
    Normal->setIconSize(QSize(60,60));
    Normal->setText("Normal");
    Normal->setFont(font_7);
    Normal->setGeometry(0,176,390,76);
    Normal->setStyleSheet("QPushButton{text-align: left;} QPushButton::checked{background:rgb(0,191,255)}");
    Normal->setCheckable(1);



    SaW->setIcon(QIcon(":/icons/a.png"));
    SaW->setIconSize(QSize(60,60));
    SaW->setText("Schwarz auf Weiß");
    SaW->setFont(font_7);
    SaW->setGeometry(0,252,390,76);
    SaW->setStyleSheet("QPushButton{text-align: left;} QPushButton::checked{background:rgb(0,191,255)}");
    SaW->setCheckable(1);

    GaS->setIcon(QIcon(":/icons/a(2).png"));
    GaS->setIconSize(QSize(60,60));
    GaS->setText("Gelb auf Schwarz");
    GaS->setFont(font_7);
    GaS->setGeometry(0,328,390,76);
    GaS->setStyleSheet("QPushButton{text-align: left;} QPushButton::checked{background:rgb(0,191,255)}");
    GaS->setCheckable(1);

    SaG->setIcon(QIcon(":/icons/a(3).png"));
    SaG->setIconSize(QSize(60,60));
    SaG->setText("Schwarz auf Gelb");
    SaG->setFont(font_7);
    SaG->setGeometry(0,404,390,76);
    SaG->setStyleSheet("QPushButton{text-align: left;} QPushButton::checked{background:rgb(0,191,255)}");
    SaG->setCheckable(1);

    Kontrast_btn->addButton(Normal);
    Kontrast_btn->addButton(SaW);
    Kontrast_btn->addButton(GaS);
    Kontrast_btn->addButton(SaG);
    Kontrast_btn->setExclusive(true);


    Zahlen->setIcon(QIcon(":/icons/1.png"));
    Zahlen->setIconSize(QSize(60,60));
    Zahlen->setText("Zahlen-Pin");
    Zahlen->setFont(font_7);
    Zahlen->setGeometry(410,176,390,76);
    Zahlen->setStyleSheet("QPushButton{text-align: left;}");
//    Zahlen->setCheckable(1);

    Symbol->setIcon(QIcon(":/animal/fox"));
    Symbol->setIconSize(QSize(60,60));
    Symbol->setText("Symbol-Pin");
    Symbol->setFont(font_7);
    Symbol->setGeometry(410,252,390,76);
    Symbol->setStyleSheet("QPushButton{text-align: left;}");
//    Symbol->setCheckable(1);

    Gesicht->setIcon(QIcon(":/icons/smile"));
    Gesicht->setIconSize(QSize(60,60));
    Gesicht->setText("Gesichterkennung");
    Gesicht->setFont(font_7);
    Gesicht->setGeometry(410,328,390,76);
    Gesicht->setStyleSheet("QPushButton{text-align: left;}");
//    Gesicht->setCheckable(1);

    Sprach->setIcon(QIcon(":/icons/tap1"));
    Sprach->setIconSize(QSize(60,60));
    Sprach->setText("Zwei-Finger-Tap\n->Sprachausgabe");
    Sprach->setFont(font_5);
    Sprach->setGeometry(410,404,390,76);
    Sprach->setStyleSheet("QPushButton{border: None; padding: -1;}");











}

hilfe_window::~hilfe_window()
{

}
