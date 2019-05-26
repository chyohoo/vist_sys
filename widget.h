#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QtMultimedia/QMediaPlayer>
#include <QCloseEvent>
#include <main_menu.h>
#include <QPropertyAnimation>




class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
//    void playCloseAnimation(QWidget *w);

protected:
    void mousePressEvent(QMouseEvent *e);
//    void closeEvent(QCloseEvent *e_c);


signals:
//    void play_animation();
    void go_to_main_menu();


private:
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;



    QPushButton *speaker;
    QMediaPlayer *audio_welcome;

    QPushButton *menu;

    main_menu *menu_m;




};

#endif // WIDGET_H
