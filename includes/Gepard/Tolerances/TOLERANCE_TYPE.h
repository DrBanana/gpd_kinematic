///////////////////////////////////////////////////////////
//  
//  Реализация 	Class TOLERANCE_TYPE
//  Создана:   	16-фев-2010 15:48:58
//  Автор: 		Anton
///////////////////////////////////////////////////////////

#pragma once

namespace Gepard
{
	namespace Tolerances
	{
		/**
		 * Типы допусков
		 */
		enum TOLERANCE_TYPE
		{			
			/**
			 *	Не задано
			 */
			TT_UNKNOWN,
			/**
			 *	Прямолинейность
			 */
			TT_STRAIGHTNESS,
			/**
			 * Плоскостность
			 */
			TT_FLATNESS,
			/**
			 * Круглости
			 */
			TT_ROUNDNESS,
			/**
			 * цилиндричности
			 */
			TT_CYLINDRICITY,
			/**
			 *	Профиль продольного сечения
			 */
			TT_LONGITUDINAL_SECTION_PROFILE,
			/**
			 * Параллельности
			 */
			TT_PARALLELITY,
			/**
			 * Ортогональности
			 */
			TT_PERPENDICULARITY,
			/**
			 * допуск наклона
			 */
			TT_ANGULARITY,
			/**
			 * на соосность
			 */
			TT_COAXILITY,
			/**
			 * Симметричность
			 */
			TT_SYMMETRY,
			/**
			 * Позиционный
			 */
			TT_POSITIONING,
			/**
			 *	Пересечение осей
			 */
			TT_CROSS_AXES,
			/**
			 * Радиальное биение
			 */
			TT_RADIAL_RUNOUT,
			/**
			 * Торцевое биение
			 */
			TT_FACE_RUNOUT,
// 			/**
// 			 *	Биение в заданном направлении
// 			 */
// 			TT_DIRECTION_RUNOUT,
// 			/**
// 			 *	Полное радиальное биение
// 			 */
// 			TT_TOTAL_RADIAL_RUNOUT,
// 			/**
// 			 *	Полное торцевое биение
// 			 */
// 			TT_TOTAL_FACE_RUNOUT,
			/**
			 *	Допуск формы заданного профиля
			 */
			TT_PROFILE_FORM,
			/**
			 *	Допуск формы заданной поверхности
			 */
			TT_SURFACE_FORM,
			/**
			 * допуск на диаметр
			 */
			TT_DIAMETER,
			/**
			 * допуск на линейный размер
			 */
			TT_LINEAR,
			/**
			 * Допуск концентричности
			 */
			TT_CONCENTRICITY,
			/**
			 * Суммарное отклонение от паралл-ти/плоск-ти
			 */
			TT_SUM_PARALLELITY_FLATNESS,
			/**
			 * Суммарное отклонение от ортогон-ти/плоск-ти
			 */
			TT_SUM_PERPENDICULARITY_FLATNESS,
			/**
			 * Отклонение от ортогон-ти оси относит. плоск-ти
			 */
			TT_PERPENDICULARITY_TO_PLANE,
			/**
			 * допуск формы
			 */
			TT_FORM

			};

	}

}

