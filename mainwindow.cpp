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
    ui->MondayTemp->setText( QString("")+QString::number(get_temp_hd(get_weather_json_hd(city),0)));
    ui->TuesdayTemp->setText( QString("")+QString::number(get_temp_hd(get_weather_json_hd(city),1)));
    ui->WednesdayTemp->setText( QString("")+QString::number(get_temp_hd(get_weather_json_hd(city),2)));
    ui->ThursdayTemp->setText( QString("")+QString::number(get_temp_hd(get_weather_json_hd(city),3)));
    ui->MondayMin->setText( QString("")+QString::number(get_temp_min_hd(get_weather_json_hd(city),0)));
    ui->TuesdayMin->setText( QString("")+QString::number(get_temp_min_hd(get_weather_json_hd(city),1)));
    ui->WednesdayMin->setText( QString("")+QString::number(get_temp_min_hd(get_weather_json_hd(city),2)));
    ui->ThursdayMin->setText( QString("")+QString::number(get_temp_min_hd(get_weather_json_hd(city),3)));
    ui->MondayMax->setText( QString("")+QString::number(get_temp_max_hd(get_weather_json_hd(city),0)));
    ui->TuesdayMax->setText( QString("")+QString::number(get_temp_max_hd(get_weather_json_hd(city),1)));
    ui->WednesdayMax->setText( QString("")+QString::number(get_temp_max_hd(get_weather_json_hd(city),2)));
    ui->ThursdayMax->setText( QString("")+QString::number(get_temp_max_hd(get_weather_json_hd(city),3)));
    ui->MondayWeather->setText( QString("")+QString(get_weather_description_hd(get_weather_json_hd(city),0)));
    ui->TuesdayWeather->setText( QString("")+QString(get_weather_description_hd(get_weather_json_hd(city),1)));
    ui->WednesdayWeather->setText( QString("")+(get_weather_description_hd(get_weather_json_hd(city),2)));
    ui->ThursdayWeather->setText( QString("")+(get_weather_description_hd(get_weather_json_hd(city),3)));
    // wind icon
    double degree = GetWindDirection(100);
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

void MainWindow::on_pushButton_clicked()
{
    QString City = ui->SearchLine->text();
}

