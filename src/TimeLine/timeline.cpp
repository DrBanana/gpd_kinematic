#include "timeline.h"

TimeLine::TimeLine(int defSegments, QWidget *parent)
    : QWidget(parent)
{

    segmentSize = 50;
    timeStep=1;
    //ui.setupUi(this);

    rowCount = 0;

    fRowHeight = 25; //Высота ячейки с линейкой

    w = segmentSize*defSegments+segmentSize; //Ширина сцены по дефолту.
    h = 50;

    this->resize(1200, 200);

    //Объявляем виджеты
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
	
	mainMenu->addMenu(mRun);                //Менюшку в бар
	mRun->addAction(aRun);                  //Экшн в менюшку
	mRun->addAction(aRunParams);

	mainMenu->addMenu(mAdd);
	mAdd->addAction(aMover);
   
	
	//Компоновка таймлайна
    QBoxLayout *mainLay = new QVBoxLayout();
    
    mainLay->addWidget(TableViewer, 1, 0);
	mainLay->setMenuBar(mainMenu);
    this->setLayout(mainLay);
    

    //Второе окно, с кнопочками
    win = new QWidget();
    win->resize(40, 80);
    
    QPushButton * addButton = new QPushButton(tr("+"));  //Добавить
    addButton->show();

    QPushButton * delButton = new QPushButton(tr("-"));         //Удалить
    delButton->show();

    QPushButton * dropButton = new QPushButton(tr("drop"));  //Сброс
    dropButton->show();

    QPushButton * addButton2 = new QPushButton(tr("++"));
    addButton2->show();


    //Компонуем кнопки

    QBoxLayout * boxLay = new QVBoxLayout(win);

    boxLay->addWidget(addButton, 1);
    boxLay->addWidget(delButton, 1);
    boxLay->addWidget(dropButton, 1);
    boxLay->addWidget(addButton2, 1);

    win->setLayout(boxLay);
    win->show();                  //Показываем кнопки

    //Сбрасываем шаги
    TimeLine::dropTime();

    //Рисуем линейку;
    for (int i = segmentsAmount; i < defSegments; i++)
    {
        TimeLine::addTime();
    }

    //Устанавливаем размеры ячеек
    TableViewer->setColumnWidth(1, w+segmentSize/2);
    TableViewer->setRowHeight(0, fRowHeight+10);
    

    //связываем сигналы-слоты
    connect(addButton, SIGNAL(clicked()), this, SLOT(addRow()));
    connect(delButton, SIGNAL(clicked()), this, SLOT(delRow()));
    connect(dropButton, SIGNAL(clicked()), this, SLOT(dropTime()));
    connect(addButton2, SIGNAL(clicked()), this, SLOT(addDrive()));
	connect(aRunParams, SIGNAL(triggered()), this, SLOT(actionRunWithPrms()));
	connect(aMover, SIGNAL(triggered()), this, SLOT(actionAdd()));

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

void TimeLine::addTimeMarks(QGraphicsScene * scene)
{
    int paintFrom = 0;
    QPen _pen2(Qt::gray, 1, Qt::DashLine);

    for (int i = 0; i < segmentsAmount+1; i++)
    {
        scene->addLine(paintFrom,0, paintFrom, scene->height(), _pen2);
        paintFrom += segmentSize;
    }

    //Проверка номеров
    QGraphicsTextItem * ptext;
    ptext = scene->addText(QString::number(rowCount));
    ptext->setPos(5, 5);

}

void TimeLine::addRow()
{
    _row newRow;

    TableViewer->setRowCount(TableViewer->rowCount()+1); //Прибавляем строку (текущее 0 + 1, 2+1...)

    int thisRow = rowCount;  //Текущая строка

    //Создаем новые виджеты для структуры
    QGraphicsScene * scene = new QGraphicsScene(0, 0, w, fRowHeight*2);
    QGraphicsView * view = new QGraphicsView();

	//Назначаем объекты структуре
    newRow.rowGScene = scene;
    newRow.rowGView = view;
    newRow.rowGView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

	//Грузим CMover в структуру строки
	//CMover * pMover = new CMover();



    rowVect.push_back(newRow);  //Пишем структуру в массив

    TableViewer->setCellWidget(TableViewer->rowCount() - 1, 1, rowVect[thisRow].rowGView); //Помещаем вьювер графики в новую строку

    rowVect[thisRow].rowGView->setScene(rowVect[thisRow].rowGScene);  //Устанавливаем в новый графиквьювер новую сцену
    TimeLine::addTimeMarks(rowVect[thisRow].rowGScene);//Рисуем разделительные метки на сцене

    rowVect[thisRow].rowGView->show();

    TableViewer->setRowHeight(TableViewer->rowCount() - 1, fRowHeight * 2+3);  //+3 пикселя что-бы ячейка была чуть выше высоты сцены, да бы не появлялся боковой скроллбар

    rowCount++;

    
}

void TimeLine::delRow()
{
    if (rowCount == 0) return;

    rowVect.pop_back();

    TableViewer->setRowCount(TableViewer->rowCount() - 1);

    rowCount--;
}

TimeLine::~TimeLine()
{
	//win->close();
	delete(win);
}

void TimeLine::actionRunWithPrms()
{
	prmWin = new tRunPrmWin(segmentsAmount);
	prmWin->show();
}

void TimeLine::actionAdd()
{
	addMovement = new AddMovementDlg(segmentsAmount);
	addMovement->show();
}
