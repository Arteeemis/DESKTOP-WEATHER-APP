#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "day.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double GetWindDirection(double);
    void set_weather(QString city, QJsonObject obj,QJsonObject obj_hd);
    QJsonObject obj;
    QJsonObject obj_hd;
    QString city;

private:
    Ui::MainWindow *ui;
    Day *day;

signals:
    void signal(int DayNumber, QJsonObject obj_hd, QString city);

private slots:
    void on_monday_clicked();

    void on_tuesday_clicked();

    void on_wednesday_clicked();

    void on_thursday_clicked();
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
