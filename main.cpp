#include "mainwindow.h"
#include <QCoreApplication>
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QString city = "Москва";
    //QJsonObject obj = get_weather_json(city);
    //QString description = get_weather_description(obj);
    //double temperature = get_temp(obj);
    //double min_temp = get_temp_min(obj);
    //double max_temp = get_temp_max(obj);
    //double feels_like = get_feels_like(obj);
    //int humidity = get_humidity(obj);
    //double pressure = get_pressure(obj);
    //double ws = get_wind_speed(obj);
    //auto start = std::chrono::system_clock::now();
    //// Print the weather information
    //qDebug() << QString("Погода в городе %1: %2, %3°C").arg(city, description, QString::number(temperature));
    //qDebug() << QString("min temp ") << QString::number(min_temp);
    //qDebug() << QString("max temp ") << QString::number(max_temp);
    //qDebug() << QString("feels like") << QString::number(feels_like);
    //qDebug() << QString("humidity ") << humidity << QString("%");
    //qDebug() << QString("pressure ") << pressure ;
    //qDebug() << QString("wind speed ") << ws << QString("м/с");
    //qDebug() << obj;
    MainWindow w;
    w.show();
    return a.exec();
}
