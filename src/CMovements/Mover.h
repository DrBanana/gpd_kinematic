//#pragma once

#ifndef MOVER_H
#define MOVER_H

#include "CMovements\CMovements.h"
#include "..\includes\gepard.h"

#include <algorithm>
#include <vector>  
#include <functional>
#include<string>

using namespace std;

 //����� "���������"
 
class CMover
{
private:
    
    Gepard::Topology_Geometry::GPDSolid *m_part;
	std::string m_partName;
    vector<CMovements> m_movementsVector;
public:
    

    CMover(Gepard::Topology_Geometry::GPDSolid *);
    virtual ~CMover(void);
    
    /*
     *	������ ������
     */
    void SetPart(Gepard::Topology_Geometry::GPDSolid*);

	void SetPartReper(Gepard::BasicMath::GPDReper);

    /*
    * �������� ������ �� ������
    */
    Gepard::Topology_Geometry::GPDSolid * GetPart();

    /*
     *	�������� �����������
     */
    int AddMovement(CMovements);
	int AddMovement(EMovementTypes, string, double, Gepard::BasicMath::GPDPoint, Gepard::BasicMath::GPDVector, int, int, string, Gepard::Topology_Geometry::GPDFace*);

    ////////////////////////////////
    // Method:    GetMovementAt
    // FullName:  CMover::GetMovementAt
    // Access:    public 
    // Returns:   CMovements
    // Qualifier:
    // Parameter: int pos ����� �������� � ������, ������� ����� ��������
    ////////////////////////////////
    CMovements* GetMovementAt(int pos);

    CMovements* GetFirstMovement();

    int GetSizeOfmovementsVector();

    void SetMovementsVector(vector<CMovements>);
   
    void MoveIt(int);
    void MoveAll();
    void OneStepMove(int movement);
    int GetStepsCntForMovement(int movementId);

    //�������� ������� ������� ��������� ����
    Gepard::BasicMath::TModifyPointsFunc getModFunc(int movement, int stp);

    //��������� ����� ����� ���� � ����������� �� ��������
    void CalcReper(int movement, Gepard::BasicMath::GPDReper &oldRep, Gepard::BasicMath::GPDReper &newRep);

	void setPartName(std::string);
	std::string getPartName();

	void cutMovements();

	int getStart();
	int getEnd();

	void sortMovements();
};

#endif //MOVER_H
