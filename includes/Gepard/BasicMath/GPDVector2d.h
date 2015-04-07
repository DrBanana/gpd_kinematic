///////////////////////////////////////////////////////////
//  GPDVector2d.h
//  Реализация	Class GPDVector2d
//  Создано:    09-ноя-2012 12:34:49
//  Автор:		Anton
///////////////////////////////////////////////////////////

#if !defined(EA_5DF37002_DBD9_44e3_837E_BFACFE6834FB__INCLUDED_)
#define EA_5DF37002_DBD9_44e3_837E_BFACFE6834FB__INCLUDED_

#include <string>
#include "basicGPDVector2d.h"

namespace Gepard
{
    namespace BasicMath
    {
        class GPDPoint2d;
        /**
         * Класс - двухмерный вектор
         */		
        class GPDVector2d : public basicGPDVector2d
        {

        public:
            GPDVector2d();
            ~GPDVector2d();			
            GPDVector2d(double u, double v);
            /**
             * Получить скалярное произведение
             */
            double getScalarProduct(GPDVector2d& Vec);
            /**
             * Сумма векторов
             */
            void Sum(GPDVector2d &b);
            /**
             * Сумма векторов
             */
            GPDVector2d operator+(GPDVector2d &a);
            /**
             * Сумма векторов
             */
            void operator+=(GPDVector2d &a);
            /**
             * Разность векторов
             */
            void Difference(GPDVector2d &b);
            /**
             * Разность векторов
             */
            GPDVector2d operator-(GPDVector2d &a);
            /**
             * Умножение вектора на скаляр
             */
            void ScalarMulVector(double scalar);
            /**
             * Умножение вектора на скаляр
             */
            GPDVector2d operator*(double scalar);
            /**
             * Получение длины вектора
             */
            double getLength();
            /**
             * Нормализация вектора
             */
            void Normalize(void);
            /**
             * Нормализация вектора, текущий вектор не меняется
             */
            GPDVector2d getNormalized();
            /**
             * Перевод вектора в точку
             */
            Gepard::BasicMath::GPDPoint2d toPoint(void);
            /**
             * Перевод вектора в строку
             */
            std::string toString(void);
            /**
             * Получение угла между векторами 
             */
            double getAngle(GPDVector2d &a);
            /**
             *	Функция инвертирования вектора
             */
            void Invert();
            /**
             *	Функция возвращает инвертированный вектор
             */
            GPDVector2d getInverted();
        };

    }

}
#endif // !defined(EA_5DF37002_DBD9_44e3_837E_BFACFE6834FB__INCLUDED_)
