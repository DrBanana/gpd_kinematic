 #include"tDelWin.h"

tDelWin::tDelWin(int newRowCount, QWidget *parent /*= 0*/)
{
	rowCount = newRowCount;

	mainLabel = new QLabel(tr("Insert string number from 1 to ")+QString::number(rowCount));
	okButton = new QPushButton(tr("OK"));
	cancelButton = new QPushButton(tr("Cancel"));
	numLine = new QLineEdit();

	mainLay = new QGridLayout();

	mainLay->addWidget(mainLabel, 0, 0,1,2);
	mainLay->addWidget(numLine, 1, 0);
	mainLay->addWidget(okButton, 2, 0);
	mainLay->addWidget(cancelButton, 2, 1);

	this->setLayout(mainLay);

	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));

}

tDelWin::~tDelWin()
{

}

void tDelWin::showEvent(QShowEvent * event)
{
	mainLabel->setText(tr("Insert string number from 1 to ") + QString::number(rowCount));
}

