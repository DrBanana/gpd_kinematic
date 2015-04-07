///////////////////////////////////////////////////////////
//  nurbsFuncs.h
//  Дополнительные функции, связанные с вычислением NURBS
//  кривых и поверхностей
//  Создано:      11-мар-2015 16:06
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#ifndef NURBSFUNCS_H
#define NURBSFUNCS_H

#include "GPDPoint.h"
#include <vector>

namespace Gepard 
{
    namespace BasicMath 
    {

        /**
         *	Максимальный порядок для B-spline (установлен от балды =))
         */
        const unsigned int nurbs_max_order = 50;       
        /**
         *	Вычислить точку по методу Кокса-Де-Бура
         *  k - порядок B-Spline
         *  knots - массив узлов (количество = cp + k, cp - контрольные точки)
         *  control_points - задающие точки
         *  t - значение параметра ( t=>[0; 1], knots[l] <= t < knots[l+1] )
         *  l - Интервал (номер узла в узловом векторе), l >= k-1
         *  ev_type - Тип вычисления
         *  ov - Выходной вектор (либо одно значение в x, если тип Rational_Coeffs)
         */
        void EvaluateDeBoor( int k, const double *knots, GPDPointArray &control_points, 
                             double t, int l, GPDVector &ov);

        /**
         *	Получить значение текущего интервала
         */
        int getInterval(double t, const double *knots, int k_size);

        /**
         *	Задать узловой вектор (если его нет - создать)
         */
        void SetKnots(int cp_count, int order, 
                      const std::vector<double> &knots_in, 
                            std::vector<double> &knots_out,
                      const std::vector<int> &mults = std::vector<int>() );

    }//BasicMath
}//Gepard


#endif