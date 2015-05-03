#ifndef TDELWIN_H
#define TDELWIN_H

#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>

class tDelWin : public QWidget
{
	Q_OBJECT

public:

	tDelWin(int, QWidget *parent = 0);
	~tDelWin();

	void showEvent(QShowEvent *) override;
	void closeEvent(QCloseEvent *) override;

public slots:

	void sendNum();

signals :

	void accept(int);

private:

	QLabel * mainLabel;

	QPushButton * okButton;
	QPushButton * cancelButton;

	QLineEdit * numLine;


	QGridLayout * mainLay;

	QMessageBox * msgBox;

	int rowCount;

};



#endif //TDELWIN_H