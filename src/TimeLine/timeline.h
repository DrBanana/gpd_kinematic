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

	//Добавление сегментов шкалы
	void addTime();
	void delTime();
	void dropTime();

	//Добавление строк, со строкой добвляется CMover
	void addRow(CMover);
	void delRow();

	//Добавление разделительных меток на новую сцену
	void addTimeMarks(QGraphicsScene &);

	//Добавление гравических элементов

	void addGraphicMarks(vector<QGraphicsRectItem *>, vector<QGraphicsTextItem *>,CMover, QGraphicsScene &);

	//Запуск
	void actionRunWithPrms();
	void actionRun();

	//окно добавления движения
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
	//Экшны меню
	QMenu * mRun;             //Меню запуска
	QMenu * mAdd;             //Меню добавления
	QAction * aRun;           //Запуск
	QAction * aRunParams;     //Запуск с параметрами
	QAction * aMover;         //Добавить двигатель + установить движения 

	AddMovementDlg * addMovementDialog;

	int segmentSize; //Размер сегмента по дефолту, в пикселях
	int segmentsAmount; //Текущее количество сегментов (после запуска равно общему числу сегментов)

	int fRowHeight; //Высота верхней строки со шкалой
	int tlRowHeight; //Высота строки

	qreal timeStep; //Шаг

	int tlRowCount; //число строк не считая линейку
	int tlRectSize; //Размер прямоугольника движения

	int w; //ширина сцены по дефлоту
	int h; //высота сцены

	std::vector <_row> rowVect;  //Вектор строк
	
};

#endif // TIMELINE_H
