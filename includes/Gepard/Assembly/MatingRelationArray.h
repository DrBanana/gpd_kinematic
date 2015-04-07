///////////////////////////////////////////////////////////
//  MatingRelationArray.cpp
//  ���������� 	Class MatingRelationArray
//  �������:   	20-���-2010 15:27:02
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_D58B8F9A_0AE2_4795_ABDB_FBC83B233405__INCLUDED_)
#define EA_D58B8F9A_0AE2_4795_ABDB_FBC83B233405__INCLUDED_

#include "../General/basicList.h"
#include "MatingRelation.h"
#include "../BasicMath/GPDReper.h"

namespace Gepard
{
	namespace Assembly
	{
		/**
		 * ������ ������� ����������
		 */
		class MatingRelationList : public Gepard::General::basicList<MatingRelation>
		{

		public:
			MatingRelationList();
			~MatingRelationList();

			/**
			 *	����� ������� ���������� �� ��������� ���������� ������
			 */
			MatingRelation* FindMatingRelationByDependReper(Gepard::BasicMath::GPDReperPtr _dependReper);

		};

	}

}
#endif // !defined(EA_D58B8F9A_0AE2_4795_ABDB_FBC83B233405__INCLUDED_)
