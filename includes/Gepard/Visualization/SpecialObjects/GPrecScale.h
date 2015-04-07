///////////////////////////////////////////////////////////
// GPrecScale.h
// Специальный объект - шкала диаграммы точности
// Created on:      15-окт-2014 11:10
// Original author: Anton
///////////////////////////////////////////////////////////

#ifndef GPRECSCALE_H
#define GPRECSCALE_H

#include "SpecialObject.h"
#include <string>

namespace Gepard 
{
    namespace Visualization 
    {
        namespace SpecialObjects 
        {

            /**
             *  Специальный объект - шкала диаграммы точности
             */
            class GPrecScale : public SpecialGObject
            {
            public:
                 /**
                 *  Конструктор класса
                 */
                GPrecScale(GFontManager *fManager=nullptr);                
                
                /**
                 *  Установить значения натягов
                 */
                void SetTightness(double max, double min);

                /**
                 *  Установить значения зазоров
                 */
                void SetClearance(double max, double min);

                /**
                 *  Установить значение max зазора (gap) и натяга (interference)
                 */
                void SetGapAndInterference(double max_gap, double max_interference);

                /**
                 *  Функция отображения объекта
                 */
                void Render() override;

            private:
                
                /**
                *	Значение max натяга
                */		
                double max_tightness;
                /**
                *	Значение min натяга
                */
                double min_tightness;
                /**
                *	Значение max зазора
                */
                double max_clearance;
                /**
                *	Значение min зазора
                */
                double min_clearance;

                /**
                 *  Отобразить список текстов
                 */
                void RenderTextList(double x0, double cur_t, double cur_y, double t_step, double y_step, unsigned int countPoints);

            };


        };
    };
};

#endif