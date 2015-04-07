///////////////////////////////////////////////////////////
// GAxis.h
// Специальный объект - Ось
// Created on:      30-май-2014 14:15:21
// Original author: Anton
///////////////////////////////////////////////////////////

#ifndef GAXIS_H
#define GAXIS_H
#pragma once

#include "SpecialObject.h"
#include <string>

namespace Gepard
{
    namespace Visualization
    {
        namespace SpecialObjects 
        {

            /**
             *  Специальный объект - ось
             */
            class GAxis : public SpecialGObject
            {
            public:

                enum AXIS_TYPE
                {
                     AT_LINE        //Просто линия
                    ,AT_CONE_ARROW  //Линия со стрелкой в виде конуса
                    ,AT_CONE_CYL    //Цилиндр и стрелка в виде конуса
                };

                /**
                 *  Конструктор класса
                 */
                GAxis(GFontManager *fManager=nullptr);
                ~GAxis();

                /**
                 *  Установить цвет
                 */
                void SetColor(GColor color);

                /**
                 *  Установить координаты оси
                 */
                void SetCoords( float x0,float y0,float z0,
                                float x1,float y1,float z1 );

                /**
                 *  Установить координаты оси
                 */
                void SetCoords( GVector _p0, GVector _p1 );

                /**
                 *  Установить тип оси
                 */
                void SetAxisType(AXIS_TYPE _type);

                /**
                 *  Показывать ли текст
                 */
                void ShowText(bool show = true);

                /**
                 *  Установить текст метки
                 */
                void SetLabelText(std::string _text);

                 /**
                 *  Функция отображения объекта
                 */
                void Render() override;

            private:

                /**
                 *  Рассчитать угол и ориентацию в зависимости от координат
                 */
                void calcAngleOrient();

                /**
                 *  Тип оси
                 */
                AXIS_TYPE axis_type;

                /**
                 *  Цвет оси
                 */
                GColor axis_color;

                /**
                 *  Координаты оси
                 */
                GVector p0, p1;

                /**
                 *  Объект для отображения цилиндра
                 */
                GLUquadricObj *ArrowCylinder;

                /**
                 *  Угол ориентации
                 */
                float axis_angle;

                /**
                 *  Вектор ориентации
                 */
                GVector orient;
                      
                /**
                 *  Показывать ли текстовые метки
                 */
                bool isShowText;          

            };
        }//SpecialObjects
    }//Visualization
}//Gepard

#endif
