#include "CMovements.h"


CMovements::CMovements(EMovementTypes movType, QString name ,/*Gepard::BasicMath::*/GPDVector axis, double shift, int start, int end)
    : m_moveType(movType), m_name(name),m_axis(axis),m_shift(shift),m_start(start),m_end(end)
{
    if (end>start)
    {
        m_start=0;
        m_end=1;
    }
}

CMovements::CMovements( const CMovements& copy)
{
    m_moveType=copy.m_moveType;
	m_name = copy.m_name;
    m_axis=copy.m_axis;
    m_end=copy.m_end;
    m_shift=copy.m_shift;
    m_start=copy.m_start;
}

CMovements::~CMovements()
{
}

void CMovements::SetMovementType(EMovementTypes movType)
{
    m_moveType=movType;
}

void CMovements::SetMoveName(QString newName)
{
	m_name.clear();
	m_name = newName;
}

QString CMovements::GetMoveName()
{
	return m_name;
}


void CMovements::SetShift(double shift)
{
    m_shift=shift;
}

void CMovements::SetAxis(Gepard::BasicMath::GPDVector axis)
{
    m_axis = axis;
}

int CMovements::GetStart()
{
    return m_start;
}

void CMovements::SetStart(int start)
{
    if (start>m_end)
    {
        return;
    }
    m_start=start;
}

void CMovements::SetEnd(int end)
{
    if (end<m_start)
    {
        return;
    }
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



