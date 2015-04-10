
#include "AddMovementDlg.h"

#include <Gepard/Visualization/GCamera.h>
#include <Gepard/Visualization/GPDGeometryRender.h>

using namespace Gepard::Visualization;
using namespace Gepard::Callbacks;
using namespace Gepard::Topology_Geometry;

/**
 *	������� ���������� ��� ������
 */
QString GetSolidName(Gepard::Topology_Geometry::GPDSolid *_solidPtr)
{
    QString solName = _solidPtr->GetSolidName();

    QString _messageStr = solName.isEmpty() ? QDialog::tr("Solid") : solName;

    _messageStr += " (";
    _messageStr += QString::number(_solidPtr->GetSolidUIN());
    _messageStr += ")";

    return _messageStr;
}



AddMovementDlg::AddMovementDlg(QWidget *parent) 
    : QDialog(parent)    
{

}

/**
*  ����������� ������� ��������� ������ - ������� �� �������� ������������
*/
void AddMovementDlg::renderCallbackEvent(Gepard::Visualization::GCallbackMessage _message)
{
    if (!isVisible()) return;
    if (!_message._Object) return;

    if (_message._Object->_type == GODT_FACE)
    {
        GPDFace* _facePtr = (GPDFace*)_message._Object->ObjectData;
        if (!_facePtr) return;

        GPDSolid *solidPtr = _facePtr->parentSolidPtr;

        //�������� ����:
        GCamera* cam0 = GeometryRenderManager::GetCamera(0);
        GPDGeometryRender* render0 = (GPDGeometryRender*)cam0;
        render0->SetSolidSelection(solidPtr);
        

        //��� ��� ����� ������� ������ ����������:
        //��������� ��� �� �������� "�������� ��������"
        //emit addMovementSignal(solidPtr);

        qDebug() << "Solid name:" << GetSolidName(solidPtr) << " = "<< solidPtr;

        //ui.lineEdit_Object->setText(GetSolidName(solidPtr));

    }//if GODT_FACE

}