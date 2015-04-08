#pragma once
#include "..\includes\gepard.h"
using namespace Gepard::Topology_Geometry;

/*
 *	ѕеречисление типов движени€
 */
enum EMovementTypes
{
    LINEAR,
    CIRCULAR
};

/*
 *	 ласс ƒвижений
 */
class CMovements
{
private:
    //“ип движени€ из enum EMovementTypes
    EMovementTypes m_moveType;
    //—мещение или угол на который надо повернуть деталь
    double m_shift; 
    //ќсь вдоль которой будет происходить смещение или ось вокруг которой будет вращатьс€ тело
    GPDVector m_axis;
    //Ќачало движени€ на таймлайне
    int m_start;
    //конец движени€ на таймлайне
    int m_end;
public:
    /*
     *	конструктор, инициализирующий все параметры по умолчанию
     *  если start<end, то ставит значени€ по умолчанию
     */
    CMovements(EMovementTypes=EMovementTypes::LINEAR,GPDVector=GPDVector(0,0,0),double=0.0,int=0,int=1);
    /*
     *	деструктор
     */
    virtual ~CMovements();
    /*
     *	«адать тип движени€
     */
    void SetMovementType(EMovementTypes);
    /*
     *	задать смещение или угол в зависимости от типа движени€
     */
    void SetShift(double);
    /*
     *	задать ось
     */
    void SetAxis(GPDVector);
    /*
     *	задать начало движени€ на таймлайне
     */
    void SetStart(int);
    /*
     *	получить начало движени€ на таймлайне
     */
    int GetStart();
    /*
     *	задать конец движени€ на таймлайне
     */
    void SetEnd(int);
    /*
     *	получить конец движени€ на таймлайне
     */
    int GetEnd();
    /*
     *	получить сдвиг на один шаг
     */
    int GetMovePerStep();
    /*
     *	получить количество шагов
     */
    int GetStepsCnt();
};