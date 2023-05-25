#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
#include "weatherAPI.h"
#include "timeforuse.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString city = "Moscow";
    // Earth Img
    QPixmap pix(":/resources/img/cute_earth.png");
    int w = ui->Earth->width();
    int h = ui->Earth->height();
    ui->Earth->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    //
    this->setWindowTitle("WeatherApp");
    // прозрачность кнопки
    ui->label->setStyleSheet("background: transparent;");
    //
    day = new Day;

    connect(this, &MainWindow::signal, day, &Day::slot);
    connect(day, &Day::mainwindow, this, &MainWindow::show);
    ui->label_29->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" + QString("")+QString::number(get_temp(get_weather_json(city)))+QString("°")+ "</span></p></body></html>");
    ui->label_31->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" +QString(" ")+QString::number(get_wind_speed(get_weather_json(city)))+QString(" м/с")+ "</span></p></body></html>");
    ui->label_32->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" +get_dotw(0)+QString(", ")+get_day(0)+QString(" ")+get_month()+ "</span></p></body></html>");
    ui->label->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + get_dotw(1)+QString(" ")+get_day(1) + "</span></p></body></html>");
    ui->label_2->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" +get_dotw(2)+QString(" ")+get_day(2) + "</span></p></body></html>");
    ui->label_3->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + get_dotw(3)+QString(" ")+get_day(3)+ "</span></p></body></html>");
    ui->label_4->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" +get_dotw(4)+QString(" ")+get_day(4) + "</span></p></body></html>");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_monday_clicked()
{
    day->setStyleSheet("background-color: rgb(247, 147, 30);");
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal();
    //закрываем основное окно
    this->close();
}

void MainWindow::on_tuesday_clicked()
{
    day->setStyleSheet("background-color: rgb(127, 205, 238);");
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal();
    //закрываем основное окно
    this->close();
}

void MainWindow::on_wednesday_clicked()
{
    day->setStyleSheet("background-color: rgb(7, 64, 123);");
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal();
    //закрываем основное окно
    this->close();
}

void MainWindow::on_thursday_clicked()
{
    day->setStyleSheet("background-color: rgb(14, 15, 59);");
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal();
    //закрываем основное окно
    this->close();
}
