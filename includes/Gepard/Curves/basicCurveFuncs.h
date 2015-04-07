///////////////////////////////////////////////////////////
//  basicCurveFuncs
//  ���������� 	������� ������� ������ � �������
//  �������:   	28-���-2012 15:56:45
//  �����: 		Anton
///////////////////////////////////////////////////////////
#pragma once
#include "..\BasicMath\GPDPoint2dn.h"
#include "..\BasicMath\GPDPoint2d.h"


namespace Gepard
{
    namespace Curves
    {
        /**
         * ������� ���������� �������� � ���� ������ (2D)
         */
        void calcThreeNormals(	Gepard::BasicMath::GPDPoint2dnPtr P1, 
                                Gepard::BasicMath::GPDPoint2dnPtr P2, 
                                Gepard::BasicMath::GPDPoint2dnPtr P3);

        /**
         *	��������� ���� ����� � ����������� ���������.
         *	����� �� ����� (� ��������� �� minimumPrecision*delta)
         */
        bool isPointsEquals(Gepard::BasicMath::GPDPoint2dPtr P1,
                            Gepard::BasicMath::GPDPoint2dPtr P2, double delta = 1.0);
    };
};