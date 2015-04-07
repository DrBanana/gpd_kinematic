///////////////////////////////////////////////////////////
//  QtGRenderWidget.h
//  Виджет для отображения геометрии
//  Created on:      27-авг-2013 15:09:41
//  Original author: Anton
///////////////////////////////////////////////////////////

#include "QtGRenderWidget.h"
#include <QDebug>

using namespace Gepard::Visualization;

//------------------------------------------------------------------------
QtGRenderWidget::QtGRenderWidget(bool deleteOnClose /*= true*/, QWidget *parent/* = NULL*/)
    : QGLWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose, deleteOnClose); //при закрытии, виджет будет удален
    setWindowFlags(Qt::Dialog);
    setMouseTracking(true);    
    isCloseOnCloseCamera = true;
    isShowOnShowCamera = true;
}
//------------------------------------------------------------------------
QtGRenderWidget::~QtGRenderWidget()
{
    makeCurrent();
}
//------------------------------------------------------------------------
void QtGRenderWidget::paintGL()
{   
    makeCurrent();
    DrawGeometry(); 
    SetCameraInitFlag();//Камера инициализирована
}
//------------------------------------------------------------------------
void QtGRenderWidget::initializeGL()
{   
    makeCurrent();

    SetRenderSize( geometry().left(), geometry().top(),
                   geometry().width(), geometry().height());
    InitCamera();

    //ShowGCSAxes(true);
}
//------------------------------------------------------------------------
void QtGRenderWidget::resizeGL(int nWidth, int nHeight)
{
    ResizeCamera(nWidth, nHeight);
    emit SizeChanged(nWidth, nHeight);
}
//------------------------------------------------------------------------
void QtGRenderWidget::mousePressEvent(QMouseEvent *event)
{    
    GCAMERA_EVENT gc_event = GCE_NO_EVENT;

    if      ( event->button()==Qt::LeftButton )   gc_event = GCE_MOUSELBUTTONDOWN;
    else if ( event->button()==Qt::RightButton )  gc_event = GCE_MOUSERBUTTONDOWN;
    else if ( event->button()==Qt::MiddleButton ) gc_event = GCE_MOUSEMBUTTONDOWN;

    if (gc_event!=GCE_NO_EVENT) 
    {
        MouseEvent(gc_event, event->x(), event->y(),
                             event->modifiers() & Qt::ShiftModifier,
                             event->modifiers() & Qt::ControlModifier );
        repaint();
    }
}
//------------------------------------------------------------------------
void QtGRenderWidget::mouseReleaseEvent(QMouseEvent *event)
{    
    GCAMERA_EVENT gc_event = GCE_NO_EVENT;

    if      ( event->button()==Qt::LeftButton )   gc_event = GCE_MOUSELBUTTONUP;
    else if ( event->button()==Qt::RightButton )  gc_event = GCE_MOUSERBUTTONUP;
    else if ( event->button()==Qt::MiddleButton ) gc_event = GCE_MOUSEMBUTTONUP;

    if (gc_event!=GCE_NO_EVENT) 
    {
        MouseEvent(gc_event, event->x(), event->y(),
            event->modifiers() & Qt::ShiftModifier,
            event->modifiers() & Qt::ControlModifier );
        repaint();
    }
}
//------------------------------------------------------------------------
void QtGRenderWidget::mouseMoveEvent(QMouseEvent *event)
{    
    GCAMERA_EVENT gc_event = GCE_MOUSEMOVE;

    MouseEvent(gc_event, event->x(), event->y(),
                         event->modifiers() & Qt::ShiftModifier,
                         event->modifiers() & Qt::ControlModifier );
    repaint();
}
//------------------------------------------------------------------------
void QtGRenderWidget::wheelEvent(QWheelEvent *event)
{    
    GCAMERA_EVENT gc_event = GCE_NO_EVENT;

    //скроллим вниз
    if      ( event->delta()<0 ) gc_event = GCE_MOUSEWHEELDOWN;
    else if ( event->delta()>0 ) gc_event = GCE_MOUSEWHEELUP;

    if (gc_event!=GCE_NO_EVENT) 
    {
        MouseEvent(gc_event, event->x(), event->y(),
                             event->modifiers() & Qt::ShiftModifier,
                             event->modifiers() & Qt::ControlModifier );
        repaint();
    }
    
}
//------------------------------------------------------------------------
void QtGRenderWidget::keyPressEvent(QKeyEvent *event)
{
    GCAMERA_EVENT gc_event = GCE_NO_EVENT;

    switch (event->key())
    {
        case Qt::Key_Enter:  gc_event = GCE_KEY_ENTER;  break;
        case Qt::Key_Delete: gc_event = GCE_KEY_DELETE; break;
        default: break;
    }

    if (gc_event!=GCE_NO_EVENT)
    {
        KeyboardEvent(gc_event, event->modifiers() & Qt::ShiftModifier,
                                event->modifiers() & Qt::ControlModifier);
        repaint();
    }

}
//------------------------------------------------------------------------
/**
*  Виртуальная функция - закрыть камеру
*/
void QtGRenderWidget::CloseCamera()
{   
    makeCurrent();
    printf("QtGRenderWidget::CloseCamera()\n");
    if (isCloseOnCloseCamera) close();
    emit CloseCameraSignal();
}
//------------------------------------------------------------------------
/**
* Функция вызывается у дочернего окна(виджета) для перерисовки его контента
*/
void QtGRenderWidget::RepaintContent()
{
    makeCurrent();
    repaint();
}
//------------------------------------------------------------------------

/**
*  Событие, когда форма отображается
*/
void QtGRenderWidget::showEvent(QShowEvent *_event)
{
    emit VisibilityChanged(true);
}

/**
*  Событие, когда форма закрывается
*/
void QtGRenderWidget::hideEvent ( QHideEvent * event )
{
    makeCurrent();
    printf("QtGRenderWidget::hideEvent\n");
    emit VisibilityChanged(false);
}


/**
*  Функция "обратного вызова" от камеры
*/
void QtGRenderWidget::CallbackEvent(Gepard::Visualization::GCallbackMessage _message)
{
    emit CallbackSignal(_message);
}

/**
*  Виртуальная функция - Показать камеру
*/
void QtGRenderWidget::ShowCamera()
{
    makeCurrent();
    if (isShowOnShowCamera) show();
    emit ShowCameraSignal();
}

/**
*  Нужно ли закрывать виджет при поступлении сигнала о закрытии
*/
void QtGRenderWidget::SetCloseFlag(bool isClose)
{
    isCloseOnCloseCamera = isClose;
}

/**
*  Нужно ли показывать виджет при поступлении сигнала о показе
*/
void QtGRenderWidget::SetShowFlag(bool isShow)
{
    isShowOnShowCamera = isShow;
}

/**
*	 Сделать текущим контекст OpenGL для данной камеры
*/
void QtGRenderWidget::SetCurrentGLContext()
{
    makeCurrent();
}