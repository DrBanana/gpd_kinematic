#include "timeline.h"

#include <Gepard/Callbacks/CB_GeometryRender.h>
#include <Gepard/GeometryManager.h>

using namespace Gepard::Callbacks;


TimeLine::TimeLine(int defSegments, Gepard::GeometryManager *g_manager, QWidget *parent)
    : QWidget(parent)
{
	
	TimeLine_g_manager = g_manager;

    segmentSize = 50;
    timeStep=1;
    //ui.setupUi(this);

	tlRowCount = 0;

	fRowHeight = 25; //Высота ячейки с линейкой
	tlRowHeight = 30; //Высота строки
	tlRectSize = 15;

    w = segmentSize*defSegments+segmentSize; //Ширина сцены по дефолту.
    h = 50;

    this->resize(1200, 200);

    //Объявляем виджеты
	doubleclick_event = new QGraphicsSceneMouseEvent();

    TableViewer = new QTableWidget(1, 2, this);

    TableViewer->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel); //Скролл по пикселям
	TableViewer->setColumnWidth(1, w);

    QHeaderView * hHeader = new QHeaderView(Qt::Horizontal); //Свой горизонтальный хэдер с блэк-джеком и фиксированым размером
	TableViewer->setHorizontalHeader(hHeader);               //Устанавливаем хэдер в TableViewer
    hHeader->setSectionResizeMode(1, QHeaderView::Fixed);       //Теперь когда он видит таблицу можно явно указать номер секции 
                                                                //и указать режим изменения размера, только программно

    QHeaderView * vHeader = new QHeaderView(Qt::Vertical);
    vHeader->setSectionResizeMode(QHeaderView::Fixed);           //менять размер всех строк тока программно
	TableViewer->setVerticalHeader(vHeader);

	//Скроем хэдер
	TableViewer->horizontalHeader()->hide();


	TableViewer->show();


	//сцена
    graphS = new QGraphicsScene(0, 0, w, fRowHeight); //Сцена со шкалой

    graphicsWindow = new QGraphicsView();                      //Вьювер линейки
    graphicsWindow->setScene(graphS);	                           //Добавляем сцену во вьювер
    graphicsWindow->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    graphicsWindow->show();

    //graphicsWindow->setDragMode(QGraphicsView::ScrollHandDrag);

    //Устанавливаем graphicView в таблицу
	TableViewer->setCellWidget(0, 1, graphicsWindow);
    
	//МенюБар
	mainMenu = new QMenuBar();
	
	mRun = new QMenu(tr("Run"), mainMenu);                   //Менюшка в баре
	mAdd = new QMenu(tr("Add"), mainMenu);

	aRunParams = new QAction(tr("Run with params"), mRun);   //Экшн запуск
	aRun = new QAction(tr("Run"), mRun);                     //Экшн запуск с параметрами
	aMover = new QAction(tr("Add part mover"), mAdd);
	aRemove = new QAction(tr("Remove row"), mainMenu);
	
	mainMenu->addMenu(mRun);                //Менюшку в бар
	mRun->addAction(aRun);                  //Экшн в менюшку
	mRun->addAction(aRunParams);

	mainMenu->addMenu(mAdd);
	mAdd->addAction(aMover);

	mainMenu->addAction(aRemove);
   
	
	//Компоновка таймлайна
    QBoxLayout *mainLay = new QVBoxLayout();
    
    mainLay->addWidget(TableViewer, 1, 0);
	mainLay->setMenuBar(mainMenu);
    this->setLayout(mainLay);
    

    //Сбрасываем шаги
    TimeLine::dropTime();

    //Рисуем линейку;
    for (int i = segmentsAmount; i < defSegments; i++)
    {
        TimeLine::addTime();
    }

    //Устанавливаем размеры ячеек
	TableViewer->setColumnWidth(1, w + segmentSize / 2);
	TableViewer->setRowHeight(0, fRowHeight+5);
    
	//Объявляем виджеты окон
	addMovementDialog = new AddMovementDlg(segmentsAmount);
	prmWin = new tRunPrmWin(segmentsAmount);
	delWin = new tDelWin(rowVect.size());


    //связываем сигналы-слоты

	connect(aRunParams, SIGNAL(triggered()), this, SLOT(actionRunWithPrms()));
	connect(aRun, SIGNAL(triggered()), this, SLOT(actionRun()));
	connect(aRemove, SIGNAL(triggered()), this, SLOT(delRowDialog()));
	connect(aMover, SIGNAL(triggered()), this, SLOT(actionAdd()));
	connect(addMovementDialog, SIGNAL(moverToLine(CMover)), this, SLOT(addRow(CMover)));
	connect(delWin, SIGNAL(accept(int)), this, SLOT(delRow(int)));


}


