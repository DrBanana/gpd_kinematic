///////////////////////////////////////////////////////////
//  TC_counters
//  �������� ����� �.�.
//  �������:   	 22-���-2014 14:21
//  �����: 		 Dr_Freeman
///////////////////////////////////////////////////////////

#ifndef TCCOUNTERS_H
#define TCCOUNTERS_H

#include <vector>
#include "../Tolerances/Tolerance.h"

namespace Gepard 
{    
    namespace Analysis 
    {

        // ��������� �������� ����� �.�.
        struct TC_counter
        {
            unsigned int maxCS;     //������������ ����� ����� �.�.
            unsigned int index;     //������� �������� ������� ��������

            TC_counter() {maxCS = index = 0;}
            TC_counter(unsigned int _max, unsigned int _ind)
                           : maxCS(_max), index(_ind){}
        };

        //������ ���������
        class TC_counters : public std::vector<TC_counter>
        {
        public:
            TC_counters();
            TC_counters( Gepard::Tolerances::TolerancePtrArray *tArray );

            /**
             *  ��������� ���������
             */
            void operator++(int);
           
            /**
             *  �������� ����� ����� ���������
             */
            unsigned int total();

            /**
             *  ����� ��������
             */
            void setNull();

            /**
             *  ���������� ������� �� �������
             */
            void setCounter(unsigned int index);

            /**
             *  �������� ������� ������ �����
             */
            unsigned int getCurrentIndex();

        private:
            /**
             *  ������� ������ ����� �.�.
             */
            unsigned int tc_index;
        };

    }//Analysis
}//Gepard
#endif