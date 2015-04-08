#include "Mover.h"


CMover::CMover(GPDSolid &part)
    : m_part(part)
{
}

CMover::~CMover(void)
{
}

void CMover::SetPart( GPDSolid &part )
{
    m_part=part;
}

int CMover::AddMovement(EMovementTypes movType,GPDVector axis,double shift,int start,int end )
{
    m_movementsVector.push_back(CMovements(movType,axis,shift,start,end));
    return m_movementsVector.size();
}

