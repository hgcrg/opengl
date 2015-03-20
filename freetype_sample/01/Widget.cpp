#include "Widget.h"
#include "Stage.h"
Widget::Widget(QWidget *parent)
    :QGLWidget(parent)
    ,m_pStage(new Stage())
{
}


Widget::~Widget()
{

}


void Widget::initializeGL()
{
    if (m_pStage)
    {
        m_pStage->Init();
    }
}


void Widget::resizeGL(int w, int h)
{
    if (m_pStage)
    {
        m_pStage->Reshape(w, h);
    }
}


void Widget::paintGL()
{
    if (m_pStage)
    {
        m_pStage->Display();
    }
    update();
}
