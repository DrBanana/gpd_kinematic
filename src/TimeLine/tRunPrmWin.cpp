#include "tRunPrmWin.h"

tRunPrmWin::tRunPrmWin(int stepsOnTL, QWidget *parent) 
	: QWidget (parent)
{
	stepCount = stepsOnTL;

	QString * mLabel = new QString(tr("Choise steps: 0 - "));
	mLabel->append(QString::number(stepsOnTL));

	mainLabel = new QLabel();
	mainLabel->setText(*mLabel);

	startLabel = new QLabel(tr("start from:"));
	endLabel = new QLabel(tr("end on:"));

	okButton = new QPushButton(tr("OK"));
	cancelButton = new QPushButton(tr("Cancel"));

	startLine = new QLineEdit();
	endLine = new QLineEdit();

	mainLay = new QGridLayout();

	mainLay->addWidget(mainLabel, 0, 0, 1 ,2);
	mainLay->addWidget(startLabel, 1, 0);
	mainLay->addWidget(startLine, 1, 1 );
	mainLay->addWidget(endLabel, 2, 0);
	mainLay->addWidget(endLine, 2, 1);
	mainLay->addWidget(okButton, 3, 0);
	mainLay->addWidget(cancelButton, 3, 1);

	this->setLayout(mainLay);

	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(okButton, SIGNAL(clicked()), this, SLOT(Run()));

}

tRunPrmWin::~tRunPrmWin()
{

}


void tRunPrmWin::Run()
{
	startStep = startLine->text().toInt();
	endStep = endLine->text().toInt();

	msgBox = new QMessageBox(QMessageBox::Warning, tr("Error"), tr("EndStep is greater than StepCount"), QMessageBox::Ok);

	if (endStep > stepCount) 
	{
		msgBox = new QMessageBox(QMessageBox::Warning, tr("Error"), tr("EndStep is greater than StepCount"), QMessageBox::Ok);
		msgBox->exec();
		return;
	}
	if (startStep>=endStep)
	{
		msgBox = new QMessageBox(QMessageBox::Warning, tr("Error"), tr("StartStep is greater or equal to EndStep"), QMessageBox::Ok);
		msgBox->exec();
		return;
	}

	
	close();
}
