#include "uxtumbler.h"
#include <QDebug>

UXTUMBLER::UXTUMBLER(QWidget *parent) : QWidget(parent)
{

    mtime.start();
    lasttime = mtime.msec();
    connect(timer,SIGNAL(timeout()),this,SLOT(interf()));
    timer->start(10);
}

void UXTUMBLER::mousePressEvent(QMouseEvent *event)
{    timer->stop();

    speedinfluent = false;
    initpoint = event->pos();
    curpoint = event->pos();
    lastpos = event->pos();
     stayval = curval;
      mspeed = 0;

}

void UXTUMBLER::mouseMoveEvent(QMouseEvent *event)
{
    if(curval != (stayval -  0.02*(event->pos() - initpoint).x()))
    {
        curval = stayval -  0.02*(event->pos() - initpoint).x();
        update();
    }
    if(curval>=maxbound)
    {
        curval=maxbound;
        update();
        return;
    }
    if(curval<=minbound)
    { curval = minbound;update();return;}
//    if((mtime.msec() - lasttime)>1)
    qDebug() << qreal((event->pos()-lastpos).x())/(lasttime);
    mspeed  = qreal((event->pos()-lastpos).x())/(lasttime);
    lasttime = mtime.msec();
    mtime.restart();
    lastpos = event->pos();

}

void UXTUMBLER::mouseReleaseEvent(QMouseEvent *event)
{

        speedinfluent = true;
        stayval -= 0.02*(event->pos() - initpoint).x();
        curval = stayval;
        if(curval>=maxbound)
        {
            curval=maxbound;
            update();
            return;
        }
        if(curval<=minbound)
        { curval = minbound;update();return;}
    update();

    timer->start();

}

void UXTUMBLER::paintEvent(QPaintEvent *event)
{

    QPainter *mpainter = new QPainter;
    mpainter->begin(this);
    mpainter->setRenderHint(QPainter::Antialiasing);
    mpainter->setBrush(QBrush(QColor(74,74,74)));
    mpainter->drawRect(0,0,500,500);
    QLinearGradient *gr = new QLinearGradient(0,0,300,0.1);
    gr->setColorAt(0,QColor(74,74,74,0.5));
    gr->setColorAt(0.5,QColor(255,255,255));
    gr->setColorAt(1.0,QColor(74,74,74,0.5));
    QPen mpen;
    mpen.setBrush(QBrush(*gr));
    mpen.setWidth(10);
    mpainter->setPen(mpen);
    mpainter->drawLine(40,90,350,90);
    mpainter->drawLine(40,128,350,128);
    qreal leftv = curval -3;
    qreal repair = leftv-int(leftv);
//    for(int i = 0;i<(300);i++)
//    {
//        qreal cacher = leftv+i*0.02;
//        if(int(cacher) == (cacher))
//            mpainter->drawText(QRect(i,0,20,20),QString::number(cacher));
//    }
    for(int i=0;i<6;i++)
    {
        mpainter->drawText(QRect(int((i-repair)*50)+50,100,30,30),QString::number(int(leftv)+i));
    }
    mpen.setWidth(3);
    mpainter->setPen(mpen);
    mpainter->drawLine(157,130,157,120);
    mpainter->end();
}

void UXTUMBLER::interf()
{
    if(speedinfluent)
    {
//        qDebug() << "Doing" << mspeed << " "
//                 << (mspeed >0.00001 || mspeed<-0.00001);
        if(mspeed >=0.01 || mspeed<= -0.01)
        {    qDebug() << "checking!";

            curval -=(10*mspeed*0.2 /*-50*0.001*/);
            if(int(curval)>maxbound)
            {  curval = maxbound;
            mspeed = 0;}
            if(int(curval)<minbound)
            {  curval = minbound;
            mspeed = 0;}
            qDebug() << curval;
            repaint();
            if(mspeed>0.2)
                mspeed = 0.2;
                        if(mspeed < -0.2)
                        mspeed = -0.2;
            if(mspeed>0)
                mspeed -=0.001;
            else
                mspeed += 0.001;
        }
        else
        {
            if(int(curval) != curval)
            {
                qDebug() << "checking!2 " << curval << "  " + QString::number(int(curval) - curval);
                if(int(curval)>maxbound)
                {      curval = maxbound;
                return;}
                if(int(curval)<minbound)
                {            curval = minbound;
                return;}
                if( (int(curval) - curval) <-0.005)
                    curval+=0.004;
                 else if((int(curval) - curval)<0) curval = int(curval);
                if(((int(curval) - curval)>0.005))
                    curval -= 0.004;
                else if(((int(curval) - curval)>0))
                    curval = int(curval);
                update();
            }
        }

    }

}

qreal UXTUMBLER::getcurval()
{
    return curval;
}
