///////////////////////////////////////////////////////////
//  FixingRelationArray.cpp
//  ���������� 	Class FixingRelationArray
//  �������:   	20-���-2010 15:38:14
//  �����: 		Dr_Freeman
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
         * ������ �����������
         */
        class FixingRelationArray : public Gepard::General::basicList<FixingRelation>
        {

        public:
            FixingRelationArray();
            ~FixingRelationArray();

            /**
             *	�������� ������� ����������
             *	���� true - ������� �����, ���� false - �������� � ������ ����������� ���������
             */
            bool CheckFixing(Gepard::BasicMath::GPDVector Vector);

            /**
             *	�������� ������� ����������
             *	���� true - ������� �����, ���� false - �������� � ������ ����������� ���������
             */
            bool CheckFixing(Gepard::BasicMath::GPDVector axis, double fi);

            /**
             *	������� ��������� �������� �� ��� ����������� �����������
             *  + �������� �������������� ������ ������ �� ����������� ������������ 
             */
            Gepard::BasicMath::GPDVector calcProjection(Gepard::BasicMath::GPDVector Vector);

            /**
             *	���������� ���, ������������ ������� ����� ������������� ����� - true
             *	���� �������� � ������������� �������������� (������� ����������� �� ���������) - false
             *	������� ���������:	��� ������, ������� ���� ������������� (reper_axis)
             *	�������� ���������: ���������� ���, ������������ ������� ���� ������� �� ���� Pi (rot_axis)
             *	���� rot_axis = reper_axis � ��������� false, ������ ��� ������� ����������� - ����� ������������
             *	����� ���, ������������� reper_axis
             */
            bool getInvertAxis(Gepard::BasicMath::GPDVector reper_axis,Gepard::BasicMath::GPDVector &rot_axis );


            /**
             *	�������� ����� ������� ����������� - � ���������, ���� �� ��� ����� �������
             */
            void AddFixingRelation(FixingRelation &fixingRel);


        };

    }

}
#endif // !defined(EA_982A14DC_BCFF_40f5_B96C_189D12AC4A2D__INCLUDED_)
