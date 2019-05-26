#include "main_menu.h"
#include <QLayout>
#include <QFont>
#include <QSize>
#include <QDebug>
#include <QObject>
#include <QPropertyAnimation>

main_menu::main_menu(QWidget *parent)
    : QWidget(parent),
      Besucher(new QLabel(this)),
      Grund(new QLabel(this)),
      eye(new QPushButton(this)),
      ear(new QPushButton(this)),
      hand(new QPushButton(this)),
      man(new QPushButton(this)),
      box(new QPushButton(this)),
      monitor(new QPushButton(this)),
      speaker_m(new QPushButton(this)),
      help(new QToolButton(this)),
      bell(new QToolButton(this)),
      grund_btn(new QButtonGroup(this)),
      back_to_start(new QPushButton(this)),
      speaker_audio(new QMediaPlayer(this)),
      bell_audio(new QMediaPlayer(this)),
      dialog(new QTextEdit(this)),
      chat_window(new QTextEdit(this))


{
    this->setAttribute(Qt::WA_TransparentForMouseEvents,false);
    this->setFixedSize(800,480);

    QLabel* startWindow = new QLabel(this);
    startWindow->setStyleSheet("QLabel{border-image:url(:/icons/startWindow.png);padding:-1}");

    QPropertyAnimation *animation = new QPropertyAnimation(startWindow, "geometry");
    animation->setDuration(2000);
    animation->setStartValue(QRect(0,0,800,480));
    animation->setEndValue(QRect(0,480,0,0));
    animation->setEasingCurve(QEasingCurve::OutQuart);

    animation->start();

    QFont font_3,font_4,font_8;
    font_3.setPixelSize(50);
    font_4.setPixelSize(40);
    font_8.setPixelSize(16);

    Besucher->setText("Besucher");
    Besucher->setFont(font_3);
    Besucher->setAlignment(Qt::AlignCenter);
    Besucher->setStyleSheet("QLabel{background-color:rgb(79,148,205);border:1px solid blacks;}");
    Grund->setText("Grund");
    Grund->setFont(font_3);
    Grund->setAlignment(Qt::AlignCenter);
    Grund->setStyleSheet("QLabel{background-color:rgb(79,148,205);border:1px solid blacks;}");


    eye->setIcon(QIcon(":/icons/eye"));
    eye->setText("  Sehend  ");
    eye->setIconSize(QSize(50,50));
    eye->setFont(font_4);
    eye->setFixedHeight(100);
    eye->setFixedWidth(250);
    eye->setCheckable(1);
    eye->setStyleSheet("QPushButton::checked{background:green} QPushButton{background:rgb(205,205,205)}");

    connect(eye,&QPushButton::toggled,[&] {

        if(eye->isChecked()){
            eye->setIcon(QIcon(":/icons/visible-opened-eye-interface-option(1).png"));
            eye->setText("   Seh-\nschwäche");
            eye->setIconSize(QSize(50,50));
        }else {
            eye->setIcon(QIcon(":/icons/eye"));
            eye->setText("  Sehend  ");
            eye->setIconSize(QSize(50,50));
        }
    });


    ear->setIcon(QIcon(":/icons/ear"));
    ear->setText("  Hörend ");
    ear->setIconSize(QSize(50,50));
    ear->setFont(font_4);
    ear->setFixedHeight(100);
    ear->setCheckable(1);
    ear->setStyleSheet("QPushButton::checked{background:green} QPushButton{background:rgb(205,205,205)}");

    connect(ear,&QPushButton::toggled,[&] {
        if(ear->isChecked()){
            ear->setIcon(QIcon(":/icons/ear(1).png"));
            ear->setText("   Hör-\nschwäche");
            ear->setIconSize(QSize(50,50));
        }else {
            ear->setIcon(QIcon(":/icons/ear"));
            ear->setText("  Hörend  ");
            ear->setIconSize(QSize(50,50));
        }
    });


    hand->setIcon(QIcon(":/icons/deaf-sign-language(1).png"));
    hand->setText(" Zeichen-\n sprache");
    hand->setIconSize(QSize(50,50));
    hand->setFont(font_4);
    hand->setFixedHeight(100);
    hand->setCheckable(1);
    hand->setStyleSheet("QPushButton::checked{background:green} QPushButton{background:rgb(205,205,205)}");

    connect(hand,&QPushButton::toggled,[&]{
        if(hand->isChecked()){
            hand->setIcon(QIcon(":/icons/deaf"));
            hand->setText(" Zeichen-\n sprache");
            hand->setIconSize(QSize(50,50));
        }else {
            hand->setIcon(QIcon(":/icons/deaf-sign-language(1).png"));
            hand->setText(" Zeichen-\n sprache");
            hand->setIconSize(QSize(50,50));
        }
    });

    Mask_btns = new QLabel(this);
    Mask_btns->setGeometry(0,0,495,370);
    Mask_btns->setStyleSheet("QLabel{background:rgba(0,0,0,0.8)}");
    Mask_btns->hide();



    man->setIcon(QIcon(":/icons/user"));
    man->setText("  Besuch");
    man->setIconSize(QSize(50,50));
    man->setFont(font_4);
    man->setFixedHeight(100);
//    man->setFixedWidth(255);
    man->setStyleSheet("QPushButton{background:rgb(205,205,205)}");
    man->setCheckable(1);
    connect(man,&QPushButton::toggled,[&] {
        if(man->isChecked()){
            man->setStyleSheet("QPushButton::checked{background:rgb(232, 120, 0)}");
            box->setStyleSheet("QPushButton{background:rgb(205,205,205)}");
            monitor->setStyleSheet("QPushButton{background:rgb(205,205,205)}");
            Mask_btns->show();
            Mask_bell->show();
            dialog->setTextColor(Qt::white);
//            dialog->setFont(font_8)
            dialog->setFontPointSize(36);
            dialog->append(">Ja,ich bin auf dem Weg");



        }
    });


    chat_window->setGeometry(0,0,495,365);
    chat_window->setStyleSheet("background:rgb(205,205,205)");
    chat_window->hide();

    _5min = new QPushButton(this);
    _5min->setGeometry(260,380,220,85);
    _5min->setStyleSheet("background:rgb(255,165,0)");
    _5min->setText("5 Min");
    _5min->setFont(font_3);
    _5min->hide();
    _10min = new QPushButton(this);
    _10min->setGeometry(510,380,220,85);
    _10min->setStyleSheet("background:rgb(255,165,0)");
    _10min->setText("10 Min");
    _10min->setFont(font_3);
    _10min->hide();

    warte = new QPushButton(this);
    warte->setGeometry(260,380,220,85);
    warte->setStyleSheet("background:rgb(255,165,0)");
    warte->setText("Ich warte");
    warte->setFont(font_3);
    warte->hide();
    weg = new QPushButton(this);
    weg->setGeometry(510,380 ,220,85);
    weg->setStyleSheet("background:rgb(255,165,0)");
    weg->setText("Bin weg");
    weg->setFont(font_3);
    weg->hide();

    box->setIcon(QIcon(":/icons/box"));
    box->setText("Lieferung");
    box->setIconSize(QSize(50,50));
    box->setFont(font_4);
    box->setFixedHeight(100);
    box->setCheckable(1);
    box->setStyleSheet("QPushButton{background:rgb(205,205,205)}");
    connect(box,&QPushButton::toggled,[&]{
        if(box->isChecked()){
            box->setStyleSheet("QPushButton::checked{background:rgb(232, 120, 0)}");
            man->setStyleSheet("QPushButton{background:rgb(205,205,205)}");
            monitor->setStyleSheet("QPushButton{background:rgb(205,205,205)}");

            Mask_bell->show();
            chat_window->show();
            chat_window->setFontPointSize(80);
            chat_window->setReadOnly(1);
            chat_window->append("CHAT");


            warte->show();
            weg->show();



        }
    });

    connect(weg,&QPushButton::clicked,[&] {
        chat_window->append(">Bin weg");
        warte->hide();
        weg->hide();
        _10min->show();
        _5min->show();

    });

    connect(warte,&QPushButton::clicked,[&] {
        chat_window->append(">Ich warte");
    });

    connect(_10min,&QPushButton::clicked,[&] {
       chat_window->append(">In 10 Minuten.");
    });
    connect(_5min,&QPushButton::clicked,[&] {
       chat_window->append(">In 5 Minuten.");
    });

    bell->setText("Klingeln");
    bell->setFont(font_4);
    bell->setIcon(QIcon(":/icons/bell1"));
    bell->setIconSize(QSize(150,150));
    bell->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    bell->setStyleSheet("background-color:rgb(255,165,0)");
    bell->setGeometry(510,110,300,255);
    bell->setFixedSize(300,255);
    bell_audio->setMedia(QUrl("qrc:/musci/welcome"));
    bell_audio->setVolume(100);

    connect(bell,&QPushButton::clicked,[&]
        {
            if(bell_audio->state() != QMediaPlayer::PlayingState)
                {
                    bell_audio->play();
                    bell->setIcon(QIcon(":/icons/bell"));
                    bell->setIconSize(QSize(100,100));
                    bell->setStyleSheet("background-color:rgb(255,165,0)");

                }
        });
    connect(bell_audio,&QMediaPlayer::stateChanged,[&]
        {
            if(bell_audio->state() !=QMediaPlayer::PlayingState)
            {
                bell->setIcon(QIcon(":/icons/bell1"));
                bell->setIconSize(QSize(100,100));
                bell->setStyleSheet("background-color:rgb(255,165,0)");
            }
            else
            {
                bell->setIcon(QIcon(":/icons/bell"));
                bell->setIconSize(QSize(100,100));
                bell->setStyleSheet("background-color:rgb(255,165,0)");
            }
        });



    monitor->setIcon(QIcon(":/icons/webcam.png"));
    monitor->setText("   Video");
    monitor->setIconSize(QSize(70,70));
    monitor->setFont(font_4);
    monitor->setFixedHeight(100);
    monitor->setCheckable(1);
    monitor->setStyleSheet("QPushButton{background:rgb(205,205,205)}");
    camera = new QCamera;
    viewFinder = new QCameraViewfinder;
    viewFinder->setGeometry(0,0,500,368);
    camera->setViewfinder(viewFinder);

    QCameraViewfinderSettings setting;
    setting.setResolution(160,120);
//           setting.setMinimumFrameRate(24);
    camera->setViewfinderSettings(setting);



    Mask_bell = new QLabel(this);
    Mask_bell->setGeometry(495,109,300,255);
    Mask_bell->setStyleSheet("QLabel{background:rgba(205,205,205,0.8)}");
    Mask_bell->hide();

    connect(monitor,&QPushButton::toggled,[&]{
            if(monitor->isChecked()){
                monitor->setStyleSheet("QPushButton::checked{background:rgb(232, 120, 0)}");
                man->setStyleSheet("QPushButton{background:rgb(205,205,205)}");
                box->setStyleSheet("QPushButton{background:rgb(205,205,205)}");
                Mask_bell->show();
                camera->start();

                viewFinder->show();

           }
        });



    grund_btn->addButton(man);
    grund_btn->addButton(box);
    grund_btn->addButton(monitor);
    grund_btn->setExclusive(true);


    speaker_m->setStyleSheet("QPushButton{border-image:url(:/icons/speaker);padding: -1}");
    speaker_m->setGeometry(530,100,0,0);
    speaker_m->setFixedSize(100,100);

    speaker_audio->setMedia(QUrl("qrc:/musci/welcome"));
    speaker_audio->setVolume(100);

    connect(speaker_m,&QPushButton::clicked,[&]
        {
            if(speaker_audio->state() != QMediaPlayer::PlayingState)
                {
                    speaker_audio->play();
                    speaker_m->setStyleSheet("QPushButton{border-image:url(:/icons/speaker1);padding: -1}");
                }
        });
    connect(speaker_audio,&QMediaPlayer::stateChanged,[&]
        {
            if(speaker_audio->state() !=QMediaPlayer::PlayingState)
            {
                speaker_m->setStyleSheet("QPushButton{border-image:url(:/icons/speaker);padding: -1}");
            }
            else
            {
                speaker_m->setStyleSheet("QPushButton{border-image:url(:/icons/speaker1);padding: -1}");
            }
        });




    help->setText("Hilfe");
    help->setFont(font_4);
    help->setIcon(QIcon(":/icons/question"));
    help->setIconSize(QSize(50,50));
    help->setGeometry(700,0,100,100);
    help->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    help->setStyleSheet("background-color:rgb(70,130,180)");


    hilfe = new hilfe_window();
    hilfe->hide();

    connect(hilfe,&hilfe_window::return_to_main_s,this,&QWidget::show);
    connect(help,&QToolButton::clicked,[&]
        {
         hilfe->show();
         if(camera->state()== QCamera::ActiveState)
         {
             Mask_bell->hide();
             Mask_btns->hide();
             camera->stop();
             viewFinder->close();
         }
    });



    back_to_start->setText("Familie Teco\nVincenz-Prießnitz-Straße 1\n76131 Karlsruhe");
    back_to_start->setFont(font_8);

    back_to_start->setFixedSize(QSize(200,110));
    connect(back_to_start,&QPushButton::clicked,this,[&] {
        emit back_to_start_s();
        if(camera->state()== QCamera::ActiveState)
        {
            camera->stop();
            viewFinder->close();
        }
        if(bell_audio->state() == QMediaPlayer::PlayingState)
        {
            bell_audio->stop();

        }
        this->close();



    });

//    dialog->setTextBackgroundColor(Qt::black);
    dialog->setGeometry(205,366,595,111);
    dialog->setStyleSheet("QTextEdit{background:black}");
    dialog->setReadOnly(1);
//    dialog->setFixedSize();


    QGridLayout *main_layout = new QGridLayout;
    main_layout->addWidget(Besucher,0,0,1,1);
    main_layout->addWidget(Grund,0,1,1,1);
    main_layout->addWidget(eye,1,0,2,1);
    main_layout->addWidget(ear,3,0,2,1);
    main_layout->addWidget(hand,5,0,2,1);
    main_layout->addWidget(man,1,1,2,1);
    main_layout->addWidget(box,3,1,2,1);
    main_layout->addWidget(monitor,5,1,2,1);
    main_layout->addWidget(speaker_m,0,3,2,1);
    main_layout->addWidget(help,0,4,2,1);
    main_layout->addWidget(bell,2,3,5,2);
    main_layout->addWidget(back_to_start,7,0,2,1);
//    main_layout->addWidget(dialog,7,1,2,4);
    main_layout->setSpacing(0);
    setLayout(main_layout);

//    this->setAttribute(Qt::WA_DeleteOnClose,true);


}

main_menu::~main_menu()
{

}
