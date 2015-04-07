///////////////////////////////////////////////////////////
//  vFuncs.h
//  Дополнительные графические функции
//  Создана:   	21-фев-2014 14:30:10
//  Автор: 		Freeman
///////////////////////////////////////////////////////////

#pragma once

#include <vector>

namespace Gepard 
{
    namespace Visualization 
    {
        /**
         *  Вычислить мировые координаты по экранным координатам 
         */
        void calcWorldFrom2DCoords(int x, int y, double (&coords)[3], double z = 0.0 );

        /**
         *  Вычислить координаты селектирующего отрезка
         */
        void calc_select_line(int mouse_x, int mouse_y, std::vector<float> &sel);

        /**
         *  Получить 3D координаты по координатам 2D
         */
        void GetOGLPos(int x, int y, std::vector<float> &vec);
      
    }//Visualization
}//Gepard