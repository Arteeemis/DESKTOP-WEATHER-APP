#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // bg Img
    QPixmap bkgnd(":/resources/img/bkg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    // Earth Img
    QPixmap pix(":/resources/img/globe.png");
    int w = ui->Earth->width();
    int h = ui->Earth->height();
    ui->Earth->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    //
    this->setWindowTitle("WeatherApp");
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
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal();
    //закрываем основное окно
    this->close();
}

void MainWindow::on_tuesday_clicked()
{
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal();
    //закрываем основное окно
    this->close();
}

void MainWindow::on_wednesday_clicked()
{
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal();
    //закрываем основное окно
    this->close();
}

void MainWindow::on_thursday_clicked()
{
    //открываем дополнительное окно
    day->show();
    //вызов сигнала
    emit signal();
    //закрываем основное окно
    this->close();
}
