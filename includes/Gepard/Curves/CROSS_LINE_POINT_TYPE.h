///////////////////////////////////////////////////////////
//  CROSS_LINE_POINT_TYPE.h
//  Реализация Class CROSS_LINE_POINT_TYPE
//  Создано:      15-дек-2012 14:23:18
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_E5D4E200_0F79_42f1_9E9B_671C9315CD1F__INCLUDED_)
#define GPD_E5D4E200_0F79_42f1_9E9B_671C9315CD1F__INCLUDED_

namespace Gepard
{
    namespace Curves
    {
        /**
         * Тип точки для определения пересечения линий
         */
        enum CROSS_LINE_POINT_TYPE
        {
            /**
             *  Неизвестно
             */
            CLPT_NONE = 0, 
            /**
             * Точка слева от линии
             */
            CLPT_LEFT = 1,
            /**
             * Точка справа от линии
             */
            CLPT_RIGHT = 2,
            /**
             * Поверхность перед линией (перед первой точкой)
             */
            CLPT_BEYOND = 3,
            /**
             * Точка позади линии (после послед. точки)
             */
            CLPT_BEHIND = 4,
            /**
             * Точка между нач. и кон. точками линии
             */
            CLPT_BETWEEN = 5,
            /**
             * Точка равна начальной точке
             */
            CLPT_ORIGIN = 6,
            /**
             * Точка равна конечной точке линии
             */
            CLPT_DESTINATION = 7
        };

    }

}
#endif // !defined(GPD_E5D4E200_0F79_42f1_9E9B_671C9315CD1F__INCLUDED_)
