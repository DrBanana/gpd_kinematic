#pragma once
#include "CMovements.h"
#include "..\includes\gepard.h"
#include <algorithm>
#include <vector>  
using namespace Gepard::Topology_Geometry;
using namespace std;

/*
 *	����� "���������"
 */
class CMover
{
private:
    /*
     *	������ �� ������
     */
    GPDSolid &m_part;
    /*
     *	��������� �������� ��� ����
     */
    vector<CMovements> m_movementsVector;
public:
    /*
     *	�����������
     */
    CMover(GPDSolid &);
    virtual ~CMover(void);
    /*
     *	������ ������
     */
    void SetPart(GPDSolid&);
    /*
     *	�������� �����������
     */
    int AddMovement(EMovementTypes,GPDVector,double,int=0,int=1);

    int AddMovement(CMovements);

    //************************************
    // Method:    GetMovementAt
    // FullName:  CMover::GetMovementAt
    // Access:    public 
    // Returns:   CMovements
    // Qualifier:
    // Parameter: int pos ����� �������� � ������, ������� ����� ��������
    //************************************
    CMovements* GetMovementAt(int pos);

    CMovements* GetFirstMovement();

    int GetSizeOfmovementsVector();
   
    void Move();
};

