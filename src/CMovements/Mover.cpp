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

int CMover::AddMovement(EMovementTypes movType, string name, double shift, GPDPoint point, GPDVector axis, int start = 0, int end = 1, string axisName = "", Gepard::Topology_Geometry::GPDFace* _facePtr=nullptr)
{
	m_movementsVector.push_back(CMovements(movType, name, shift, point, axis, start, end, axisName, _facePtr));
    return m_movementsVector.size();
}

int CMover::GetStepsCntForMovement(int movementId)
{
    return m_movementsVector.at(movementId).GetStepsCnt();
}

//посчитать новый репер тела в зависимости от движения
void CMover::CalcReper(int movement, Gepard::BasicMath::GPDReper &oldRep, Gepard::BasicMath::GPDReper &newRep)
{
    CMovements move = m_movementsVector.at(movement);
    int steps = move.GetStepsCnt();

    GPDReper rep = m_part->SolidReper;
    oldRep = rep;
    int start = move.GetStart();
    int end = move.GetEnd();
    double _oneStepShift = move.GetMovePerStep();

	double _resultShift = _oneStepShift;

    if (move.GetMovementType() == EMovementTypes::CIRCULAR)
    {
        GPDReper mReper;
		mReper.R  = move.GetPoint().toVector();
		mReper.E1 = move.GetAxis();
		mReper.E2.setCoords(-mReper.E1.y, mReper.E1.x, mReper.E1.z);
		mReper.E3 = mReper.E1 * mReper.E2;
		rep.Transform(GPDReper::getGlobalReper(), mReper);
        mReper.morphByAngleAndAxis(move.GetAxis(), _resultShift);
		rep.Transform(mReper, GPDReper::getGlobalReper());
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
    CalcReper(movement, repOld, repNew);

    TModifyPointsFunc f = [repOld, repNew](Gepard::BasicMath::GPDPoint2d, Gepard::BasicMath::GPDPoint &P)
    {
        P.Transform(GPDReper::getGlobalReper(), const_cast<GPDReper&>(repOld));
        P.Transform(const_cast<GPDReper&>(repNew), GPDReper::getGlobalReper());
    };

    return f;
}

void CMover::OneStepMove(int movement)
{
    GPDReper repOld, repNew;
    CalcReper(movement, repOld, repNew);
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

void CMover::SetPartReper(GPDReper  rep)
{
	m_part->UpdateSolidPosition(rep);
}

void CMover::setPartName(std::string name)
{
	m_partName = name;
}

std::string CMover::getPartName()
{
	return m_partName;
}

void CMover::cutMovements()
{
	vector <CMovements> newMovementsVector;
	CMovements oldMovement;
	CMovements newMovement;
	int stepsCnt;

	//Разрезаем движения
	for (int i = 0; i < m_movementsVector.size(); i++)
	{
		oldMovement = m_movementsVector[i];

		stepsCnt = oldMovement.GetStepsCnt();

		for (int j = 0; j < stepsCnt; j++)
		{

			//Выдергиваем шаги из движения
			newMovement.SetMoveName(oldMovement.GetMoveName()+"_"+ std::to_string(j));             //Копируем имя
			newMovement.SetMovementType(oldMovement.GetMovementType());                            //Копируем тип
			if (newMovement.GetMovementType() == CIRCULAR)
			{
				newMovement.SetShift(oldMovement.GetDegrees() / stepsCnt);
			}
			else
			{
				newMovement.SetShift(oldMovement.GetShift() / stepsCnt);                           //Копируем часть сдвига в области периода
			}
			newMovement.SetAxis(oldMovement.GetAxis());                                            //Копируем ось
			newMovement.SetPoint(oldMovement.GetPoint());                                          //Точку
			newMovement.SetStart(oldMovement.GetStart()+j);                                        //Присваиваем начало равное начальной точке периода      
			newMovement.SetEnd(newMovement.GetStart()+1);                                           //Присваиваем конец равный конечной точке периода
			newMovement.setAxisName(oldMovement.getAxisName());                                    //копируем имя оси
			newMovement.setFace(oldMovement.getFace());                                            //Копируем поверхность

			newMovementsVector.push_back(newMovement);
		}
	}

	m_movementsVector.swap(newMovementsVector);

}

int CMover::getStart()
{
	int start = m_movementsVector[0].GetStart();

	for (int i = 0; i < m_movementsVector.size(); i++)
	{
		if (start > m_movementsVector[i].GetStart())
		{
			start = m_movementsVector[i].GetStart();
		}
	}

	return start;
}

int CMover::getEnd()
{
	int end = m_movementsVector[0].GetEnd();

	for (int i = 0; i < m_movementsVector.size(); i++)
	{
		if (end < m_movementsVector[i].GetEnd())
		{
			end = m_movementsVector[i].GetEnd();
		}
	}

	return end;
}

void CMover::sortMovements()
{
	//Сделали cutMovements

	std::sort(m_movementsVector.begin(), m_movementsVector.end(), [](CMovements &A, CMovements &B)->bool 
	{
		return (A.GetStart() < B.GetStart());
	});

}
