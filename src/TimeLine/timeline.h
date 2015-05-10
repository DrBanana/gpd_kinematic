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
		  rowGScene(rowGScene),
		  tmovments(r.tmovments),
		  tnames(r.tnames)

	{

	};

	///////////////////////////////////////
	QGraphicsScene * rowGScene;
	QGraphicsView * rowGView;

	std::vector <tGraphicsRectItem *> tmovments;
	std::vector <QGraphicsTextItem *> tnames;

	CMover partMover;
};


class TimeLine : public QWidget
{
	Q_OBJECT

public:
	TimeLine(int, Gepard::GeometryManager *, QWidget *parent = 0);
	~TimeLine();

public slots:

	//Добавление сегментов шкалы
	void addTime();
	void delTime();
	void dropTime();

	//Добавление строк, со строкой добвляется CMover
	void addRow(CMover);
	void delRowDialog();
	void delRow(int);

	//Редактирование движения
	void editMovement();

	//Добавление разделительных меток на новую сцену
	void addTimeMarks(QGraphicsScene &);

	//Добавление гравических элементов

	void addGraphicMarks(vector<tGraphicsRectItem *>&, vector<QGraphicsTextItem *>&,CMover&, QGraphicsScene &);

	//Запуск
	void actionRunWithPrms();
	void actionRun();

	//окно добавления движения
	void actionAdd();

	void mouseDoubleClickEvent(QMouseEvent * event) override;

	//Показать окно редактирования
	void showEdit(CMovements *);

	//Добавить ограничивающие маркеры
	void addSplitters();
	//Двигать маркеры
	void moveSplitterLeft();
	void moveSplitterRight();


signals:




protected:


private:
	//Ui::TimeLineClass ui;
	
	Gepard::GeometryManager * TimeLine_g_manager;

	QGraphicsSceneMouseEvent * doubleclick_event;  //Эвент мыши в рамках сцены

	QTableWidget * TableViewer;
	QGraphicsScene * graphS;
	QGraphicsView * graphicsWindow;

	tRunPrmWin * prmWin;
	tDelWin * delWin;
	tEditWin * editWin;
	AddMovementDlg * addMovementDialog;

	//Экшны меню
	QMenuBar * mainMenu;
	QMenu * mRun;             //Меню запуска
	QMenu * mAdd;             //Меню добавления
	QAction * aRun;           //Запуск
	QAction * aRunParams;     //Запуск с параметрами
	QAction * aMover;         //Добавить двигатель + установить движения 
	QAction * aRemove;

	//Тулбар и кнопки
	QToolBar * tBar;
	QAction * aRight;
	QAction * aLeft;

	//Ограничители симуляции
	QGraphicsRectItem * splitFirst;
	QGraphicsRectItem * splitSecond;

	int segments;  //Количество сегментов
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
