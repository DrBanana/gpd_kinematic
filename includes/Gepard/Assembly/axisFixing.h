///////////////////////////////////////////////////////////
//  axisFixing.cpp
//  Реализация 	Class axisFixing
//  Создана:   	25-сен-2010 13:36:25
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_785255EF_6B55_4b4c_9CCE_DD0D837B59E9__INCLUDED_)
#define EA_785255EF_6B55_4b4c_9CCE_DD0D837B59E9__INCLUDED_

#include "axisFixingType.h"

#include <fstream>

using namespace std;

namespace Gepard
{
    namespace Assembly
    {
        /**
         * Структура закрепления оси
         */
        class axisFixing
        {

        public:
            axisFixing();
            ~axisFixing();

            bool operator==(axisFixingType fixType);
            void operator=(axisFixingType fixType);
            void operator=(axisFixing _axfixing);
            void operator=(double _value); 			
            /**
             * получить значение (в случае двойного значения, возвращается value_min)
             */
            double val();
            /**
             * установить значение (в случае двойного значения, устанавливается value_min)
             */
            void val(double _value);
            /**
             * Возврат минимального значения в случае двойного значения
             */
            double val_min();
            /**
             * возврат максимального значения в случае двойного значения
             */
            double val_max();
            /**
             * установить минимальное значение в случае минимального значения
             */
            void val_min(double v_min);
            /**
             * установить максимальное значение в случае двойного значения
             */
            void val_max(double v_max);

            /**
             * тип закрепления оси
             */
            Gepard::Assembly::axisFixingType axis_fixing_type;

            
            //перегруженный оператор вывода
            friend ostream& axisFixing::operator<<(ostream& os, axisFixing &fixRel)
            {    
                unsigned int fType = fixRel.axis_fixing_type;
                os.write((char*) &fType, sizeof fType);
                os.write((char*) &fixRel.value_min, sizeof fixRel.value_min);
                os.write((char*) &fixRel.value_max, sizeof fixRel.value_max);
                return os;
            }

            //перегруженный оператор ввода
            friend istream& axisFixing::operator>>(istream& is, axisFixing &fixRel)
            {    
                unsigned int fType = 0;
                is.read((char*) &fType, sizeof fType);
                is.read((char*) &fixRel.value_min, sizeof fixRel.value_min);
                is.read((char*) &fixRel.value_max, sizeof fixRel.value_max);

                fixRel.axis_fixing_type = (Gepard::Assembly::axisFixingType)fType;

                return is;
            }

        private:
            /**
             * значение - минимум
             */
            double value_min;
            /**
             * значение-максимум
             */
            double value_max;

        };

    }

}
#endif // !defined(EA_785255EF_6B55_4b4c_9CCE_DD0D837B59E9__INCLUDED_)
