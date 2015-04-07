#include "CMovements.h"


CMovements::CMovements( GPDSolid &part )
    : m_part(part)
{
    
}

CMovements::~CMovements()
{

}

void CMovements::SetMovementType( EMovementTypes movType )
{
    m_moveType=movType;
}

void CMovements::SetShift( double shift )
{
    m_shift=shift;
}

void CMovements::SetAxis( GPDVector axis )
{
    m_axis = axis;
}

void CMovements::SetPart( GPDSolid &part )
{
    m_part=part;
}

void CMovements::Move()
{
//     switch (m_moveType)
//         case UMovementTypes::LINEAR:
//                         break;
// 
//         case UMovementTypes::CIRCULAR:
//                         break;
//         default:
//             break;
}

int CMovements::GetStart()
{
    return m_start;
}

void CMovements::SetStart( int start)
{
    m_start=start;
}

void CMovements::SetEnd( int end)
{
    m_end=end;
}

int CMovements::GetEnd()
{
    return m_end;
}

int CMovements::GetMovePerStep()
{
    int len = m_end-m_start;
    return m_shift/len;
}

int CMovements::GetStepsCnt()
{
    return m_end-m_start;
}


