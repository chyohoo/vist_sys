#include "widget.h"
#include <QFont>
#include <QMouseEvent>
#include <QDebug>
#include <QWindow>
#include <QPropertyAnimation>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      label_1(new QLabel(this)),
      label_2(new QLabel(this)),
      label_3(new QLabel(this)),
      label_4(new QLabel(this)),
      label_5(new QLabel(this)),
      speaker(new QPushButton(this)),
//      menu(new QPushButton("menu",this)),
      audio_welcome(new QMediaPlayer(this))

{
    QFont font_1,font_2;
    font_1.setPointSize(100);
    font_2.setPointSize(60);

    label_1->setGeometry(270,50,0,0);
    label_1->setText("Familie Teco");
//    label_1->setAlignment(Qt::AlignHCenter);
    label_1->setFont(font_1);
    label_1->adjustSize();

    label_2->setGeometry(0,55,0,0);
    label_2->setText("________________________________");
    label_2->setFont(font_1);
    label_2->adjustSize();

    label_3->setGeometry(240,240,0,0);
    label_3->setText("Vincenz-Prießnitz-Straße 1");
    label_3->setFont(font_2);
    label_3->adjustSize();

    label_4->setGeometry(280,280,0,0);
    label_4->setText("76131 Karlsruhe");
    label_4->setFont(font_2);
    label_4->adjustSize();

    label_5->setGeometry(200,450,0,0);
    label_5->setText("<< Bitte Bildschirm berühren >>");
    label_5->setFont(font_2);
    label_5->adjustSize();

    speaker->setGeometry(730,30,50,50);
    speaker->setStyleSheet("QPushButton{border-image:url(:/icons/speaker);padding: -1}"
                            );

    audio_welcome->setMedia(QUrl("qrc:/musci/welcome"));
    audio_welcome->setVolume(100);

    connect(speaker,&QPushButton::clicked,[&]
        {
            if(audio_welcome->state() != QMediaPlayer::PlayingState)
                {
                    audio_welcome->play();
                    speaker->setStyleSheet("QPushButton{border-image:url(:/icons/speaker1);padding: -1}");
                }
        });
    connect(audio_welcome,&QMediaPlayer::stateChanged,[&]
        {
            if(audio_welcome->state() !=QMediaPlayer::PlayingState)
            {
                speaker->setStyleSheet("QPushButton{border-image:url(:/icons/speaker);padding: -1}");
            }
            else
            {
                speaker->setStyleSheet("QPushButton{border-image:url(:/icons/speaker1);padding: -1}");
            }
        });




//    connect(animation,&QPropertyAnimation::finished,this,&QWidget::close);

    connect(this,&Widget::go_to_main_menu,[&]{
                    menu_m = new main_menu();
                    menu_m->setWindowFlags(Qt::Dialog);

//                    menu_m->show();
//                    menu_m->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//                    menu_m->resize(this->size());
                    menu_m->setAttribute(Qt::WA_DeleteOnClose);

                    menu_m->show();
                    connect(menu_m,&main_menu::back_to_start_s,this,&QWidget::show);

                    this->hide();





            });

    this->setFixedSize(800,480);
}

void Widget::mousePressEvent(QMouseEvent *e){
    if(  e->x()>730 && e->x()<780 &&e->y()>50 && e->y()<100){
        QWidget::event(e);
    } else {

        emit go_to_main_menu();

    }
}



Widget::~Widget()
{

}



//void Widget::closeEvent(QCloseEvent *e_c)
//{





//}
