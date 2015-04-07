///////////////////////////////////////////////////////////
//  basicGPDVector2d.h
//  Реализация	Class basicGPDVector2d
//  Создано:    08-ноя-2012 21:09:32
//  Автор:      Anton
///////////////////////////////////////////////////////////

#if !defined(EA_4BBA0A0B_CE25_4705_9FC4_473F4D059CB9__INCLUDED_)
#define EA_4BBA0A0B_CE25_4705_9FC4_473F4D059CB9__INCLUDED_

namespace Gepard
{
    namespace BasicMath
    {
        /**
         * базовый класс двухмерного вектора
         */
        class basicGPDVector2d 
        {

        public:
            /**
             * координаты вектора
             */
            double u;
            /**
             * координаты вектора
             */
            double v;

            basicGPDVector2d();
            ~basicGPDVector2d();
            
            /**
             * Равны ли объекты
             */
            virtual bool isEquals(basicGPDVector2d& Vector2d);
            /**
             * Равен ли нулю
             */
            virtual bool isNull();
            /**
             * Не равны ли объекты
             */
            virtual bool operator!=(basicGPDVector2d& Vector2d);
            /**
             * Равны ли объекты
             */
            virtual bool operator==(basicGPDVector2d& Vector2d);
            /**
             * Установить координаты
             */
            virtual void setCoords(double U, double V);
            /**
             * Установить координаты
             */
            virtual void setCoords(basicGPDVector2d& Vector2d);
            /**
             * Обнулить
             */
            virtual void setNull();

        };
    }
}
#endif // !defined(EA_4BBA0A0B_CE25_4705_9FC4_473F4D059CB9__INCLUDED_)
