#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Gepard/Callbacks/CB_GeometryRender.h>
#include <Gepard/MathModel.h>
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

    connect(ui->actionOpen_project, SIGNAL(triggered()), SLOT(on_actionOpenProject_triggered()));
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

    CMover m (mathModel->Solids[0]);
    GPDVector vect;
    vect.x =0;
    vect.y =0;
    vect.z =-1;
    GPDPoint point(0,0,0);
    //CMovements mc = CMovements(EMovementTypes::CIRCULAR,point,"",vect,1.0,0,1);
	CMovements ml(EMovementTypes::LINEAR, "", 20.0, point, vect, 0, 5, "");
//     CMovements mr = CMovements();
//     mr.SetAxis(GPDVector(0,-1,0));
//     mr.SetMovementType(CIRCULAR);
//     mr.SetPoint(point);
//     mr.SetShift(2.0);
//     mr.SetStart(0);
//     mr.SetEnd(0);
       m.AddMovement(ml);
     //m.AddMovement(mr);
     //m.AddMovement(mc);
       int cnt = m.GetSizeOfmovementsVector();
       
       Gepard::GPDSolid *solidPtr = mathModel->Solids[0];

       auto cam0 = GeometryRenderManager::GetCamera(0);
       auto cam0Render = dynamic_cast<GPDGeometryRender*>(cam0);

        for (int i =0;i<cnt;i++)
        {
            int _cnt = m.GetStepsCntForMovement(i);
            for (int j=0;j<_cnt;j++)
            {
                m.OneStepMove(i,j);
                auto f = m.getModFunc(i, j);

                if (cam0Render->isSolidExist(solidPtr))
                {
                    for (auto fItr  = solidPtr->Faces.std_begin();
                              fItr != solidPtr->Faces.std_end(); fItr++)
                    {
                        cam0Render->ModifyObject((void*)&(*fItr), f);
                    }//for
                    cam0Render->RepaintContent();
                }//if

                //g_manager.HideSolid(mathModel->Solids[0]);
                //mathModel->PrepareGeometry();
                //g_manager.ShowSolidInRender(mathModel->Solids[0],GeometryRenderManager::GetCamera(0));
                //break;
                //Sleep(1000);
            }
        }
//    m.MoveIt(0);
//         g_manager.HideSolid(mathModel->Solids[0]);
//         g_manager.ShowSolidInRender(mathModel->Solids[0],GeometryRenderManager::GetCamera(0));
//     Gepard::Analysis::KeyCharacteristicsPtrArray* kca = mathModel->GetKCArrayPtr();
//     
//     kca->set_start();
//     while (auto curKC = kca->get_next())
//     {
//         (*curKC)->Analize();
//     }
}

void MainWindow::on_actionOpenTimeLine_triggered()
{
    //Таймлайн
    timeLineWidget = new TimeLine(20, &g_manager);
    timeLineWidget->show();

    //Доквиджет для таймлайна
    tLineWidget = new QDockWidget(this);
    this->addDockWidget(Qt::BottomDockWidgetArea, tLineWidget);
    tLineWidget->setAllowedAreas(Qt::BottomDockWidgetArea);
    tLineWidget->setWidget(timeLineWidget);
    tLineWidget->show();
}

void MainWindow::on_actionOpenProject_triggered()
{
    QString filename = QFileDialog::getOpenFileName( this, tr("Open file"), QDir::currentPath(),tr("GePARD project file")+" (*.gpd);;");
    if( filename.isNull() ) return;

    auto cam0 = GeometryRenderManager::GetCamera(0);
    auto cam0Render = dynamic_cast<GPDGeometryRender*>(cam0);

    
    int import_ret = g_manager.importGPD(filename.toStdString(), cam0Render);

    if (import_ret!=0)
    {
        qDebug()<<"Файл не был загружен!";
        g_manager.GetMathModelPtr()->CloseModel();
    }
}