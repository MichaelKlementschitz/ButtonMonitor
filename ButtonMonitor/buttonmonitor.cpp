#include "buttonmonitor.h"
#include <wiringPi.h>
#include <QTimer>

ButtonMonitor::ButtonMonitor(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    wiringPiSetupGpio();
    pinMode(B1, INPUT);
    pinMode(B2, INPUT);
    pinMode(B3, INPUT);
    updateValue();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
    timer->start(T_UPDATE);
}

void ButtonMonitor::updateValue()
{
    for(int i = 1; i <= 3; i++)
    {
        (findChild<QLabel *>("btn" + QString::number(i)))->setText(QString::number(1-digitalRead(Butn[i-1])));
        (findChild<QLabel *>("btn" + QString::number(i)))->setStyleSheet((1-digitalRead(Butn[i-1])) ? "background-color:red;color: black;" : "background-color:black;color: white;");
    }
}
