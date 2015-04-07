///////////////////////////////////////////////////////////
//  
//  Реализация 	Class axisFixingType
//  Создана:   	25-сен-2010 13:35:52
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_A41622C5_E0B4_4512_9681_9FB426CD7D3A__INCLUDED_)
#define EA_A41622C5_E0B4_4512_9681_9FB426CD7D3A__INCLUDED_

namespace Gepard
{
	namespace Assembly
	{
		/**
		 * тип закрепления оси
		 */
		enum axisFixingType
		{
			/**
			 * Зафиксировано - нет движения/поворота
			 */
			AFT_FIXED = 1,
			/**
			 * Можно передвигать/вращать
			 */
			AFT_UNFIXED = 2,
			/**
			 * Можно двигать/перемещать только в пределах значения value
			 */
			AFT_UNFIXED_VALUE = 3,
			/**
			 * Можно сдвигать только от Min к Max
			 */
			AFT_UNFIXED_VALUES_MIN_MAX = 4
		};

	}

}
#endif // !defined(EA_A41622C5_E0B4_4512_9681_9FB426CD7D3A__INCLUDED_)
