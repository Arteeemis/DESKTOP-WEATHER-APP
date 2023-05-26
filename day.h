#ifndef DAY_H
#define DAY_H

#include <QWidget>
#include <QtGui>
#include <QPixmap>
#include <QMessageBox>

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
    QPoint MyPos;
public slots:
    void slot(int DayNumber, QJsonObject obj_hd, QString city);

private slots:
    void on_GoBack_clicked();

    void on_ExitButton_clicked();

    void mouseMoveEvent(QMouseEvent *);

    void mousePressEvent(QMouseEvent *);

    void mouseReleaseEvent(QMouseEvent *);

signals:
    void mainwindow();
};

#endif // DAY_H
