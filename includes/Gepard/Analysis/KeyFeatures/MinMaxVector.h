///////////////////////////////////////////////////////////
//  MinMaxVector.h
//  ����������� ������ � �������
//  �������:  2-���-2014
//  ������������ �����: Anton
//  ��������: ����������� �������� - ��� ����������
//            ������������ ������/��������
///////////////////////////////////////////////////////////

#pragma once

#include "../../BasicMath/GPDVector.h"
#include "../../BasicMath/GPDPoint.h"

namespace Gepard 
{
    namespace Analysis 
    {
        /**
         *  ����������� ������ � �������
         */
        struct MinMaxVector
        {       
            /**
             *  ������ ��������
             */
            Gepard::BasicMath::GPDVector vector_min;

            /**
             *  ������ ���������
             */
            Gepard::BasicMath::GPDVector vector_max;

            /**
             *  ����� �� ������� ����� ��� ��������
             */
            Gepard::BasicMath::GPDPoint p_base_min;

            /**
             *  ����� �� ������� ����� ��� ���������
             */
            Gepard::BasicMath::GPDPoint p_base_max;

            /**
             *  ����� �� ��������� ����� ��� ��������
             */
            Gepard::BasicMath::GPDPoint p_dep_min;

            /**
             *  ����� �� ��������� ����� ��� ���������
             */
            Gepard::BasicMath::GPDPoint p_dep_max;

        };
    }
}
