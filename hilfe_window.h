#ifndef HILFE_WINDOW_H
#define HILFE_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QButtonGroup>


class hilfe_window : public QWidget
{
    Q_OBJECT
public:
    explicit hilfe_window(QWidget *parent = 0);
    ~hilfe_window();

signals:
    void return_to_main_s();

public slots:

private:
   QPushButton *Kontrast;
   QPushButton *Aufschliessen;
   QToolButton *Hilfe;
   QLabel *ZweiFingerTap;

   QPushButton *Normal;
   QPushButton *SaW;
   QPushButton *GaS;
   QPushButton *SaG;
   QPushButton *Zahlen;
   QPushButton *Symbol;
   QPushButton *Gesicht;
   QPushButton *Sprach;

   QButtonGroup *Kontrast_btn;
   QButtonGroup *Aufschliessen_btn;


public:   QPushButton *return_to_main;


};

#endif // HILFE_WINDOW_H
