#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "QDebug"
#include "QString"
#include "QTextBrowser"
#include "QTextEdit"
#include "QStringList"
#include "QTimer"
#include "QObject"
#include "QLabel"
#include <QHBoxLayout>
#include <QThread>
#include <QCoreApplication>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    isMuted(false),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    ui->labelcizgi->lower();
    ui->labelcizgi2->lower();
    ui->labelcizgi3->lower();
    ui->labelcizgi4->lower();
    ui->labelcikti5->lower();

    ui->muteButton->setText("Mute");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(repeatedAction()));

    timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(repeatedAction1()));

    timer2 = new QTimer(this);
    connect(timer2, SIGNAL(timeout()), this, SLOT(repeatedAction2()));

    timer3 = new QTimer(this);
    connect(timer3, SIGNAL(timeout()), this, SLOT(repeatedAction3()));

    timer4 = new QTimer(this);
    connect(timer4, SIGNAL(timeout()), this, SLOT(repeatedAction4()));

    timer5 = new QTimer(this);
    connect(timer5, SIGNAL(timeout()), this, SLOT(repeatedAction5()));

    timer6 = new QTimer(this);
    connect(timer6, SIGNAL(timeout()), this, SLOT(repeatedAction6()));

    timer7 = new QTimer(this);
    connect(timer7, SIGNAL(timeout()), this, SLOT(repeatedAction7()));

    timer8 = new QTimer(this);
    connect(timer8, SIGNAL(timeout()), this, SLOT(repeatedAction8()));

    timer9 = new QTimer(this);
    connect(timer9, SIGNAL(timeout()), this, SLOT(repeatedAction9()));

    timer10 = new QTimer(this);
    connect(timer10, SIGNAL(timeout()), this, SLOT(repeatedAction10()));

    timer11 = new QTimer(this);
    connect(timer11, SIGNAL(timeout()), this, SLOT(repeatedAction11()));

    timerclock = new QTimer (this);
    connect(timerclock, SIGNAL(timeout()), this, SLOT(updateclock()));
    timerclock->start(1000);


}


MainWindow::~MainWindow()
{

    QProcess::startDetached("pkill -f edsdongu.sh");
    QProcess::startDetached("pkill -f edsdongu2.sh");
    QProcess::startDetached("pkill -f edsdongu3.sh");
    QProcess::startDetached("pkill -f edsdongu4.sh");
    QProcess::startDetached("pkill -f beepwarning.sh");

    delete ui;

}


void MainWindow::updateclock() {
    //clock
        QString command =  "cat /root/Eko/clock.txt";
        QProcess process;
        process.start(command);
        process.waitForFinished(-1);
        QString output = process.readAllStandardOutput();
        ui->saat->setText(output);


}

void MainWindow::on_pushButton_clicked()
{
    QProcess::startDetached("/root/Eko/./beepwarning.sh");
    QProcess::startDetached("/root/Eko/./edsdongu.sh");
    QProcess::startDetached("/root/Eko/./edsdongu2.sh");
    QProcess::startDetached("/root/Eko/./edsdongu3.sh");
    QProcess::startDetached("/root/Eko/./edsdongu4.sh");
    timer->start(100);
    timer1->start(110);
    timer2->start(120);
    timer3->start(130);
    timer4->start(140);
    timer5->start(150);
    timer6->start(160);
    timer7->start(170);
    timer8->start(180);
    timer9->start(190);
    timer10->start(200);
    timer11->start(210);





}

void MainWindow::on_stop_clicked()
{

    QTimer::singleShot(1000, this, SLOT(stoptimers()));

    QProcess::startDetached("pkill -f edsdongu.sh");
    QProcess::startDetached("pkill -f edsdongu2.sh");
    QProcess::startDetached("pkill -f edsdongu3.sh");
    QProcess::startDetached("pkill -f edsdongu4.sh");
    QProcess::startDetached("pkill -f beepwarning.sh");

}


void MainWindow::stoptimers()
{

    timer11->stop();
    timer10->stop();
    timer9->stop();
    timer8->stop();
    timer7->stop();
    timer6->stop();
    timer5->stop();
    timer4->stop();
    timer3->stop();
    timer2->stop();
    timer1->stop();
    timer->stop();
}





