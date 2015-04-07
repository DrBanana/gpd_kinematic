///////////////////////////////////////////////////////////
//  basicFuncs.cpp
//  ���������� 	Class basicFuncs
//  �������:   	15-���-2010 21:01:35
//  �����: 		Anton
///////////////////////////////////////////////////////////
#pragma once
#include <math.h>
#include <iostream>

namespace Gepard
{
    //class GPDSurface;
    namespace BasicMath
    {
        //���������� ���������� ������� ������
        /**
        * ����� �� double Pi=3.1415926535897932385;
        */			
        const double Pi=3.1415926535897932384626433832795;
        /*
        *  ��/2
        */
        const double Pi_div_2=1.5707963267948966192313216916398;
        /*
        *  ��/4
        */
        const double Pi_div_4=0.78539816339744830961566084581988;
        /*
        *  ��*2
        */
        const double Pi_dot_2=6.283185307179586476925286766559;

        /*
        *  exp
        */
        const double exp = 2.7182818284590452353602874713527;

        /*
        * exp*2
        */
        const double exp_dot_2 = 7.389056098930650227230427460575;

        /**
         *	ON_EPSILON = 2^-52
         */
        const double epsilon = 2.2204460492503131e-16;

        /**
         *	������ �� �������
         */
        const double sqrt_epsilon = 1.490116119385000000e-8;

        /*
        * ������� �������� ���������� - ��������, ���� ���������� 
        * ����� ������� ������ prec, �� ����� �����
        */
        const double minimumPrecision = 1e-008;

        /**
         *  ������� ��������
         */
        const double minPrecSqr = minimumPrecision*minimumPrecision;

        /**
         *	��������� �������� �� ���������
         */
        const double precDelta = 1000;

        /**
         *	��������� ��������
         */
        const double minPrecLow = minimumPrecision * precDelta;

        /**
         *	����� ������� ����� - ��� ������ ��������, ���� ������ ����������� �����
         */
        const double maximumValue = 1e+009;
        
// #ifdef GPD_USE_PARALLEL_CODE
// 		/**
// 		*	������������ ����� ����/�������
// 		*/
// 		const int maxThreads = 128;
// #else
// 		/**
// 		*	������������ ����� ����/�������
// 		*/
// 		const int maxThreads = 1;
// #endif
//------------------------------------------------------------------------
        //���������� �������

        /**
         * ������� �����
         */
        inline double sqr(double x){return x*x;};

        /**
         *	�������� x � y �������� ����� �� ������ (�� minimumPrecision*delta)
         */
        bool isApproxEquals(double x, double y, double delta = 1.0);

        /**
        *	�������� ����� ���� �������
        */
        //int getNumCores();

        /**
        *	"�����" ���������� =)
        */
        inline double gpd_acos(double x)
        {
            if (x>1) x=1;
            if (x<-1) x=-1;
            return acos(x);
        }

        /**
         *  ����������� �������� ���� �� �������� � �������
         */
        inline double CalcRadianFromGrad( double angle )
        {
            return angle*Pi/180.0;
        }

        /**
         *  ����������� �������� ���� �� �������� � �������
         */
        inline double CalcGradFromRadian( double angle )
        {
            return angle*180.0/Pi;
        }

        //���������� ��������� ������
        /**
        *	��������� ������������ ��������������� �� ���� ����
        */
        struct BoundingBox
        {
            double x[2];
            double y[2];
            double z[2];

            BoundingBox() { clear(); }
            void clear() {
                x[1] = -maximumValue;
                y[1] = -maximumValue;
                z[1] = -maximumValue;
                x[0] = maximumValue;
                y[0] = maximumValue;
                z[0] = maximumValue;
            }

            /**
             *  �������� � ��������������� �����
             */
            void AddPoint(double px, double py, double pz, bool isFirst=false)
            {
                if (isFirst) {
                    x[0] = x[1] = px;
                    y[0] = y[1] = py;
                    z[0] = z[1] = pz;
                    return;
                }

                if (px < x[0]) x[0] = px;
                if (px > x[1]) x[1] = px;
                if (py < y[0]) y[0] = py;
                if (py > y[1]) y[1] = py;
                if (pz < z[0]) z[0] = pz;
                if (pz > z[1]) z[1] = pz;
            }

            /**
             *	��������� �������������� 
             */
            void AddBoundingBox(BoundingBox &bb)
            {
                if (bb.x[0] < x[0]) x[0] = bb.x[0];
                if (bb.x[1] > x[1]) x[1] = bb.x[1];
                if (bb.y[0] < y[0]) y[0] = bb.y[0];
                if (bb.y[1] > y[1]) y[1] = bb.y[1];
                if (bb.z[0] < z[0]) z[0] = bb.z[0];
                if (bb.z[1] > z[1]) z[1] = bb.z[1];
            }

            /**
             *	�������� �����
             */
            void GetCenter(float(&center)[3])
            {                
                center[0] = (float)((x[1] + x[0]) / 2.0);
                center[1] = (float)((y[1] + y[0]) / 2.0);
                center[2] = (float)((z[1] + z[0]) / 2.0);
            }

            /**
            *	�������� ���������� �������
            */
            void GetBoundSize(float(&s)[3])
            {
                s[0] = (float)(x[1] - x[0]);
                s[1] = (float)(y[1] - y[0]);
                s[2] = (float)(z[1] - z[0]);
            }
        };
//------------------------------------------------------------------------
    }

}