void TimeLine::addTime()
{

    int subSegments = 1 / timeStep;  //5

    int subSegmentSize = segmentSize / subSegments;  //10

    int paintFrom = segmentsAmount*segmentSize;  //0
    
    QPen _pen(Qt::black, 1);
    QPen _pen2(Qt::gray, 1, Qt::DashLine);
    QGraphicsTextItem * ptext;

    //Рисуем 1 сегмент 
    graphS->addLine(paintFrom, 0, paintFrom, fRowHeight, _pen2); //Направляющая в начале
    graphS->addLine(paintFrom + segmentSize, 0, paintFrom + segmentSize, fRowHeight, _pen2); //Направляющая в конце

    graphS->addLine(paintFrom, 0, paintFrom, 10, _pen); //0       от paintFrom
    ptext = graphS->addText(QString::number(segmentsAmount));  //Переопределяем текстовый элемент
    ptext->setPos(paintFrom, 5);                                 //Двигаем под начало сегмента

    graphS->addLine(paintFrom + segmentSize, 0, paintFrom + segmentSize, 10, _pen); //50   до paintFrom + segmentSize
    ptext = graphS->addText(QString::number(segmentsAmount+1));
    ptext->setPos(paintFrom + segmentSize, 5);
    //Рисуем внутри сегмента
    for (int i = 1; i < subSegments; i++) //1,2,3,4;
    {
        graphS->addLine(paintFrom+subSegmentSize*i, 0, paintFrom+subSegmentSize*i, 5, _pen);  //0+10*1; 0+10*2...
    }

    segmentsAmount += 1;

}

void TimeLine::delTime()
{
    if (segmentsAmount == 1){ return; }

    int newSegmentsAmount = segmentsAmount -= 1;
    segmentsAmount = 0;

    graphS->clear();

    for (int i = 0; i < newSegmentsAmount; i++)
    {
        TimeLine::addTime();
    }
}

void TimeLine::dropTime()
{
    segmentsAmount = 0;
    graphS->clear();
    TimeLine::addTime();
}

void TimeLine::addTimeMarks(QGraphicsScene  &scene)
{
    int paintFrom = 0;
    QPen _pen2(Qt::gray, 1, Qt::DashLine);

    for (int i = 0; i < segmentsAmount+1; i++)
    {
        scene.addLine(paintFrom,0, paintFrom, scene.height(), _pen2);
        paintFrom += segmentSize;
    }
}

void TimeLine::addRow(CMover moverFromDialog)
{
	
	_row newRow(moverFromDialog, w, tlRowHeight);

	rowVect.push_back(newRow);  //Пишем структуру в массив

	//Создаем сцену и вьювер для структуры
	rowVect[tlRowCount].rowGScene = new QGraphicsScene();
	rowVect[tlRowCount].rowGView = new QGraphicsView();

	
	int a = TableViewer->rowCount();
 
 	//TableViewer->setRowCount(TableViewer->rowCount() + 1); //Прибавляем строку (текущее 0 + 1, 2+1...)
	TableViewer->insertRow(a);
 
	int b = TableViewer->rowCount();
 	
	TableViewer->setCellWidget(TableViewer->rowCount() - 1, 1, rowVect[tlRowCount].rowGView); //Помещаем вьювер графики в новую строку

	rowVect[tlRowCount].rowGScene->setSceneRect(0, 0, w, moverFromDialog.GetSizeOfmovementsVector() * tlRectSize);
 	addTimeMarks(*rowVect[tlRowCount].rowGScene);
 	
 	rowVect[tlRowCount].rowGView->setScene(rowVect[tlRowCount].rowGScene);
 	rowVect[tlRowCount].rowGView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 	rowVect[tlRowCount].rowGView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
 	rowVect[tlRowCount].rowGView->show();
 	
	//Установим высоту строки в зависимости от количества движений
	int height = moverFromDialog.GetSizeOfmovementsVector()*tlRectSize;
	TableViewer->setRowHeight(TableViewer->rowCount() - 1, moverFromDialog.GetSizeOfmovementsVector() * tlRectSize + 5);
	
	//Добавляем прямоугольники

	addGraphicMarks(newRow.tmovments, newRow.tnames, moverFromDialog, *rowVect[tlRowCount].rowGScene);

	tlRowCount++;

	qDebug() << "Mover recieved";
}

