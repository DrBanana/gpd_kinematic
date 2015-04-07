///////////////////////////////////////////////////////////
//  vFuncs.h
//  �������������� ����������� �������
//  �������:   	21-���-2014 14:30:10
//  �����: 		Freeman
///////////////////////////////////////////////////////////

#pragma once

#include <vector>

namespace Gepard 
{
    namespace Visualization 
    {
        /**
         *  ��������� ������� ���������� �� �������� ����������� 
         */
        void calcWorldFrom2DCoords(int x, int y, double (&coords)[3], double z = 0.0 );

        /**
         *  ��������� ���������� �������������� �������
         */
        void calc_select_line(int mouse_x, int mouse_y, std::vector<float> &sel);

        /**
         *  �������� 3D ���������� �� ����������� 2D
         */
        void GetOGLPos(int x, int y, std::vector<float> &vec);
      
    }//Visualization
}//Gepard