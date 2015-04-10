
#pragma once

#include <Gepard/Callbacks/CB_GeometryRender.h>
#include <Gepard/Topology_Geometry/GPDSolid.h>

#include <QtWidgets/QDialog>
#include <QtGui>

using namespace Gepard::Visualization;

/**
 *	����� ������� ������� ���������� �������� ������
 */
class AddMovementDlg : public QDialog,
                              Gepard::Callbacks::GeometryRenderCallback
{
    Q_OBJECT

public:

    AddMovementDlg(QWidget *parent = 0);

    /**
    *  ����������� ������� ��������� ������ - ������� �� �������� ������������
    */
    void renderCallbackEvent(Gepard::Visualization::GCallbackMessage _message) override;

signals:

    void addMovementSignal(Gepard::Topology_Geometry::GPDSolid *solidPtr);


};
