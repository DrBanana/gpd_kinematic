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
#include <AddMovement/AddMovementDlg.h>
//#include"CMovements/CMovements.h"
//#include"CMovements/Mover.h"

struct _row
{ 
	_row(CMover &_mover, int w, int rowHeight) 
	: partMover(_mover)
	//, rowGScene(0, 0, w, rowHeight)
	{			

	};

	_row(const _row &r)
		: partMover(r.partMover)
		//, rowGScene(r.rowGScene.sceneRect())
	{

	};

	///////////////////////////////////////
	QGraphicsScene * rowGScene;
	QGraphicsView * rowGView;

	std::vector <QGraphicsRectItem *> tmovments;
	std::vector <QGraphicsTextItem *> tnames;

	CMover partMover;
};


class TimeLine : public QWidget
{
	Q_OBJECT

public:
	TimeLine(int, Gepard::GeometryManager, QWidget *parent = 0);
	~TimeLine();

public slots:

	//���������� ��������� �����
	void addTime();
	void delTime();
	void dropTime();

	//���������� �����, �� ������� ���������� CMover
	void addRow(CMover);
	void delRow();

	//���������� �������������� ����� �� ����� �����
	void addTimeMarks(QGraphicsScene &);

	//���������� ����������� ���������

	void addGraphicMarks(vector<QGraphicsRectItem *>, vector<QGraphicsTextItem *>,CMover, QGraphicsScene &);

	//������
	void actionRunWithPrms();
	void actionRun();

	//���� ���������� ��������
	void actionAdd();


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
	QMenu * mAdd;             //���� ����������
	QAction * aRun;           //������
	QAction * aRunParams;     //������ � �����������
	QAction * aMover;         //�������� ��������� + ���������� �������� 

	AddMovementDlg * addMovementDialog;

	int segmentSize; //������ �������� �� �������, � ��������
	int segmentsAmount; //������� ���������� ��������� (����� ������� ����� ������ ����� ���������)

	int fRowHeight; //������ ������� ������ �� ������
	int tlRowHeight; //������ ������

	qreal timeStep; //���

	int tlRowCount; //����� ����� �� ������ �������
	int tlRectSize; //������ �������������� ��������

	int w; //������ ����� �� �������
	int h; //������ �����

	std::vector <_row> rowVect;  //������ �����
	
};

#endif // TIMELINE_H
