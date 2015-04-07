///////////////////////////////////////////////////////////
//  GPDLine2d.h
//  Реализация	Class GPDLine2d
//  Создано:    09-ноя-2012 13:11:20
//  Автор:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_04D4164D_FF6D_48f1_A237_71DCEF2E75C1__INCLUDED_)
#define EA_04D4164D_FF6D_48f1_A237_71DCEF2E75C1__INCLUDED_

#include "CROSS_LINE_TYPE.h"
#include "CROSS_LINE_POINT_TYPE.h"
#include "../BasicMath/GPDVector2d.h"
#include "../BasicMath/GPDPoint2dn.h"

namespace Gepard
{
    namespace Curves
    {
        /**
         * Класс линии
         */
        class GPDLine2d
        {

        public:
            GPDLine2d();
            GPDLine2d(Gepard::BasicMath::GPDPoint2dn PStart, Gepard::BasicMath::GPDPoint2dn PEnd);
            ~GPDLine2d();

            /**
             * Начальная и конечная точки
             */
            Gepard::BasicMath::GPDPoint2dn P0, P1;

            /**
             * Массив точек кривой
             */
            Gepard::BasicMath::GPDPoint2dnArray Points;

            /**
             * Создать 2d линию
             */
            void createLine2d(unsigned int numPoints);
            /**
             * Проверить линии на пересечение и, в случае пересечения, вернуть точку
             * пересечения.
             */
            CROSS_LINE_TYPE crossLines(GPDLine2d &line2d, Gepard::BasicMath::GPDPoint2dRef crossPoint);

            /**
             * Проверить линии на пересечение и, в случае пересечения, вернуть точку
             * пересечения.
             */
            static CROSS_LINE_TYPE crossLines(	Gepard::BasicMath::GPDPoint2d *A, Gepard::BasicMath::GPDPoint2d *B, 
                                                Gepard::BasicMath::GPDPoint2d *C, Gepard::BasicMath::GPDPoint2d *D, 
                                                Gepard::BasicMath::GPDPoint2dRef crossPoint );
            
            /**
             *	Классифицировать точку по отношению к данной линии (отрезку)
             */
            CROSS_LINE_POINT_TYPE classifyPoint(Gepard::BasicMath::GPDPoint2d *P);

            /**
             *	Классифицировать точку по отношению к данной линии (отрезку)
             */
            static CROSS_LINE_POINT_TYPE classifyPoint( Gepard::BasicMath::GPDPoint2d *A, 
                                                        Gepard::BasicMath::GPDPoint2d *B,
                                                        Gepard::BasicMath::GPDPoint2d *P );
            
            /**
             *	Пересекаются ли две линии
             */
            bool isCrossLines(GPDLine2d &line2d, Gepard::BasicMath::GPDPoint2dPtr outP = 0);

            /**
             *	Пересекаются ли две линии
             */
            static bool isCrossLines( Gepard::BasicMath::GPDPoint2d *A, Gepard::BasicMath::GPDPoint2d *B, 
                                      Gepard::BasicMath::GPDPoint2d *C, Gepard::BasicMath::GPDPoint2d *D, 
                                      Gepard::BasicMath::GPDPoint2dPtr outP = 0);

            /**
             *	Найти тип пересечения линий
             */
            CROSS_LINE_TYPE intersectLines(GPDLine2d &line2d, double &t);

            /**
             *	Найти тип пересечения линий (AB) и (BC)
             */
            static CROSS_LINE_TYPE intersectLines( Gepard::BasicMath::GPDPoint2d *A, Gepard::BasicMath::GPDPoint2d *B, 
                                                   Gepard::BasicMath::GPDPoint2d *C, Gepard::BasicMath::GPDPoint2d *D,
                                                   double &t );
            
            /**
             *	Получить расстояние от точки до ОТРЕЗКА
             */
            double getDistance(Gepard::BasicMath::GPDPoint2d *P, Gepard::BasicMath::GPDPoint2d *_outP = 0);

            /**
             *	Получить расстояние от точки P до ОТРЕЗКА (_A,_B)
             */
            static double getDistance(  Gepard::BasicMath::GPDPoint2d *_A, Gepard::BasicMath::GPDPoint2d *_B, 
                                        Gepard::BasicMath::GPDPoint2d *_P, Gepard::BasicMath::GPDPoint2d *_outP = 0);



        };

    }

}
#endif // !defined(EA_04D4164D_FF6D_48f1_A237_71DCEF2E75C1__INCLUDED_)
