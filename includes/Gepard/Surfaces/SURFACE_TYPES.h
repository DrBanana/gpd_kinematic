///////////////////////////////////////////////////////////
//  SURFACE_TYPES.h
//  Реализация Class SURFACE_TYPES
//  Создано:      15-ноя-2012 17:35:19
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_8342E6E2_1142_46e0_B234_2B5B21FD70D4__INCLUDED_)
#define EA_8342E6E2_1142_46e0_B234_2B5B21FD70D4__INCLUDED_

namespace Gepard
{
    namespace Surfaces
    {
        /**
         * Типы поверхностей
         */
        enum SURFACE_TYPES
        {
            /**
             * Плоскость
             */
            ST_PLANE = 1,
            /**
             * Цилиндрическая поверхность
             */
            ST_CYLINDRICAL = 2,
            /**
             * Сферическая
             */
            ST_SPHERICAL = 3,
            /**
             * ТОР
             */
            ST_TOROIDAL = 4,
            /**
             * Конус
             */
            ST_CONICAL = 5,
            /**
             * Поверхность свободной формы
             */
            ST_FREEFORM = 6,
            /**
             * B-spline  с узлами
             */
            ST_B_SPLINE_WITH_KNOTS = 7,
            /**
             * B-spline без узлов
             */
            ST_B_SPLINE = 8,
            /**
             * Поверхность Безье
             */
            ST_BEZIER = 9,
            /**
             * Рациональный B_Spline
             */
            ST_RATIONAL_B_SPLINE = 10,
            /**
             *	NURBS
             */
            ST_NURBS = 11
            
        };

    }

}
#endif // !defined(EA_8342E6E2_1142_46e0_B234_2B5B21FD70D4__INCLUDED_)
