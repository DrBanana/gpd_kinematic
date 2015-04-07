///////////////////////////////////////////////////////////
//  FixingRelationArray.cpp
//  –еализаци€ 	Class FixingRelationArray
//  —оздана:   	20-июл-2010 15:38:14
//  јвтор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_982A14DC_BCFF_40f5_B96C_189D12AC4A2D__INCLUDED_)
#define EA_982A14DC_BCFF_40f5_B96C_189D12AC4A2D__INCLUDED_

#include "../General/basicList.h"
#include "FixingRelation.h"

namespace Gepard
{
    namespace Assembly
    {
        /**
         * ћассив закреплений
         */
        class FixingRelationArray : public Gepard::General::basicList<FixingRelation>
        {

        public:
            FixingRelationArray();
            ~FixingRelationArray();

            /**
             *	ѕроверка условий сопр€жений
             *	если true - двигать можно, если false - движение в данном направлении запрещено
             */
            bool CheckFixing(Gepard::BasicMath::GPDVector Vector);

            /**
             *	ѕроверка условий сопр€жений
             *	если true - двигать можно, если false - движение в данном направлении запрещено
             */
            bool CheckFixing(Gepard::BasicMath::GPDVector axis, double fi);

            /**
             *	‘ункци€ вычисл€ет проекции на все разрешенные направлени€
             *  + получает результирующий вектор сдвига по разрешенным направлени€м 
             */
            Gepard::BasicMath::GPDVector calcProjection(Gepard::BasicMath::GPDVector Vector);

            /**
             *	¬озвращает ось, относительно которой можно инвертировать репер - true
             *	либо сообщает о невозможности инвертировани€ (услови€ закреплени€ не позвол€ют) - false
             *	¬ходные параметры:	ќсь репера, который надо инвертировать (reper_axis)
             *	¬ыходные параметры: ѕолученна€ ось, относительно которой надо вращать на угол Pi (rot_axis)
             *	≈сли rot_axis = reper_axis и вернулось false, значит нет условий закреплений - можно использовать
             *	любую ось, ортогональную reper_axis
             */
            bool getInvertAxis(Gepard::BasicMath::GPDVector reper_axis,Gepard::BasicMath::GPDVector &rot_axis );


            /**
             *	ƒобавить новое условие закреплени€ - с проверкой, есть ли уже такое условие
             */
            void AddFixingRelation(FixingRelation &fixingRel);


        };

    }

}
#endif // !defined(EA_982A14DC_BCFF_40f5_B96C_189D12AC4A2D__INCLUDED_)
