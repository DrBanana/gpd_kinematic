///////////////////////////////////////////////////////////
//  Fit.cpp
//  Реализация 	Class Fit
//  Создана:   	23-июн-2011 19:45:22
//  Автор: 		Freeman
///////////////////////////////////////////////////////////

#pragma once

#include "../General/basicList.h"

namespace Gepard
{
    namespace Assembly	
    {
	    class AssemblyNode;
	    class MatingRelation;
    }

    namespace Topology_Geometry {class GPDFace;}

	namespace Tolerances
	{

		class Tolerance;

		/**
		 *	Класс Посадка
		 */
		struct Fit
		{
		
			Fit()
            {
                shaft_face = nullptr;
                hole_face = nullptr;
            }
			

			/**
			 *	Узел Вал
			 */
			//Gepard::Assembly::AssemblyNode *shaft_node;

			/**
			 *	Поверхность вала
			 */
			Gepard::Topology_Geometry::GPDFace *shaft_face;

			/**
			 *	Узел Отверстие
			 */
			//Gepard::Assembly::AssemblyNode *hole_node;

			/**
			 *	Поверхность отверстия
			 */
			Gepard::Topology_Geometry::GPDFace *hole_face;

			/**
			 *	Условие сопряжения, соответствующее данной посадке
			 */
			//Gepard::Assembly::MatingRelation *mating_relation;

			/** 
			 *	Система вала, либо система отверстия - пусть пока что будет здесь =)
			 */
			//bool ShaftBasisSystem;

			/**
			 *	Тип посадки - H7/g6 ...
			 */
			std::string Fit_type;

			/**
			 *	Значения отклонений вала - минимум
			 */	
			double shaft_min;

			/**
			 *	Значения отклонений вала - максимум
			 */	
			double shaft_max;

			/**
			 *	Значения отклонений отверстия - минимум
			 */	
			double hole_min;

			/**
			 *	Значения отклонений отверстия - максимум
			 */	
			double hole_max;

			/**
			 *	Указатель - допуск на диаметр вала
			 */
			//Gepard::Tolerances::Tolerance *shaft_parent_tolerance;

			/**
			 *	Указатель - допуск на диаметр отверстия
			 */
			//Gepard::Tolerances::Tolerance *hole_parent_tolerance;

		};

		typedef Fit* FitPtr;
		typedef Gepard::General::basicList<Fit> FitArray;
		typedef Gepard::General::basicList<FitPtr> FitPtrArray;
	}
}