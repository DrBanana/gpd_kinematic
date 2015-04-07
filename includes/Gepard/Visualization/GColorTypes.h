#pragma once
#include <vector>

namespace Gepard
{
    namespace Visualization
    {
        /**
            ����� ����� ������ ����������� ����� ��� ����������
            http://www.stm.dp.ua/web-design/color-html.php 
         */
 
         struct __GColorType
         {
            char color_name[50]; //�������� �����
            int R,G,B; //�������� RGB
            float r,g,b; //�������� RGB
         };
 
         //������ ������
         class GColorTypes
         {
        public: 
            std::vector<__GColorType> COLORS; //������ �������� ����������� �����
        public:
            GColorTypes();
            ~GColorTypes();
        
            void AddColorToArray(int R, int G, int B, char *color_name); //�������� ���� � ������
            void FillColorArray(); //��������� ������ ������
            __GColorType getColorByName(char clrName[50]);
            __GColorType getRandomColor(); //�������� ��������� ����
         };
 
         extern GColorTypes G_COLORTYPES_ARRAY; //������ ����������� ������
    }
}