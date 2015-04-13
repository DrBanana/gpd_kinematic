#include "Mover.h"


CMover::CMover(GPDSolid *part)
    : m_part(part)
{
}

CMover::~CMover(void)
{
}

void CMover::SetPart(GPDSolid *part)
{
    m_part=part;
}

int CMover::AddMovement( CMovements movement)
{
m_movementsVector.push_back(movement);
return m_movementsVector.size();
}

int CMover::AddMovement(EMovementTypes movType, QString name, GPDVector axis, double shift, int start, int end)
{
    m_movementsVector.push_back(CMovements(movType, name,axis,shift,start,end));
    return m_movementsVector.size();
}

void CMover::Move()
{

}

/////////////////////////////////////
// Method:    GetMovementAt
// FullName:  CMover::GetMovementAt
// Access:    public 
// Returns:   CMovements*
// Qualifier:
// Parameter: int pos
/////////////////////////////////////
CMovements* CMover::GetMovementAt( int pos )
{
    return &m_movementsVector.at(pos);
}

CMovements* CMover::GetFirstMovement()
{
    return &m_movementsVector.at(0);
}

int CMover::GetSizeOfmovementsVector()
{
    return m_movementsVector.size();
}
