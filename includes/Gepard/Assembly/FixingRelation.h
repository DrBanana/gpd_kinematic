///////////////////////////////////////////////////////////
//  FixingRelation.cpp
//  –еализаци€ 	Class FixingRelation
//  —оздана:   	20-июл-2010 14:59:18
//  јвтор: 		Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_73FEAD2D_DD7F_40dd_BEF5_D741340AAE0A__INCLUDED_)
#define EA_73FEAD2D_DD7F_40dd_BEF5_D741340AAE0A__INCLUDED_

#include "../Surfaces/GPDSurface.h"
#include "FixingRelationType.h"
#include "basicDOF.h"

namespace Gepard
{
    namespace Assembly
    {
        /**
         * ”слови€ закреплени€
         */
        class MatingRelation;
        class FixingRelation : public Gepard::Assembly::basicDOF
        {

        public:
            FixingRelation();
            ~FixingRelation();
            /**
             * «акрепл€ема€ поверхность - т.е. репер данной поверхности 
             */
            Gepard::Surfaces::GPDSurfacePtr fastenedSurface;

            /**
             *	”казатель на закрепл€емый репер
             */
            Gepard::BasicMath::GPDReperPtr fastenedReperPtr;

            /**
             * «акрепл€ющий репер (система координат), относительно которого задано условие закреплени€
             */
            Gepard::BasicMath::GPDReper fixativeReper;

            /**
             *	“ип данного закреплени€
             */
            FixingRelationType relationType;

            /**
             *	”казатель на условие сопр€жени€ - из-за которого получилось данное условие закреплени€
             */
            MatingRelation *parentMatingRelation;

            /**
             *	ѕроверка вектора сдвига на удовлетворение данному условию закреплени€
             * если true - двигать можно, если false - движение в данном направлении запрещено
             */
            bool CheckFixing(Gepard::BasicMath::GPDVector Vector);

            /**
             *	ѕроверка услови€ поворота на удовлетворение данному условию закреплени€
             * если true - поворачивать можно, если false - поворот на данный угол относительно оси запрещен
             */
            bool CheckFixing(Gepard::BasicMath::GPDVector axis, double fi);

            /**
             *	‘ункци€ вычисл€ет проекции на все разрешенные направлени€
             *  + получает результирующий вектор сдвига по разрешенным направлени€м 
             */
            Gepard::BasicMath::GPDVector calcProjection(Gepard::BasicMath::GPDVector Vector);

            /**
             *  ѕроверка, €вл€етс€ ли заданное условие идентичным текущему
             */
            bool isEquals(FixingRelation& fr_ref);

            //перегруженный оператор вывода
            friend ostream& FixingRelation::operator<<(ostream& os, FixingRelation &fixRel)
            {    
                int fType = (int)fixRel.relationType;
                os.write((char *) &fType, sizeof fType);
                             
                os << fixRel.fixativeReper;

                os << fixRel.aE1 << fixRel.aE2 << fixRel.aE3;
                os << fixRel.dE1 << fixRel.dE2 << fixRel.dE3;

                return os;
            }

            //перегруженный оператор ввода
            friend istream& FixingRelation::operator>>(istream& is, FixingRelation &fixRel)
            {   
                int fType = 0;
                is.read((char *) &fType, sizeof fType);

                fixRel.relationType = (FixingRelationType)fType;                                
                is >> fixRel.fixativeReper;
                                                                
                is >> fixRel.aE1 >> fixRel.aE2 >> fixRel.aE3;
                is >> fixRel.dE1 >> fixRel.dE2 >> fixRel.dE3;

                return is;
            }

        private: 
            /**
             *	ѕроверка на запрет всех перемещений
             */
            bool CheckIfFixedEverything();
            /**
             *	ѕроверка на разрешение всех перемещений
             */
            bool CheckIfUnFixedEverything();

            /**
             * можно ли перемещатьс€ по Ex
             *	если да, то projVector - вектор проекции на Ex, x = {1,2,3}
             */
            bool checkFixingEx(int x, Gepard::BasicMath::GPDVector Vector, Gepard::BasicMath::GPDVector *projVector=NULL);

        };

    }

}
#endif // !defined(EA_73FEAD2D_DD7F_40dd_BEF5_D741340AAE0A__INCLUDED_)
