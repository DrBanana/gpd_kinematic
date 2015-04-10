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

	//Добавление сегментов шкалы
	void addTime();
	void delTime();
	void dropTime();

	//Добавление строк, со строкой добвляется CMover
	void addRow();
	void delRow();

	//Добавление разделительных меток на новую сцену
	void addTimeMarks(QGraphicsScene *);

	//Запуск
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
	//Экшны меню
	QMenu * mRun;             //Меню запуска
	QAction * aRun;           //Запуск
	QAction * aRunParams;     //Запуск с параметрами

	int segmentSize; //Размер сегмента по дефолту, в пикселях
	int segmentsAmount; //Текущее количество сегментов (после запуска равно общему числу сегментов)

	int fRowHeight; //Высота верхней строки со шкалой

	qreal timeStep; //Шаг

	int rowCount; //число строк не считая линейку

	int w; //ширина сцены по дефлоту
	int h; //высота сцены

	std::vector <_row> rowVect;  //Вектор строк
	
};

#endif // TIMELINE_H
