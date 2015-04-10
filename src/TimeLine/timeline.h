#ifndef TIMELINE_H
#define TIMELINE_H

#include <QtWidgets/QWidget>
//#include "ui_timeline.h"



#include<Qlabel>
#include<qgraphicsview>
#include<qgraphicsitem.h>
#include<qboxlayout>
#include<qgridlayout>
#include<qtableview.h>
#include<qtablewidget.h>
#include<qsplitter>
#include <qpushbutton>
#include <QAbstractItemModel>
#include<qpainter>
#include<qpixmap>
#include<qstandarditemmodel.h>
#include<vector>
#include <qlineedit.h>
#include<qheaderview.h>
#include <QMenuBar>

#include"tRunPrmWin.h"
#include"CMovements/CMovements.h"
#include"CMovements/Mover.h"

struct _row
{ 
	QGraphicsScene *rowGScene;
	QGraphicsView *rowGView;

	std::vector <QGraphicsRectItem *> tmovments;

	CMover * partMover;
};


class TimeLine : public QWidget
{
	Q_OBJECT

public:
	TimeLine(int,QWidget *parent = 0);
	~TimeLine();

public slots:

	//���������� ��������� �����
	void addTime();
	void delTime();
	void dropTime();

	//���������� �����, �� ������� ���������� CMover
	void addRow();
	void delRow();

	//���������� �������������� ����� �� ����� �����
	void addTimeMarks(QGraphicsScene *);

	//������
	void actionRunWithPrms();

signals:




protected:


private:
	//Ui::TimeLineClass ui;
	
	QTableWidget * TableViewer;
	QGraphicsScene * graphS;
	QGraphicsView * graphicsWindow;
	QMenuBar * mainMenu;
	tRunPrmWin * prmWin;

	QWidget *win;
	//����� ����
	QMenu * mRun;             //���� �������
	QAction * aRun;           //������
	QAction * aRunParams;     //������ � �����������

	int segmentSize; //������ �������� �� �������, � ��������
	int segmentsAmount; //������� ���������� ��������� (����� ������� ����� ������ ����� ���������)

	int fRowHeight; //������ ������� ������ �� ������

	qreal timeStep; //���

	int rowCount; //����� ����� �� ������ �������

	int w; //������ ����� �� �������
	int h; //������ �����

	std::vector <_row> rowVect;  //������ �����
	
};

#endif // TIMELINE_H
