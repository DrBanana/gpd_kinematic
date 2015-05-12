///////////////////////////////////////////////////////////
//  GPDBezierCurve.h
//  ����������	Class GPDBezierCurve
//  �������:    10-���-2012 16:53:48
//  �����:		PashaP
///////////////////////////////////////////////////////////
#pragma once

#include "../BasicMath/GPDPoint.h"
#include "GPDCurve3D.h"
#include <vector>

namespace Gepard
{
    namespace Curves
    {
        
        //using namespace Gepard::BasicMath;
        /**
         * ����� ���������� Bezier ������
         */ 
        class GPDBezierCurve : public Gepard::Curves::GPDCurve3D
        {

        private:

            int k; //������� ������ �����
            int Resolution; //���������� ����� ������ �����
            std::vector<Gepard::BasicMath::GPDPoint> ControlPoints;

            /**
             *	������ ������� ����� �� ���������
             */
            void calcCurrentPoint(double u, Gepard::BasicMath::GPDPoint &pnt);

             /**
             *	��������� ���������� �� ���������
             */
            void setDefaultParameters() override;


            public:

                GPDBezierCurve ();
                ~GPDBezierCurve ();
                GPDBezierCurve (int t, std::vector<Gepard::BasicMath::GPDPoint> &Control);

            /**
            *	��������� ������ ����� � �������� ������ �����
            */
            void calcBezier( unsigned int numPoints=0, bool checkPrec = true );
                        
            /**
            * ��������� ������ � �������� ������ �����
            * (����� ������, ����� ����� ���������� ����� ����� � ��������� precDelta)
            */
            void calcCurve(unsigned int numPoints = 0, bool checkPrec = true) override;

             /**
             *  ������ ��������� ��� ������
             */
            void setParameters( int t, std::vector<Gepard::BasicMath::GPDPoint> &Control );

            /**
             *  ����������� ����� ������ �� ������� ��������� oldReper � ������� ��������� newReper
             */
            void ConvertToBasis( Gepard::BasicMath::GPDReper &oldReper, 
                                 Gepard::BasicMath::GPDReper &newReper) override;

            /**
             *  ��������� ������ ������ � �����
             */            
            void saveToFile(std::ostream& os) override;
            /**
             *  ��������� ������ �� ������
             */
            void readFromFile(std::istream& _is) override;
        };
    }
}