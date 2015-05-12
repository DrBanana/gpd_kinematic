///////////////////////////////////////////////////////////
//  GPDCircle.cpp
//  ���������� 	Class GPDCircle
//  �������:   	04-���-2010 17:20:51
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////
#pragma once

#include "GPDEllipse.h"

namespace Gepard
{
    namespace Curves
    {
        class GPDCircle : public Gepard::Curves::GPDEllipse
        {

        public:
            GPDCircle();
            ~GPDCircle();
                        
            GPDCircle( double radius, Gepard::BasicMath::GPDPoint location, Gepard::BasicMath::GPDVector direction, 
                                      Gepard::BasicMath::GPDPoint PStart,   Gepard::BasicMath::GPDPoint PEnd);

            /**
            *	��������� ���������� � �������� ������ �����
            */
            void calcCircle( unsigned int numPoints=0, bool checkPrec = true );

            /**
            * ��������� ������ � �������� ������ �����
            * (����� ������, ����� ����� ���������� ����� ����� � ��������� precDelta)
            */
            void calcCurve(unsigned int numPoints = 0, bool checkPrec = true) override;

            /**
             *  ������ ��������� ��� ������
             */
            void setParameters( double radius,
                                Gepard::BasicMath::GPDPoint location, 
                                Gepard::BasicMath::GPDVector direction, 
                                Gepard::BasicMath::GPDPoint PStart, 
                                Gepard::BasicMath::GPDPoint PEnd );                        

            /**
             *  ����������� ����� ������ �� ������� ��������� oldReper � ������� ��������� newReper
             */
            void ConvertToBasis( Gepard::BasicMath::GPDReper &oldReper, 
                                 Gepard::BasicMath::GPDReper &newReper) override;

        private:
            /**
             *	��������� ���������� �� ���������
             */
            void setDefaultParameters() override;
        };

    }

}

