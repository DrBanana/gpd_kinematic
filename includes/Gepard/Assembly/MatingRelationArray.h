///////////////////////////////////////////////////////////
//  MatingRelationArray.cpp
//  Реализация 	Class MatingRelationArray
//  Создана:   	20-июл-2010 15:27:02
//  Автор: 		Dr_Freeman
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
		 * Массив условий сопряжений
		 */
		class MatingRelationList : public Gepard::General::basicList<MatingRelation>
		{

		public:
			MatingRelationList();
			~MatingRelationList();

			/**
			 *	Поиск условия сопряжения по заданному зависимому реперу
			 */
			MatingRelation* FindMatingRelationByDependReper(Gepard::BasicMath::GPDReperPtr _dependReper);

		};

	}

}
#endif // !defined(EA_D58B8F9A_0AE2_4795_ABDB_FBC83B233405__INCLUDED_)
