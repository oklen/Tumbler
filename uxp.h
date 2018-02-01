#ifndef UXP_H
#define UXP_H

#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>

class UXP : public QWidget
{
    Q_OBJECT
public:
    explicit UXP(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QPoint initpoint = QPoint(0,0);
    QPoint curpoint = QPoint(0,0);
    bool shoulddraw = false;
signals:

public slots:
};

#endif // UXP_H
