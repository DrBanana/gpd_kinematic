#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <Gepard/Callbacks/CB_GeometryRender.h>
#include <GRenderWin.h>

using namespace Gepard::Callbacks;
using namespace Gepard::BasicMath;
using namespace Gepard::Topology_Geometry;
using namespace Gepard::Visualization;
using namespace Gepard::Surfaces;
using namespace Gepard::Assembly;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
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