void MainWindow::repeatedAction()
{

    //ED1

                   QString command1 =  "cat /root/Eko/ed01/ed01.txt";
                   QProcess process1;
                   process1.start(command1);
                   process1.waitForFinished(-1);



    //Yazi
                   QString output1 = process1.readAllStandardOutput();
                   qDebug() << output1;
                   ui->ed1->setText(output1);
                   QString renk1 = ui->ed1->text();
                   if (renk1.contains("!!!!!!!!!")) {
                       ui->ed1->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                   }
                   else if (renk1.contains("State2= Scan")) {
                       ui->ed1->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                   }
                   else if (renk1.contains("State2= Dieback")) {
                       ui->ed1->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                   }
                   else if (renk1.contains("Cold")) {
                       ui->ed1->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                   }
                   else if (renk1.contains("WAIT FOR MAIN BELT START")) {
                       ui->ed1->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                   }
                   else if (renk1.contains("Diagnostic")) {
                      ui->ed1->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                   }
                   else if (renk1.contains("System Check")) {
                       ui->ed1->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                   }
                   else if (renk1.contains("CONNECTING")) {
                       ui->ed1->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                   }
                   else if (renk1.contains("WaitingForDevices")) {
                       ui->ed1->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                   }
                   else if (renk1.contains("DevicesUninitialized")) {
                       ui->ed1->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                   }
                   else if (renk1.contains("Disconnected")) {
                       ui->ed1->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                   }


    //ED2

                   QString command2 =  "cat /root/Eko/ed02/ed02.txt";
                   QProcess process2;
                   process2.start(command2);
                   process2.waitForFinished(-1);



    //Yazi
                   QString output2 = process2.readAllStandardOutput();
                   qDebug() << output2;
                   ui->ed2->setText(output2);

                   QString renk2 = ui->ed2->text();
                   if (renk2.contains("!!!!!!!!!")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                   }
                   else if (renk2.contains("State2= Scan")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                   }
                   else if (renk2.contains("State2= Dieback")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                   }
                   else if (renk2.contains("Cold")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                   }
                   else if (renk2.contains("WAIT FOR MAIN BELT START")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                   }
                   else if (renk2.contains("Diagnostic")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                   }
                   else if (renk2.contains("System Check")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                   }
                   else if (renk2.contains("CONNECTING")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                   }
                   else if (renk2.contains("WaitingForDevices")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                   }
                   else if (renk2.contains("DevicesUninitialized")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                   }
                   else if (renk2.contains("Disconnected")) {
                       ui->ed2->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                   }


               }

void MainWindow::repeatedAction1()
{
    //ED3

                         QString command3 =  "cat /root/Eko/ed03/ed03.txt";
                         QProcess process3;
                         process3.start(command3);
                         process3.waitForFinished(-1);


       //Yazi
                                 QString output3 = process3.readAllStandardOutput();
                                 qDebug() << output3;
                                 ui->ed3->setText(output3);
                                 QString renk3 = ui->ed3->text();
                                 if (renk3.contains("!!!!!!!!!")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                                 }
                                 else if (renk3.contains("State2= Scan")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                                 }
                                 else if (renk3.contains("State2= Dieback")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                                 }
                                 else if (renk3.contains("Cold")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                                 }
                                 else if (renk3.contains("WAIT FOR MAIN BELT START")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                                 }
                                 else if (renk3.contains("Diagnostic")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                                 }
                                 else if (renk3.contains("System Check")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                                 }
                                 else if (renk3.contains("CONNECTING")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                                 }
                                 else if (renk3.contains("WaitingForDevices")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                                 }
                                 else if (renk3.contains("DevicesUninitialized")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                                 }
                                 else if (renk3.contains("Disconnected")) {
                                     ui->ed3->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                                 }





    //ED4

                   QString command4 =  "cat /root/Eko/ed04/ed04.txt";
                   QProcess process4;
                   process4.start(command4);
                   process4.waitForFinished(-1);


    //Yazi
                  QString output4 = process4.readAllStandardOutput();
                  qDebug() << output4;
                  ui->ed4->setText(output4);
                  QString renk4 = ui->ed4->text();
                  if (renk4.contains("!!!!!!!!!")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                  }
                  else if (renk4.contains("State2= Scan")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                  }
                  else if (renk4.contains("State2= Dieback")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                  }
                  else if (renk4.contains("Cold")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                  }
                  else if (renk4.contains("WAIT FOR MAIN BELT START")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                  }
                  else if (renk4.contains("Diagnostic")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk4.contains("System Check")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk4.contains("CONNECTING")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk4.contains("WaitingForDevices")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk4.contains("DevicesUninitialized")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk4.contains("Disconnected")) {
                      ui->ed4->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                  }


              }
void MainWindow::repeatedAction2()
{



    //ED5

               QString command5 =  "cat /root/Eko/ed05/ed05.txt";
               QProcess process5;
               process5.start(command5);
               process5.waitForFinished(-1);


    //Yazi
               QString output5 = process5.readAllStandardOutput();
               qDebug() << output5;
               ui->ed5->setText(output5);
               QString renk5 = ui->ed5->text();
               if (renk5.contains("!!!!!!!!!")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
               }
               else if (renk5.contains("State2= Scan")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
               }
               else if (renk5.contains("State2= Dieback")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk5.contains("Cold")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk5.contains("WAIT FOR MAIN BELT START")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk5.contains("Diagnostic")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk5.contains("System Check")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk5.contains("CONNECTING")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk5.contains("WaitingForDevices")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk5.contains("DevicesUninitialized")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk5.contains("Disconnected")) {
                   ui->ed5->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
               }



    //ED6

                           QString command6 =  "cat /root/Eko/ed06/ed06.txt";
                           QProcess process6;
                           process6.start(command6);
                           process6.waitForFinished(-1);


    //Yazi
                           QString output6 = process6.readAllStandardOutput();
                           qDebug() << output6;
                           ui->ed6->setText(output6);
                           QString renk6 = ui->ed6->text();
                           if (renk6.contains("!!!!!!!!!")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                           }
                           else if (renk6.contains("State2= Scan")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                           }
                           else if (renk6.contains("State2= Dieback")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk6.contains("Cold")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk6.contains("WAIT FOR MAIN BELT START")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk6.contains("Diagnostic")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk6.contains("System Check")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk6.contains("CONNECTING")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk6.contains("WaitingForDevices")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk6.contains("DevicesUninitialized")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk6.contains("Disconnected")) {
                               ui->ed6->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                           }







}


