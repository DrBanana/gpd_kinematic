#include "tEditWin.h"

#include <Gepard/Visualization/GCamera.h>
#include <Gepard/Visualization/GPDGeometryRender.h>

using namespace Gepard::Visualization;
using namespace Gepard::Callbacks;
using namespace Gepard::Topology_Geometry;
using namespace Gepard::BasicMath;

tEditWin::tEditWin(CMovements* thisMovement, QWidget *parent /*= 0*/)
	: QWidget(parent)
{
	movement = thisMovement;

	if (thisMovement->GetMovementType() == LINEAR) { typeFlag = true; }
	else if (thisMovement->GetMovementType() == CIRCULAR) { typeFlag = false; }

	this->setWindowFlags(Qt::WindowStaysOnTopHint);

	//Палитра
	greenPalette = new QPalette();
	greenPalette->setColor(QPalette::Base, QColor(0, 255, 0, 120));

	//Определяем виджеты

	mainLay = new QGridLayout();

	mainLabel = new QLabel(tr("Movement edit "));
	nameLabel = new QLabel(tr("Name: "));
	shiftLabel = new QLabel(tr("Shift: "));
	axisLabel = new QLabel(tr("Axis: "));
	startLabel = new QLabel(tr("Start: "));
	endLabel = new QLabel(tr("End: "));

	nameEdit = new QLineEdit();
	shiftEdit = new QLineEdit();
	axisEdit = new QLineEdit();
	startEdit = new QLineEdit();
	endEdit = new QLineEdit();

	okButton = new QPushButton(tr("Ok"));
	cancelButton = new QPushButton(tr("Cancel"));

	//Вешаем их на лэйаут
	//0
	mainLay->addWidget(mainLabel,0,0,1,2);
	//1
	mainLay->addWidget(nameLabel,1,0);
	mainLay->addWidget(nameEdit, 1, 1);
	//2
	mainLay->addWidget(shiftLabel,2,0);
	mainLay->addWidget(shiftEdit,2,1);
	//3
	mainLay->addWidget(axisLabel,3,0);
	mainLay->addWidget(axisEdit,3,1);
	//4
	mainLay->addWidget(startLabel,4,0);
	mainLay->addWidget(startEdit,4,1);
	//5
	mainLay->addWidget(endLabel,5,0);
	mainLay->addWidget(endEdit,5,1);
	//6
	mainLay->addWidget(okButton,6,0);
	mainLay->addWidget(cancelButton,6,1);

	this->setLayout(mainLay);

	//Заполняем поля

	nameEdit->setText(QString::fromStdString(thisMovement->GetMoveName()));
	shiftEdit->setText(QString::number(thisMovement->GetDegrees()));               
	axisEdit->setPalette(*greenPalette);
	axisEdit->setReadOnly(true);
	axisEdit->setText(QString::fromStdString(thisMovement->getAxisName()));
	startEdit->setText(QString::number(thisMovement->GetStart()));
	endEdit->setText(QString::number(thisMovement->GetEnd()));

	//На случай если пользователь не будет менять ось
	shiftEnd = movement->GetAxis();
	shiftStart.setNull();


	prtPoint = movement->GetPoint();

	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(okButton, SIGNAL(clicked()), this, SLOT(sendMovement()));

}

tEditWin::~tEditWin()
{

}

void tEditWin::renderCallbackEvent(Gepard::Visualization::GCallbackMessage _message)
{
	if (!isVisible()) return;
	if (!_message._Object) return;
	//if (shiftEdit->hasSelectedText == false) return;

	if (_message._Object->_type == GODT_FACE)
	{
		GPDFace* _facePtr = (GPDFace*)_message._Object->ObjectData;
		if (!_facePtr) return;

		axisEdit->setText(GetFaceName(_facePtr));


		fReper = _facePtr->GetFaceReper();

		shift = shiftEdit->text().toInt();

		shiftStart = fReper.R;
		shiftEnd = fReper.R + fReper.E2*shift;

		showAxis();
	}
}

void tEditWin::setLinear()
{
	mainLabel->setText("Movement edit (Linear)");
	shiftLabel->setText("Shift: ");
}

void tEditWin::setCircular()
{
	mainLabel->setText("Movement edit (Circular)");
	shiftLabel->setText("Angle: ");
}

void tEditWin::showEvent(QShowEvent * event)
{

	//Определяем тип движения
	if (typeFlag==true)
	{
		setLinear();
	}
	else if (typeFlag==false)
	{
		setCircular();
	}

	//Рисуем ось
	GPDPoint startPoint = movement->GetPoint();
	GPDVector endPoint = movement->GetAxis();

	showAxis(startPoint.x, startPoint.y, startPoint.z, endPoint.x*movement->GetShift(), endPoint.y*movement->GetShift(), endPoint.z*movement->GetShift());

	event->accept();

}

void tEditWin::closeEvent(QCloseEvent * event)
{
	if (newAxis != nullptr)
	{
		GCamera * cam0 = GeometryRenderManager::GetCamera(0);
		GPDGeometryRender * cam0Render = dynamic_cast<GPDGeometryRender*>(cam0);

		cam0Render->DeleteSpecialGObject((SpecialGObject*)newAxis);
	}


	event->accept();
}

QString tEditWin::GetFaceName(Gepard::Topology_Geometry::GPDFace * _facePrt)
{
	QString faceName = QString::fromStdString(_facePrt->GetFaceTypeStr());
	faceName.append(tr(" "));
	faceName.append(QString::number(_facePrt->GetUIN()));

	return faceName;
}

void tEditWin::showAxis()
{
	GCamera * cam0 = GeometryRenderManager::GetCamera(0);
	GPDGeometryRender * cam0Render = dynamic_cast<GPDGeometryRender*>(cam0);

	cam0Render->DeleteSpecialGObject((SpecialGObject*)newAxis);

	newAxis = cam0Render->DrawAxis(shiftStart.x, shiftStart.y, shiftStart.z, shiftEnd.x, shiftEnd.y, shiftEnd.z, GColor(0, 0, 0), "Axis");
}

void tEditWin::showAxis(int x0, int y0, int z0, int x1, int y1, int z1)
{
	GCamera * cam0 = GeometryRenderManager::GetCamera(0);
	GPDGeometryRender * cam0Render = dynamic_cast<GPDGeometryRender*>(cam0);

	cam0Render->DeleteSpecialGObject((SpecialGObject*)newAxis);

	newAxis = cam0Render->DrawAxis(x0, y0, z0, x1, y1, z1, GColor(0, 0, 0), "Axis");
}



void tEditWin::deleteAxis(GAxis * Axis)
{
	GCamera * cam0 = GeometryRenderManager::GetCamera(0);
	GPDGeometryRender * cam0Render = dynamic_cast<GPDGeometryRender*>(cam0);

	cam0Render->DeleteSpecialGObject((SpecialGObject*)Axis);
}

void tEditWin::sendMovement()
{

	//Пишем в него данные
	movement->SetMoveName(nameEdit->text().toStdString());
	movement->SetShift(shiftEdit->text().toDouble());
	movement->SetAxis((shiftEnd - shiftStart).getNormalized());  //Тут - то все и портится...
	movement->SetPoint(prtPoint);
	movement->SetStart(startEdit->text().toInt());
	movement->SetEnd(endEdit->text().toInt());
	movement->setAxisName(axisEdit->text().toStdString());

	emit movementEdited();

	this->close();
}