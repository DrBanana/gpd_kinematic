///////////////////////////////////////////////////////////
//  GRenderWin.h
//  ���� ��� ����������� ��������� � ���������
//  Created on:      9-���-2014 17:59
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
     *  ����������� ������ � ����������
     */
    QtGRenderWidget *_render;

    /**
     * ���������� ���� "������� ����, ���� ��� ��������"
     */
    void SetCloseOnHide(bool flag);

signals:

    /**
        *  ������ ��������� ���������
        */
    void VisibilityChanged(bool isVisible);

    /**
        *  ������ "��������� ������"
        */
    void CallbackSignal(Gepard::Visualization::GCallbackMessage _message);

    /**
        *  ��������� ������ ����
        */
    void SizeChanged(int nWidth, int nHeight);

protected:

    /**
     *  �������, ����� ����� ������������
     */
    void showEvent(QShowEvent *_event) override;

    /**
     *  �������, ����� ����� �����������
     */
    void hideEvent ( QHideEvent *_event ) override;

    /**
     *  ��������� �� ����, ���� ��� ��������
     */
    bool isCloseOnHide;

protected slots:

    /**
     *  ������������� ������ ������
     */
    void DropCamShift();

    /**
     *  ������������� ������
     */
    void CenterCamShift();

private:

    /**
     *  ������������� ����
     */
    void Init(bool registerCamera, bool isWidget, QWidget *parent);
};

#endif