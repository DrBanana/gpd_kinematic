///////////////////////////////////////////////////////////
//  GText.h
//  Текст для отображения в модуле визуализации
//  Created on:      16-май-2014 15:24:33
//  Original author: Anton
///////////////////////////////////////////////////////////

#ifndef GTEXT_H
#define GTEXT_H

#include "gl_inc.h"

#include <string>
#include "GVector.h"
#include "GFontManager.h"
#include "GColor.h"

namespace Gepard
{
    namespace Visualization
    {

        /**
         *  Тип текста
         */
        enum GTextType { GTT_2D, GTT_3D, GTT_INFO };

        /**
         *  Структура, определяющая ориентацию текста в пространстве
         */
        struct GTextOrientation
        {
            float fi;   //Угол ориентации fi
            float psi;  //Угол ориентации psi

            GVector fi_vector;  //Вектор ориентации для угла fi
            GVector psi_vector; //Вектор ориентации для угла psi

            GTextOrientation()
            {
                fi = 0.0f;
                psi = 0.0f;
            }
        };

        /**
         *  Структура типа Графический текст
         */
        class GText
        {
        public:

            GTextType           _type;   //Тип шрифта
            std::string         _text;   //Текст для отображения
            GColor              _color;  //Цвет шрифта
            FTFont*             _font;   //Шрифт (Удалять его не надо, это сделает FontManager)
            FTPoint             _pos;    //Позиция
            GTextOrientation    _orient; //Ориентация 3D текста

            //Конструктор
            GText();

            /**
             *  Отобразить текст
             */
            void Render();
        };
    }//Visualization
}//Gepard

#endif // GTEXT_H
