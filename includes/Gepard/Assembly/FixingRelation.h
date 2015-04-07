///////////////////////////////////////////////////////////
//  FixingRelation.cpp
//  ���������� 	Class FixingRelation
//  �������:   	20-���-2010 14:59:18
//  �����: 		Freeman
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
         * ������� �����������
         */
        class MatingRelation;
        class FixingRelation : public Gepard::Assembly::basicDOF
        {

        public:
            FixingRelation();
            ~FixingRelation();
            /**
             * ������������ ����������� - �.�. ����� ������ ����������� 
             */
            Gepard::Surfaces::GPDSurfacePtr fastenedSurface;

            /**
             *	��������� �� ������������ �����
             */
            Gepard::BasicMath::GPDReperPtr fastenedReperPtr;

            /**
             * ������������ ����� (������� ���������), ������������ �������� ������ ������� �����������
             */
            Gepard::BasicMath::GPDReper fixativeReper;

            /**
             *	��� ������� �����������
             */
            FixingRelationType relationType;

            /**
             *	��������� �� ������� ���������� - ��-�� �������� ���������� ������ ������� �����������
             */
            MatingRelation *parentMatingRelation;

            /**
             *	�������� ������� ������ �� �������������� ������� ������� �����������
             * ���� true - ������� �����, ���� false - �������� � ������ ����������� ���������
             */
            bool CheckFixing(Gepard::BasicMath::GPDVector Vector);

            /**
             *	�������� ������� �������� �� �������������� ������� ������� �����������
             * ���� true - ������������ �����, ���� false - ������� �� ������ ���� ������������ ��� ��������
             */
            bool CheckFixing(Gepard::BasicMath::GPDVector axis, double fi);

            /**
             *	������� ��������� �������� �� ��� ����������� �����������
             *  + �������� �������������� ������ ������ �� ����������� ������������ 
             */
            Gepard::BasicMath::GPDVector calcProjection(Gepard::BasicMath::GPDVector Vector);

            /**
             *  ��������, �������� �� �������� ������� ���������� ��������
             */
            bool isEquals(FixingRelation& fr_ref);

            //������������� �������� ������
            friend ostream& FixingRelation::operator<<(ostream& os, FixingRelation &fixRel)
            {    
                int fType = (int)fixRel.relationType;
                os.write((char *) &fType, sizeof fType);
                             
                os << fixRel.fixativeReper;

                os << fixRel.aE1 << fixRel.aE2 << fixRel.aE3;
                os << fixRel.dE1 << fixRel.dE2 << fixRel.dE3;

                return os;
            }

            //������������� �������� �����
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
             *	�������� �� ������ ���� �����������
             */
            bool CheckIfFixedEverything();
            /**
             *	�������� �� ���������� ���� �����������
             */
            bool CheckIfUnFixedEverything();

            /**
             * ����� �� ������������ �� Ex
             *	���� ��, �� projVector - ������ �������� �� Ex, x = {1,2,3}
             */
            bool checkFixingEx(int x, Gepard::BasicMath::GPDVector Vector, Gepard::BasicMath::GPDVector *projVector=NULL);

        };

    }

}
#endif // !defined(EA_73FEAD2D_DD7F_40dd_BEF5_D741340AAE0A__INCLUDED_)
