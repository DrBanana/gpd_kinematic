#include "tEditWin.h"

tEditWin::tEditWin(CMovements* thisMovement, QWidget *parent /*= 0*/)
	: QWidget(parent)
{

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

	//Определяем тип движения
	if (thisMovement->GetMovementType() == LINEAR)
	{
		setLinear();
	}
	else if (thisMovement->GetMovementType() == CIRCULAR)
	{
		setCircular();
	}

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


}

tEditWin::~tEditWin()
{

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
