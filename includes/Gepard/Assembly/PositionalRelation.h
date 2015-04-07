///////////////////////////////////////////////////////////
//  PositionalRelation.cpp
//  ���������� 	Class PositionalRelation
//  �������:   	20-���-2010 15:08:01
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_DC6C7381_679F_4dc0_8F0A_D8EF6FDAF8ED__INCLUDED_)
#define EA_DC6C7381_679F_4dc0_8F0A_D8EF6FDAF8ED__INCLUDED_

#include "basicDOF.h"
#include "../BasicMath/GPDReper.h"

namespace Gepard
{
	namespace Assembly
	{
		/**
		 * ����� �������� ��������� ������������ ������� ���� ����������� �����
		 */
		class PositionalRelation : public Gepard::Assembly::basicDOF
		{

		public:			
			/**
			 * ������� �����
			 */
			Gepard::BasicMath::GPDReper BaseReper;
			/**
			 * ��������� �����
			 */
			Gepard::BasicMath::GPDReper DependReper;

			PositionalRelation();
			~PositionalRelation();
			/**
			 * ��������� ���� �������
			 */
			void expandTol();

		};

	}

}
#endif // !defined(EA_DC6C7381_679F_4dc0_8F0A_D8EF6FDAF8ED__INCLUDED_)
