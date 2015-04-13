#include "timeline.h"

TimeLine::TimeLine(int defSegments, QWidget *parent)
    : QWidget(parent)
{

    segmentSize = 50;
    timeStep=1;
    //ui.setupUi(this);

    rowCount = 0;

    fRowHeight = 25; //������ ������ � ��������

    w = segmentSize*defSegments+segmentSize; //������ ����� �� �������.
    h = 50;

    this->resize(1200, 200);

    //��������� �������
    TableViewer = new QTableWidget(1, 2, this);
    TableViewer->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel); //������ �� ��������
    TableViewer->setColumnWidth(1, w);

    QHeaderView * hHeader = new QHeaderView(Qt::Horizontal); //���� �������������� ����� � ����-������ � ������������ ��������
    TableViewer->setHorizontalHeader(hHeader);               //������������� ����� � TableViewer
    hHeader->setSectionResizeMode(1, QHeaderView::Fixed);       //������ ����� �� ����� ������� ����� ���� ������� ����� ������ 
                                                                //� ������� ����� ��������� �������, ������ ����������

    QHeaderView * vHeader = new QHeaderView(Qt::Vertical);
    vHeader->setSectionResizeMode(QHeaderView::Fixed);           //������ ������ ���� ����� ���� ����������
    TableViewer->setVerticalHeader(vHeader);

	//������ �����
	TableViewer->horizontalHeader()->hide();


    TableViewer->show(); 


	//�����
    graphS = new QGraphicsScene(0, 0, w, fRowHeight); //����� �� ������

    graphicsWindow = new QGraphicsView();                      //������ �������
    graphicsWindow->setScene(graphS);	                           //��������� ����� �� ������
    graphicsWindow->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    graphicsWindow->show();

    //graphicsWindow->setDragMode(QGraphicsView::ScrollHandDrag);

    //������������� graphicView � �������
    TableViewer->setCellWidget(0, 1, graphicsWindow);
    
	//�������
	mainMenu = new QMenuBar();
	
	mRun = new QMenu(tr("Run"), mainMenu);                   //������� � ����
	mAdd = new QMenu(tr("Add"), mainMenu);

	aRunParams = new QAction(tr("Run with params"), mRun);   //���� ������
	aRun = new QAction(tr("Run"), mRun);                     //���� ������ � �����������
	aMover = new QAction(tr("Add part mover"), mAdd);
	
	mainMenu->addMenu(mRun);                //������� � ���
	mRun->addAction(aRun);                  //���� � �������
	mRun->addAction(aRunParams);

	mainMenu->addMenu(mAdd);
	mAdd->addAction(aMover);
   
	
	//���������� ���������
    QBoxLayout *mainLay = new QVBoxLayout();
    
    mainLay->addWidget(TableViewer, 1, 0);
	mainLay->setMenuBar(mainMenu);
    this->setLayout(mainLay);
    

    //������ ����, � ����������
    win = new QWidget();
    win->resize(40, 80);
    
    QPushButton * addButton = new QPushButton(tr("+"));  //��������
    addButton->show();

    QPushButton * delButton = new QPushButton(tr("-"));         //�������
    delButton->show();

    QPushButton * dropButton = new QPushButton(tr("drop"));  //�����
    dropButton->show();

    QPushButton * addButton2 = new QPushButton(tr("++"));
    addButton2->show();


    //��������� ������

    QBoxLayout * boxLay = new QVBoxLayout(win);

    boxLay->addWidget(addButton, 1);
    boxLay->addWidget(delButton, 1);
    boxLay->addWidget(dropButton, 1);
    boxLay->addWidget(addButton2, 1);

    win->setLayout(boxLay);
    win->show();                  //���������� ������

    //���������� ����
    TimeLine::dropTime();

    //������ �������;
    for (int i = segmentsAmount; i < defSegments; i++)
    {
        TimeLine::addTime();
    }

    //������������� ������� �����
    TableViewer->setColumnWidth(1, w+segmentSize/2);
    TableViewer->setRowHeight(0, fRowHeight+10);
    

    //��������� �������-�����
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

    //������ 1 ������� 
    graphS->addLine(paintFrom, 0, paintFrom, fRowHeight, _pen2); //������������ � ������
    graphS->addLine(paintFrom + segmentSize, 0, paintFrom + segmentSize, fRowHeight, _pen2); //������������ � �����

    graphS->addLine(paintFrom, 0, paintFrom, 10, _pen); //0       �� paintFrom
    ptext = graphS->addText(QString::number(segmentsAmount));  //�������������� ��������� �������
    ptext->setPos(paintFrom, 5);                                 //������� ��� ������ ��������

    graphS->addLine(paintFrom + segmentSize, 0, paintFrom + segmentSize, 10, _pen); //50   �� paintFrom + segmentSize
    ptext = graphS->addText(QString::number(segmentsAmount+1));
    ptext->setPos(paintFrom + segmentSize, 5);
    //������ ������ ��������
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

    //�������� �������
    QGraphicsTextItem * ptext;
    ptext = scene->addText(QString::number(rowCount));
    ptext->setPos(5, 5);

}

void TimeLine::addRow()
{
    _row newRow;

    TableViewer->setRowCount(TableViewer->rowCount()+1); //���������� ������ (������� 0 + 1, 2+1...)

    int thisRow = rowCount;  //������� ������

    //������� ����� ������� ��� ���������
    QGraphicsScene * scene = new QGraphicsScene(0, 0, w, fRowHeight*2);
    QGraphicsView * view = new QGraphicsView();

	//��������� ������� ���������
    newRow.rowGScene = scene;
    newRow.rowGView = view;
    newRow.rowGView->setAlignment(Qt::AlignLeft | Qt::AlignTop);

	//������ CMover � ��������� ������
	//CMover * pMover = new CMover();



    rowVect.push_back(newRow);  //����� ��������� � ������

    TableViewer->setCellWidget(TableViewer->rowCount() - 1, 1, rowVect[thisRow].rowGView); //�������� ������ ������� � ����� ������

    rowVect[thisRow].rowGView->setScene(rowVect[thisRow].rowGScene);  //������������� � ����� ������������ ����� �����
    TimeLine::addTimeMarks(rowVect[thisRow].rowGScene);//������ �������������� ����� �� �����

    rowVect[thisRow].rowGView->show();

    TableViewer->setRowHeight(TableViewer->rowCount() - 1, fRowHeight * 2+3);  //+3 ������� ���-�� ������ ���� ���� ���� ������ �����, �� �� �� ��������� ������� ���������

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
