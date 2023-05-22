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
    //
    //this->setStyleSheet("QFrame#{border-style: solid;"
    //                    "border-width: 3px;"
    //                    "border-radius: 4px;"
    //                    "background-color: rgb(247, 147, 30);"
    //                    "border-color:  rgb(255, 252, 245);}");
}

Day::~Day()
{
    delete ui;
}

void Day::slot()
{
    // в скобочки нужно будет передавать реальные параметры
    ui->City->setText("city_param");
    ui->Date->setText("date_param");
    ui->Temp->setText("temp_param");
    ui->Pressure->setText("press_param");
    ui->MaxTemp->setText("maxT_param");
    ui->MinTemp->setText("minT_param");
    ui->WindSpeed->setText("wspeed_param");
}


void Day::on_GoBack_clicked()
{
    this->close();
    emit mainwindow();
}

