//#pragma once

#ifndef MOVER_H
#define MOVER_H

#include "CMovements\CMovements.h"
#include "..\includes\gepard.h"
#include <algorithm>
#include <vector>  

using namespace std;


 // ласс "двигатель"
 
class CMover
{
private:
    
    Gepard::Topology_Geometry::GPDSolid *m_part;
    vector<CMovements> m_movementsVector;
public:
    

    CMover(Gepard::Topology_Geometry::GPDSolid *);
    virtual ~CMover(void);
    
    /*
     *	задать деталь
     */
    void SetPart(Gepard::Topology_Geometry::GPDSolid*);

    /*
    * ѕолучить ссылку на деталь
    */
    Gepard::Topology_Geometry::GPDSolid * GetPart();

    /*
     *	добавить перемещение
     */
    int AddMovement(CMovements);
    int AddMovement(EMovementTypes,Gepard::BasicMath::GPDPoint, string,Gepard::BasicMath::GPDVector,double,int=0,int=1);

    ////////////////////////////////
    // Method:    GetMovementAt
    // FullName:  CMover::GetMovementAt
    // Access:    public 
    // Returns:   CMovements
    // Qualifier:
    // Parameter: int pos Ќомер движени€ в списке, которое хотим получить
    ////////////////////////////////
    CMovements* GetMovementAt(int pos);

    CMovements* GetFirstMovement();

    int GetSizeOfmovementsVector();

    void SetMovementsVector(vector<CMovements>);
   
    void MoveIt(int);
    void MoveAll();
    void OneStepMove(int movement,int stp);
    int GetStepsCntForMovement(int movementId);
};

#endif //MOVER_H
