///////////////////////////////////////////////////////////
//  KF_MinMaxIntersection.h
//  Ключевое свойство - Максимальное и минимальное врезание
//  Создано:  6-окт-2014
//  Оригинальный автор: Anton
///////////////////////////////////////////////////////////


#pragma once

#include "KF_MinMaxRelation.h"

namespace Gepard 
{
    namespace Analysis 
    {
        /**
         *  Ключевое свойство - Максимальное и минимальное врезание
         */
        class KF_MinMaxIntersection : public KF_MinMaxRelation                                 
        {
        public:
            KF_MinMaxIntersection();
        };
    }
}