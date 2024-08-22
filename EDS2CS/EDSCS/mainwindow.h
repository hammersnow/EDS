#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QList>
#include <QPushButton>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;
    QTimer *timer6;
    QTimer *timer7;
    QTimer *timer8;
    QTimer *timer9;
    QTimer *timer10;
    QTimer *timer11;
    QTimer *timerclock;
    bool isMuted;
    Ui::MainWindow *ui;

private slots:
    void updateclock();
    void on_muteButton_clicked();
    void on_pushButton_7_released();
    void on_pushButton_6_released();
    void on_pushButton_5_released();
    void on_pushButton_4_released();
    void on_pushButton_3_released();
    void on_pushButton_2_released();
    void on_systemmonitor_released();
    void on_bagfinder_released();
    void on_seasoning_released();
    void on_screen_released();
    void on_dpp_released();
    void on_filament_released();
    void on_ed14sm_2_released();
    void on_ed14lcc_2_released();
    void on_ed13sm_2_released();
    void on_ed13lcc_2_released();
    void on_ed12sm_2_released();
    void on_ed12lcc_2_released();
    void on_ed11sm_2_released();
    void on_ed11lcc_2_released();
    void on_ed10sm_2_released();
    void on_ed10lcc_2_released();
    void on_ed9sm_2_released();
    void on_ed9lcc_2_released();
    void on_ed6sm_2_released();
    void on_ed6lcc_2_released();
    void on_ed5sm_2_released();
    void on_ed5lcc_2_released();
    void on_ed4sm_2_released();
    void on_ed4lcc_2_released();
    void on_ed3sm_2_released();
    void on_ed3lcc_2_released();
    void on_ed2sm_2_released();
    void on_ed2lcc_2_released();
    void on_ed1sm_2_released();
    void on_edlcc_2_released();
    void on_svc2_15_released();
    void on_svc2_12_released();
    void on_svc2_21_released();
    void on_svc2_14_released();
    void on_svc2_22_released();
    void on_svc2_18_released();
    void on_svc2_17_released();
    void on_svc2_13_released();
    void on_svc2_16_released();
    void on_svc2_20_released();
    void on_svc2_19_released();
    void on_ed1svc_2_released();
    void on_ed14sm_released();
    void on_ed14lcc_released();
    void on_ed13sm_released();
    void on_ed13lcc_released();
    void on_ed12sm_released();
    void on_ed12lcc_released();
    void on_ed11sm_released();
    void on_ed11lcc_released();
    void on_ed10sm_released();
    void on_ed10lcc_released();
    void on_ed9sm_released();
    void on_ed9lcc_released();
    void on_ed6sm_released();
    void on_ed6lcc_released();
    void on_ed5sm_released();
    void on_ed5lcc_released();
    void on_ed4sm_released();
    void on_ed4lcc_released();
    void on_ed3sm_released();
    void on_ed3lcc_released();
    void on_ed2sm_released();
    void on_ed2lcc_released();
    void on_ed1sm_released();
    void on_edlcc_released();
    void on_svc2_11_released();
    void on_svc2_10_released();
    void on_svc2_9_released();
    void on_svc2_8_released();
    void on_svc2_7_released();
    void on_svc2_6_released();
    void on_svc2_5_released();
    void on_svc2_4_released();
    void on_svc2_3_released();
    void on_svc2_2_released();
    void on_svc2_released();
    void on_ed1svc_released();
    void on_stop_clicked();
    void on_pushButton_clicked();
    void repeatedAction();
    void repeatedAction1();
    void repeatedAction2();
    void repeatedAction3();
    void repeatedAction4();
    void repeatedAction5();
    void repeatedAction6();
    void repeatedAction7();
    void repeatedAction8();
    void repeatedAction9();
    void repeatedAction10();
    void repeatedAction11();
    void stoptimers();


};

#endif // MAINWINDOW_H