void MainWindow::repeatedAction3()
{

    //ED9

                   QString command9 =  "cat /root/Eko/ed09/ed09.txt";
                   QProcess process9;
                   process9.start(command9);
                   process9.waitForFinished(-1);


    //Yazi
                  QString output9 = process9.readAllStandardOutput();
                  qDebug() << output9;
                  ui->ed9->setText(output9);
                  QString renk9 = ui->ed9->text();
                  if (renk9.contains("!!!!!!!!!")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                  }
                  else if (renk9.contains("State2= Scan")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                  }
                  else if (renk9.contains("State2= Dieback")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                  }
                  else if (renk9.contains("Cold")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                  }
                  else if (renk9.contains("WAIT FOR MAIN BELT START")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                  }
                  else if (renk9.contains("Diagnostic")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk9.contains("System Check")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk9.contains("CONNECTING")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk9.contains("WaitingForDevices")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk9.contains("DevicesUninitialized")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk9.contains("Disconnected")) {
                      ui->ed9->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                  }






    //ED10

               QString command10 =  "cat /root/Eko/ed10/ed10.txt";
               QProcess process10;
               process10.start(command10);
               process10.waitForFinished(-1);


    //Yazi
               QString output10 = process10.readAllStandardOutput();
               qDebug() << output10;
               ui->ed10->setText(output10);
               QString renk10 = ui->ed10->text();
               if (renk10.contains("!!!!!!!!!")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
               }
               else if (renk10.contains("State2= Scan")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
               }
               else if (renk10.contains("State2= Dieback")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk10.contains("Cold")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk10.contains("WAIT FOR MAIN BELT START")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk10.contains("Diagnostic")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk10.contains("System Check")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk10.contains("CONNECTING")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk10.contains("WaitingForDevices")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk10.contains("DevicesUninitialized")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk10.contains("Disconnected")) {
                   ui->ed10->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
               }



           }



void MainWindow::repeatedAction4()
{
    //ED11

                           QString command11 =  "cat /root/Eko/ed11/ed11.txt";
                           QProcess process11;
                           process11.start(command11);
                           process11.waitForFinished(-1);


    //Yazi
                           QString output11 = process11.readAllStandardOutput();
                           qDebug() << output11;
                           ui->ed11->setText(output11);
                           QString renk11 = ui->ed11->text();
                           if (renk11.contains("!!!!!!!!!")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                           }
                           else if (renk11.contains("State2= Scan")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                           }
                           else if (renk11.contains("State2= Dieback")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk11.contains("Cold")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk11.contains("WAIT FOR MAIN BELT START")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk11.contains("Diagnostic")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk11.contains("System Check")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk11.contains("CONNECTING")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk11.contains("WaitingForDevices")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk11.contains("DevicesUninitialized")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk11.contains("Disconnected")) {
                               ui->ed11->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                           }





    //ED12

                   QString command12 =  "cat /root/Eko/ed12/ed12.txt";
                   QProcess process12;
                   process12.start(command12);
                   process12.waitForFinished(-1);


    //Yazi
                  QString output12 = process12.readAllStandardOutput();
                  qDebug() << output12;
                  ui->ed12->setText(output12);
                  QString renk12 = ui->ed12->text();
                  if (renk12.contains("!!!!!!!!!")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                  }
                  else if (renk12.contains("State2= Scan")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                  }
                  else if (renk12.contains("State2= Dieback")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                  }
                  else if (renk12.contains("Cold")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                  }
                  else if (renk12.contains("WAIT FOR MAIN BELT START")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                  }
                  else if (renk12.contains("Diagnostic")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk12.contains("System Check")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk12.contains("CONNECTING")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk12.contains("WaitingForDevices")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk12.contains("DevicesUninitialized")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                  }
                  else if (renk12.contains("Disconnected")) {
                      ui->ed12->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                  }


              }

void MainWindow::repeatedAction5()
{



    //ED13

               QString command13 =  "cat /root/Eko/ed13/ed13.txt";
               QProcess process13;
               process13.start(command13);
               process13.waitForFinished(-1);


    //Yazi
               QString output13 = process13.readAllStandardOutput();
               qDebug() << output13;
               ui->ed13->setText(output13);
               QString renk13 = ui->ed13->text();
               if (renk13.contains("!!!!!!!!!")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
               }
               else if (renk13.contains("State2= Scan")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
               }
               else if (renk13.contains("State2= Dieback")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk13.contains("Cold")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk13.contains("WAIT FOR MAIN BELT START")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk13.contains("Diagnostic")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk13.contains("System Check")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk13.contains("CONNECTING")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk13.contains("WaitingForDevices")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk13.contains("DevicesUninitialized")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk13.contains("Disconnected")) {
                   ui->ed13->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
               }



    //ED14
                           QString command14 =  "cat /root/Eko/ed14/ed14.txt";
                           QProcess process14;
                           process14.start(command14);
                           process14.waitForFinished(-1);





    //Yazi
                           QString output14 = process14.readAllStandardOutput();
                           qDebug() << output14;
                           ui->ed14->setText(output14);
                           QString renk14 = ui->ed14->text();
                           if (renk14.contains("!!!!!!!!!")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                           }
                           else if (renk14.contains("State2= Scan")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                           }
                           else if (renk14.contains("State2= Dieback")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk14.contains("Cold")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk14.contains("WAIT FOR MAIN BELT START")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk14.contains("Diagnostic")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk14.contains("System Check")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk14.contains("CONNECTING")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk14.contains("WaitingForDevices")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk14.contains("DevicesUninitialized")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk14.contains("Disconnected")) {
                               ui->ed14->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                           }




}





