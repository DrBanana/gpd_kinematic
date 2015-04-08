#include "CMovements.h"


CMovements::CMovements(EMovementTypes movType,GPDVector axis,double shift,int start,int end)
    : m_moveType(movType),m_axis(axis),m_shift(shift),m_start(start),m_end(end)
{
    if (end>start)
    {
        m_start=0;
        m_end=1;
    }
}

CMovements::~CMovements()
{
}

void CMovements::SetMovementType(EMovementTypes movType)
{
    m_moveType=movType;
}

void CMovements::SetShift(double shift)
{
    m_shift=shift;
}

void CMovements::SetAxis(GPDVector axis)
{
    m_axis = axis;
}

int CMovements::GetStart()
{
    return m_start;
}

void CMovements::SetStart(int start)
{
    m_start=start;
}

void CMovements::SetEnd(int end)
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


