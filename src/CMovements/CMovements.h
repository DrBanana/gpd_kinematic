
#ifndef CMOVEMENTS_H
#define CMOVEMENTS_H

#include "..\includes\gepard.h"
#include <QString>
using namespace Gepard::BasicMath;


 //	Перечисление типов движения
 
enum EMovementTypes
{
    LINEAR,
    CIRCULAR
};


 //	Класс Движений
 
class CMovements
{
private:
    //Тип движения из enum EMovementTypes
    EMovementTypes m_moveType;
	//Имя движения
	QString m_name;
    //Смещение или угол на который надо повернуть деталь
    double m_shift; 
    //Ось вдоль которой будет происходить смещение или ось вокруг которой будет вращаться тело
	/*Gepard::BasicMath::*/GPDVector m_axis;
    //Начало движения на таймлайне
    int m_start;
    //конец движения на таймлайне
    int m_end;
public:
    
     //	конструктор, инициализирующий все параметры по умолчанию
     // если start<end, то ставит значения по умолчанию
     
	CMovements(EMovementTypes = EMovementTypes::LINEAR, QString = " ",/*Gepard::BasicMath::*/GPDVector = /*Gepard::BasicMath::*/GPDVector(0, 0, 0), double = 0.0, int = 0, int = 1);
    
    
     //	конструктор копирования
     
    CMovements(const CMovements&);
    
     //	деструктор
     
    virtual ~CMovements();
    
     //	Задать тип движения
     
    void SetMovementType(EMovementTypes);
    EMovementTypes GetMovementType();
    /*
     *	задать смещение или угол в зависимости от типа движения
     */
void SetShift(double);
	// Задать имя
	void SetMoveName(QString);

	//Получить имя

	QString GetMoveName();
    
     //	задать смещение или угол в зависимости от типа движения
     
    
    /*
     *	задать ось
     */
    void SetAxis(GPDVector);
    GPDVector GetAxis();
    /*
     *	задать начало движения на таймлайне
     *  если значение больше m_end, ничего не происходит
     */
    void SetStart(int);
    
    //	получить начало движения на таймлайне
     
    int GetStart();
    
     //	задать конец движения на таймлайне
     // если значение меньше m_start, ничего не происходит
     
    void SetEnd(int);
    
     //	получить конец движения на таймлайне
     
    int GetEnd();
    
     //	получить сдвиг на один шаг
     
    int GetMovePerStep();
    
     //	получить количество шагов
     
    int GetStepsCnt();
};

#endif //CMOVEMENTS_H