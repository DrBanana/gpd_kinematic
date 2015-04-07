///////////////////////////////////////////////////////////
//  basicGPDVector.h
//  Реализация	Class basicGPDVector
//  Создано:    08-ноя-2012 21:09:31
//  Автор:      Anton
///////////////////////////////////////////////////////////

#if !defined(EA_4CCD46A4_F47C_44bf_A6E0_616F364D8094__INCLUDED_)
#define EA_4CCD46A4_F47C_44bf_A6E0_616F364D8094__INCLUDED_

#include <fstream>

namespace Gepard
{
    namespace BasicMath
    {
        using namespace std;

        /**
         * Базовый класс вектора
         */
        class basicGPDVector
        {
        
        public:
            /**
             * координаты
             */
            double x,y,z;

            basicGPDVector();
            basicGPDVector(double X, double Y, double Z);
            ~basicGPDVector();
            /**
             * Равны ли объекты
             */
            virtual bool isEquals(basicGPDVector& Vector);
            /**
             * Равен ли нулю
             */
            virtual bool isNull();
            /**
             * Не равны ли объекты
             */
            virtual bool operator!=(basicGPDVector& Vector);
            /**
             * Равны ли объекты
             */
            virtual bool operator==(basicGPDVector& Vector);
            /**
             * Установить координаты
             */
            virtual void setCoords(double X, double Y, double Z);
            /**
             * Установить координаты
             */
            virtual void setCoords(basicGPDVector& Vector);
            /**
             * Обнулить
             */
            virtual void setNull();

            /**
             *  Получить координаты по индексу
             */
            double operator[](int i);

        };

    }

}
#endif // !defined(EA_4CCD46A4_F47C_44bf_A6E0_616F364D8094__INCLUDED_)
