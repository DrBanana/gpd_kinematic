
#ifndef CMOVEMENTS_H
#define CMOVEMENTS_H

#include "..\includes\gepard.h"
#include <QString>
using namespace Gepard::BasicMath;


 //	ѕеречисление типов движени€
 
enum EMovementTypes
{
    LINEAR,
    CIRCULAR
};


 //	 ласс ƒвижений
 
class CMovements
{
private:
    //“ип движени€ из enum EMovementTypes
    EMovementTypes m_moveType;
	//»м€ движени€
	QString m_name;
    //—мещение или угол на который надо повернуть деталь
    double m_shift; 
    //ќсь вдоль которой будет происходить смещение или ось вокруг которой будет вращатьс€ тело
	/*Gepard::BasicMath::*/GPDVector m_axis;
    //Ќачало движени€ на таймлайне
    int m_start;
    //конец движени€ на таймлайне
    int m_end;
public:
    
     //	конструктор, инициализирующий все параметры по умолчанию
     // если start<end, то ставит значени€ по умолчанию
     
	CMovements(EMovementTypes = EMovementTypes::LINEAR, QString = " ",/*Gepard::BasicMath::*/GPDVector = /*Gepard::BasicMath::*/GPDVector(0, 0, 0), double = 0.0, int = 0, int = 1);
    
    
     //	конструктор копировани€
     
    CMovements(const CMovements&);
    
     //	деструктор
     
    virtual ~CMovements();
    
     //	«адать тип движени€
     
    void SetMovementType(EMovementTypes);

	// «адать им€

	void SetMoveName(QString);

	//ѕолучить им€

	QString GetMoveName();
    
     //	задать смещение или угол в зависимости от типа движени€
     
    void SetShift(double);
    
     //	задать ось
     
	void SetAxis(/*Gepard::BasicMath::*/GPDVector);
    
     //	задать начало движени€ на таймлайне
     // если значение больше m_end, ничего не происходит
     
    void SetStart(int);
    
    //	получить начало движени€ на таймлайне
     
    int GetStart();
    
     //	задать конец движени€ на таймлайне
     // если значение меньше m_start, ничего не происходит
     
    void SetEnd(int);
    
     //	получить конец движени€ на таймлайне
     
    int GetEnd();
    
     //	получить сдвиг на один шаг
     
    int GetMovePerStep();
    
     //	получить количество шагов
     
    int GetStepsCnt();
};

#endif //CMOVEMENTS_H