#ifndef WEATHERAPI_H
#define WEATHERAPI_H
#include <QEventLoop>
#include <QJsonObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>

QJsonObject get_weather_json(QString city);
double get_temp(QJsonObject obj);
QString get_weather_description(QJsonObject obj);
double get_temp_min(QJsonObject obj);
double get_temp_max(QJsonObject obj);
double get_feels_like(QJsonObject obj);
int get_humidity(QJsonObject obj);
double get_pressure(QJsonObject obj);
double get_wind_speed(QJsonObject obj);
QJsonObject get_weather_json_hd(QString city);
double get_temp_hd(QJsonObject obj, int day);
double get_temp_min_hd(QJsonObject obj, int day);
double get_temp_max_hd(QJsonObject obj, int day);
QString get_weather_description_hd(QJsonObject obj, int day);
#endif // WEATHERAPI_H
