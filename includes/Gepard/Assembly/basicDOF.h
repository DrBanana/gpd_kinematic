///////////////////////////////////////////////////////////
//  basicDOF.cpp
//  Реализация 	Class basicDOF
//  Создана:   	20-июл-2010 19:13:30
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_DCD59602_D472_4663_88FA_E4BDA7D909EA__INCLUDED_)
#define EA_DCD59602_D472_4663_88FA_E4BDA7D909EA__INCLUDED_

#include "axisFixing.h"

namespace Gepard
{
    namespace Assembly
    {
        /**
         * Класс Степеней свободы (Degree of freedom)
         */
        class basicDOF
        {

        public:

            /**
             *	закрепление по передвижению репера
             */
            axisFixing dE1, dE2, dE3;

            /**
             *	закрепление по повороту относительно осей репера
             */
            axisFixing aE1, aE2, aE3;

            /**
             * Закрепить по всем направлениям
             */
            void fixEverything();

            /**
             * Убрать закрепление по всем направлениям
             */
            void unfixEverything();

            basicDOF();
            ~basicDOF();

        };

    }

}
#endif // !defined(EA_DCD59602_D472_4663_88FA_E4BDA7D909EA__INCLUDED_)
