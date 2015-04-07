///////////////////////////////////////////////////////////
//  axisFixing.cpp
//  ���������� 	Class axisFixing
//  �������:   	25-���-2010 13:36:25
//  �����: 		Dr_Freeman
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
         * ��������� ����������� ���
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
             * �������� �������� (� ������ �������� ��������, ������������ value_min)
             */
            double val();
            /**
             * ���������� �������� (� ������ �������� ��������, ��������������� value_min)
             */
            void val(double _value);
            /**
             * ������� ������������ �������� � ������ �������� ��������
             */
            double val_min();
            /**
             * ������� ������������� �������� � ������ �������� ��������
             */
            double val_max();
            /**
             * ���������� ����������� �������� � ������ ������������ ��������
             */
            void val_min(double v_min);
            /**
             * ���������� ������������ �������� � ������ �������� ��������
             */
            void val_max(double v_max);

            /**
             * ��� ����������� ���
             */
            Gepard::Assembly::axisFixingType axis_fixing_type;

            
            //������������� �������� ������
            friend ostream& axisFixing::operator<<(ostream& os, axisFixing &fixRel)
            {    
                unsigned int fType = fixRel.axis_fixing_type;
                os.write((char*) &fType, sizeof fType);
                os.write((char*) &fixRel.value_min, sizeof fixRel.value_min);
                os.write((char*) &fixRel.value_max, sizeof fixRel.value_max);
                return os;
            }

            //������������� �������� �����
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
             * �������� - �������
             */
            double value_min;
            /**
             * ��������-��������
             */
            double value_max;

        };

    }

}
#endif // !defined(EA_785255EF_6B55_4b4c_9CCE_DD0D837B59E9__INCLUDED_)
