///////////////////////////////////////////////////////////
//  GPDVector.cpp
//  Реализация 	Class GPDVector
//  Создана:   	15-фев-2010 16:35:50
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

        class GPDPoint;
        class GPDReper;

        /**
         * Класс вектора
         */
        class GPDVector : public basicGPDVector
        {

        public:
            GPDVector();
            ~GPDVector();

            GPDVector(double X, double Y, double Z);
            /**
             * скалярное произведение векторов
             */
            double getScalarProduct(GPDVector &Vector);
            /**
             * Вектороное произведение векторов
             */
            void CrossProduct(GPDVector &b);
            /**
             * Вектороное произведение векторов
             */
            GPDVector operator*(GPDVector &a);
            /**
             *  Скалярное произведение векторов
             */
            double operator&(GPDVector &a);
            /**
             * Смешанное произведение 3-х векторов
             */
            double getScalarTripleProduct(GPDVector &b, GPDVector &c);
            /**
             * Сумма векторов
             */
            void Sum(GPDVector &b);
            /**
             * Сумма векторов
             */
            GPDVector operator+(GPDVector &a);
            /**
             * Сумма векторов
             */
            void operator+=(GPDVector &a);
            /**
             * Разность векторов
             */
            void Difference(GPDVector &b);
            /**
             * Разность векторов
             */
            GPDVector operator-(GPDVector &a);
            /**
             * Умножение вектора на скаляр
             */
            void ScalarMulVector(double scalar);
            /**
             * Умножение вектора на скаляр
             */
            GPDVector operator*(double scalar);
            /**
             * Коллинеарность векторов
             */
            bool isColinear(GPDVector &a);
            /**
             * Ортогональность векторов
             */
            bool isOrthogonal(GPDVector &a);
            /**
             * Компланарность векторов
             */
            bool isComplanar(GPDVector &b, GPDVector &c);
            /**
             * Получение длины вектора
             */
            double getLength();
            /**
             *  Получение квадрата длины вектора
             */
            double getSqrLength();
            /**
             * Нормализация вектора
             */
            void Normalize(void);
            /**
             * Нормализация вектора, текущий вектор не меняется
             */
            GPDVector getNormalized();
            /**
             * Перевод вектора в точку
             */
            Gepard::BasicMath::GPDPoint toPoint(void);
            /**
             * Перевод вектора в строку
             */
            std::string toString(void);
            /**
             * Получение угла между векторами 
             */
            double getAngle(GPDVector &a);
            /**
             * Функция поворота вектора вокруг оси против часовой стрелки (входной вектор - ось)
             */
            void Rotate(GPDVector &axis, double angle);
            /**
             * Функция поворота вектора вокруг оси против часовой стрелки (Входной вектор - ось)			 
             */
            GPDVector getRotated(GPDVector &axis, double angle);
            /**
            * Функция перевода вектора из одной систеы координат в другую. Текущий вектор не меняется
            */
            GPDVector getTransformed(Gepard::BasicMath::GPDReper OLD, Gepard::BasicMath::GPDReper NEW);
            /**
            * Функция перевода вектора из одной систеы координат в другую. Меняется текущий вектор
            */
            void Transform(Gepard::BasicMath::GPDReper OLD, Gepard::BasicMath::GPDReper NEW);
            /**
             *	Функция инвертирования вектора
             */
            void Invert();
            /**
             *	Функция возвращает инвертированный вектор
             */
            GPDVector getInverted();

            /**
            *  Векторы одинаковы (с погрешностью minimumPrecision)
            */
            bool isApproxEquals(GPDVector &v);

            //перегруженный оператор вывода
            friend ostream& operator<<(ostream& os, const GPDVector &gpd_vector)
            {			
                os.write((char *) &gpd_vector, sizeof(GPDVector));
                return os;

            }
            //перегруженный оператор ввода
            friend istream& operator>>(istream& is, GPDVector &gpd_vector)
            {
                is.read((char *) &gpd_vector, sizeof(GPDVector));
                return is;
            }

        };

        typedef GPDVector* GPDVectorPtr;	//Указатель на вектор
        typedef GPDVector& GPDVectorRef;	//Ссылка на вектор
        typedef Gepard::General::basicArray<GPDVector> GPDVectorArray;	//Массив векторов
        typedef Gepard::General::basicList<GPDVector> GPDVectorList;	//Список векторов
        typedef Gepard::General::basicArray<GPDVectorPtr> GPDVectorPtrArray;	//Массив указателей на вектор - НЕ ЗАБУДЬ УДАЛИТЬ! (ЕСЛИ НАДО).
        typedef Gepard::General::basicList<GPDVectorPtr> GPDVectorPtrList;		//Список указателей на вектор - НЕ ЗАБУДЬ УДАЛИТЬ! (ЕСЛИ НАДО).

    }

}

