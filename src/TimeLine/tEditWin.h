#ifndef TEDITWIN_H
#define TEDITWIN_H

#include "..\includes\gepard.h"
#include <Gepard/Callbacks/CB_GeometryRender.h>
#include <Gepard/Topology_Geometry/GPDSolid.h>
#include <Gepard/Visualization/SpecialObjects/GAxis.h>
#include <Gepard/Visualization/GColor.h>

#include<QWidget>

#include<Qlabel>
#include<QLineEdit>
#include<QPushButton>
#include<QGridLayout>
#include <QPalette>
#include <QShowEvent>


#include <CMovements/Mover.h>

using namespace Gepard::Visualization;

class tEditWin : public QWidget, Gepard::Callbacks::GeometryRenderCallback

{
	Q_OBJECT

public:

	tEditWin(CMovements *, QWidget *parent = 0);
	~tEditWin();

	public slots:

	void setLinear();
	void setCircular();

	void showEvent(QShowEvent *) override;  //

	void closeEvent(QCloseEvent *) override;

public slots:

	void sendMovement();

	//Виртуальная функция обратного вызова - реакции на действия пользователя
	void renderCallbackEvent(Gepard::Visualization::GCallbackMessage _message) override;

	QString GetFaceName(Gepard::Topology_Geometry::GPDFace *);

	void showAxis();
	void showAxis(int, int, int, int, int, int);
	void deleteAxis(GAxis *);

signals:

	void movementEdited();

private:

	QPalette * redPalette;
	QPalette * greenPalette;

	CMovements * movement;

	QGridLayout * mainLay;

	QLabel * mainLabel;
	QLabel * nameLabel;
	QLabel * shiftLabel;
	QLabel * axisLabel;
	QLabel * startLabel;
	QLabel * endLabel;

	QLineEdit * nameEdit;
	QLineEdit * shiftEdit;
	QLineEdit * axisEdit;
	QLineEdit * startEdit;
	QLineEdit * endEdit;

	QPushButton * okButton;
	QPushButton * cancelButton;

	bool typeFlag;

	int shift;

	Gepard::BasicMath::GPDReper fReper;
	GAxis * newAxis;                                //ось

	Gepard::BasicMath::GPDVector shiftEnd;
	Gepard::BasicMath::GPDVector shiftStart;

	Gepard::BasicMath::GPDPoint prtPoint;
};

#endif //TEDITWIN_H