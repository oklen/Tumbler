#ifndef UXTUMBLER_H
#define UXTUMBLER_H

#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QTime>
#include <QTimer>

class UXTUMBLER : public QWidget
{
    Q_OBJECT
public:
    explicit UXTUMBLER(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    qreal getcurval();


    QTime mtime;
    QPoint initpoint = QPoint(0,0);
    QPoint curpoint = QPoint(0,0);
    QPoint lastpos = QPoint(0,0);
    qreal curval = 50.0;
    qreal stayval = 50.0;
    qreal mspeed;
    QTimer *timer = new QTimer;
    int lasttime = 0;
    int maxbound = 100;
    int minbound = 10;
    bool shoulddraw = false;
    bool speedinfluent = false;
    bool shouldclose = false;
signals:

public slots:
    void interf();
};

#endif // UXTUMBLER_H
