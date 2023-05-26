#include "weatherAPI.h"
#include "timeforuse.h"

QJsonObject get_weather_json(QString city){
    QString baseUrl = "https://api.openweathermap.org/data/2.5/weather";
    QString apiKey = "bfa8d426b626bbfadae0dfb17496323c";
    QUrlQuery query;
    query.addQueryItem("q", city);
    query.addQueryItem("appid", apiKey);
    query.addQueryItem("lang", "ru");
    query.addQueryItem("units", "metric");

    // Build the request URL
    QUrl url(baseUrl);
    url.setQuery(query);

    // Create a network access manager to make the HTTP request
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(QNetworkRequest(url));

    // Create an event loop to block until the request is finished
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Parse the JSON response
    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();
    return obj;
}

QJsonObject get_weather_json_(QString city){
    QString baseUrl = "https://api.openweathermap.org/data/2.5/forecast";
    QString apiKey = "bfa8d426b626bbfadae0dfb17496323c";
    QUrlQuery query;
    query.addQueryItem("q", city);
    query.addQueryItem("appid", apiKey);
    query.addQueryItem("lang", "ru");
    query.addQueryItem("units", "metric");

    // Build the request URL
    QUrl url(baseUrl);
    url.setQuery(query);

    // Create a network access manager to make the HTTP request
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(QNetworkRequest(url));

    // Create an event loop to block until the request is finished
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Parse the JSON response
    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();
    return obj;
}

double get_temp(QJsonObject obj){
    QJsonObject weather = obj["weather"].toArray()[0].toObject();
    double temperature = obj["main"].toObject()["temp"].toDouble();
    return temperature;
}

QString get_weather_description(QJsonObject obj){
    QJsonObject weather = obj["weather"].toArray()[0].toObject();
    QString description = weather["description"].toString();
    return description;
}

double get_temp_min(QJsonObject obj){
    QJsonObject weather = obj["weather"].toArray()[0].toObject();
    double temperature = obj["main"].toObject()["temp_min"].toDouble();
    return temperature;
}

double get_temp_max(QJsonObject obj){
    QJsonObject weather = obj["weather"].toArray()[0].toObject();
    double temperature = obj["main"].toObject()["temp_max"].toDouble();
    return temperature;
}

double get_feels_like(QJsonObject obj){
    QJsonObject weather = obj["weather"].toArray()[0].toObject();
    double feels_like = obj["main"].toObject()["feels_like"].toDouble();
    return feels_like;
}

int get_humidity(QJsonObject obj){
    QJsonObject weather = obj["weather"].toArray()[0].toObject();
    int humidity = obj["main"].toObject()["humidity"].toDouble();
    return humidity;
}

double get_pressure(QJsonObject obj){
    QJsonObject weather = obj["weather"].toArray()[0].toObject();
    double pressure = obj["main"].toObject()["pressure"].toDouble();
    return (pressure/1.333);
}

double get_wind_speed(QJsonObject obj){
    QJsonObject weather = obj["weather"].toArray()[0].toObject();
    double speed = obj["wind"].toObject()["speed"].toDouble();
    return speed;
}

// functions to get the hourly/daily(hd) info about the weather

QJsonObject get_weather_json_hd(QString city){
    QString baseUrl = "https://api.openweathermap.org/data/2.5/forecast";
    QString apiKey = "bfa8d426b626bbfadae0dfb17496323c";
    QUrlQuery query;
    query.addQueryItem("q", city);
    query.addQueryItem("appid", apiKey);
    query.addQueryItem("lang", "ru");
    query.addQueryItem("units", "metric");

    // Build the request URL
    QUrl url(baseUrl);
    url.setQuery(query);

    // Create a network access manager to make the HTTP request
    QNetworkAccessManager manager;
    QNetworkReply *reply = manager.get(QNetworkRequest(url));

    // Create an event loop to block until the request is finished
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Parse the JSON response
    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();
    return obj;
}

double get_temp_hd(QJsonObject obj, int day){ // receives day(0 - tomorrow ... )
    int temp = 0;
    QJsonArray weather = obj["list"].toArray();
    for (int i = 0; i < weather.size(); i++){// 8 9 11 12
        if (get_day(1) == (QString(weather[i].toObject()["dt_txt"].toString()[8])+QString(weather[i].toObject()["dt_txt"].toString()[9]))) {
            if (QString(weather[i].toObject()["dt_txt"].toString()[11]) == '1' && QString(weather[i].toObject()["dt_txt"].toString()[12]) =='5'){
                temp = i+8*day;
                break;
            }
        }
    }
    double temperature = weather[temp].toObject()["main"].toObject()["temp"].toDouble();
    return temperature;
}

double get_temp_min_hd(QJsonObject obj, int day){ // receives day(0 - tomorrow ... )
    int temp = 0;
    QJsonArray weather = obj["list"].toArray();
    for (int i = 0; i < weather.size(); i++){// 8 9 11 12
        if (get_day(1) == (QString(weather[i].toObject()["dt_txt"].toString()[8])+QString(weather[i].toObject()["dt_txt"].toString()[9]))) {
            if (QString(weather[i].toObject()["dt_txt"].toString()[11]) == '2' && QString(weather[i].toObject()["dt_txt"].toString()[12]) =='1'){
                temp = i+8*day;
                break;
            }
        }
    }
    double temperature = weather[temp].toObject()["main"].toObject()["temp_min"].toDouble();
    return temperature;
}

double get_temp_max_hd(QJsonObject obj, int day){ // receives day(0 - tomorrow ... )
    int temp = 0;
    QJsonArray weather = obj["list"].toArray();
    for (int i = 0; i < weather.size(); i++){// 8 9 11 12
        if (get_day(1) == (QString(weather[i].toObject()["dt_txt"].toString()[8])+QString(weather[i].toObject()["dt_txt"].toString()[9]))) {
            if (QString(weather[i].toObject()["dt_txt"].toString()[11]) == '1' && QString(weather[i].toObject()["dt_txt"].toString()[12]) =='2'){
                temp = i+8*day;
                break;
            }
        }
    }
    double temperature = weather[temp].toObject()["main"].toObject()["temp_max"].toDouble();
    return temperature+1;
}

QString get_weather_description_hd(QJsonObject obj, int day){ // receives day(0 - tomorrow ... )
    int temp = 0;
    QJsonArray weather = obj["list"].toArray();
    for (int i = 0; i < weather.size(); i++){// 8 9 11 12
        if (get_day(1) == (QString(weather[i].toObject()["dt_txt"].toString()[8])+QString(weather[i].toObject()["dt_txt"].toString()[9]))) {
            if (QString(weather[i].toObject()["dt_txt"].toString()[11]) == '1' && QString(weather[i].toObject()["dt_txt"].toString()[12]) =='5'){
                temp = i+8*day;
                break;
            }
        }
    }
    QJsonObject temperature = weather[temp].toObject()["weather"].toArray()[0].toObject();
    QString ans = temperature["description"].toString();
    return ans;
}

