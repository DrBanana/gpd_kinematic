///////////////////////////////////////////////////////////
//  TC_counters
//  Счетчики точек К.П.
//  Создана:   	 22-сен-2014 14:21
//  Автор: 		 Dr_Freeman
///////////////////////////////////////////////////////////

#ifndef TCCOUNTERS_H
#define TCCOUNTERS_H

#include <vector>
#include "../Tolerances/Tolerance.h"

namespace Gepard 
{    
    namespace Analysis 
    {

        // Структура счетчика точек К.П.
        struct TC_counter
        {
            unsigned int maxCS;     //Максимальное число точек К.П.
            unsigned int index;     //Текущее значение индекса счетчика

            TC_counter() {maxCS = index = 0;}
            TC_counter(unsigned int _max, unsigned int _ind)
                           : maxCS(_max), index(_ind){}
        };

        //Массив счетчиков
        class TC_counters : public std::vector<TC_counter>
        {
        public:
            TC_counters();
            TC_counters( Gepard::Tolerances::TolerancePtrArray *tArray );

            /**
             *  Инкремент счетчиков
             */
            void operator++(int);
           
            /**
             *  Получить общее число вариантов
             */
            unsigned int total();

            /**
             *  Сброс счетчика
             */
            void setNull();

            /**
             *  Установить счетчик по индексу
             */
            void setCounter(unsigned int index);

            /**
             *  Получить текущий индекс точки
             */
            unsigned int getCurrentIndex();

        private:
            /**
             *  Текущий индекс точки К.П.
             */
            unsigned int tc_index;
        };

    }//Analysis
}//Gepard
#endif