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
#include <QGraphicsSceneMouseEvent>
#include <QToolButton>
#include <QToolBar>
#include <QGraphicsLineItem>
#include <QMessageBox>

#include"tRunPrmWin.h"
#include "tGraphicsRectItem.h"
#include"tDelWin.h"
#include <AddMovement/AddMovementDlg.h>
#include "tEditWin.h"
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
		: partMover(r.partMover),
		  rowGScene(r.rowGScene),
          rowGView(r.rowGView),
		  tmovments(r.tmovments)

	{

	};

	///////////////////////////////////////
	QGraphicsScene * rowGScene;
	QGraphicsView * rowGView;

	std::vector <tGraphicsRectItem *> tmovments;

	CMover partMover;
};


class TimeLine : public QWidget
{
	Q_OBJECT

public:
	TimeLine(int, Gepard::GeometryManager *, QWidget *parent = 0);
	~TimeLine();

public slots:

	//���������� ��������� �����
	void addTime();
	void delTime();
	void dropTime();

	//���������� �����, �� ������� ���������� CMover
	void addRow(CMover);
	void delRowDialog();
	void delRow(int);

	//�������������� ��������
	void resizeMarker();

	//���������� �������������� ����� �� ����� �����
	void addTimeMarks(QGraphicsScene *);

	//���������� ����������� ���������

	//void addGraphicMarks(vector<tGraphicsRectItem *>&,CMover&, QGraphicsScene &);
    void addGraphicMarks(_row &r);

	//������
	void actionRunWithPrms();
	void actionRun();

	//���� ���������� ��������
	void actionAdd();

	void mouseDoubleClickEvent(QMouseEvent * event) override;

	//�������� ���� ��������������
	void showEdit(CMovements *);

	//�������� �������������� �������
	void addSplitters();
	//������� �������
	void moveSplitterLeft();
	void moveSplitterRight();
	//����� ������� (���)
	void resetState();

	//��������� ��������
	CMovements splitMovementF(CMovements *, int, int);   //��������� �������� � ���������� ������ �����
	CMovements splitMovementB(CMovements *, int, int);   //��������� �������� � ���������� ��������� �����
	CMovements pullMovement(CMovements *, int, int);     //�������� ����� ��������

signals:




protected:


private:
	//Ui::TimeLineClass ui;

	QLabel * partName;
	
	Gepard::GeometryManager * TimeLine_g_manager;

	QGraphicsSceneMouseEvent * doubleclick_event;  //����� ���� � ������ �����

	QTableWidget * TableViewer;
	QGraphicsScene * graphS;
	QGraphicsView * graphicsWindow;

	tRunPrmWin * prmWin;
	tDelWin * delWin;
	tEditWin * editWin;
	AddMovementDlg * addMovementDialog;

	//����� ����
	QMenuBar * mainMenu;
	QMenu * mRun;             //���� �������
	QMenu * mAdd;             //���� ����������
	QAction * aRun;           //������
	QAction * aRunParams;     //������ � �����������
	QAction * aMover;         //�������� ��������� + ���������� �������� 
	QAction * aRemove;
	QAction * aReset;

	//������ � ������
	QToolBar * tBar;
	QAction * aRight;
	QAction * aLeft;

	//������������ ���������
	QGraphicsRectItem * splitFirst;
	QGraphicsRectItem * splitSecond;

	int segments;  //���������� ���������
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

	std::vector <Gepard::BasicMath::GPDReper> defaultRepers;

	tGraphicsRectItem * sednderRect;
	
	Gepard::GeometryManager g_manager;

	bool stateFlag;  //
};

#endif // TIMELINE_H
