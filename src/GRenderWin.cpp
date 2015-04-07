///////////////////////////////////////////////////////////
//  GRenderWin.cpp
//  Окно для отображения геометрии с тулбарами
//  Created on:      9-окт-2014 17:59
//  Original author: Anton
///////////////////////////////////////////////////////////

#include "GRenderWin.h"

#include <Gepard/Callbacks/CB_GeometryRender.h>
#include <Gepard/Visualization/GCamera.h>

using namespace Gepard::Visualization;
using namespace Gepard::Callbacks;

GRenderWin::GRenderWin(bool registerCamera /*= true*/, bool isWidget/* = true*/, QWidget *parent /*= 0*/)
    : QMainWindow(parent)
{
   Init(registerCamera,isWidget,parent);
}

//isWidget = false, registerCamera=true
GRenderWin::GRenderWin(QWidget *parent/* = 0*/)
    :QMainWindow(parent)
{
    Init(true,false,parent);
}

/**
*  Инициализация окна
*/
void GRenderWin::Init(bool registerCamera, bool isWidget, QWidget *parent)
{
    setAttribute(Qt::WA_DeleteOnClose,true);
    if (isWidget) setWindowFlags(Qt::Widget);

    _render = new QtGRenderWidget(false);
    _render->SetCloseFlag(false);
    _render->SetShowFlag(false);
    _render->RenderSetting.isShowAxes = true;


    if (registerCamera) {
        GeometryRenderManager::RegisterGCamera(dynamic_cast<GCamera*>(_render));
    }

    auto centerAct = new QAction(QIcon(":/Resources/Center.png"),"",this);
    auto dropTransReper = new QAction(QIcon(":/Resources/DropTransformReper.png"),"",this);

    QToolBar *bar = new QToolBar(this);
    addToolBar(bar);
    bar->setAllowedAreas(Qt::TopToolBarArea);
    bar->addAction(centerAct);
    bar->addAction(dropTransReper);
    
    setCentralWidget(_render);

    setMinimumWidth(200);
    setMinimumHeight(200);    

    connect(_render, SIGNAL(CallbackSignal(Gepard::Visualization::GCallbackMessage)), 
        this, SIGNAL(CallbackSignal(Gepard::Visualization::GCallbackMessage)));
    connect(_render, SIGNAL(SizeChanged(int, int)), this, SIGNAL(SizeChanged(int, int)));
    connect(_render, SIGNAL(CloseCameraSignal()), this, SLOT(close()));
    connect(_render, SIGNAL(ShowCameraSignal()),  this, SLOT(show()));

    connect(centerAct, SIGNAL(triggered()), this, SLOT(CenterCamShift()));
    connect(dropTransReper, SIGNAL(triggered()), this, SLOT(DropCamShift()));
    

    isCloseOnHide = true;
}

/**
*  Скрыть диалог
*/
void GRenderWin::hideEvent(QHideEvent *_event)
{
    emit VisibilityChanged(false);
    if (isCloseOnHide) close();
}

/**
*  Событие, когда форма отображается
*/
void GRenderWin::showEvent(QShowEvent *_event)
{
    emit VisibilityChanged(true);
}

/**
* Установить флаг "Закрыть окно, если оно прячется"
*/
void GRenderWin::SetCloseOnHide(bool flag)
{
    isCloseOnHide = flag;
}

/**
*  Центрирование сдвига камеры
*/
void GRenderWin::DropCamShift()
{
    if (!_render) return;
    _render->DropCenterCamShift();
}

/**
*  Центрирование камеры
*/
void GRenderWin::CenterCamShift()
{
    if (!_render) return;
    _render->SetCenterToCamShift();
}