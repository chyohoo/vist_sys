#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QToolButton>
#include <QButtonGroup>
#include <QtMultimedia/QMediaPlayer>
#include <QTextEdit>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <hilfe_window.h>



class main_menu : public QWidget
{
    Q_OBJECT
public:
    explicit main_menu(QWidget *parent = 0);
    ~main_menu();

signals:
    void back_to_start_s();

private:
    QPushButton *eye;
    QPushButton *man;
    QPushButton *ear;
    QPushButton *box;
    QPushButton *hand;
    QPushButton *monitor;
    QToolButton *bell;
    QToolButton *help;
    QPushButton *speaker_m;
    QPushButton *back_to_start;
    QButtonGroup *grund_btn;
    QPushButton *warte;
    QPushButton *weg;
    QPushButton *_10min;
    QPushButton *_5min;

    QLabel *Besucher;
    QLabel *Grund;
    QLabel *Mask_bell;
    QLabel *Mask_btns;

    QMediaPlayer *speaker_audio;
    QMediaPlayer *bell_audio;

    QTextEdit *dialog;
    QTextEdit *chat_window;
    hilfe_window *hilfe;

    QCamera *camera;
    QCameraViewfinder *viewFinder;




};

#endif // MAIN_MENU_H
