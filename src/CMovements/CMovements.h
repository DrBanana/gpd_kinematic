
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
	/*Gepard::BasicMath::*/GPDVector m_axis;
    //������ �������� �� ���������
    int m_start;
    //����� �������� �� ���������
    int m_end;
public:
    
     //	�����������, ���������������� ��� ��������� �� ���������
     // ���� start<end, �� ������ �������� �� ���������
     
	CMovements(EMovementTypes = EMovementTypes::LINEAR, QString = " ",/*Gepard::BasicMath::*/GPDVector = /*Gepard::BasicMath::*/GPDVector(0, 0, 0), double = 0.0, int = 0, int = 1);
    
    
     //	����������� �����������
     
    CMovements(const CMovements&);
    
     //	����������
     
    virtual ~CMovements();
    
     //	������ ��� ��������
     
    void SetMovementType(EMovementTypes);
    EMovementTypes GetMovementType();
    /*
     *	������ �������� ��� ���� � ����������� �� ���� ��������
     */
void SetShift(double);
	// ������ ���
	void SetMoveName(QString);

	//�������� ���

	QString GetMoveName();
    
     //	������ �������� ��� ���� � ����������� �� ���� ��������
     
    
    /*
     *	������ ���
     */
    void SetAxis(GPDVector);
    GPDVector GetAxis();
    /*
     *	������ ������ �������� �� ���������
     *  ���� �������� ������ m_end, ������ �� ����������
     */
    void SetStart(int);
    
    //	�������� ������ �������� �� ���������
     
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
};

#endif //CMOVEMENTS_H