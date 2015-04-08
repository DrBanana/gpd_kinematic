#pragma once
#include "CMovements.h"
#include "..\includes\gepard.h"
#include <algorithm>
#include <vector>  
using namespace Gepard::Topology_Geometry;
using namespace std;

/*
 *	Класс "двигатель"
 */
class CMover
{
private:
    /*
     *	ссылко на деталь
     */
    GPDSolid &m_part;
    /*
     *	коллекция движения для тела
     */
    vector<CMovements> m_movementsVector;
public:
    /*
     *	конструктор
     */
    CMover(GPDSolid &);
    virtual ~CMover(void);
    /*
     *	задать деталь
     */
    void SetPart(GPDSolid&);
    /*
     *	добавить перемещение
     */
    int AddMovement(EMovementTypes,GPDVector,double,int=0,int=1);
};

