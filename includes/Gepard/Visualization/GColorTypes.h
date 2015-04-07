#pragma once
#include <vector>

namespace Gepard
{
    namespace Visualization
    {
        /**
            здесь нужно задать стандартные цвета для примитивов
            http://www.stm.dp.ua/web-design/color-html.php 
         */
 
         struct __GColorType
         {
            char color_name[50]; //название цвета
            int R,G,B; //значения RGB
            float r,g,b; //значения RGB
         };
 
         //массив цветов
         class GColorTypes
         {
        public: 
            std::vector<__GColorType> COLORS; //массив содержит стандартные цвета
        public:
            GColorTypes();
            ~GColorTypes();
        
            void AddColorToArray(int R, int G, int B, char *color_name); //добавить цвет в массив
            void FillColorArray(); //заполнить массив цветов
            __GColorType getColorByName(char clrName[50]);
            __GColorType getRandomColor(); //получить случайный цвет
         };
 
         extern GColorTypes G_COLORTYPES_ARRAY; //массив стандартных цветов
    }
}