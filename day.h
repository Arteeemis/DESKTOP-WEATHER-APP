#ifndef DAY_H
#define DAY_H

#include <QWidget>

namespace Ui {
class Day;
}

class Day : public QWidget
{
    Q_OBJECT

public:
    explicit Day(QWidget *parent = nullptr);
    ~Day();
    double GetWindDirection(double);

private:
    Ui::Day *ui;

public slots:
    void slot();

private slots:
    void on_GoBack_clicked();

signals:
    void mainwindow();
};

#endif // DAY_H
