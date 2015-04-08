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


struct _row
{ 
	QGraphicsScene *rowGScene;/* = new QGraphicsScene();*/
	QGraphicsView *rowGView; /*= new QGraphicsView();*/
	std::vector <QGraphicsRectItem *> tmovments;
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

	//���������� �����
	void addRow();
	void delRow();

	//���������� �������������� ����� �� ����� �����
	void addTimeMarks(QGraphicsScene *);

	//���������� ��������
	void addMovment();

signals:

	bool addClick();
	bool delClick();
	bool dropClick();

protected:


private:
	//Ui::TimeLineClass ui;
	
	QTableWidget * TableViewer;
	QGraphicsScene * graphS;
	QGraphicsView * graphicsWindow;
	QMenuBar * mainMenu;

	//����� ����
	QMenu * mRun;             //���� �������
	QAction * aRun;           //������
	QAction * aRunParams;     //������ � �����������

	int segmentSize; //������ �������� �� �������, � ��������
	int segmentsAmount; //������� ���������� ���������

	int fRowHeight; //������ ������� ������ �� ������

	qreal timeStep; //���

	int rowCount; //����� ����� �� ������ �������

	int w; //������ ����� �� �������
	int h; //������ �����

	std::vector <_row> rowVect;  //������ �����

	
};

#endif // TIMELINE_H
