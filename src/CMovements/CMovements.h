#pragma once
#include "..\includes\gepard.h"
using namespace Gepard::Topology_Geometry;

enum EMovementTypes
{
    LINEAR,
    CIRCULAR
};

class CMovements
{
private:
    GPDSolid &m_part;
    EMovementTypes m_moveType;
    double m_shift;
    GPDVector m_axis;
    int m_start;
    int m_end;
public:
    CMovements(GPDSolid&);
    ~CMovements();
    void SetMovementType(EMovementTypes);
    void SetShift(double);
    void SetAxis(GPDVector);
    void SetPart(GPDSolid&);
    void SetStart(int);
    int GetStart();
    void SetEnd(int);
    int GetEnd();
    int GetMovePerStep();
    int GetStepsCnt();
    void Move();
};