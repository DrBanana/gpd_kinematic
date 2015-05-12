#include "Mover.h"
using namespace Gepard::BasicMath;
using namespace Gepard::Topology_Geometry;

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

int CMover::AddMovement(EMovementTypes movType, string name, double shift, GPDPoint point, GPDVector axis, int start=0, int end=1, string axisName="")
{
    m_movementsVector.push_back(CMovements(movType,name, shift, point,axis,start,end,axisName));
    return m_movementsVector.size();
}

int CMover::GetStepsCntForMovement(int movementId)
{
    return m_movementsVector.at(movementId).GetStepsCnt();
}

//посчитать новый репер тела в зависимости от движения
void CMover::CalcReper(int movement, int stp, Gepard::BasicMath::GPDReper &oldRep, Gepard::BasicMath::GPDReper &newRep)
{
    CMovements move = m_movementsVector.at(movement);
    int steps = move.GetStepsCnt();
    if (stp > steps || stp < 0)
    {
        return;
    }

    GPDReper rep = m_part->SolidReper;
    oldRep = rep;
    int start = move.GetStart();
    int end = move.GetEnd();
    double _oneStepShift = move.GetMovePerStep();

    double _resultShift = _oneStepShift*(stp + 1);

    if (move.GetMovementType() == EMovementTypes::CIRCULAR)
    {
        GPDReper mReper;
        mReper.R.setCoords(move.GetPoint().nx, move.GetPoint().ny, move.GetPoint().nz);
        mReper.morphByAngleAndAxis(move.GetAxis(), _resultShift);
        rep.Transform(GPDReper::getGlobalReper(), mReper);
    }
    else
    if (move.GetMovementType() == EMovementTypes::LINEAR)
    {
        GPDVector vec = move.GetAxis()*_resultShift;
        rep.R += vec;
    }

    newRep = rep;
}

//Получить текущую функцию изменения тела
Gepard::BasicMath::TModifyPointsFunc CMover::getModFunc(int movement, int stp)
{    
    GPDReper repOld, repNew;
    CalcReper(movement, stp, repOld, repNew);

    TModifyPointsFunc f = [repOld, repNew](Gepard::BasicMath::GPDPoint2d, Gepard::BasicMath::GPDPoint &P)
    {
        P.Transform(GPDReper::getGlobalReper(), const_cast<GPDReper&>(repOld));
        P.Transform(const_cast<GPDReper&>(repNew), GPDReper::getGlobalReper());
    };

    return f;
}

void CMover::OneStepMove(int movement,int stp)
{
    GPDReper repOld, repNew;
    CalcReper(movement, stp, repOld, repNew);
    m_part->UpdateSolidPosition(repNew);
}

void CMover::MoveIt(int pos)
{
    CMovements move = m_movementsVector.at(pos);
    GPDReper rep = m_part->SolidReper;
    if (move.GetMovementType()==EMovementTypes::CIRCULAR)
    {
       GPDReper mReper;
       mReper.R.setCoords(move.GetPoint().nx,move.GetPoint().ny,move.GetPoint().nz);
       mReper.morphByAngleAndAxis(move.GetAxis(),move.GetShift());
       rep.Transform(GPDReper::getGlobalReper(), mReper);
    }
    else
        if (move.GetMovementType()==EMovementTypes::LINEAR)
        {
            GPDVector vec = move.GetAxis()*move.GetShift();
            rep.R += vec;
        }
    m_part->UpdateSolidPosition(rep);
}

void CMover::MoveAll()
{
    int cnt = GetSizeOfmovementsVector();
    GPDReper rep = m_part->SolidReper;
    for (int i=0;i<cnt;i++)
    {
        CMovements move = m_movementsVector.at(i);
        if (move.GetMovementType()==EMovementTypes::CIRCULAR)
        {
            GPDReper mReper;
            mReper.R.setCoords(move.GetPoint().nx,move.GetPoint().ny,move.GetPoint().nz);
            mReper.morphByAngleAndAxis(move.GetAxis(),move.GetShift());
            rep.Transform(GPDReper::getGlobalReper(), mReper);
        }
        else
            if (move.GetMovementType()==EMovementTypes::LINEAR)
            {
                GPDVector vec = move.GetAxis()*move.GetShift();
                rep.R += vec;
            }
            m_part->UpdateSolidPosition(rep);
    }
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

void CMover::SetMovementsVector(vector<CMovements>  newVector)
{
    m_movementsVector.swap(newVector);
}

GPDSolid * CMover::GetPart()
{
    return m_part;
}
