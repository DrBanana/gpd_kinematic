///////////////////////////////////////////////////////////
//  AnalysisEntity.h
//  Абстрактная сущность, используемая в анализе
//  Создано:  30-сен-2014
//	Оригинальный автор: Anton
///////////////////////////////////////////////////////////

#pragma once

#include "../General/basicList.h"
#include "../General/basicArray.h"

namespace Gepard 
{
    namespace Analysis 
    {    
        /**
         *	Тип сущности
         */
        enum ANALYSIS_ENT_TYPE 
        {            
            AET_CP_TOLERANCE,          //Допуск
            AET_CP_FIT,                //Посадка
            AET_AR_MATING_RELATION,    //Условие сопряжения
            AET_AR_OTHER			   //Другое - тут нужно придумать еще типы
        };
    
        /**
         *	Абстрактная сущность
         */
        struct AnalysisEntity
        {
            /**
             *	Тип правила анализа
             */
            ANALYSIS_ENT_TYPE _type;
            /**
             *	Указатель на класс сущности
             *	(каждый тип обрабатывается по-разному)
             */
            void* _data;
        };
        /**
         *  Список сущностей
         */
        class AnalysisEntityList : public Gepard::General::basicList<AnalysisEntity>
        {
        public:
            /**
             *  Найти параметр по указателю
             */
            int findByData(void *p)
            {
                set_start();
                while (auto e = get_next())
                {
                    if (e->_data == p) return get_current_index();
                }
                return -1;
            }
        };
    }//Analysis
}//Gepard
