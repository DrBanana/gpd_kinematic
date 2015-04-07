///////////////////////////////////////////////////////////
//  GRenderWin.h
//  Окно для отображения геометрии с тулбарами
//  Created on:      9-окт-2014 17:59
//  Original author: Anton
///////////////////////////////////////////////////////////

#ifndef GRENDERWIN_H
#define GRENDERWIN_H

#include "QtGRenderWidget.h"

#include <QtWidgets/QtWidgets>

class GRenderWin : public QMainWindow
{
    Q_OBJECT

public:
    GRenderWin(bool registerCamera, bool isWidget, QWidget *parent = 0);
    GRenderWin(QWidget *parent = 0);//isWidget = false, registerCamera=true
   
    /**
     *  Центральный виджет с геометрией
     */
    QtGRenderWidget *_render;

    /**
     * Установить флаг "Закрыть окно, если оно прячется"
     */
    void SetCloseOnHide(bool flag);

signals:

    /**
        *  Сигнал изменения видимости
        */
    void VisibilityChanged(bool isVisible);

    /**
        *  Сигнал "Обратного вызова"
        */
    void CallbackSignal(Gepard::Visualization::GCallbackMessage _message);

    /**
        *  Изменился размер окна
        */
    void SizeChanged(int nWidth, int nHeight);

protected:

    /**
     *  Событие, когда форма отображается
     */
    void showEvent(QShowEvent *_event) override;

    /**
     *  Событие, когда форма закрывается
     */
    void hideEvent ( QHideEvent *_event ) override;

    /**
     *  Закрывать ли окно, если оно прячется
     */
    bool isCloseOnHide;

protected slots:

    /**
     *  Центрирование сдвига камеры
     */
    void DropCamShift();

    /**
     *  Центрирование камеры
     */
    void CenterCamShift();

private:

    /**
     *  Инициализация окна
     */
    void Init(bool registerCamera, bool isWidget, QWidget *parent);
};

#endif