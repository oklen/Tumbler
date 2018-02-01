#include "uxp.h"
#include "cmath"

UXP::UXP(QWidget *parent) : QWidget(parent)
{

    resize(500,500);
}

void UXP::mousePressEvent(QMouseEvent *event)
{
    initpoint = event->pos();
    curpoint = event->pos();
    shoulddraw = true;
    update();
}

void UXP::mouseMoveEvent(QMouseEvent *event)
{
    curpoint = event->pos();
    update();
}

void UXP::mouseReleaseEvent(QMouseEvent *event)
{
    shoulddraw = false;
    update();
}

void UXP::paintEvent(QPaintEvent *event)
{
    if(shoulddraw){
        QPainter *mypainter = new QPainter;
        QLinearGradient *gr = new QLinearGradient(0,0,500,500);
        gr->setColorAt(0.0,Qt::red);
        gr->setColorAt(0.5,Qt::yellow);
        gr->setColorAt(1.0,Qt::black);
        QPen mpen;
        mpen.setWidth(1);

        mpen.setColor(Qt::red);
        mpen.setBrush(QBrush(*gr));
        QBrush mbrush(*gr);
        mypainter->begin(this);
        mypainter->setPen(mpen);
        mypainter->setBrush(mbrush);
        mypainter->setRenderHints(QPainter::Antialiasing);


        mypainter->drawEllipse(initpoint,15,15);

        mypainter->drawLine(initpoint,curpoint);
        if(curpoint!=initpoint){
            mypainter->drawLine(curpoint+QPoint(20,0),curpoint+QPoint(-20,0));
            mypainter->drawLine(curpoint-QPoint(0,20),curpoint+QPoint(0,20));
        }
//        if(!QPoint(curpoint-initpoint).isNull()){
//            float k = (curpoint - initpoint ).y()/(curpoint - initpoint).x();
//            mypainter->drawLine(QPoint(curpoint.x()+100/(std::sqrt(1+1/k*k)),curpoint.y()+100*k/std::sqrt(1+k*k)),
//                                QPoint(curpoint.x()-100*1/(std::sqrt(1+k*k)),curpoint.y()-100*k/std::sqrt(1+k*k)));
//        }
        mypainter->end();
    }
}
