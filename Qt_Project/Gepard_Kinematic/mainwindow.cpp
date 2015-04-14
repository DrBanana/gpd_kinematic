#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Gepard/Callbacks/CB_GeometryRender.h>
#include <GRenderWin.h>
#include "CMovements/Mover.h"

using namespace Gepard::Callbacks;
using namespace Gepard::BasicMath;
using namespace Gepard::Topology_Geometry;
using namespace Gepard::Visualization;
using namespace Gepard::Surfaces;
using namespace Gepard::Assembly;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    progressDlg(parent),
 
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GRenderWin *gRender = new GRenderWin(true, true, this);
    setCentralWidget(gRender);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpenStep_triggered()
{
    QString filename = QFileDialog::getOpenFileName( this, tr("Open file"), QDir::currentPath(),tr("STEP file formats")+" (*.stp);;");
    if( filename.isNull() ) return;

     auto cam0 = GeometryRenderManager::GetCamera(0);
     auto cam0Render = dynamic_cast<GPDGeometryRender*>(cam0);

     int import_ret = g_manager.importSTEP(filename.toStdString(), cam0Render);
     
     if (import_ret!=0)
     {
         qDebug()<<"Файл не был загружен!";
         g_manager.GetMathModelPtr()->CloseModel();
     }
     //Gepard::MathModel *mathModel = g_manager.GetMathModelPtr();
}

void MainWindow::on_actionMoveIt_triggered()
{
    Gepard::MathModel *mathModel = g_manager.GetMathModelPtr();

    CMover m = CMover(mathModel->Solids[0]);
    GPDVector vect;
    vect.x =1;
    vect.y =0;
    vect.z =0;
    GPDPoint point = GPDPoint(0,0,0);
    CMovements mc = CMovements(EMovementTypes::CIRCULAR,point,"",vect,1.0,0,1);
    CMovements ml = CMovements(EMovementTypes::LINEAR,point,"",vect,20.0,0,1);
    CMovements mr = CMovements();
    mr.SetAxis(GPDVector(0,-1,0));
    mr.SetMovementType(CIRCULAR);
    mr.SetPoint(point);
    mr.SetShift(2.0);
    mr.SetStart(0);
    mr.SetEnd(0);

    m.AddMovement(ml);
    m.AddMovement(mr);
    int cnt = m.AddMovement(mc);
        for (int i =0;i<cnt;i++)
        {
            m.MoveIt(i);
        }
//    m.MoveIt(0);
    g_manager.HideSolid(mathModel->Solids[0]);
    g_manager.ShowSolidInRender(mathModel->Solids[0],GeometryRenderManager::GetCamera(0));
}