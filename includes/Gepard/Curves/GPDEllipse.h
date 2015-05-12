///////////////////////////////////////////////////////////
//  GPDEllipse.cpp
//  ���������� 	Class GPDEllipse
//  �������:   	04-���-2010 15:36:50
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#pragma once

#include "GPDCurve3D.h"
#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDVector.h"
#include "../BasicMath/GPDReper.h"
#include <vector>

namespace Gepard
{
    namespace Curves
    {
        /**
         * ������
         */
        class GPDEllipse : public Gepard::Curves::GPDCurve3D
        {

        public:
            GPDEllipse();
            ~GPDEllipse();

            GPDEllipse( double r_small, double R_big, 
                        Gepard::BasicMath::GPDPoint location, 
                        Gepard::BasicMath::GPDVector direction, 
                        Gepard::BasicMath::GPDPoint Pstart, 
                        Gepard::BasicMath::GPDPoint Pend );
            /**
             * ����� ������
             */
            double r;
            /**
             * ������� ������
             */
            double R;
            /**
             * ����������� ����� ������� ����� � ��������
             */
            Gepard::BasicMath::GPDPoint Location;
            /**
             * ����������� - ������ �������� �������
             */
            Gepard::BasicMath::GPDVector Direction_vector;

            /**
             * ��������� ������ � �������� ����� �����
             */
            void calcEllipse(int numPoints = 0, bool checkPrec = true);

            /**
            * ��������� ������ � �������� ������ �����
            * (����� ������, ����� ����� ���������� ����� ����� � ��������� precDelta)
            */
            void calcCurve(unsigned int numPoints = 0, bool checkPrec = true) override;

            /**
             *  ������ ��������� ��� ������
             */
            void setParameters( double r_small, double R_big, 
                                Gepard::BasicMath::GPDPoint location, 
                                Gepard::BasicMath::GPDVector direction, 
                                Gepard::BasicMath::GPDPoint Pstart, 
                                Gepard::BasicMath::GPDPoint Pend );

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

            /**
            *	������ ���������
            */
            bool isEquivalent(Gepard::Curves::GPDCurve3DPtr curve3dPtr) override;

            private:
            /**
             *	��������� ���������� �� ���������
             */
            virtual void setDefaultParameters() override;


        };

    }

}

