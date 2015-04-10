#pragma once
#include <CMovements\CMovements.h>
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
   Gepard::Topology_Geometry::GPDSolid &m_part;
    /*
     *	коллекция движения для тела
     */
   vector<CMovements> m_movementsVector;
public:
    /*
     *	конструктор
     */
	CMover(Gepard::Topology_Geometry::GPDSolid &);
    virtual ~CMover(void);
    /*
     *	задать деталь
     */
	void SetPart(Gepard::Topology_Geometry::GPDSolid&);
    /*
     *	добавить перемещение
     */
    int AddMovement(EMovementTypes,Gepard::BasicMath::GPDVector,double,int=0,int=1);

    int AddMovement(CMovements);

    //************************************
    // Method:    GetMovementAt
    // FullName:  CMover::GetMovementAt
    // Access:    public 
    // Returns:   CMovements
    // Qualifier:
    // Parameter: int pos Номер движения в списке, которое хотим получить
    //************************************
    CMovements* GetMovementAt(int pos);

    CMovements* GetFirstMovement();

    int GetSizeOfmovementsVector();
   
    void Move();
};

