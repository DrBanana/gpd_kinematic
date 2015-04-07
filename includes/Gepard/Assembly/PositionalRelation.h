///////////////////////////////////////////////////////////
//  PositionalRelation.cpp
//  Реализация 	Class PositionalRelation
//  Создана:   	20-июл-2010 15:08:01
//  Автор: 		Dr_Freeman
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
		 * Класс описания взаимного расположения реперов двух сопрягаемых узлов
		 */
		class PositionalRelation : public Gepard::Assembly::basicDOF
		{

		public:			
			/**
			 * Базовый репер
			 */
			Gepard::BasicMath::GPDReper BaseReper;
			/**
			 * Зависимый репер
			 */
			Gepard::BasicMath::GPDReper DependReper;

			PositionalRelation();
			~PositionalRelation();
			/**
			 * расширить поле допуска
			 */
			void expandTol();

		};

	}

}
#endif // !defined(EA_DC6C7381_679F_4dc0_8F0A_D8EF6FDAF8ED__INCLUDED_)