void TimeLine::delRowDialog()
{
	if (rowVect.size() == 0) { return; }

	delWin->show();
}

void TimeLine::delRow(int numRow)
{
	std::vector <_row> tempVect;

	for (int i = 0; i < rowVect.size(); i++)
	{
		if (i != numRow - 1) 
		{
			tempVect.push_back(rowVect[i]);
		}
	}

	TableViewer->removeRow(numRow);

	tempVect.swap(rowVect);
}

TimeLine::~TimeLine()
{
	delete(prmWin);
	delete(addMovementDialog);
}

void TimeLine::actionRunWithPrms()
{
	prmWin->show();
}

void TimeLine::actionRun()
{

	int rowCnt = rowVect.size();
	

	for (int i = 0; i < rowCnt; i++)
	{

		int movementsCnt = rowVect[i].partMover.GetSizeOfmovementsVector();

		for (int j = 0; j < movementsCnt; j++)
		{
			rowVect[i].partMover.MoveIt(j);


			//Обновляем
			TimeLine_g_manager->HideSolid(rowVect[i].partMover.GetPart());
			TimeLine_g_manager->ShowSolidInRender(rowVect[i].partMover.GetPart(), GeometryRenderManager::GetCamera(0));
		}
		
	}




}

void TimeLine::actionAdd()
{
	addMovementDialog->show();
}

void TimeLine::addGraphicMarks(vector<QGraphicsRectItem *> Marks, vector<QGraphicsTextItem *> Names, CMover prtMover, QGraphicsScene &scene)
{
	int mCount = prtMover.GetSizeOfmovementsVector();
	QRectF mRectF;                                       //Геометрия маркера
	QGraphicsRectItem * mRectItem;                       //Указатель на маркер
	QGraphicsTextItem mNameItem;                         //Имя маркера
	CMovements * movement;
	int height = tlRectSize;
	int width = (movement->GetEnd() - movement->GetStart())*segmentSize;
	int vStart;   //Начало по вертикали
	int hStart;   //Начало по горизонтали


	QPen pen(Qt::black, 1 , Qt::SolidLine);
	QBrush brush(QColor(0,0,255,125), Qt::SolidPattern);
	

	for (int i = 0; i < mCount; i++)
	{
		movement = prtMover.GetMovementAt(i);

		width = (movement->GetEnd() - movement->GetStart())*segmentSize;  //Сколько шагов занимает движение и его длинна в пикселях
		vStart = i * height;   //Первый элемент в верху, второй ниже на 15 пикс и тд.
		hStart = movement->GetStart()*segmentSize;

		mRectF.setRect(hStart, vStart, width, height);  //Устанавливаем размеры геометрии маркера

		mRectItem = scene.addRect(mRectF, pen, brush); //Добавляем RectItem на сцену и пишем указатель на него
		mRectItem->setFlags(QGraphicsItem::ItemIsSelectable);

		Marks.push_back(mRectItem);                      //Пишем указатель в массив

		Marks[i]->setBrush(brush);
		
		Names.push_back(scene.addText(QString::fromStdString(movement->GetMoveName())));
		Names[i]->setParentItem(Marks[i]);
	}
}

void TimeLine::mouseDoubleClickEvent(QMouseEvent * event)
{
	addMovementDialog->show();

	event->accept();
}