//ed1

void MainWindow::on_ed1svc_released()
{
    QProcess service;
    QString selectedOption = ui->comboBox1->currentText();
    if (selectedOption == "SCC") {
        service.start("ssh -qo ConnectTimeout=1 10.1.10.37 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption == "DPP") {
            service.start("ssh -qo ConnectTimeout=1 10.1.10.37 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption == "IRC") {
                service.start("ssh -qo ConnectTimeout=1 10.1.10.37 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption == "IAC") {
                    service.start("ssh -qo ConnectTimeout=1 10.1.10.37 svc -k /service/imp/");
    }
                service.waitForFinished(-1);
}


//ed2
void MainWindow::on_svc2_released()
{
    QProcess service2;
    QString selectedOption1 = ui->comboBox1_2->currentText();
    if (selectedOption1 == "SCC") {
        service2.start("ssh -qo ConnectTimeout=1 10.1.10.40 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption1 == "DPP") {
            service2.start("ssh -qo ConnectTimeout=1 10.1.10.40 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption1 == "IRC") {
                service2.start("ssh -qo ConnectTimeout=1 10.1.10.40 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption1 == "IAC") {
                    service2.start("ssh -qo ConnectTimeout=1 10.1.10.40 svc -k /service/imp/");
    }
                service2.waitForFinished(-1);

}


//ed3
void MainWindow::on_svc2_2_released()
{
    QProcess service3;
    QString selectedOption3 = ui->comboBox1_3->currentText();
    if (selectedOption3 == "SCC") {
        service3.start("ssh -qo ConnectTimeout=1 10.1.10.35 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption3 == "DPP") {
            service3.start("ssh -qo ConnectTimeout=1 10.1.10.35 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption3 == "IRC") {
                service3.start("ssh -qo ConnectTimeout=1 10.1.10.35 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption3 == "IAC") {
                    service3.start("ssh -qo ConnectTimeout=1 10.1.10.35 svc -k /service/imp/");
    }
                service3.waitForFinished(-1);
}


//ed4
void MainWindow::on_svc2_3_released()
{
    QProcess service4;
    QString selectedOption4 = ui->comboBox1_4->currentText();
    if (selectedOption4 == "SCC") {
        service4.start("ssh -qo ConnectTimeout=1 10.1.10.36 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption4 == "DPP") {
            service4.start("ssh -qo ConnectTimeout=1 10.1.10.36 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption4 == "IRC") {
                service4.start("ssh -qo ConnectTimeout=1 10.1.10.36 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption4 == "IAC") {
                    service4.start("ssh -qo ConnectTimeout=1 10.1.10.36 svc -k /service/imp/");
    }
                service4.waitForFinished(-1);
}


//ed5
void MainWindow::on_svc2_4_released()
{
    QProcess service5;
    QString selectedOption5 = ui->comboBox1_5->currentText();
    if (selectedOption5 == "SCC") {
        service5.start("ssh -qo ConnectTimeout=1 10.1.10.38 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption5 == "DPP") {
            service5.start("ssh -qo ConnectTimeout=1 10.1.10.38 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption5 == "IRC") {
                service5.start("ssh -qo ConnectTimeout=1 10.1.10.38 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption5 == "IAC") {
                    service5.start("ssh -qo ConnectTimeout=1 10.1.10.38 svc -k /service/imp/");
    }
                service5.waitForFinished(-1);
}

//ed6
void MainWindow::on_svc2_5_released()
{
    QProcess service6;
    QString selectedOption6 = ui->comboBox1_6->currentText();
    if (selectedOption6 == "SCC") {
        service6.start("ssh -qo ConnectTimeout=1 10.1.10.39 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption6 == "DPP") {
            service6.start("ssh -qo ConnectTimeout=1 10.1.10.39 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption6 == "IRC") {
                service6.start("ssh -qo ConnectTimeout=1 10.1.10.39 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption6 == "IAC") {
                    service6.start("ssh -qo ConnectTimeout=1 10.1.10.39 svc -k /service/imp/");
    }
                service6.waitForFinished(-1);
}

//ed9
void MainWindow::on_svc2_6_released()
{
    QProcess service7;
    QString selectedOption7 = ui->comboBox1_7->currentText();
    if (selectedOption7 == "SCC") {
        service7.start("ssh -qo ConnectTimeout=1 10.1.10.25 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption7 == "DPP") {
            service7.start("ssh -qo ConnectTimeout=1 10.1.10.25 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption7 == "IRC") {
                service7.start("ssh -qo ConnectTimeout=1 10.1.10.25 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption7 == "IAC") {
                    service7.start("ssh -qo ConnectTimeout=1 10.1.10.25 svc -k /service/imp/");
    }
                service7.waitForFinished(-1);
}

//ed10
void MainWindow::on_svc2_7_released()
{
    QProcess service8;
    QString selectedOption8 = ui->comboBox1_8->currentText();
    if (selectedOption8 == "SCC") {
        service8.start("ssh -qo ConnectTimeout=1 10.1.10.17 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption8 == "DPP") {
            service8.start("ssh -qo ConnectTimeout=1 10.1.10.17 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption8 == "IRC") {
                service8.start("ssh -qo ConnectTimeout=1 10.1.10.17 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption8 == "IAC") {
                    service8.start("ssh -qo ConnectTimeout=1 10.1.10.17 svc -k /service/imp/");
    }
                service8.waitForFinished(-1);
}


//ed11
void MainWindow::on_svc2_8_released()
{
    QProcess service9;
    QString selectedOption9 = ui->comboBox1_9->currentText();
    if (selectedOption9 == "SCC") {
        service9.start("ssh -qo ConnectTimeout=1 10.1.10.23 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption9 == "DPP") {
            service9.start("ssh -qo ConnectTimeout=1 10.1.10.23 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption9 == "IRC") {
                service9.start("ssh -qo ConnectTimeout=1 10.1.10.23 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption9 == "IAC") {
                    service9.start("ssh -qo ConnectTimeout=1 10.1.10.23 svc -k /service/imp/");
    }
                service9.waitForFinished(-1);
}


//ed12
void MainWindow::on_svc2_9_released()
{
    QProcess service10;
    QString selectedOption10 = ui->comboBox1_10->currentText();
    if (selectedOption10 == "SCC") {
        service10.start("ssh -qo ConnectTimeout=1 10.1.10.22 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption10 == "DPP") {
            service10.start("ssh -qo ConnectTimeout=1 10.1.10.22 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption10 == "IRC") {
                service10.start("ssh -qo ConnectTimeout=1 10.1.10.22 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption10 == "IAC") {
                    service10.start("ssh -qo ConnectTimeout=1 10.1.10.22 svc -k /service/imp/");
    }
                service10.waitForFinished(-1);
}


//ed13
void MainWindow::on_svc2_10_released()
{
    QProcess service11;
    QString selectedOption11 = ui->comboBox1_11->currentText();
    if (selectedOption11 == "SCC") {
        service11.start("ssh -qo ConnectTimeout=1 10.1.10.33 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption11 == "DPP") {
            service11.start("ssh -qo ConnectTimeout=1 10.1.10.33 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption11 == "IRC") {
                service11.start("ssh -qo ConnectTimeout=1 10.1.10.33 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption11 == "IAC") {
                    service11.start("ssh -qo ConnectTimeout=1 10.1.10.33 svc -k /service/imp/");
    }
                service11.waitForFinished(-1);
}


//ed14
void MainWindow::on_svc2_11_released()
{
    QProcess service12;
    QString selectedOption12 = ui->comboBox1_12->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.32 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.32 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.32 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.32 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

void MainWindow::on_edlcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.37 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed1sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.37 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed2lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.40 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed2sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.40 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed3lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.35 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed3sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.35 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed4lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.36 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed4sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.36 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed5lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.38 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed5sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.38 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed6lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.39 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed6sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.39 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed9lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.25 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed9sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.25 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed10lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.17 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed10sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.17 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed11lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.23 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed11sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.23 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed12lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.22 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed12sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.22 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed13lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.33 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed13sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.33 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed14lcc_released()
{
    QProcess::startDetached("ssh -X 10.1.10.32 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed14sm_released()
{
    QProcess::startDetached("ssh -X 10.1.10.32 ssh -X scc /opt/eds/bin/sm");
}






////---------2-4 2-6 ---------/////




void MainWindow::repeatedAction6()
{



    //ED15

               QString command15 =  "cat /root/Eko/ed15/ed15.txt";
               QProcess process15;
               process15.start(command15);
               process15.waitForFinished(-1);


    //Yazi
               QString output15 = process15.readAllStandardOutput();
               qDebug() << output15;
               ui->ed15->setText(output15);
               QString renk15 = ui->ed15->text();
               if (renk15.contains("!!!!!!!!!")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
               }
               else if (renk15.contains("State2= Scan")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
               }
               else if (renk15.contains("State2= Dieback")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk15.contains("Cold")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk15.contains("WAIT FOR MAIN BELT START")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk15.contains("Diagnostic")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk15.contains("System Check")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk15.contains("CONNECTING")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk15.contains("WaitingForDevices")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk15.contains("DevicesUninitialized")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk15.contains("Disconnected")) {
                   ui->ed15->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
               }



    //ED16
                           QString command16 =  "cat /root/Eko/ed16/ed16.txt";
                           QProcess process16;
                           process16.start(command16);
                           process16.waitForFinished(-1);





    //Yazi
                           QString output16 = process16.readAllStandardOutput();
                           qDebug() << output16;
                           ui->ed16->setText(output16);
                           QString renk16 = ui->ed16->text();
                           if (renk16.contains("!!!!!!!!!")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                           }
                           else if (renk16.contains("State2= Scan")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                           }
                           else if (renk16.contains("State2= Dieback")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk16.contains("Cold")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk16.contains("WAIT FOR MAIN BELT START")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk16.contains("Diagnostic")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk16.contains("System Check")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk16.contains("CONNECTING")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk16.contains("WaitingForDevices")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk16.contains("DevicesUninitialized")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk16.contains("Disconnected")) {
                               ui->ed16->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                           }




}



void MainWindow::repeatedAction7()
{



    //ED17

               QString command17 =  "cat /root/Eko/ed17/ed17.txt";
               QProcess process17;
               process17.start(command17);
               process17.waitForFinished(-1);


    //Yazi
               QString output17 = process17.readAllStandardOutput();
               qDebug() << output17;
               ui->ed17->setText(output17);
               QString renk17 = ui->ed17->text();
               if (renk17.contains("!!!!!!!!!")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
               }
               else if (renk17.contains("State2= Scan")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
               }
               else if (renk17.contains("State2= Dieback")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk17.contains("Cold")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk17.contains("WAIT FOR MAIN BELT START")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk17.contains("Diagnostic")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk17.contains("System Check")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk17.contains("CONNECTING")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk17.contains("WaitingForDevices")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk17.contains("DevicesUninitialized")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk17.contains("Disconnected")) {
                   ui->ed17->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
               }



    //ED18
                           QString command18 =  "cat /root/Eko/ed18/ed18.txt";
                           QProcess process18;
                           process18.start(command18);
                           process18.waitForFinished(-1);





    //Yazi
                           QString output18 = process18.readAllStandardOutput();
                           qDebug() << output18;
                           ui->ed18->setText(output18);
                           QString renk18 = ui->ed18->text();
                           if (renk18.contains("!!!!!!!!!")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                           }
                           else if (renk18.contains("State2= Scan")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                           }
                           else if (renk18.contains("State2= Dieback")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk18.contains("Cold")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk18.contains("WAIT FOR MAIN BELT START")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk18.contains("Diagnostic")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk18.contains("System Check")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk18.contains("CONNECTING")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk18.contains("WaitingForDevices")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk18.contains("DevicesUninitialized")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk18.contains("Disconnected")) {
                               ui->ed18->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                           }




}


void MainWindow::repeatedAction8()
{



    //ED19

               QString command19 =  "cat /root/Eko/ed19/ed19.txt";
               QProcess process19;
               process19.start(command19);
               process19.waitForFinished(-1);


    //Yazi
               QString output19 = process19.readAllStandardOutput();
               qDebug() << output19;
               ui->ed19->setText(output19);
               QString renk19 = ui->ed19->text();
               if (renk19.contains("!!!!!!!!!")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
               }
               else if (renk19.contains("State2= Scan")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
               }
               else if (renk19.contains("State2= Dieback")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk19.contains("Cold")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk19.contains("WAIT FOR MAIN BELT START")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk19.contains("Diagnostic")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk19.contains("System Check")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk19.contains("CONNECTING")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk19.contains("WaitingForDevices")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk19.contains("DevicesUninitialized")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk19.contains("Disconnected")) {
                   ui->ed19->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
               }



    //ED20
                           QString command20 =  "cat /root/Eko/ed20/ed20.txt";
                           QProcess process20;
                           process20.start(command20);
                           process20.waitForFinished(-1);





    //Yazi
                           QString output20 = process20.readAllStandardOutput();
                           qDebug() << output20;
                           ui->ed20->setText(output20);
                           QString renk20 = ui->ed20->text();
                           if (renk20.contains("!!!!!!!!!")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                           }
                           else if (renk20.contains("State2= Scan")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                           }
                           else if (renk20.contains("State2= Dieback")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk20.contains("Cold")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk20.contains("WAIT FOR MAIN BELT START")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk20.contains("Diagnostic")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk20.contains("System Check")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk20.contains("CONNECTING")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk20.contains("WaitingForDevices")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk20.contains("DevicesUninitialized")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk20.contains("Disconnected")) {
                               ui->ed20->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                           }




}


void MainWindow::repeatedAction9()
{



    //ED23

               QString command23 =  "cat /root/Eko/ed23/ed23.txt";
               QProcess process23;
               process23.start(command23);
               process23.waitForFinished(-1);


    //Yazi
               QString output23 = process23.readAllStandardOutput();
               qDebug() << output23;
               ui->ed23->setText(output23);
               QString renk23 = ui->ed23->text();
               if (renk23.contains("!!!!!!!!!")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
               }
               else if (renk23.contains("State2= Scan")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
               }
               else if (renk23.contains("State2= Dieback")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk23.contains("Cold")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk23.contains("WAIT FOR MAIN BELT START")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk23.contains("Diagnostic")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk23.contains("System Check")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk23.contains("CONNECTING")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk23.contains("WaitingForDevices")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk23.contains("DevicesUninitialized")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk23.contains("Disconnected")) {
                   ui->ed23->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
               }



    //ED24
                           QString command24 =  "cat /root/Eko/ed24/ed24.txt";
                           QProcess process24;
                           process24.start(command24);
                           process24.waitForFinished(-1);





    //Yazi
                           QString output24 = process24.readAllStandardOutput();
                           qDebug() << output24;
                           ui->ed24->setText(output24);
                           QString renk24 = ui->ed24->text();
                           if (renk24.contains("!!!!!!!!!")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                           }
                           else if (renk24.contains("State2= Scan")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                           }
                           else if (renk24.contains("State2= Dieback")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk24.contains("Cold")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk24.contains("WAIT FOR MAIN BELT START")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk24.contains("Diagnostic")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk24.contains("System Check")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk24.contains("CONNECTING")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk24.contains("WaitingForDevices")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk24.contains("DevicesUninitialized")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk24.contains("Disconnected")) {
                               ui->ed24->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                           }




}


void MainWindow::repeatedAction10()
{



    //ED25

               QString command25 =  "cat /root/Eko/ed25/ed25.txt";
               QProcess process25;
               process25.start(command25);
               process25.waitForFinished(-1);


    //Yazi
               QString output25 = process25.readAllStandardOutput();
               qDebug() << output25;
               ui->ed25->setText(output25);
               QString renk25 = ui->ed25->text();
               if (renk25.contains("!!!!!!!!!")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
               }
               else if (renk25.contains("State2= Scan")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
               }
               else if (renk25.contains("State2= Dieback")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk25.contains("Cold")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk25.contains("WAIT FOR MAIN BELT START")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk25.contains("Diagnostic")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk25.contains("System Check")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk25.contains("CONNECTING")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk25.contains("WaitingForDevices")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk25.contains("DevicesUninitialized")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk25.contains("Disconnected")) {
                   ui->ed25->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
               }



    //ED26
                           QString command26 =  "cat /root/Eko/ed26/ed26.txt";
                           QProcess process26;
                           process26.start(command26);
                           process26.waitForFinished(-1);





    //Yazi
                           QString output26 = process26.readAllStandardOutput();
                           qDebug() << output26;
                           ui->ed26->setText(output26);
                           QString renk26 = ui->ed26->text();
                           if (renk26.contains("!!!!!!!!!")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                           }
                           else if (renk26.contains("State2= Scan")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                           }
                           else if (renk26.contains("State2= Dieback")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk26.contains("Cold")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk26.contains("WAIT FOR MAIN BELT START")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk26.contains("Diagnostic")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk26.contains("System Check")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk26.contains("CONNECTING")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk26.contains("WaitingForDevices")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk26.contains("DevicesUninitialized")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk26.contains("Disconnected")) {
                               ui->ed26->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                           }




}


void MainWindow::repeatedAction11()
{



    //ED27

               QString command27 =  "cat /root/Eko/ed27/ed27.txt";
               QProcess process27;
               process27.start(command27);
               process27.waitForFinished(-1);


    //Yazi
               QString output27 = process27.readAllStandardOutput();
               qDebug() << output27;
               ui->ed27->setText(output27);
               QString renk27 = ui->ed27->text();
               if (renk27.contains("!!!!!!!!!")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
               }
               else if (renk27.contains("State2= Scan")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
               }
               else if (renk27.contains("State2= Dieback")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk27.contains("Cold")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk27.contains("WAIT FOR MAIN BELT START")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
               }
               else if (renk27.contains("Diagnostic")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk27.contains("System Check")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk27.contains("CONNECTING")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk27.contains("WaitingForDevices")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk27.contains("DevicesUninitialized")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
               }
               else if (renk27.contains("Disconnected")) {
                   ui->ed27->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
               }



    //ED28
                           QString command28 =  "cat /root/Eko/ed28/ed28.txt";
                           QProcess process28;
                           process28.start(command28);
                           process28.waitForFinished(-1);





    //Yazi
                           QString output28 = process28.readAllStandardOutput();
                           qDebug() << output28;
                           ui->ed28->setText(output28);
                           QString renk28 = ui->ed28->text();
                           if (renk28.contains("!!!!!!!!!")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0.431111 rgba(177, 0, 0, 188), stop:1 rgba(255, 255, 255, 255)); }");
                           }
                           else if (renk28.contains("State2= Scan")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: rgb(0, 190, 0); }");
                           }
                           else if (renk28.contains("State2= Dieback")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk28.contains("Cold")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk28.contains("WAIT FOR MAIN BELT START")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: rgb(0, 203, 221); }");
                           }
                           else if (renk28.contains("Diagnostic")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk28.contains("System Check")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk28.contains("CONNECTING")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk28.contains("WaitingForDevices")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk28.contains("DevicesUninitialized")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: rgb(203, 213, 0); }");
                           }
                           else if (renk28.contains("Disconnected")) {
                               ui->ed28->setStyleSheet("QLabel { background-color: rgb(165, 165, 165); }");
                           }




}

//ed15
void MainWindow::on_ed1svc_2_released()
{

    QProcess service12;
    QString selectedOption12 = ui->comboBox1_22->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.20 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.20 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.20 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.20 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

//ed16
void MainWindow::on_svc2_19_released()
{
    QProcess service12;
    QString selectedOption12 = ui->comboBox1_18->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.28 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.28 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.28 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.28 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}


//ED17
void MainWindow::on_svc2_20_released()
{
    QProcess service12;
    QString selectedOption12 = ui->comboBox1_24->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.21 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.21 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.21 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.21 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

//ed18

void MainWindow::on_svc2_16_released()
{

    QProcess service12;
    QString selectedOption12 = ui->comboBox1_20->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.26 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.26 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.26 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.26 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

//ed19

void MainWindow::on_svc2_13_released()
{

    QProcess service12;
    QString selectedOption12 = ui->comboBox1_21->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.27 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.27 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.27 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.27 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

//ed20

void MainWindow::on_svc2_17_released()
{

    QProcess service12;
    QString selectedOption12 = ui->comboBox1_13->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.24 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.24 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.24 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.24 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

//ed23

void MainWindow::on_svc2_18_released()
{
    QProcess service12;
    QString selectedOption12 = ui->comboBox1_16->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.44 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.44 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.44 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.44 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

//ed24

void MainWindow::on_svc2_22_released()
{
    QProcess service12;
    QString selectedOption12 = ui->comboBox1_23->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.46 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.46 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.46 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.46 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

//ed25

void MainWindow::on_svc2_14_released()
{
    QProcess service12;
    QString selectedOption12 = ui->comboBox1_15->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.43 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.43 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.43 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.43 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

//ed26

void MainWindow::on_svc2_21_released()
{
    QProcess service12;
    QString selectedOption12 = ui->comboBox1_19->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.45 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.45 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.45 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.45 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

//ed27
void MainWindow::on_svc2_12_released()
{
    QProcess service12;
    QString selectedOption12 = ui->comboBox1_14->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.41 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.41 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.41 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.41 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}

//ed28

void MainWindow::on_svc2_15_released()
{
    QProcess service12;
    QString selectedOption12 = ui->comboBox1_17->currentText();
    if (selectedOption12 == "SCC") {
        service12.start("ssh -qo ConnectTimeout=1 10.1.10.42 ssh -qo ConnectTimeout=1 scc svc -k /service/scs/");
    } else if (selectedOption12 == "DPP") {
            service12.start("ssh -qo ConnectTimeout=1 10.1.10.42 ssh -qo ConnectTimeout=1 dpp svc -k /service/dpp/");
        } else if (selectedOption12 == "IRC") {
                service12.start("ssh -qo ConnectTimeout=1 10.1.10.42 ssh -qo ConnectTimeout=1 irc svc -k /service/gpuirc/");
            } else if (selectedOption12 == "IAC") {
                    service12.start("ssh -qo ConnectTimeout=1 10.1.10.42 svc -k /service/imp/");
    }
                service12.waitForFinished(-1);
}





void MainWindow::on_edlcc_2_released()
{
     QProcess::startDetached("ssh -X 10.1.10.20 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed1sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.20 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed2lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.28 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed2sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.28 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed3lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.21 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed3sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.21 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed4lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.26 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed4sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.26 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed5lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.27 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed5sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.27 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed6lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.24 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed6sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.24 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed9lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.44 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed9sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.44 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed10lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.46 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed10sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.46 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed11lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.43 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed11sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.43 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed12lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.45 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed12sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.45 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed13lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.41 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed13sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.41 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_ed14lcc_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.42 ssh -X scc /opt/eds/bin/lcc");
}

void MainWindow::on_ed14sm_2_released()
{
    QProcess::startDetached("ssh -X 10.1.10.42 ssh -X scc /opt/eds/bin/sm");
}

void MainWindow::on_filament_released()
{
    QProcess::startDetached("/root/Eko/./filamentnew");
}

void MainWindow::on_dpp_released()
{
    QProcess::startDetached("/root/Eko/./DppCat");
}

void MainWindow::on_screen_released()
{
    QProcess::startDetached("/root/Eko/./screen");
}

void MainWindow::on_seasoning_released()
{
    QProcess::startDetached("/root/Eko/./seasoning");
}

void MainWindow::on_bagfinder_released()
{
    QProcess::startDetached("/root/Eko/./bag_finder");
}

void MainWindow::on_systemmonitor_released()
{
    QProcess::startDetached("/root/Eko/./mv3d_system_monitor");
}

void MainWindow::on_pushButton_2_released()
{
    QProcess::startDetached("xterm");
}

void MainWindow::on_pushButton_3_released()
{
    QProcess::startDetached("xterm -hold -e /usr/local/bin/./tubecounter");
}

void MainWindow::on_pushButton_4_released()
{
    QProcess::startDetached("xterm -hold -e /usr/local/bin/./powercycle.sh");
}

void MainWindow::on_pushButton_5_released()
{
    QProcess::startDetached("xterm -hold -e /usr/local/bin/./disk.sh");
}

void MainWindow::on_pushButton_6_released()
{
    QProcess::startDetached("xterm -hold -e /usr/local/bin/./msf_collector");
}

void MainWindow::on_pushButton_7_released()
{
    QProcess::startDetached("/root/Eko/./Logscreen");
}



void MainWindow::on_muteButton_clicked()
{
    if (isMuted) {
        QProcess::startDetached("/root/Eko/./beepwarning.sh");
        ui->muteButton->setText("Mute");
    } else {
        QProcess::startDetached("pkill -f beepwarning.sh");
        ui->muteButton->setText("Unmuted");
    }
    isMuted = !isMuted;
}
