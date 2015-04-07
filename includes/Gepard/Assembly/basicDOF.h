///////////////////////////////////////////////////////////
//  basicDOF.cpp
//  ���������� 	Class basicDOF
//  �������:   	20-���-2010 19:13:30
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_DCD59602_D472_4663_88FA_E4BDA7D909EA__INCLUDED_)
#define EA_DCD59602_D472_4663_88FA_E4BDA7D909EA__INCLUDED_

#include "axisFixing.h"

namespace Gepard
{
    namespace Assembly
    {
        /**
         * ����� �������� ������� (Degree of freedom)
         */
        class basicDOF
        {

        public:

            /**
             *	����������� �� ������������ ������
             */
            axisFixing dE1, dE2, dE3;

            /**
             *	����������� �� �������� ������������ ���� ������
             */
            axisFixing aE1, aE2, aE3;

            /**
             * ��������� �� ���� ������������
             */
            void fixEverything();

            /**
             * ������ ����������� �� ���� ������������
             */
            void unfixEverything();

            basicDOF();
            ~basicDOF();

        };

    }

}
#endif // !defined(EA_DCD59602_D472_4663_88FA_E4BDA7D909EA__INCLUDED_)
