#pragma once
#include "..\includes\gepard.h"
using namespace Gepard::Topology_Geometry;

/*
 *	������������ ����� ��������
 */
enum EMovementTypes
{
    LINEAR,
    CIRCULAR
};

/*
 *	����� ��������
 */
class CMovements
{
private:
    //��� �������� �� enum EMovementTypes
    EMovementTypes m_moveType;
    //�������� ��� ���� �� ������� ���� ��������� ������
    double m_shift; 
    //��� ����� ������� ����� ����������� �������� ��� ��� ������ ������� ����� ��������� ����
    GPDVector m_axis;
    //������ �������� �� ���������
    int m_start;
    //����� �������� �� ���������
    int m_end;
public:
    /*
     *	�����������, ���������������� ��� ��������� �� ���������
     *  ���� start<end, �� ������ �������� �� ���������
     */
    CMovements(EMovementTypes=EMovementTypes::LINEAR,GPDVector=GPDVector(0,0,0),double=0.0,int=0,int=1);
    
    /*
     *	����������� �����������
     */
    CMovements(const CMovements&);
    /*
     *	����������
     */
    virtual ~CMovements();
    /*
     *	������ ��� ��������
     */
    void SetMovementType(EMovementTypes);
    /*
     *	������ �������� ��� ���� � ����������� �� ���� ��������
     */
    void SetShift(double);
    /*
     *	������ ���
     */
    void SetAxis(GPDVector);
    /*
     *	������ ������ �������� �� ���������
     *  ���� �������� ������ m_end, ������ �� ����������
     */
    void SetStart(int);
    /*
     *	�������� ������ �������� �� ���������
     */
    int GetStart();
    /*
     *	������ ����� �������� �� ���������
     *  ���� �������� ������ m_start, ������ �� ����������
     */
    void SetEnd(int);
    /*
     *	�������� ����� �������� �� ���������
     */
    int GetEnd();
    /*
     *	�������� ����� �� ���� ���
     */
    int GetMovePerStep();
    /*
     *	�������� ���������� �����
     */
    int GetStepsCnt();
};