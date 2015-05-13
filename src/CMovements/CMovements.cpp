#include "CMovements.h"
#include <string>

using namespace Gepard::BasicMath;
using namespace Gepard::Topology_Geometry;
using namespace std;
// CMovements::CMovements(EMovementTypes movType, 
//                         QString name ,
//                         GPDVector axis, 
//                         double shift, 
//                         int start, 
//                         int end)
//     : m_moveType(movType), 
//     m_name(name),
//     m_axis(axis),
//     m_shift(shift),
//     m_start(start),
//     m_end(end)
// {
//     if (end>start)
//     {
//         m_start=0;
//         m_end=1;
//     }
// }

CMovements::CMovements(EMovementTypes movType,
                        string name,
						double shift,
						GPDPoint point,
                        GPDVector axis, 
                        int start, 
                        int end,
						string axisName,
						Gepard::Topology_Geometry::GPDFace * prtFace)
    : m_moveType(movType),
    m_name(name),
	m_shift(shift),
	m_point(point),
    m_axis(axis),
    m_start(start),
    m_end(end),
	m_axisName(axisName),
	m_prtFace(prtFace)
{
    if (end<start)
    {
        m_start=0;
        m_end=1;
    }
}

// CMovements::CMovements( const CMovements& copy)
// {
//     m_moveType=copy.m_moveType;
//     m_name = copy.m_name;
//     m_axis=copy.m_axis;
//     m_end=copy.m_end;
//     m_shift=copy.m_shift;
//     m_start=copy.m_start;
// 	m_axisName = copy.m_axisName;
// 
// }

CMovements::~CMovements()
{
}

void CMovements::SetMovementType(EMovementTypes movType)
{
    m_moveType=movType;
}

void CMovements::SetMoveName(std::string newName)
{
    m_name.clear();
    m_name = newName;
}

std::string CMovements::GetMoveName()
{
    return m_name;
}

void CMovements::SetShift(double shift)
{
    m_shift=shift;
}
double CMovements::GetShift()
{
    if (m_moveType==CIRCULAR)
    {
        return ((m_shift*Gepard::BasicMath::Pi)/180.0);
    }
    return m_shift;
}

double CMovements::GetDegrees()
{
	return m_shift;
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

    //»з-за проверки невозможно установить начало больше 0, т.к. создаетс€ экземпл€р со значением m_end = 1, при установек m_start > 1 ничего не произойдет
//     if (start>m_end)
//     {
//         return;
//     }
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

double CMovements::GetMovePerStep()
{
    double len = m_end-m_start;
    return (GetShift()/len);
}

int CMovements::GetStepsCnt()
{
    return m_end-m_start;
}

EMovementTypes CMovements::GetMovementType()
{
    return m_moveType;
}

Gepard::BasicMath::GPDVector CMovements::GetAxis()
{
    return m_axis;
}



Gepard::BasicMath::GPDPoint CMovements::GetPoint()
{
    return m_point;
}

void CMovements::SetPoint( GPDPoint point)
{
    m_point=point;
}

void CMovements::setAxisName(string newName)
{
	m_axisName.clear();
	m_axisName = newName;
}

std::string CMovements::getAxisName()
{
	return m_axisName;
}

void CMovements::setFace(Gepard::Topology_Geometry::GPDFace * prtFace)
{
	m_prtFace = prtFace;
}

Gepard::Topology_Geometry::GPDFace * CMovements::getFace()
{
	return m_prtFace;
}

void CMovements::Update()
{
	Gepard::BasicMath::GPDVector shiftStart;
	Gepard::Topology_Geometry::GPDReper newRep;

	newRep = m_prtFace->GetFaceReper();

	shiftStart = newRep.R;

	GPDPoint newPoint(shiftStart.x, shiftStart.y, shiftStart.z);

	m_point = newPoint;

	
}




