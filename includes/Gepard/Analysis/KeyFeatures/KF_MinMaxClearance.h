///////////////////////////////////////////////////////////
//  KF_MinMaxClearance.h
//  Ключевое свойство - Максимальный и минимальный зазор
//  Создано:  2-окт-2014
//  Оригинальный автор: Anton
///////////////////////////////////////////////////////////

#pragma once

#include "KF_MinMaxRelation.h"

namespace Gepard 
{    
    namespace Analysis 
    {
        /**
         *  Ключевое свойство - Максимальный и минимальный зазор
         */
        class KF_MinMaxClearance : public KF_MinMaxRelation                                 
        {
        public:
            KF_MinMaxClearance();         
        };
    }
}
