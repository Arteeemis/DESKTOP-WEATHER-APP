#include "day.h"
#include "ui_day.h"
#include "weatherAPI.h"
#include "timeforuse.h"

Day::Day(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Day)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    // wind icon
    //QJsonObject obj = get_weather_json();
    // ПОМЕНЯТЬ ПАРАМЕТР ФУНКЦИИ GetWindDirection

}

Day::~Day()
{
    delete ui;
}

double Day::GetWindDirection(double degree)
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

void Day::slot(int DayNumber, QJsonObject obj_hd, QString city)
{
    switch(DayNumber)
    {
    case 1:
        ui->groupBox->setStyleSheet("QGroupBox{background-color: rgb(247, 147, 30);"
                                    "border-style: solid;"
                                    "border-radius: 29px;"
                                    "border-width: 12px;"
                                    "border-color: rgb(255, 252, 245);}");
        break;
    case 2:
        ui->groupBox->setStyleSheet("QGroupBox{background-color: rgb(127, 205, 238);"
                                    "border-style: solid;"
                                    "border-radius: 29px;"
                                    "border-width: 12px;"
                                    "border-color: rgb(255, 252, 245);}");
        break;
    case 3:
        ui->groupBox->setStyleSheet("QGroupBox{background-color: rgb(7, 64, 123);"
                                    "border-style: solid;"
                                    "border-radius: 29px;"
                                    "border-width: 12px;"
                                    "border-color: rgb(255, 252, 245);}");
        break;
    case 4:
        ui->groupBox->setStyleSheet("QGroupBox{background-color: rgb(14, 15, 59);"
                                    "border-style: solid;"
                                    "border-radius: 29px;"
                                    "border-width: 12px;"
                                    "border-color: rgb(255, 252, 245);}");
        break;

    }

    // В скобочки нужно будет передавать реальные параметры - API
    ui->CityData->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + city+ "</span></p></body></html>");
    ui->DateData->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" + QString(get_day(DayNumber)) + "</span></p></body></html>");
    ui->TempData->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" +QString::number(get_temp_d(obj_hd,DayNumber-1))+ "</span></p></body></html>");
    ui->PressureData->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" +QString::number(get_pressure_d(obj_hd,DayNumber-1))+ "</span></p></body></html>");
    ui->HumidityData->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" +QString::number(get_humidity_d(obj_hd,DayNumber-1))+QString(" %")+ "</span></p></body></html>");
    ui->FeelsLikeData->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" +QString::number(get_feels_like_d(obj_hd,DayNumber-1))+ "</span></p></body></html>");
    ui->WindData->setText("<html><head/><body><p><span style=\" color:#fffcf5;\">" +QString::number(get_wind_speed_d(obj_hd,DayNumber-1))+ "</span></p></body></html>");
    double degree = GetWindDirection(get_wind_direct_d(obj_hd,DayNumber-1));
    QPixmap WindPix(":/resources/img/windiconday.png");
    WindPix = WindPix.transformed(QTransform()
                                      .translate(ui->WindIconDay->x(), ui->WindIconDay->y())
                                      .rotate(degree)
                                      .translate(-ui->WindIconDay->x(), -ui->WindIconDay->y()));
    int w = ui->WindIconDay->width();
    int h = ui->WindIconDay->height();

    ui->WindIconDay->setPixmap(WindPix.scaled(w, h, Qt::KeepAspectRatio,  Qt::SmoothTransformation));
}

void Day::on_GoBack_clicked()
{
    this->close();
    emit mainwindow();
}

void Day::on_ExitButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Выход", "Вы действительно хотите закрыть приложение?",
                                                              QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        this->close();
    }
}

void Day::mouseMoveEvent(QMouseEvent *e)
{
    if(MyPos.x() >= 0 && e->buttons() && Qt::LeftButton)
    {
        QPoint dif = e->pos() - MyPos;
        QPoint npos = this->pos() + dif;
        this->move(npos);
    }
}

void Day::mousePressEvent(QMouseEvent *e)
{
    MyPos = e->pos();
}

void Day::mouseReleaseEvent(QMouseEvent *e)
{
    MyPos = QPoint(-1,1);
}

