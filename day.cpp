#include "day.h"
#include "ui_day.h"
#include <QPixmap>

Day::Day(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Day)
{
    ui->setupUi(this);
    //
    QPixmap bkgnd(":/resources/img/bkgd.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    // wind icon
    double degree = GetWindDirection(100);
    QPixmap WindPix(":/resources/img/windiconday.png");
    WindPix = WindPix.transformed(QTransform()
                                      .translate(ui->WindIconDay->x(), ui->WindIconDay->y())
                                      .rotate(degree)
                                      .translate(-ui->WindIconDay->x(), -ui->WindIconDay->y()));
    int w = ui->WindIconDay->width();
    int h = ui->WindIconDay->height();

    ui->WindIconDay->setPixmap(WindPix.scaled(w, h, Qt::KeepAspectRatio,  Qt::SmoothTransformation));

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

void Day::slot()
{
    // В скобочки нужно будет передавать реальные параметры - API
    //ui->City->setText("city_param");
    //ui->Date->setText("date_param");
    //ui->Temp->setText("temp_param");
    //ui->Pressure->setText("press_param");
    //ui->MaxTemp->setText("maxT_param");
    //ui->MinTemp->setText("minT_param");
    //ui->WindSpeed->setText("wspeed_param");
}


void Day::on_GoBack_clicked()
{
    this->close();
    emit mainwindow();
}

