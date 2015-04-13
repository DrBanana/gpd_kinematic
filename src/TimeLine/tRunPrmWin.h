#ifndef TRUNPRMWIN_H
#define TRUNPRMWIN_H

#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>
#include <QString>

class tRunPrmWin : public QWidget
{
	Q_OBJECT

public:

	tRunPrmWin(int, QWidget *parent = 0);
	~tRunPrmWin();

protected slots:

	void Run();

private:
	
	QLabel * mainLabel;
	QLabel * startLabel;
	QLabel * endLabel;

	QPushButton * okButton;
	QPushButton * cancelButton;

	QLineEdit * startLine;
	QLineEdit * endLine;

	QGridLayout * mainLay;

	QMessageBox * msgBox;

	int stepCount;

	int startStep;
	int endStep;
};


#endif // TRUNPRMWIN_H
