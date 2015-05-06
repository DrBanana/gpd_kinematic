#ifndef TGRAPHICSRECTITEM_H
#define TGRAPHICSRECTITEM_H

#include<QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class tGraphicsRectItem : public QGraphicsRectItem
{
	//Q_OBJECT

public:

	tGraphicsRectItem(const QRectF & rect, QGraphicsItem * parent = 0);
	~tGraphicsRectItem();


protected:

	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

public slots:

	void sendSignal();

signals :

	void doubleClicked(int a);

private:



};


#endif //TGRAPHICSRECTITEM_H