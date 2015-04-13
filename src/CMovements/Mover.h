//#pragma once

#ifndef MOVER_H
#define MOVER_H

#include "CMovements\CMovements.h"
#include "..\includes\gepard.h"
#include <algorithm>
#include <vector>  
using namespace Gepard::Topology_Geometry;
using namespace std;


 //Класс "двигатель"
 
class CMover
{
private:
    
     //ссылко на деталь
     
    GPDSolid *m_part;
    
     //коллекция движения для тела
 
   vector<CMovements> m_movementsVector;
public:
    
     //	конструктор
     
	CMover(GPDSolid *);
    virtual ~CMover(void);
    
     //	задать деталь
     
	void SetPart(GPDSolid*);
    
     //	добавить перемещение
     
	int AddMovement(CMovements);

    int AddMovement(EMovementTypes, QString,GPDVector,double,int=0,int=1);

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
   
    void Move();
};

#endif //MOVER_H