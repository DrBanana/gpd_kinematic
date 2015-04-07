///////////////////////////////////////////////////////////
//  GPDLine.cpp
//  ���������� 	Class GPDLine
//  �������:   	23-���-2010 10:58:23
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////
#pragma once

#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDVector.h"
#include "GPDCurve3D.h"

namespace Gepard
{
    namespace Curves
    {
        class GPDLine : public Gepard::Curves::GPDCurve3D
        {

        public:
            GPDLine();
            ~GPDLine();

            /**
             *  �����������
             */
            GPDLine( Gepard::BasicMath::GPDPoint PStart, 
                     Gepard::BasicMath::GPDPoint PEnd );

            /**
            *	��������� ����� �� �������� ����������
            */
            void calcLine(unsigned int numPoints=0);

            /**
             * ��������� ������ � �������� ������ �����
             */
            void calcCurve(unsigned int numPoints=0) override;

            /**
             *  ������ ��������� ��� ������
             */
            void setParameters( Gepard::BasicMath::GPDPoint PStart, 
                                Gepard::BasicMath::GPDPoint PEnd );                        

        private:
            /**
             *	��������� ���������� �� ���������
             */
            void setDefaultParameters();
        };

    }

}

