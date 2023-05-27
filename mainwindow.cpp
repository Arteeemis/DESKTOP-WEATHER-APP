#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
#include "weatherAPI.h"
#include "timeforuse.h"

void MainWindow::set_weather(QString city, QJsonObject obj,QJsonObject obj_hd ){
    if (city_found(get_weather_json(city))){
    ui->TempNow->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" + QString("")+QString::number(get_temp(obj))+QString("°")+ "</span></p></body></html>");
    ui->WindNow->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" +QString(" ")+QString::number(get_wind_speed(obj))+QString(" м/с")+ "</span></p></body></html>");
    ui->DayOneTemp->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_d(obj_hd,0))+QString("°")+ "</span></p></body></html>");
    ui->DayTwoTemp->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_d(obj_hd,1))+QString("°")+ "</span></p></body></html>");
    ui->DayThreeTemp->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_d(obj_hd,2))+QString("°")+ "</span></p></body></html>");
    ui->DayFourTemp->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_d(obj_hd,3))+QString("°")+ "</span></p></body></html>");
    ui->DayOneMin->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_min_d(obj_hd,0))+QString("°")+ "</span></p></body></html>");
    ui->DayTwoMin->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_min_d(obj_hd,1))+QString("°")+ "</span></p></body></html>");
    ui->DayThreeMin->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_min_d(obj_hd,2))+QString("°")+ "</span></p></body></html>");
    ui->DayFourMin->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_min_d(obj_hd,3))+QString("°")+ "</span></p></body></html>");
    ui->DayOneMax->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_max_d(obj_hd,0))+QString("°")+ "</span></p></body></html>");
    ui->DayTwoMax->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_max_d(obj_hd,1))+QString("°")+ "</span></p></body></html>");
    ui->DayThreeMax->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_max_d(obj_hd,2))+QString("°")+ "</span></p></body></html>");
    ui->DayFourMax->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString::number(get_temp_max_d(obj_hd,3))+QString("°")+ "</span></p></body></html>");//
    ui->DayOneWeather->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString(get_weather_description_d(obj_hd,0))+ "</span></p></body></html>");
    ui->DayTwoWeather->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+QString(get_weather_description_d(obj_hd,1))+ "</span></p></body></html>");
    ui->DayThreeWeather->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+(get_weather_description_d(obj_hd,2))+ "</span></p></body></html>");
    ui->DayFourWeather->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString("")+(get_weather_description_d(obj_hd,3))+ "</span></p></body></html>");
    ui->HourOneTemp->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" +QString::number(get_temp_hourly(obj_hd,0))+QString("°")+ "</span></p></body></html>");
    ui->HourTwoTemp->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" +QString::number(get_temp_hourly(obj_hd,1))+QString("°")+ "</span></p></body></html>");
    ui->HourThreeTemp->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" +QString::number(get_temp_hourly(obj_hd,2))+QString("°")+ "</span></p></body></html>");
        double degree = GetWindDirection(get_wind_direct(obj));
    QPixmap WindPix(":/resources/img/windicon5 (2).png");
    WindPix = WindPix.transformed(QTransform()
                                      .translate(ui->WindIcon->x(), ui->WindIcon->y())
                                      .rotate(degree)
                                      .translate(-ui->WindIcon->x(), -ui->WindIcon->y()));
    int w = ui->WindIcon->width();
    int h = ui->WindIcon->height();

    ui->WindIcon->setPixmap(WindPix.scaled(w, h, Qt::KeepAspectRatio,  Qt::SmoothTransformation));
    } else
    {
    QMessageBox::critical(this, "Error" ,"Такого города нет, введите другой");
    }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    city = "Москва";
    // Earth Img
    QPixmap pix(":/resources/img/cute_earth.png");
    int w = ui->Earth->width();
    int h = ui->Earth->height();
    ui->Earth->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    //
    this->setWindowTitle("WeatherApp");
    // прозрачность кнопки
    ui->DayOne->setStyleSheet("background: transparent;");
    //
    day = new Day;

    connect(this, &MainWindow::signal, day, &Day::slot);
    connect(day, &Day::mainwindow, this, &MainWindow::show);
    obj = get_weather_json(city);
    obj_hd = get_weather_json_hd(city);
    ui->Date->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" +get_dotw(0)+QString(", ")+get_day(0)+QString(" ")+get_month()+ "</span></p></body></html>");
    ui->DayOne->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + get_dotw(1)+QString(" ")+get_day(1) + "</span></p></body></html>");
    ui->DayTwo->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" +get_dotw(2)+QString(" ")+get_day(2) + "</span></p></body></html>");
    ui->DayThree->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + get_dotw(3)+QString(" ")+get_day(3)+ "</span></p></body></html>");
    ui->DayFour->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" +get_dotw(4)+QString(" ")+get_day(4) + "</span></p></body></html>");
    ui->HourOne->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" +get_hours(obj_hd,0)+QString(" ")+ "</span></p></body></html>");
    ui->HourTwo->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" +get_hours(obj_hd,1)+QString(" ")+ "</span></p></body></html>");
    ui->HourThree->setText("<html><head/><body><p><span style=\" color:#0e0f3b;\">" +get_hours(obj_hd,2)+ "</span></p></body></html>");
    ui->SearchLine->setText(city);
    set_weather(city,obj,obj_hd);
    // wind icon
    double degree = GetWindDirection(get_wind_direct(obj));
    QPixmap WindPix(":/resources/img/windicon5 (2).png");
    WindPix = WindPix.transformed(QTransform()
                                      .translate(ui->WindIcon->x(), ui->WindIcon->y())
                                      .rotate(degree)
                                      .translate(-ui->WindIcon->x(), -ui->WindIcon->y()));
    w = ui->WindIcon->width();
    h = ui->WindIcon->height();

    ui->WindIcon->setPixmap(WindPix.scaled(w, h, Qt::KeepAspectRatio,  Qt::SmoothTransformation));
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::GetWindDirection(double degree)
{
    double d = 0.0;
    if((degree >= 0 && degree < 45) || (degree > 315 && degree <= 360))
        d = 0;
    else if(degree >= 45 && degree < 135)
        d = 90;
    else if(degree >= 135 && degree < 225)
        d = 180;
    else if(degree >= 225 && degree <= 315)
        d = 270;

    return d;
}

void MainWindow::on_monday_clicked()
{
    //day->setStyleSheet("background-color: rgb(247, 147, 30);");
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal(1,obj_hd,city);
    //закрываем основное окно
    this->close();
}

void MainWindow::on_tuesday_clicked()
{
    //day->setStyleSheet("background-color: rgb(127, 205, 238);");
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal(2,obj_hd,city);
    //закрываем основное окно
    this->close();
}

void MainWindow::on_wednesday_clicked()
{
    //day->setStyleSheet("background-color: rgb(7, 64, 123);");
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal(3,obj_hd,city);
    //закрываем основное окно
    this->close();
}

void MainWindow::on_thursday_clicked()
{
    //day->setStyleSheet("background-color: rgb(14, 15, 59);");
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal(4,obj_hd,city);
    //закрываем основное окно
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    QString city = ui->SearchLine->text();
    QJsonObject obj = get_weather_json(city);
    QJsonObject obj_hd = get_weather_json_hd(city);
    set_weather(city,obj,obj_hd);

}

