///////////////////////////////////////////////////////////
// SpecialObject.h
// Специальный объект
// Created on:      30-май-2014 13:54:40
//  Original author: Anton
///////////////////////////////////////////////////////////

#ifndef SPECIALOBJECT_H
#define SPECIALOBJECT_H
#pragma once

#include "../gl_inc.h"
#include "../GColor.h"
#include "../GVector.h"
#include "../GText.h"
#include "../GFontManager.h"

namespace Gepard
{
    namespace Visualization
    {
        namespace SpecialObjects 
        {

            /**
             *  Базовый класс специального объекта
             */
            class SpecialGObject
            {
            public:
                enum SGO_TYPE
                {
                   SO_AXIS          //Ось
                  ,SO_REPER         //Репер
                  ,SO_POINT         //Точка
                  ,SO_APLANE        //Плоскость аннотации
                  ,SO_ATOL          //Аннотация допуска
                  ,SO_PREC_SCALE    //Шкала диаграммы точности
                };

                /**
                 *  Конструктор класса
                 */
                explicit SpecialGObject(SGO_TYPE oType, GFontManager *fManager=nullptr) 
                    : obj_type(oType)
                { 
                    visible  = true;
                    depth_on = true;
                    scale_on = true;

                    fontManager = fManager;
                    labelText._type = GTT_2D;
                    labelText._font = fontManager?fontManager->createLabelFont(12):nullptr;
                    unscale_factor = 1.0f;
                }

                /**
                 *  Получить тип объекта
                 */
                SGO_TYPE getType() { return obj_type; }

                /**
                 *  Функция отображения объекта
                 */
                virtual void Render() {}

                /**
                 *  Установить видиимость объекта
                 */
                virtual void SetVisible(bool flag=true) 
                { visible = flag; }

                /**
                 *  Установить флаг буфера глубины
                 */
                virtual void SetDepthBufferOn(bool flag=true)
                {  depth_on = flag;  }

                /**
                 *  Установить масштабируемость объекта
                 */
                virtual void SetScale(bool flag=true)
                {  scale_on = flag;  }

                /**
                 *  Установить значение коэффициента раз-масштабирования 
                 * (в случае, если scale_on = false)
                 */
                virtual void SetUnScaleFactor(float unscale)
                {  unscale_factor = unscale;  }

                /**
                 *  Видимый ли объект
                 */
                bool isVisible() {return visible;}

                /**
                 *  Нужно выводить объект с включенным буфером глубины
                 */
                bool isDepthOn() {return depth_on;}

                /**
                 *  Объект не должен масштабироваться
                 */
                bool isScaleOn() {return scale_on;}

            protected:
                /**
                 *  Тип специального объекта
                 */
                SGO_TYPE obj_type;

                /**
                 *  Объект является видимым
                 */
                bool visible;

                /**
                 *  Объект нужно выводить с буфером глубины
                 */
                bool depth_on;

                /**
                 *  Объект может масштабироваться
                 */
                bool scale_on;

                /**
                 *  Указатель на менеджер шрифтов
                 */
                GFontManager *fontManager;

                /**
                 *  Текст для отображения меток
                 */
                GText labelText;

                /**
                 *  Коэффициент масштабирования - для реализации scale_on = false
                 */
                float unscale_factor;
            };
        }//SpecialObjects
    }//Visualization
}//Gepard
#endif
