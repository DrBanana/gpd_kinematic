///////////////////////////////////////////////////////////
//  nurbsFuncs.h
//  �������������� �������, ��������� � ����������� NURBS
//  ������ � ������������
//  �������:      11-���-2015 16:06
//  �����: Dr_Freeman
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
         *	������������ ������� ��� B-spline (���������� �� ����� =))
         */
        const unsigned int nurbs_max_order = 50;       
        /**
         *	��������� ����� �� ������ �����-��-����
         *  k - ������� B-Spline
         *  knots - ������ ����� (���������� = cp + k, cp - ����������� �����)
         *  control_points - �������� �����
         *  t - �������� ��������� ( t=>[0; 1], knots[l] <= t < knots[l+1] )
         *  l - �������� (����� ���� � ������� �������), l >= k-1
         *  ev_type - ��� ����������
         *  ov - �������� ������ (���� ���� �������� � x, ���� ��� Rational_Coeffs)
         */
        void EvaluateDeBoor( int k, const double *knots, GPDPointArray &control_points, 
                             double t, int l, GPDVector &ov);

        /**
         *	�������� �������� �������� ���������
         */
        int getInterval(double t, const double *knots, int k_size);

        /**
         *	������ ������� ������ (���� ��� ��� - �������)
         */
        void SetKnots(int cp_count, int order, 
                      const std::vector<double> &knots_in, 
                            std::vector<double> &knots_out,
                      const std::vector<int> &mults = std::vector<int>() );

    }//BasicMath
}//Gepard


#endif