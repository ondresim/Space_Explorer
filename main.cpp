#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QTranslator>
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>
#include <unistd.h>
#include <QPropertyAnimation>
#include <QObject>
#include <QComboBox>
#include <QDialog>
#include <QString>
#include <QStackedWidget>
#include <QRadioButton>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QFile>
#include <QMessageBox>
#include "SEM_main.h"
#include "settings.h"
#include "Scores.h"
#include "game.h"

void score_setup(QVector<QLabel*> *vec);
void score_change(Game *g, QVector<QLabel*> *vec);


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMainWindow *w = new QMainWindow();
    QWidget *w2 = new QWidget();
    QWidget *w3 = new QWidget();
    QWidget *w4 = new QWidget();

    Ui_MainWindow *ui1 = new Ui_MainWindow();
    ui1->setupUi(w);
    
    Ui_Settings sett;
    sett.setupUi(w2);

    Ui_Form scr;
    scr.setupUi(w4);
    scr.lp->setText("Not played in this session");
    QVector<QLabel*> vec;
    vec.append(scr.l1);
    vec.append(scr.l2);
    vec.append(scr.l3);
    vec.append(scr.l4);
    vec.append(scr.l5);
    vec.append(scr.l6);
    vec.append(scr.l7);
    vec.append(scr.l8);
    vec.append(scr.l9);
    vec.append(scr.l10);
    vec.append(scr.lp);
    
    score_setup(&vec);


    QStackedWidget *list = new QStackedWidget();
    list->addWidget(w);
    list->addWidget(w2);
    list->addWidget(w3);
    list->addWidget(w4);
    list->setFixedSize(1024, 768);


    int spaceship_type = 1;
    QObject::connect(ui1->settings_button, &QPushButton::clicked, [&]()
                     { list->setCurrentIndex(list->currentIndex() + 1); });
    QObject::connect(sett.backtomenu_button, &QPushButton::clicked, [&]()
                     { list->setCurrentIndex(list->currentIndex() - 1); });

    Game *g;
    QTimer time;
    QObject::connect(ui1->pushButton_2, &QPushButton::clicked, [&](){Planet::control = false;time.start(25);g = new Game(w3, spaceship_type);list->setCurrentIndex(list->currentIndex() + 2);});
    QObject::connect(&time, &QTimer::timeout, [&](){if(Planet::control == true){score_change(g, &vec);delete g;list->setCurrentIndex(list->currentIndex()-2);time.stop();}});


    QObject::connect(ui1->pushButton_3, &QPushButton::clicked, [&]()
                     { QApplication::quit(); });

    QList<QPushButton *> obj = list->findChildren<QPushButton *>();
    QObject::connect(sett.radioButton_3, &QRadioButton::clicked, [&]()
                     {
                         for (int i = 0; i < obj.size(); i++)
                         {
                             obj.at(i)->setStyleSheet("background-color: yellow");
                         }
                     });
                     
    QObject::connect(sett.radioButton_5, &QRadioButton::clicked, [&]()
                     {
                         for (int i = 0; i < obj.size(); i++)
                         {
                             obj.at(i)->setStyleSheet("background-color: purple");
                         }
                     });
    QObject::connect(sett.radioButton_6, &QRadioButton::clicked, [&]()
                     {
                         for (int i = 0; i < obj.size(); i++)
                         {
                             obj.at(i)->setStyleSheet("background-color: green");
                         }
                     });
    QObject::connect(sett.radioButton, &QRadioButton::clicked, [&]()
                     {
                         for (int i = 0; i < obj.size(); i++)
                         {
                             obj.at(i)->setStyleSheet("background-color: red");
                         }
                     });
    QObject::connect(sett.radioButton_2, &QRadioButton::clicked, [&]()
                     {
                         for (int i = 0; i < obj.size(); i++)
                         {
                             obj.at(i)->setStyleSheet("background-color: white");
                         }
                     });
    QObject::connect(sett.radioButton_4, &QRadioButton::clicked, [&]()
                     {
                         for (int i = 0; i < obj.size(); i++)
                         {
                             obj.at(i)->setStyleSheet("background-color: blue");
                         }
                     });
    sett.label_3->setPixmap(QPixmap("spaceship.png"));
    sett.label_4->setPixmap(QPixmap("spaceship2.png"));
    QObject::connect(sett.radioButton_7, &QRadioButton::clicked, [&](){spaceship_type = 1;});
    QObject::connect(sett.radioButton_8, &QRadioButton::clicked, [&](){spaceship_type = 2;});
    QObject::connect(ui1->score_button, &QPushButton::clicked, [&]()
                     { list->setCurrentIndex(list->currentIndex() + 3); });
    QObject::connect(scr.back_to_menu, &QPushButton::clicked, [&]()
                     { list->setCurrentIndex(list->currentIndex() -3); });
    
    
    QMessageBox *dialog = new QMessageBox(w);
    dialog->setModal(true);
    dialog->resize(300,150);
    dialog->setText("Move the spaceship with arrow keys.\nShoot by pressing Space bar.\nAvoid getting hit by planets.\nTry to get the highest score possible!\n->Planet destroyed = 10 points\n->Planet left alive = -5 points");
    QAction *guide_action = ui1->menubar->addAction("Guide");
    QObject::connect(guide_action, &QAction::triggered, [&](){dialog->show();});


    list->show();

    return app.exec();
}



void score_setup(QVector<QLabel*> *vec){
    QFile file("scores.txt");
    int i = 0;
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        return;
    }
    QTextStream ts(&file);
    while(!ts.atEnd()){
        QString line = ts.readLine();
        vec->at(i)->setText(line);
        i += 1;
    }
    file.close();
}



void score_change(Game *g, QVector<QLabel*> *vec){

    vec->at(10)->setText(QString::number(g->score));
    QString num_pr(vec->at(10)->text());
    for(int i = 0; i < 10;i++){
        QString num(vec->at(i)->text());
        if(num.toInt() > num_pr.toInt()){
            continue;
        }else{
            QString tmp = num;
            QString tmp2;
            vec->at(i)->setText(QString::number(g->score));
            while(i<10){
                if(i!=9){
                    tmp2 = vec->at(i+1)->text();
                    vec->at(i+1)->setText(tmp);
                    tmp = tmp2;
                }
                i++;
            }
        }
    }
    QFile file("scores.txt");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        return;
    }
    QTextStream ts(&file);
    for(int i = 0; i<10; i++){
        ts << vec->at(i)->text();
        ts << "\n";
    }
    file.close();
}
