///////////////////////////////////////////////////////////
//  GPDPoint2d.h
//  Реализация Class GPDPoint2d
//  Создано:   09-ноя-2012 11:22:06
//  Автор:     Anton
///////////////////////////////////////////////////////////

#if !defined(EA_1FE276CF_DE44_4b60_846E_FCED65E7DEC7__INCLUDED_)
#define EA_1FE276CF_DE44_4b60_846E_FCED65E7DEC7__INCLUDED_

#include "basicGPDVector2d.h"
#include "..\General\basicArray.h"
#include "..\General\basicList.h"

namespace Gepard
{
    namespace BasicMath
    {
        class GPDVector2d;
        class GPDPoint2dn;
        /**
         * Класс представления двухмерной точки без нормали
         */
        class GPDPoint2d : public Gepard::BasicMath::basicGPDVector2d
        {

        public:
            GPDPoint2d();
            ~GPDPoint2d();
            GPDPoint2d(double U, double V);
            /**
             * Получить расстояние между точками
             */
            double getLength(const GPDPoint2d &P);

            /**
             *	Получить квадрат расстояния между точками
             */
            double getSqrLength(const GPDPoint2d &P);

            /**
             * Получить расстояние между точками
             */
            double getLength(const GPDPoint2d *P);

            /**
             *	Получить квадрат расстояния между точками
             */
            double getSqrLength(GPDPoint2d *P);


            /**
             * Перевод точки в вектор
             */
            Gepard::BasicMath::GPDVector2d toVector();
            
            /**
             * Разность между точками - в вектор V = P - тек
             */
            Gepard::BasicMath::GPDVector2d toVector(const GPDPoint2d &P);
            
            /**
             * Получить вектор (V = тек - P)
             */
            Gepard::BasicMath::GPDVector2d operator-(const GPDPoint2d &P);

            /**
             *  Оператор равенства двух точек
             */
            bool operator==(const GPDPoint2d &P);
            /**
             * обнулить
             */
            void setNull();
            /**
             * установка координат
             */
            void setCoords(const GPDPoint2d &P);
            /**
             * установка координат
             */
            void setCoords(const Gepard::BasicMath::GPDPoint2dn &P);

            /**
            * установка координат
            */
            void setCoords(double U, double V);
            /**
            *	Перевод точки в строку
            */
            std::string toString(void);
            /**
             * Точки приближенно равны (с точностью minimumPrecision*delta)
             */
            bool isApproxEquals(const GPDPoint2d &P, double delta = 1.0);
            /**
             * Точки приближенно равны (с точностью minimumPrecision*delta)
             */
            bool isApproxEquals(const GPDPoint2d *P, double delta = 1.0);

        };
        
        typedef GPDPoint2d* GPDPoint2dPtr;	//Указатель на 2D точку
        typedef GPDPoint2d& GPDPoint2dRef;	//Ссылка на 2D точку
        typedef Gepard::General::basicArray<GPDPoint2d> GPDPoint2dArray; 	//Массив 2d точек
        typedef Gepard::General::basicList<GPDPoint2d> GPDPoint2dList;		//Список 2d точек
        typedef Gepard::General::basicArray<GPDPoint2dPtr> GPDPoint2dPtrArray;	//Массив указателей на 2d точки
        typedef Gepard::General::basicList<GPDPoint2dPtr> GPDPoint2dPtrList;		//Список указателей на 2d точки

    }

}
#endif // !defined(EA_1FE276CF_DE44_4b60_846E_FCED65E7DEC7__INCLUDED_)
