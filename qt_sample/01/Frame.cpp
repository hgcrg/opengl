#include "Frame.h"
#include <QPainter>
Frame::Frame(QWidget *parent)
{

}

Frame::~Frame()
{

}

QColor Frame::getColor()
{
    return m_color;
}

void Frame::setColor(QColor &color)
{
    m_color = color;
}


void Frame::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QBrush(m_color));
    painter.drawRect(0, 0, 100, 100);
}
