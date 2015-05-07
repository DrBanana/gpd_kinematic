#include"tGraphicsRectItem.h"



tGraphicsRectItem::tGraphicsRectItem(const QRectF & rect, QGraphicsItem * parent)
{
	movement = nullptr;
}


void tGraphicsRectItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

	emit doubleClicked(movement);

	event->accept();
}

tGraphicsRectItem::~tGraphicsRectItem()
{

}
