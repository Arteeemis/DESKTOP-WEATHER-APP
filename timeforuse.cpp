#include "timeforuse.h"

QString get_dotw(){
    time_t now = time(0);

    // convert now to string form
    std::string dt = ctime(&now);
    std::string cur = "";
    std::vector<std::string> time_stamps;
    for (int i = 0; i < dt.size(); i++){
        if (dt[i] == ' '){
            time_stamps.push_back(cur);
            cur = "";
        } else {
            cur += dt[i];
        }
    }
    std::string dotw = time_stamps[0];
    if (dotw == "Mon"){
        return QString("Понедельник");
    } else if (dotw == "Tue"){
        return QString("Вторник");
    } else if (dotw == "Wed"){
        return QString("Среда");
    } else if (dotw == "Thu"){
        return QString("Четверг");
    } else if (dotw == "Fri"){
        return QString("Птяница");
    } else if (dotw == "Sat"){
        return QString("Суббота");
    } else if (dotw == "Sun"){
        return QString("Воскресенье");
    }
}

QString get_month() {
    time_t now = time(0);

    // convert now to string form
    std::string dt = ctime(&now);
    std::string cur = "";
    std::vector<std::string> time_stamps;
    for (int i = 0; i < dt.size(); i++){
        if (dt[i] == ' '){
            time_stamps.push_back(cur);
            cur = "";
        } else {
            cur += dt[i];
        }
    }
    std::string month = time_stamps[1];
    if (month == "Jan"){
        return QString("января");
    } else if (month == "Feb"){
        return QString("февраля");
    } else if (month == "Mar"){
        return QString("марта");
    } else if (month == "Apr"){
        return QString("апреля");
    } else if (month == "May"){
        return QString("мая");
    } else if (month == "Jun"){
        return QString("июня");
    } else if (month == "Jul"){
        return QString("июля");
    } else if (month == "Aug"){
        return QString("августа");
    } else if (month == "Sep"){
        return QString("Сентября");
    } else if (month == "Oct"){
        return QString("октября");
    } else if (month == "Nov"){
        return QString("ноября");
    } else if (month == "Dec"){
        return QString("декабря");
    }
}

QString get_day(){
    time_t now = time(0);

    // convert now to string form
    std::string dt = ctime(&now);
    std::string cur = "";
    std::vector<std::string> time_stamps;
    for (int i = 0; i < dt.size(); i++){
        if (dt[i] == ' '){
            time_stamps.push_back(cur);
            cur = "";
        } else {
            cur += dt[i];
        }
    }
    return QString::fromStdString(time_stamps[2]);
}
