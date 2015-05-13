#ifndef CMOVEMENTS_H
#define CMOVEMENTS_H

#include "..\includes\gepard.h"
#include <string>
using namespace std;


//using namespace Gepard::BasicMath;


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
    string m_name;
    //—мещение или угол на который надо повернуть деталь
    double m_shift; 
    //ќсь вдоль которой будет происходить смещение или ось вокруг которой будет вращатьс€ тело
    Gepard::BasicMath::GPDVector m_axis;
    //“очка вокруг которой надо вращать тело
    Gepard::BasicMath::GPDPoint m_point;
    //Ќачало движени€ на таймлайне
    int m_start;
    //конец движени€ на таймлайне
    int m_end;
	//»м€ оси
	string m_axisName;
public:
    
     /*
      *  конструктор, инициализирующий все параметры по умолчанию
      *  если start<end, то ставит значени€ по умолчанию
      */
    CMovements(EMovementTypes = EMovementTypes::LINEAR,
				string = " ",
				double = 0.0,
                Gepard::BasicMath::GPDPoint = Gepard::BasicMath::GPDPoint(0,0,0),
				Gepard::BasicMath::GPDVector = Gepard::BasicMath::GPDVector(0, 0, 0),
                int = 0,
                int = 1,
				string = " "
				);
    /*
     *  конструктор, инициализирующий все параметры по умолчанию
     *  если start<end, то ставит значени€ по умолчанию
     */
//     CMovements(EMovementTypes = EMovementTypes::CIRCULAR,
//         Gepard::BasicMath::GPDPoint = Gepard::BasicMath::GPDPoint(0, 0, 0),
//         QString = " ",
//         Gepard::BasicMath::GPDVector = Gepard::BasicMath::GPDVector(0, 0, 0),
//         double = 0.0,
//         int = 0,
//         int = 1);

    /*
     *	конструктор копировани€
     */
   // CMovements(const CMovements&);
    virtual ~CMovements();
    /*
     *	«адать тип движени€
     */ 
    void SetMovementType(EMovementTypes);

    EMovementTypes GetMovementType();
    /*
     *	задать смещение или угол в зависимости от типа движени€
     */
    void SetShift(double);
    /*
     *	получить смещение или угол в зависимости от типа движени€
     */
    double GetShift();

	double GetDegrees();

    // «адать им€
    void SetMoveName(string);

    //ѕолучить им€

    string GetMoveName();
    
    /*
     *	задать ось
     */
    void SetAxis(Gepard::BasicMath::GPDVector);
    /*
     *	ѕолучить ось
     */
    Gepard::BasicMath::GPDVector GetAxis();

    /*
     *	задать начало движени€ на таймлайне
     *  если значение больше m_end, ничего не происходит
     */
    void SetStart(int);
    
    /*
     *	получить начало движени€ на таймлайне
     */	
     
    int GetStart();
    
     //	задать конец движени€ на таймлайне
     // если значение меньше m_start, ничего не происходит
     
    void SetEnd(int);
    
     //	получить конец движени€ на таймлайне
     
    int GetEnd();
    
     //	получить сдвиг на один шаг
     
    double GetMovePerStep();
    
     //	получить количество шагов
     
    int GetStepsCnt();
    /*
     *	«адать точку
     */
    Gepard::BasicMath::GPDPoint GetPoint();
    /*
     *	ѕолучить точку
     */
    void SetPoint(Gepard::BasicMath::GPDPoint);

	//им€ оси
	void setAxisName(string);
	string getAxisName();
};

#endif //CMOVEMENTS_H