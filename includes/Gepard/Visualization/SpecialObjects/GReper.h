///////////////////////////////////////////////////////////
// GReper.h
// Специальный объект - Репер
// Created on:      31-май-2014 13:38:14
// Original author: Anton
///////////////////////////////////////////////////////////

#ifndef GREPER_H
#define GREPER_H
#pragma once

#include "SpecialObject.h"
#include "GAxis.h"

namespace Gepard 
{
    namespace Visualization
    {

        namespace SpecialObjects 
        {

            /**
             *  Специальный графический объект - Репер
             */
            class GReper : public SpecialGObject
            {
            public:

                enum GR_TYPE
                {
                     GR_LINES       //Линии
                    ,GR_CONE_ARROW  //С коническими стрелками на линиях
                    ,GR_CONE_CYL    //Конусы и цилиндры
                };

                GReper(GFontManager *fManager=nullptr);

                /**
                 *  Установить координаты репера
                 */
                void SetCoords(GVector r, GVector e1, GVector e2, GVector e3);

                /**
                 *  Установить тип репера
                 */
                void SetType(GR_TYPE _type);

                /**
                 *  Показывать ли текст
                 */
                void ShowText(bool show = true);

                /**
                 *  Установить текст для меток
                 */
                void SetLabelText(std::string Rs, std::string E1s, std::string E2s, std::string E3s);

                /**
                 *  Установить масштабируемость объекта
                 */
                void SetScale(bool flag=true) override;

                /**
                 *  Установить значение коэффициента раз-масштабирования 
                 * (в случае, если scale_on = false)
                 */
                void SetUnScaleFactor(float unscale) override;

                /**
                 *  Функция отображения объекта
                 */          
                void Render() override;

            private:
                /**
                 *  Тип графического объекта
                 */
                GR_TYPE reper_type;          
                /**
                 *  Три оси
                 */
                GAxis E1,E2,E3;            
         
                /**
                 *  Показывать ли текстовые метки
                 */
                bool isShowText;          

            };
        } // SpecialObjects
    }//Visualization
}// Gepard 

#endif