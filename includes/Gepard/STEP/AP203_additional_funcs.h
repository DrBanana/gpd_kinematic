///////////////////////////////////////////////////////////
//  AP03_additional_funcs.h
//  �������:    19-���-2015 14:56
//  �����:      Dr_Freeman
//  ��������:   �������������� ������� ��� ������ STEP (Ap203) 
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
        *	������� ������ ������ �����
        */
        void ParseCartesianPointsList( InstMgr *instance_manager, const char* attr_string, 
                                       std::vector<GPDPoint> &cartesian_points_list);

        /**
         *	������� ������ ������ �����
         */
        void ParseCartesianPointsArray(InstMgr *instance_manager, STEPattribute *attr, 
                                        GPDPointArray &cartesian_points_array);

        /**
        *	�������� ��������� ����������� B_Spline_Surface
        */
        void GetBSplineSurfaceParams(InstMgr *instance_manager, STEPentity *_ent, 
                                     int &u_degree, int &v_degree,
                                     bool &isClosed_u, bool &isClosed_v,
                                     bool &isSelfIntersect, GPDPointArray &control_points);
        /**
        *	�������� ��������� ����������� B_Spline_Surface_With_Knots
        */
        void GetBSplineSurfaceWithKnotsParams( STEPentity *_ent, 
                                               std::vector<double> &knots_u, std::vector<int> &mult_u,
                                               std::vector<double> &knots_v, std::vector<int> &mult_v );

        /**
         *	�������� ��������� ����������� Rational_B_Spline_Surface
         */
        void GetRationalBSplineSurfaceParams(InstMgr *instance_manager, STEPentity *_ent, std::vector<std::vector<double>> &weights);

        /**
        *	�������� ��������� ������ B_Spline_Curve
        */
        void GetBSplineCurveParams(InstMgr *instance_manager, STEPentity *_ent,
                                    int &degree, bool &isClosed, 
                                    bool &isSelfIntersect, GPDPointArray &control_points);

        /**
         *	�������� ��������� ������ B_Spline_With_Knots
         */
        void GetBSplineWithKnostCurveParams(STEPentity *_ent, std::vector<double> &knots, std::vector<int> &mults );

        /**
         *	�������� ��������� ������ Rational_B_Spline_Curve
         */
        void GetRationalBSplineCurveParams(STEPentity *_ent, std::vector<double> &w);
    }//STEP
}//Gepard

#endif