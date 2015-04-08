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

	//Добавление сегментов шкалы
	void addTime();
	void delTime();
	void dropTime();

	//Добавление строк
	void addRow();
	void delRow();

	//Добавление разделительных меток на новую сцену
	void addTimeMarks(QGraphicsScene *);

	//Добавление объектов
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

	//Экшны меню
	QMenu * mRun;             //Меню запуска
	QAction * aRun;           //Запуск
	QAction * aRunParams;     //Запуск с параметрами

	int segmentSize; //Размер сегмента по дефолту, в пикселях
	int segmentsAmount; //Текущее количество сегментов

	int fRowHeight; //Высота верхней строки со шкалой

	qreal timeStep; //Шаг

	int rowCount; //число строк не считая линейку

	int w; //ширина сцены по дефлоту
	int h; //высота сцены

	std::vector <_row> rowVect;  //Вектор строк

	
};

#endif // TIMELINE_H
