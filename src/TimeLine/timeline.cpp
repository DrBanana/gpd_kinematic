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

	fRowHeight = 25; //������ ������ � ��������
	tlRowHeight = 30; //������ ������
	tlRectSize = 15;

    w = segmentSize*defSegments+segmentSize; //������ ����� �� �������.
    h = 50;

    this->resize(1200, 200);

    //��������� �������
	doubleclick_event = new QGraphicsSceneMouseEvent();

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
	aRemove = new QAction(tr("Remove row"), mainMenu);
	
	mainMenu->addMenu(mRun);                //������� � ���
	mRun->addAction(aRun);                  //���� � �������
	mRun->addAction(aRunParams);

	mainMenu->addMenu(mAdd);
	mAdd->addAction(aMover);

	mainMenu->addAction(aRemove);
   
	
	//���������� ���������
    QBoxLayout *mainLay = new QVBoxLayout();
    
    mainLay->addWidget(TableViewer, 1, 0);
	mainLay->setMenuBar(mainMenu);
    this->setLayout(mainLay);
    

    //���������� ����
    TimeLine::dropTime();

    //������ �������;
    for (int i = segmentsAmount; i < defSegments; i++)
    {
        TimeLine::addTime();
    }

    //������������� ������� �����
	TableViewer->setColumnWidth(1, w + segmentSize / 2);
	TableViewer->setRowHeight(0, fRowHeight+5);
    
	//��������� ������� ����
	addMovementDialog = new AddMovementDlg(segmentsAmount);
	prmWin = new tRunPrmWin(segmentsAmount);
	delWin = new tDelWin(rowVect.size());


    //��������� �������-�����

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

	rowVect.push_back(newRow);  //����� ��������� � ������

	//������� ����� � ������ ��� ���������
	rowVect[tlRowCount].rowGScene = new QGraphicsScene();
	rowVect[tlRowCount].rowGView = new QGraphicsView();

	
	int a = TableViewer->rowCount();
 
 	//TableViewer->setRowCount(TableViewer->rowCount() + 1); //���������� ������ (������� 0 + 1, 2+1...)
	TableViewer->insertRow(a);
 
	int b = TableViewer->rowCount();
 	
	TableViewer->setCellWidget(TableViewer->rowCount() - 1, 1, rowVect[tlRowCount].rowGView); //�������� ������ ������� � ����� ������

	rowVect[tlRowCount].rowGScene->setSceneRect(0, 0, w, moverFromDialog.GetSizeOfmovementsVector() * tlRectSize);
 	addTimeMarks(*rowVect[tlRowCount].rowGScene);
 	
 	rowVect[tlRowCount].rowGView->setScene(rowVect[tlRowCount].rowGScene);
 	rowVect[tlRowCount].rowGView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 	rowVect[tlRowCount].rowGView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
 	rowVect[tlRowCount].rowGView->show();
 	
	//��������� ������ ������ � ����������� �� ���������� ��������
	int height = moverFromDialog.GetSizeOfmovementsVector()*tlRectSize;
	TableViewer->setRowHeight(TableViewer->rowCount() - 1, moverFromDialog.GetSizeOfmovementsVector() * tlRectSize + 5);
	
	//��������� ��������������

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


			//���������
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
	QRectF mRectF;                                       //��������� �������
	QGraphicsRectItem * mRectItem;                       //��������� �� ������
	QGraphicsTextItem mNameItem;                         //��� �������
	CMovements * movement;
	int height = tlRectSize;
	int width = (movement->GetEnd() - movement->GetStart())*segmentSize;
	int vStart;   //������ �� ���������
	int hStart;   //������ �� �����������


	QPen pen(Qt::black, 1 , Qt::SolidLine);
	QBrush brush(QColor(0,0,255,125), Qt::SolidPattern);
	

	for (int i = 0; i < mCount; i++)
	{
		movement = prtMover.GetMovementAt(i);

		width = (movement->GetEnd() - movement->GetStart())*segmentSize;  //������� ����� �������� �������� � ��� ������ � ��������
		vStart = i * height;   //������ ������� � �����, ������ ���� �� 15 ���� � ��.
		hStart = movement->GetStart()*segmentSize;

		mRectF.setRect(hStart, vStart, width, height);  //������������� ������� ��������� �������

		mRectItem = scene.addRect(mRectF, pen, brush); //��������� RectItem �� ����� � ����� ��������� �� ����
		mRectItem->setFlags(QGraphicsItem::ItemIsSelectable);

		Marks.push_back(mRectItem);                      //����� ��������� � ������

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


