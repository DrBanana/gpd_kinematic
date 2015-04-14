
#ifndef CMOVEMENTS_H
#define CMOVEMENTS_H

#include "..\includes\gepard.h"
#include <QString>
using namespace Gepard::BasicMath;


 //	������������ ����� ��������
 
enum EMovementTypes
{
    LINEAR,
    CIRCULAR
};

//	����� ��������
 
class CMovements
{
private:
    //��� �������� �� enum EMovementTypes
    EMovementTypes m_moveType;
    //��� ��������
    QString m_name;
    //�������� ��� ���� �� ������� ���� ��������� ������
    double m_shift; 
    //��� ����� ������� ����� ����������� �������� ��� ��� ������ ������� ����� ��������� ����
    GPDVector m_axis;
    //����� ������ ������� ���� ������� ����
    GPDPoint m_point;
    //������ �������� �� ���������
    int m_start;
    //����� �������� �� ���������
    int m_end;
public:
    
     /*
      *  �����������, ���������������� ��� ��������� �� ���������
      *  ���� start<end, �� ������ �������� �� ���������
      */
    CMovements(EMovementTypes = EMovementTypes::LINEAR,
                GPDPoint = GPDPoint(0,0,0),
                QString = " ",
                GPDVector = GPDVector(0, 0, 0),
                double = 0.0,
                int = 0,
                int = 1);
    /*
     *  �����������, ���������������� ��� ��������� �� ���������
     *  ���� start<end, �� ������ �������� �� ���������
     */
//     CMovements(EMovementTypes = EMovementTypes::CIRCULAR,
//         GPDPoint = GPDPoint(0,0,0), 
//         QString = " ",
//         GPDVector = GPDVector(0, 0, 0),
//         double = 0.0,
//         int = 0,
//         int = 1);

    /*
     *	����������� �����������
     */
    CMovements(const CMovements&);
    virtual ~CMovements();
    /*
     *	������ ��� ��������
     */ 
    void SetMovementType(EMovementTypes);

    EMovementTypes GetMovementType();
    /*
     *	������ �������� ��� ���� � ����������� �� ���� ��������
     */
    void SetShift(double);
    /*
     *	�������� �������� ��� ���� � ����������� �� ���� ��������
     */
    double GetShift();

    // ������ ���
    void SetMoveName(QString);

    //�������� ���

    QString GetMoveName();
    
    /*
     *	������ ���
     */
    void SetAxis(GPDVector);
    /*
     *	�������� ���
     */
    GPDVector GetAxis();

    /*
     *	������ ������ �������� �� ���������
     *  ���� �������� ������ m_end, ������ �� ����������
     */
    void SetStart(int);
    
    /*
     *	�������� ������ �������� �� ���������
     */	
     
    int GetStart();
    
     //	������ ����� �������� �� ���������
     // ���� �������� ������ m_start, ������ �� ����������
     
    void SetEnd(int);
    
     //	�������� ����� �������� �� ���������
     
    int GetEnd();
    
     //	�������� ����� �� ���� ���
     
    int GetMovePerStep();
    
     //	�������� ���������� �����
     
    int GetStepsCnt();
    /*
     *	������ �����
     */
    GPDPoint GetPoint();
    /*
     *	�������� �����
     */
    void SetPoint(GPDPoint);
};

#endif //CMOVEMENTS_H