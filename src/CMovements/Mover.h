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

 //Класс "двигатель"
 
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
     *	задать деталь
     */
    void SetPart(Gepard::Topology_Geometry::GPDSolid*);

	void SetPartReper(Gepard::BasicMath::GPDReper);

    /*
    * Получить ссылку на деталь
    */
    Gepard::Topology_Geometry::GPDSolid * GetPart();

    /*
     *	добавить перемещение
     */
    int AddMovement(CMovements);
	int AddMovement(EMovementTypes, string, double, Gepard::BasicMath::GPDPoint, Gepard::BasicMath::GPDVector, int, int, string, Gepard::Topology_Geometry::GPDFace*);

    ////////////////////////////////
    // Method:    GetMovementAt
    // FullName:  CMover::GetMovementAt
    // Access:    public 
    // Returns:   CMovements
    // Qualifier:
    // Parameter: int pos Номер движения в списке, которое хотим получить
    ////////////////////////////////
    CMovements* GetMovementAt(int pos);

    CMovements* GetFirstMovement();

    int GetSizeOfmovementsVector();

    void SetMovementsVector(vector<CMovements>);
   
    void MoveIt(int);
    void MoveAll();
    void OneStepMove(int movement);
    int GetStepsCntForMovement(int movementId);

    //Получить текущую функцию изменения тела
    Gepard::BasicMath::TModifyPointsFunc getModFunc(int movement, int stp);

    //посчитать новый репер тела в зависимости от движения
    void CalcReper(int movement, Gepard::BasicMath::GPDReper &oldRep, Gepard::BasicMath::GPDReper &newRep);

	void setPartName(std::string);
	std::string getPartName();

	void cutMovements();

	int getStart();
	int getEnd();

	void sortMovements();
};

#endif //MOVER_H
