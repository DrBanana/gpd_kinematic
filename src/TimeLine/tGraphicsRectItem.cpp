#include"tGraphicsRectItem.h"


void tGraphicsRectItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
	emit(doubleClicked());
}
