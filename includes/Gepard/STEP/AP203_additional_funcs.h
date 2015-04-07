///////////////////////////////////////////////////////////
//  AP03_additional_funcs.h
//  Создано:    19-фев-2015 14:56
//  Автор:      Dr_Freeman
//  Описание:   Дополнительные функции для чтения STEP (Ap203) 
///////////////////////////////////////////////////////////

#ifndef AP203_ADDITIONAL_FUNCS_H
#define AP203_ADDITIONAL_FUNCS_H

#include <instmgr.h>

#include "StepDefines.h"
#include "../BasicMath/GPDPoint.h"

namespace Gepard
{
    namespace STEP
    {
        using namespace Gepard::BasicMath;

        /**
        *	Функция парсит список точек
        */
        void ParseCartesianPointsList( InstMgr *instance_manager, const char* attr_string, 
                                       std::vector<GPDPoint> &cartesian_points_list);

        /**
         *	Функция парсит массив точек
         */
        void ParseCartesianPointsArray(InstMgr *instance_manager, STEPattribute *attr, 
                                        GPDPointArray &cartesian_points_array);

        /**
        *	Получить параметры поверхности B_Spline_Surface
        */
        void GetBSplineSurfaceParams(InstMgr *instance_manager, STEPentity *_ent, 
                                     int &u_degree, int &v_degree,
                                     bool &isClosed_u, bool &isClosed_v,
                                     bool &isSelfIntersect, GPDPointArray &control_points);
        /**
        *	Получить параметры поверхности B_Spline_Surface_With_Knots
        */
        void GetBSplineSurfaceWithKnotsParams( STEPentity *_ent, 
                                               std::vector<double> &knots_u, std::vector<int> &mult_u,
                                               std::vector<double> &knots_v, std::vector<int> &mult_v );

        /**
         *	Получить параметры поверхности Rational_B_Spline_Surface
         */
        void GetRationalBSplineSurfaceParams(InstMgr *instance_manager, STEPentity *_ent, std::vector<std::vector<double>> &weights);

        /**
        *	Получить параметры кривой B_Spline_Curve
        */
        void GetBSplineCurveParams(InstMgr *instance_manager, STEPentity *_ent,
                                    int &degree, bool &isClosed, 
                                    bool &isSelfIntersect, GPDPointArray &control_points);

        /**
         *	Получить параметры кривой B_Spline_With_Knots
         */
        void GetBSplineWithKnostCurveParams(STEPentity *_ent, std::vector<double> &knots, std::vector<int> &mults );

        /**
         *	Получить параметры кривой Rational_B_Spline_Curve
         */
        void GetRationalBSplineCurveParams(STEPentity *_ent, std::vector<double> &w);
    }//STEP
}//Gepard

#endif