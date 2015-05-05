#ifndef TGRAPHICSRECTITEM_H
#define TGRAPHICSRECTITEM_H

#include<QGraphicsRectItem>

class tGraphicsRectItem : public QGraphicsRectItem
{
	Q_OBJECT

public:

	tGraphicsRectItem(const QRectF & rect, QGraphicsItem * parent = 0);
	~tGraphicsRectItem();


protected:

	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;

public slots:



signals :

	void doubleClicked();

private:



};


#endif //TGRAPHICSRECTITEM_H