///////////////////////////////////////////////////////////
//  basicCurveFuncs
//  Реализация 	Базовые функции работы с кривыми
//  Создана:   	28-ноя-2012 15:56:45
//  Автор: 		Anton
///////////////////////////////////////////////////////////
#pragma once
#include "..\BasicMath\GPDPoint2dn.h"
#include "..\BasicMath\GPDPoint2d.h"


namespace Gepard
{
    namespace Curves
    {
        /**
         * Функция вычисления нормалей в трех точках (2D)
         */
        void calcThreeNormals(	Gepard::BasicMath::GPDPoint2dnPtr P1, 
                                Gepard::BasicMath::GPDPoint2dnPtr P2, 
                                Gepard::BasicMath::GPDPoint2dnPtr P3);

        /**
         *	Сравнение двух точек с минимальной точностью.
         *	Равны ли точки (с точностью до minimumPrecision*delta)
         */
        bool isPointsEquals(Gepard::BasicMath::GPDPoint2dPtr P1,
                            Gepard::BasicMath::GPDPoint2dPtr P2, double delta = 1.0);
    };
};