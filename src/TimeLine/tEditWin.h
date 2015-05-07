#ifndef TEDITWIN_H
#define TEDITWIN_H

#include<QWidget>

#include<Qlabel>
#include<QLineEdit>
#include<QPushButton>
#include<QGridLayout>

#include <CMovements/Mover.h>

class tEditWin : public QWidget

{
	Q_OBJECT

public:

	tEditWin(CMovements *, QWidget *parent = 0);
	~tEditWin();

	public slots:

	void setLinear();
	void setCircular();

private:

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

};

#endif //TEDITWIN_H