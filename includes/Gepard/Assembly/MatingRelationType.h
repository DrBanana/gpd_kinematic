///////////////////////////////////////////////////////////
//  
//  Реализация 	Class MatingRelationType
//  Создана:   	20-июл-2010 15:22:06
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_480FAC82_AE95_4fca_A58C_97554F4B3287__INCLUDED_)
#define EA_480FAC82_AE95_4fca_A58C_97554F4B3287__INCLUDED_

namespace Gepard
{
	namespace Assembly
	{
		/**
		 * Тип условия сопряжения
		 * SI - Surface Interaction (взаимодействие поверхностей)
		 */
		enum MatingRelationType
		{
			/**
			 * Нет сопряжения
			 */
			MRT_NONE = 0,
			/**
			 * Плоскость к плоскости
			 */
			MRT_SI_PLANE_TO_PLANE = 1,
			/**
			 * Цилиндр к плоскости - Ось цилиндра перпендикулярна к плоскости
			 */
			MRT_SI_CYLINDRICAL_TO_PLANE = 2,
			/**
			 * Цилиндр к цилиндру - Оси цилиндров совпадают
			 */
			MRT_SI_CYLINDRICAL_TO_CYLINDRICAL = 3,
			/**
			 * Касание поверхностей
			 */
			MRT_CONTACT_SURFACES = 4,
			/**
			 * Касание заданных точек
			 */
			MRT_CONTACT_POINTS = 5,
			/**
			 * Касание заданных ребер
			 */
			MRT_CONTACT_EDGES = 6
		};

		/**
		 *	Направление векторов
		 */
		enum MRAxesDirection
		{
			/**
			 *	Направление совпадает
			 */
			MRAD_SAME = 0,
			/**
			 *	Направление не совпадает
			 */
			MRAD_DIFFERENT = 1,
			/**
			 *	Направление не задано
			 */
			MRAD_UNKNOWN = 2
		};

	}

}
#endif // !defined(EA_480FAC82_AE95_4fca_A58C_97554F4B3287__INCLUDED_)
