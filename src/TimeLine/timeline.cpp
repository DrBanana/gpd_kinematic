#include "timeline.h"

#include <Gepard/Callbacks/CB_GeometryRender.h>
#include <Gepard/GeometryManager.h>

using namespace Gepard::Callbacks;


TimeLine::TimeLine(int defSegments, Gepard::GeometryManager *g_manager, QWidget *parent)
    : QWidget(parent)
{
	
	TimeLine_g_manager = g_manager;

	segments = defSegments;
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

	splitSecond = nullptr;

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

	//������
	tBar = new QToolBar();

	aRight = new QAction(tr(">"), tBar);
	aLeft = new QAction(tr("<"), tBar);

	tBar->addAction(aLeft);
	tBar->addAction(aRight);
	
	//���������� ���������
    QGridLayout *mainLay = new QGridLayout();

	mainLay->addWidget(tBar, 0, 0, 1, 1);
	mainLay->addWidget(TableViewer, 1, 0, 1, 1);
	mainLay->setMenuBar(mainMenu);
    this->setLayout(mainLay);
    

    //���������� ����
    TimeLine::dropTime();

    //������ �������;
    for (int i = segmentsAmount; i < defSegments; i++)
    {
        TimeLine::addTime();
    }

	//��������� ���������
	TimeLine::addSplitters();

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
	connect(aRight, SIGNAL(triggered()), this, SLOT(moveSplitterRight()));
	connect(aLeft, SIGNAL(triggered()), this, SLOT(moveSplitterLeft()));

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

void TimeLine::addTimeMarks(QGraphicsScene  *scene)
{
    int paintFrom = 0;
    QPen _pen2(Qt::gray, 1, Qt::DashLine);

    for (int i = 0; i < segmentsAmount+1; i++)
    {
        scene->addLine(paintFrom,0, paintFrom, scene->height(), _pen2);
        paintFrom += segmentSize;
    }
}

void TimeLine::addRow(CMover moverFromDialog)
{
	
	_row newRow(moverFromDialog, w, tlRowHeight);

	//������� ����� � ������ ��� ���������
	newRow.rowGScene = new QGraphicsScene();
	newRow.rowGView = new QGraphicsView();
 
 	//TableViewer->setRowCount(TableViewer->rowCount() + 1); //���������� ������ (������� 0 + 1, 2+1...)
	TableViewer->insertRow(TableViewer->rowCount());
 	
	TableViewer->setCellWidget(TableViewer->rowCount() - 1, 1, newRow.rowGView); //�������� ������ ������� � ����� ������

	partName = new QLabel();
	partName->setText(QString::fromStdString(moverFromDialog.getPartName()));  //����� ��� ������ � �����
	TableViewer->setCellWidget(TableViewer->rowCount() - 1, 0, partName); //�������� ��� ������ � �������

	newRow.rowGScene->setSceneRect(0, 0, w, moverFromDialog.GetSizeOfmovementsVector() * tlRectSize);

 	addTimeMarks(newRow.rowGScene);  //��������������� �����
 	
 	newRow.rowGView->setScene(newRow.rowGScene);
 	newRow.rowGView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
 	newRow.rowGView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
 	newRow.rowGView->show();
 	
	//��������� ������ ������ � ����������� �� ���������� ��������
	int height = moverFromDialog.GetSizeOfmovementsVector()*tlRectSize;
	TableViewer->setRowHeight(TableViewer->rowCount() - 1, moverFromDialog.GetSizeOfmovementsVector() * tlRectSize + 5);
	
	//��������� ��������������
	//addGraphicMarks(newRow.tmovments, moverFromDialog, *newRow.rowGScene);
    addGraphicMarks(newRow);

	rowVect.push_back(newRow);  //����� ��������� � ������

	Gepard::BasicMath::GPDReper newRep = newRow.partMover.GetPart()->SolidReper;
	//��������� ����� �� ����������
	defaultRepers.push_back(newRep);

	tlRowCount++;

	//������ ������ ����������� ��� ���������� ����� ������, ������ ������ ������� tRectItem'�� ��������� ����� ���������� ������� 
	//� �������� newRow, ��������� � ������� ��� ����� ��������� �� ������ ������ newRow ������� ��������� ����� ����������� �������

	//����������� ������ � ������ ������, �� ����� �������, �� ���� ��� ��������
	for (int i = 0; i < rowVect.size(); i++)
	{
		for (int j = 0; j < rowVect[i].partMover.GetSizeOfmovementsVector(); j++)
		{
			rowVect[i].tmovments[j]->movement = rowVect[i].partMover.GetMovementAt(j);
		}
		
	}

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
	std::vector <Gepard::BasicMath::GPDReper> tempRepVect;

	rowVect[numRow-1].partMover.SetPartReper(defaultRepers[numRow-1]);

	g_manager.HideSolid(rowVect[numRow - 1].partMover.GetPart());
	g_manager.ShowSolidInRender(rowVect[numRow - 1].partMover.GetPart(), GeometryRenderManager::GetCamera(0));

	for (int i = 0; i < rowVect.size(); i++)
	{
		if (i != numRow - 1) 
		{
			tempVect.push_back(rowVect[i]);
			tempRepVect.push_back(defaultRepers[i]);
		}
	}

	TableViewer->removeRow(numRow);

	tempVect.swap(rowVect);
	tempRepVect.swap(defaultRepers);

}

TimeLine::~TimeLine()
{
	delete(prmWin);
	delete(addMovementDialog);
}

void TimeLine::actionRunWithPrms()
{
	//prmWin->show();

	QMessageBox * msgBox = new QMessageBox(QMessageBox::Question, tr("Reset state"), tr("Reset state and start new simulation?"), QMessageBox::Yes | QMessageBox::No);

	int res = msgBox->exec();

	if (res == QMessageBox::No)
	{
		return;
	}

	//���������� ������� ��������

	TimeLine::resetState();
	//

	//������� ��������� �������������
	int p1 = splitFirst->x() / segmentSize;  //��������� ���
	int p2 = splitSecond->x() / segmentSize; //�������� ���

	auto cam0 = GeometryRenderManager::GetCamera(0);
	auto cam0Render = dynamic_cast<GPDGeometryRender*>(cam0);

	int rowCnt = rowVect.size();
	CMovements * thisMovement;

	Gepard::GPDSolid *solidPtr;
	int stepsCnt;
	int stepStart;
	int stepEnd;

	CMovements movementIn;
	CMovements movementOut;

	vector <CMover> newMoverVect;
	vector <CMovements> newMovementsVect;

	//�������������� ������ �������� 

	for (int i = 0; i < rowCnt; i++) //���� �� �������
	{

		int movementsCnt = rowVect[i].partMover.GetSizeOfmovementsVector();   //����� �������� ������
		solidPtr = rowVect[i].partMover.GetPart();
		CMover thisMover(solidPtr);

		for (int j = 0; j < movementsCnt; j++)  //���� �� ��������� ������
		{
			stepsCnt = rowVect[i].partMover.GetStepsCntForMovement(j);   //����� ����� ��������

			//���������� ��� ��������� ��������
			thisMovement = rowVect[i].partMover.GetMovementAt(j);
			stepStart = thisMovement->GetStart();
			stepEnd = thisMovement->GetEnd();

			if (stepEnd <= p1) //�������� ����� ��������
			{
				newMovementsVect.push_back(*thisMovement);
			}
			else if (stepStart >= p1 && stepEnd<=p2) //�������� � �������
			{
				newMovementsVect.push_back(*thisMovement);
			}
			else if (stepStart < p1 && stepEnd <= p2)  //����� �������� � �������, ����� ����� ���
			{
				//��������� ��������
				int stepIn = stepEnd - p1;
				int stepOut = p1 - stepStart;

				//������� �������� �� ��������
				movementOut = splitMovementF(thisMovement, stepOut, stepsCnt);
				newMovementsVect.push_back(movementOut);
				//������� �������� ������ ��������
				movementIn = splitMovementB(thisMovement, stepOut, stepsCnt);
				newMovementsVect.push_back(movementIn);

			}
			else if (stepStart >= p1 && stepEnd > p2)  //����� �������� � �������, ����� �� ���
			{
				//��������� ��������
				int stepIn = p2 - stepStart;
				int stepOut = stepEnd - p2;

				//������� �������� ������ ��������
				movementIn = splitMovementF(thisMovement, stepIn, stepsCnt);
				newMovementsVect.push_back(movementIn);

			}
			else if (stepStart <  p1 && stepEnd > p2)  //������ �������� �� ��������, ����� �� ��������
			{
				//��������� ��������
				int stepIn = p2 - p1;
				int stepOut = p1 - stepStart;

				//������� �������� �� ��������
				movementOut = splitMovementF(thisMovement, stepOut, stepsCnt);
				newMovementsVect.push_back(movementOut);
				//������� �������� ������ ��������
				movementIn = pullMovement(thisMovement, p1, p2);
				newMovementsVect.push_back(movementIn);

			}

		}

		thisMover.SetMovementsVector(newMovementsVect);

		newMoverVect.push_back(thisMover);
	}

	//������� �� ������ ������

	for (int i = 0; i < newMoverVect.size(); i++) //���� �� �������
	{

		int movementsCnt = newMoverVect[i].GetSizeOfmovementsVector();   //����� �������� ������
		solidPtr = newMoverVect[i].GetPart();

		for (int j = 0; j < movementsCnt; j++)  //���� �� ��������� ������
		{
			stepsCnt = newMoverVect[i].GetStepsCntForMovement(j);   //����� ����� ��������

			//���������� ��� ��������� ��������
			thisMovement = newMoverVect[i].GetMovementAt(j);

			stepStart = thisMovement->GetStart();
			stepEnd = thisMovement->GetEnd();

			if (stepEnd <= p1) //�������� �� ������ � ������
			{
				thisMovement->Update();          //����� ����� ���-�� �� ���, ������� ��� ������������, �� ��� ��� ����� �������� ���������� � 1 ���

				newMoverVect[i].MoveIt(j);
				TimeLine_g_manager->HideSolid(newMoverVect[i].GetPart());
				TimeLine_g_manager->ShowSolidInRender(newMoverVect[i].GetPart(), GeometryRenderManager::GetCamera(0));
			}
			else if (stepStart >= p1) //�������� � �������
			{
				for (int k = 0; k < stepsCnt; k++)        //���� �� ����� ��������
				{
					thisMovement->Update();

					newMoverVect[i].OneStepMove(j);

					auto f = newMoverVect[i].getModFunc(j, k);

					if (cam0Render->isSolidExist(solidPtr))
					{
						for (auto fItr = solidPtr->Faces.std_begin(); fItr != solidPtr->Faces.std_end(); fItr++)
						{
							cam0Render->ModifyObject((void*)&(*fItr), f);
						}
						cam0Render->RepaintContent();
					}
				}
			}
		}
	}
}

void TimeLine::actionRun()
{

	QMessageBox * msgBox = new QMessageBox(QMessageBox::Question, tr("Reset state"), tr("Reset state and start new simulation?"), QMessageBox::Yes | QMessageBox::No);

	int res = msgBox->exec();

    if (res == QMessageBox::No)
	{
		return;
	}

	//���������� ������� ��������

	TimeLine::resetState();
	//

	auto cam0 = GeometryRenderManager::GetCamera(0);
	auto cam0Render = dynamic_cast<GPDGeometryRender*>(cam0);

	int rowCnt = rowVect.size();
	CMovements * thisMovement;
	Gepard::GPDSolid *solidPtr;
	int stepsCnt;


	//������� ����� ����������������� �������� � ���, ��� �� ��������� ����� ����/������ ������� ������� � �� ��������� ��, � 
	//���������� ���� ������ ���������� �� 50,0,0 � ����� �������� ������������ ����� ���������� ����� ����� ��� ���� � 
	//��������� 0,0,0 ��� ����� �������� ������ ������...

	for (int i = 0; i < rowCnt; i++) //���� �� �������
	{

		int movementsCnt = rowVect[i].partMover.GetSizeOfmovementsVector();
		solidPtr = rowVect[i].partMover.GetPart();

		for (int j = 0; j < movementsCnt; j++)  //���� �� ��������� ������
		{
			stepsCnt = rowVect[i].partMover.GetStepsCntForMovement(j);

			for (int k = 0; k < stepsCnt; k++)        //���� �� ����� ��������
			{
				thisMovement = rowVect[i].partMover.GetMovementAt(j);

				thisMovement->Update();

				rowVect[i].partMover.OneStepMove(j);

				auto f = rowVect[i].partMover.getModFunc(j, k);

				if (cam0Render->isSolidExist(solidPtr))
				{
					for (auto fItr = solidPtr->Faces.std_begin(); fItr != solidPtr->Faces.std_end(); fItr++)
					{
						cam0Render->ModifyObject((void*)&(*fItr), f);
					}
					cam0Render->RepaintContent();
				}
			}
			//���������
// 			TimeLine_g_manager->HideSolid(rowVect[i].partMover.GetPart());
// 			TimeLine_g_manager->ShowSolidInRender(rowVect[i].partMover.GetPart(), GeometryRenderManager::GetCamera(0));
 		}	
	}
}

void TimeLine::actionAdd()
{
	addMovementDialog->show();
}

//void TimeLine::addGraphicMarks(vector<tGraphicsRectItem *> &Marks, CMover &prtMover, QGraphicsScene &scene)
void TimeLine::addGraphicMarks(_row &r)
{
    int mCount = r.partMover.GetSizeOfmovementsVector();
	QRectF mRectF;                                       //��������� �������
	//QGraphicsRectItem * mRectItem;                       //��������� �� ������
	tGraphicsRectItem * tRectItem;                       //��������� �� ������
	QGraphicsTextItem * mNameItem;                         //��� �������
	CMovements * movement;
	int height = tlRectSize;
	int width = 0;
	int vStart;   //������ �� ���������
	int hStart;   //������ �� �����������


	QPen pen(Qt::black, 1 , Qt::SolidLine);
	QBrush brush(QColor(0,0,255,125), Qt::SolidPattern);
	QBrush brush2(QColor(255, 0, 0, 125), Qt::SolidPattern);
	

	for (int i = 0; i < mCount; i++)
	{
		movement = r.partMover.GetMovementAt(i);

		width = (movement->GetEnd() - movement->GetStart())*segmentSize;  //������� ����� �������� �������� � ��� ������ � ��������
		vStart = i * height;   //������ ������� � �����, ������ ���� �� 15 ���� � ��.
		hStart = movement->GetStart()*segmentSize;

		mRectF.setRect(0, 0, width, height);  //������������� ������� ��������� �������

		//mRectItem = scene.addRect(mRectF, pen, brush); //��������� RectItem �� ����� � ����� ��������� �� ����
		tRectItem = new tGraphicsRectItem(mRectF);
		tRectItem->setBrush(brush2);
		tRectItem->setPen(pen);
		tRectItem->setRect(mRectF);

		tRectItem->setFlags(QGraphicsItem::ItemIsSelectable);
		tRectItem->movement = movement;

		r.rowGScene->addItem(tRectItem);
		tRectItem->setPos(hStart, vStart);

		
		tRectItem->mName = r.rowGScene->addText(QString::fromStdString(movement->GetMoveName()));
	
		QPointF Point = tRectItem->pos();
		tRectItem->mName->setPos(Point);
		//Names[i]->setParentItem(Marks[i]);
		
		
		connect(tRectItem,SIGNAL(doubleClicked(CMovements* )), this, SLOT(showEdit(CMovements*)));
		

		//�������� ������ �� ������������� ��������, �����������, ����� �� ����� ������ ����� tRectItem ������������, �����:
		//1. ������� tRect � CMovement'�, ������ ��� �������� ������ �� CMovement ��� ��������� � tRect'�?
		//2. �������������� ��� �������� ������ ��������������� ������� � ��, ��� ���� ����������� ��������������.

		//Marks.push_back(tRectItem);                      //����� ��������� � ������
        r.tmovments.push_back(tRectItem);

	}
}

void TimeLine::mouseDoubleClickEvent(QMouseEvent * event)
{
	addMovementDialog->show();

	event->accept();
}

void TimeLine::showEdit(CMovements * numMovement)
{
	sednderRect = (tGraphicsRectItem*)sender();

	editWin = new tEditWin(numMovement, segments);
	connect(editWin, SIGNAL(movementEdited()), this, SLOT(resizeMarker()));
	editWin->show();

}

void TimeLine::addSplitters()
{
	//������� �����������

	QPen _pen3(QColor(255, 0, 0, 255), 1);

	QRectF * rect = new QRectF(-2, 0, 4, fRowHeight);

	splitFirst = graphS->addRect(*rect, _pen3);
	splitSecond = graphS->addRect(*rect, _pen3);

	splitFirst->setFlags(QGraphicsItem::ItemIsSelectable);
	splitSecond->setFlags(QGraphicsItem::ItemIsSelectable);

	splitFirst->setPos(0, 0);
	splitSecond->setPos(segmentSize, 0);

	delete(rect);
}


void TimeLine::moveSplitterLeft()
{

	QPointF point;

	if (splitFirst->isSelected() == true)
	{
		point = splitFirst->pos();
		if (point.rx() == 0) { return; }
		if (point.rx() == splitSecond->pos().x() + segmentSize) { return; }
		splitFirst->setPos(point.rx()-segmentSize, 0);
	}
	else if (splitSecond->isSelected() == true)
	{
		point = splitSecond->pos();
		if (point.rx() == 0) { return; }
		if (point.rx() == splitFirst->pos().x() + segmentSize) { return; }
		splitSecond->setPos(point.rx() - segmentSize, 0);
	}
}

void TimeLine::moveSplitterRight()
{
	QPointF point;

	if (splitFirst->isSelected() == true)
	{
		point = splitFirst->pos();
		if (point.rx() == segments*segmentSize) { return; }
		if (point.rx() == splitSecond->pos().x() - segmentSize) { return; }
		splitFirst->setPos(point.rx() + segmentSize, 0);
	}
	else if (splitSecond->isSelected() == true)
	{
		point = splitSecond->pos();
		if (point.rx() == segments*segmentSize) { return; }
		if (point.rx() == splitFirst->pos().x() - segmentSize) { return; }
		splitSecond->setPos(point.rx() + segmentSize, 0);
	}
}

void TimeLine::resizeMarker()
{
	int width = (sednderRect->movement->GetEnd() - sednderRect->movement->GetStart())*segmentSize;  //������� ����� �������� �������� � ��� ������ � ��������

	int hStart = sednderRect->movement->GetStart()*segmentSize;

	QPointF point = sednderRect->pos();

	sednderRect->setRect(0, 0, width, tlRectSize);
	sednderRect->setPos(hStart, point.ry());

	point = sednderRect->pos();

	sednderRect->mName->setPos(point);
}

void TimeLine::resetState()
{
	for (int i = 0; i < rowVect.size(); i++)
	{
		rowVect[i].partMover.SetPartReper(defaultRepers[i]);

		g_manager.HideSolid(rowVect[i].partMover.GetPart());
		g_manager.ShowSolidInRender(rowVect[i].partMover.GetPart(), GeometryRenderManager::GetCamera(0));
	}
}

CMovements TimeLine::splitMovementF(CMovements * oldMovement, int piece, int steps)
{
	if (piece >= steps) { return *oldMovement; }
	if (steps != oldMovement->GetStepsCnt()) { return *oldMovement; }

	CMovements newMovement;

	newMovement.SetMoveName(oldMovement->GetMoveName());             //�������� ���
	newMovement.SetMovementType(oldMovement->GetMovementType());     //�������� ���
	if (oldMovement->GetMovementType() == CIRCULAR)
	{
		newMovement.SetShift(oldMovement->GetDegrees() / steps*piece); //�������� ����� ������ ��� �������
	}
	else
	{
		newMovement.SetShift(oldMovement->GetShift() / steps*piece); //�������� ����� ������ ��� �������
	}
	newMovement.SetAxis(oldMovement->GetAxis());                      //�������� ���
	newMovement.SetPoint(oldMovement->GetPoint());                    //�����
	newMovement.SetStart(oldMovement->GetStart());                    //������
	newMovement.SetEnd(oldMovement->GetStart()+piece);                //����������� ����� ������ ��������� ����� �������
	newMovement.setAxisName(oldMovement->getAxisName());              //�������� ��� ���
	newMovement.setFace(oldMovement->getFace());                      //�������� �����������

	return newMovement;
}

CMovements TimeLine::splitMovementB(CMovements * oldMovement, int piece, int steps)
{
	if (piece >= steps) { return *oldMovement; }
	if (steps != oldMovement->GetStepsCnt()) { return *oldMovement; }

	CMovements newMovement;

	newMovement.SetMoveName(oldMovement->GetMoveName());             //�������� ���
	newMovement.SetMovementType(oldMovement->GetMovementType());     //�������� ���
	if (oldMovement->GetMovementType() == CIRCULAR)
	{
		newMovement.SetShift(oldMovement->GetDegrees() / steps*(steps - piece)); //�������� ����� ������ � ������� �������
	}
	else
	{
		newMovement.SetShift(oldMovement->GetShift() / steps*(steps - piece)); //�������� ����� ������ � ������� �������
	}
	newMovement.SetAxis(oldMovement->GetAxis());                      //�������� ���
	newMovement.SetPoint(oldMovement->GetPoint());                    //�����
	newMovement.SetStart(oldMovement->GetStart()+piece);              //����������� ������ ������ ��������� ����� �������      
	newMovement.SetEnd(oldMovement->GetEnd());                        //�����
	newMovement.setAxisName(oldMovement->getAxisName());              //�������� ��� ���
	newMovement.setFace(oldMovement->getFace());                      //�������� �����������

	return newMovement;
}

CMovements TimeLine::pullMovement(CMovements * oldMovement, int p1, int p2)
{
	if (p2<=p1)
	{
		return *oldMovement;
	}
	CMovements newMovement;

	newMovement.SetMoveName(oldMovement->GetMoveName());             //�������� ���
	newMovement.SetMovementType(oldMovement->GetMovementType());     //�������� ���
	newMovement.SetShift(oldMovement->GetShift() / oldMovement->GetStepsCnt() * (p2 - p1)); //�������� ����� ������ � ������� �������
	newMovement.SetAxis(oldMovement->GetAxis());                      //�������� ���
	newMovement.SetPoint(oldMovement->GetPoint());                    //�����
	newMovement.SetStart(p1);                                         //����������� ������ ������ ��������� ����� �������      
	newMovement.SetEnd(p2);                                           //����������� ����� ������ �������� ����� �������
	newMovement.setAxisName(oldMovement->getAxisName());              //�������� ��� ���
	newMovement.setFace(oldMovement->getFace());                      //�������� �����������

	return newMovement;
}

