///////////////////////////////////////////////////////////
//  MinMaxVector.h
//  Минимаксный вектор с точками
//  Создано:  2-окт-2014
//  Оригинальный автор: Anton
//  Описание: Виртуальная сущность - для реализации
//            минимаксного зазора/врезания
///////////////////////////////////////////////////////////

#pragma once

#include "../../BasicMath/GPDVector.h"
#include "../../BasicMath/GPDPoint.h"

namespace Gepard 
{
    namespace Analysis 
    {
        /**
         *  Минимаксный вектор с точками
         */
        struct MinMaxVector
        {       
            /**
             *  Вектор минимума
             */
            Gepard::BasicMath::GPDVector vector_min;

            /**
             *  Вектор максимума
             */
            Gepard::BasicMath::GPDVector vector_max;

            /**
             *  Точка на базовой грани для минимума
             */
            Gepard::BasicMath::GPDPoint p_base_min;

            /**
             *  Точка на базовой грани для максимума
             */
            Gepard::BasicMath::GPDPoint p_base_max;

            /**
             *  Точка на зависимой грани для минимума
             */
            Gepard::BasicMath::GPDPoint p_dep_min;

            /**
             *  Точка на зависимой грани для максимума
             */
            Gepard::BasicMath::GPDPoint p_dep_max;

        };
    }
}
