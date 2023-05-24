#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
