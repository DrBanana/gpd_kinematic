#include"tGraphicsRectItem.h"



tGraphicsRectItem::tGraphicsRectItem(const QRectF & rect, QGraphicsItem * parent)
{

}


void tGraphicsRectItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	int a=0;

	//emit doubleClicked(a);

	event->accept();
}

tGraphicsRectItem::~tGraphicsRectItem()
{

}
