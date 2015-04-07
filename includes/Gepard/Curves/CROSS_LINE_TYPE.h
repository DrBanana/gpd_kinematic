///////////////////////////////////////////////////////////
//  CROSS_LINE_TYPE.h
//  Реализация	Class CROSS_LINE_TYPE
//  Создано:    21-ноя-2012 13:10:06
//  Автор:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(GPD_E921A0A9_FD6D_4263_8162_47B8CED8D5CB__INCLUDED_)
#define GPD_E921A0A9_FD6D_4263_8162_47B8CED8D5CB__INCLUDED_

namespace Gepard
{
    namespace Curves
    {
        /**
         * Тип пересечения линий
         */
        enum CROSS_LINE_TYPE
        {
            /**
             * Линии коллинеарны
             */
            CLT_COLLINEAR = 1,
            /**
             * Параллельные линии
             */
            CLT_PARALLEL = 2,
            /**
             * Под наклоном
             */
            CLT_SKEW = 3,
            /**
             * Пересекаются
             */
            CLT_SKEW_CROSS = 4,
            /**
             * Не пересекаются
             */
            CLT_SKEW_NO_CROSS = 5
        };

    }

}
#endif // !defined(GPD_E921A0A9_FD6D_4263_8162_47B8CED8D5CB__INCLUDED_)
