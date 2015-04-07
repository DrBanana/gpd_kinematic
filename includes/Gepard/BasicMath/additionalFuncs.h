///////////////////////////////////////////////////////////
//  additionalFuncs.cpp
//  ���������� 	additionalFuncs
//  �������:   	5-���-2013 12:50:24
//  �����: 		Freeman
//  ��������:   �������������� �������
///////////////////////////////////////////////////////////

#ifndef ADDITIONAL_FUNCS_H
#define ADDITIONAL_FUNCS_H
#pragma once

#include "GPDPoint2dn.h"
#include "GPDVector.h"
#include "GPDPoint.h"
#include "../Surfaces/QuadMap.h"

#include <functional>

namespace Gepard 
{
    namespace BasicMath 
    {

///----------------------------------------------------------------------------------------------------------
//�����������, ����� ���������� � ��.
        /**
         *  ������� ����������� ����� 3D �� ��������� ��.
         */
        typedef std::function<void(GPDPoint2d, GPDPoint &)> TModifyPointsFunc;

        /**
         *  ����������� �������
         */
        //typedef std::function<void()> TAbstractFunc;

///----------------------------------------------------------------------------------------------------------
//�������
        /**
         *  ������� ��������� ����� �������� (����� numU x numV) � ������� {U0,V0} - {U1,V1} (quad_map)
         *  �� ����������� ����� (u,v)
         *  ������������ �������� - ����� �������� �� 0 �� numU*numV
         */
        int CalcSegmentNum( double U, double V,
                            Gepard::Surfaces::QuadMap &quad_map  );

        /**
        *  ������� ��������� ������� (����������) ������� (u,v) �� ����� {U0;U1 - V0;V1}, 
        *  � ������� ��������� ����� P(U,V)
        */
        int CalcSegmentIndexes( double U, double V, 
                                double U0, double V0, 
                                double U1, double V1,
                                unsigned int NumU, unsigned int NumV,
                                int &u_index, int &v_index );

        /**
         *  ������� ��������� ������� (����������) ������� (u,v) �� ����� (quad_map), 
         *  � ������� ��������� ����� P
         *  ������� ������������ ������� � ������, ���� ����� ����� �� �������! (���� isCorrectLimits)
         */
        int CalcSegmentIndexes( Gepard::BasicMath::GPDPoint2dPtr P,
                                Gepard::Surfaces::QuadMap &quad_map,
                                int &u_index, int &v_index, bool isCorrectLimits = true );        

        /**
         *  ������� ��������� �� ������ ������� ��� ���������� �� �����
         */
        void CalcSegmentIndexesByNum( unsigned int NumSeg, 
                                      unsigned int NumU, unsigned int NumV, 
                                      int &u_index, int &v_index );

        /**
         *  ������� ��������� ������� (����������) ����� (u,v) �� ����� �� ������� ����� � �������
         */
        void CalcPointUVIndexes( unsigned int p_index, 
                                 unsigned int NumU, unsigned int NumV, 
                                 int &u_index, int &v_index );

        /**
         *  ����������� �� �������� ��������
         */
        enum SEGMENT_DIRECTION 
        {
            SD_LEFT,
            SD_RIGHT,
            SD_UP,
            SD_UP_LEFT,
            SD_UP_RIGHT,
            SD_DOWN,
            SD_DOWN_LEFT,
            SD_DOWN_RIGHT            
        };

        /**
         *  ������� ��������� ����� �������� �� ��������� ����������� �� ��������
         *  � ������ �������� -1 - ����� �� ������� �����
         */
        int CalcSegmentNumByDirection( unsigned int NumSeg, 
                                       unsigned int NumU, unsigned int NumV,
                                       SEGMENT_DIRECTION SegDir );

        /**
         *  ��������� ����� ����������� ������������ (t) � �������� �������� (l)
         */
        bool CrossTriangleAndLine(GPDPoint (t)[3], GPDVector n, GPDPoint (l)[2], GPDPoint &P);

        /**
         *	��������������� ��������� ������� ��� ����� P(2d)
         */
        void CalcPoint2DNormal(GPDPoint2dn *A, GPDPoint2dn *B, GPDPoint2dn *P);

///----------------------------------------------------------------------------------------------------------
//������

        /**
         *  ����� ��� ������������ �����
         */
        class RasterizeLine
        {
        public:
            explicit RasterizeLine(Gepard::Surfaces::QuadMap &Quad_Map);

            /**
             *  ��������� ��������������� ��������
             */
            struct PreCalcStruct
            {
                /**
                *  ������������ �������� ������������ ����� �� u
                */
                std::vector<double> d_cash_u;

                /**
                *  ������������ �������� ������������ ����� �� v
                */
                std::vector<double> d_cash_v;

                /**
                *  ��������������� �������� ��� �������
                */
                double qU, qV;
                double stepU, stepV;

                /**
                 *  ���������� �������� �� ����� �� U � V
                 */
                unsigned int countU, countV;
            };


             /**
             *  ������� ����������� ����� 2D (� ����� ����� numU x numV)
             *  (�������� �� ��������� ������)
             *  ������� ��������:
             *  P0, P1 - ���������� ������� ����� ����� (������ �������. �������)         
             *
             *  �������: 
             *  SectorsList - ������ ��������� �������� (u,v)
             *  true - ������ ������� �������� (�� P0 �� P1), 
             *  false - �������� ������� �������� (�� P1 �� P0)
             */
            bool RasterLine( Gepard::BasicMath::GPDPoint2dPtr P0,
                             Gepard::BasicMath::GPDPoint2dPtr P1,                         
                             Gepard::General::basicList<std::pair<int,int>> &SectorsList );

            /**
             *  ������� ����������� ����� 2D (� ����� ����� numU x numV)
             *  � �������� ������ ����� ����������� � ���������
             *
             *  ������� ��������:
             *  P0, P1 - ���������� ������� ����� ����� (������ �������. �������)         
             *
             *  �������: 
             *  SectorsList - ������ ��������� �������� (u,v)
             *  CrossPointList - ������, ���������� ������ ����� ����������� ������� 
             */
            void RasterLine( Gepard::BasicMath::GPDPoint2dPtr P0,
                             Gepard::BasicMath::GPDPoint2dPtr P1,                         
                             Gepard::General::basicList<std::pair<int,int>> &SectorsList,
                             Gepard::General::basicList<
                                std::list<Gepard::BasicMath::GPDPoint2d>> &CrossPointList);


         private:

            /**
             *  ��������������� ��������
             */
            PreCalcStruct preCalc;

            /**
             *  ��������� ����� ��� ������������ (�����)
             */
            Gepard::Surfaces::QuadMap quad_map;

            /**
             *  ������� ��������� ���������������� �������� ��� ��������
             */
            void PreCalc();                

        };
    };
};

#endif