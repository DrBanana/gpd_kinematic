#ifndef TGRAPHICSRECTITEM_H
#define TGRAPHICSRECTITEM_H

#include<QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QWidget>

#include"CMovements/Mover.h"

class tGraphicsRectItem : public QWidget, public QGraphicsRectItem
{
	Q_OBJECT

public:

	tGraphicsRectItem(const QRectF & rect, QGraphicsItem * parent = 0);
	~tGraphicsRectItem();

	CMovements * movement;


protected:

	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

public slots:

	//void sendSignal();

signals :

	void doubleClicked(CMovements *);

private:



};


#endif //TGRAPHICSRECTITEM_H