///////////////////////////////////////////////////////////
//  GPDPoint.cpp
//  Реализация 	Class GPDPoint
//  Создана:   	15-фев-2010 16:35:48
//  Автор: 		Anton
///////////////////////////////////////////////////////////

#pragma once

#include <string>
#include "basicGPDVector.h"
#include "..\General\basicArray.h"
#include "..\General\basicList.h"

namespace Gepard
{
    namespace BasicMath
    {
        using namespace std;

        class GPDVector;
        class GPDReper;

        /**
         * Класс точки
         */
        class GPDPoint : public basicGPDVector
        {

        public:
            GPDPoint();
            ~GPDPoint();
            /**
             * координаты нормали
             */
            double nx;
            /**
             * координаты нормали
             */
            double ny;
            /**
             * координаты нормали
             */
            double nz;

            GPDPoint(double X, double Y, double Z, double NX, double NY, double NZ);
            GPDPoint(double X, double Y, double Z);

            /**
             * Получить расстояние между точками
             */
            double getLength(GPDPoint &P);

            /**
             * Получить квадрат расстояния между точками
             */
            double getSqrLength(GPDPoint &P);

            /**
             *  Есть ли нормаль (true - значит, нет)
             */
            bool isNormalNull();

            /**
             *  Точки одинаковы (с погрешностью minimumPrecision*prec)
             */
            bool isApproxEquals(GPDPoint &P, double prec=1.0);            

            /**
             * Перевести в вектор ТЕКУЩУЮ точку
             */
            Gepard::BasicMath::GPDVector toVector();
            /**
             * Разность между точками - в вектор (V = P - тек)
             */
            Gepard::BasicMath::GPDVector toVector(GPDPoint &P);
            /**
             * Перевод текущей точки в репер
             */
            Gepard::BasicMath::GPDReper toReper();

            /**
             * Получить вектор (V = тек - P)
             */
            Gepard::BasicMath::GPDVector operator-(GPDPoint &P);
            /**
             * обнулить
             */
            void setNull();
            /**
             * установка координат
             */
            void setCoords(GPDPoint &P);
            /**
            * установка координат
            */
            void setCoords(double X, double Y, double Z, double NX, double NY, double NZ);
            /**
            * установка координат
            */
            void setCoords(double X, double Y, double Z);
            /**
             *	Установка координат нормали
             */
            void setCoordsN(double NX, double NY, double NZ);
            /**
             *	Установка нормали
             */
            void setNormal(GPDVector &_normal); 
            /**
            *	Перевод точки в строку
            */
            std::string toString(void);
            /**
             * перевод текущей точки из старой системы координат в новую. Текущая точка не
             * меняется
             */
            GPDPoint getTransformed(Gepard::BasicMath::GPDReper &OLD, Gepard::BasicMath::GPDReper &NEW);
            /**
             * перевод текущей точки из старой системы координат в новую. Меняется текущая точка
             */
            void Transform(Gepard::BasicMath::GPDReper &OLD, Gepard::BasicMath::GPDReper &NEW);
            /**
             *	Получить вектор из координат нормали
             */
            GPDVector getNormal();
            /**
             *	Функция инвертирования нормали для текущей точки
             */
            void InvertNormal();
            /**
             *  Нормализация нормали точки
             */
            void Normalize();

            //перегруженный оператор вывода
            friend ostream& operator<<(ostream& os, const GPDPoint &p)
            {			
                os.write((char *) &p, sizeof(GPDPoint));
                return os;

            }
            //перегруженный оператор ввода
            friend istream& operator>>(istream& is, GPDPoint &p)
            {
                is.read((char *) &p, sizeof(GPDPoint));
                return is;
            }
           
        };

        typedef GPDPoint* GPDPointPtr;	//указатель на точку
        typedef GPDPoint& GPDPointRef;	//ссылка на точку
        typedef Gepard::General::basicArray<GPDPoint> GPDPointArray;	//массив точек
        typedef Gepard::General::basicList<GPDPoint> GPDPointList;		//список точек
        typedef Gepard::General::basicArray<GPDPointPtr> GPDPointPtrArray;	//массив указателей на точки - НЕ ЗАБУДЬ УДАЛИТЬ (ЕСЛИ НАДО)!
        typedef Gepard::General::basicList<GPDPointPtr> GPDPointPtrList;	//список указателей на точки - НЕ ЗАБУДЬ УДАЛИТЬ (ЕСЛИ НАДО)!

    };// end namespace
}; //end namespace

