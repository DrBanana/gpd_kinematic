///////////////////////////////////////////////////////////
//  Fit.cpp
//  ���������� 	Class Fit
//  �������:   	23-���-2011 19:45:22
//  �����: 		Freeman
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
		 *	����� �������
		 */
		struct Fit
		{
		
			Fit()
            {
                shaft_face = nullptr;
                hole_face = nullptr;
            }
			

			/**
			 *	���� ���
			 */
			//Gepard::Assembly::AssemblyNode *shaft_node;

			/**
			 *	����������� ����
			 */
			Gepard::Topology_Geometry::GPDFace *shaft_face;

			/**
			 *	���� ���������
			 */
			//Gepard::Assembly::AssemblyNode *hole_node;

			/**
			 *	����������� ���������
			 */
			Gepard::Topology_Geometry::GPDFace *hole_face;

			/**
			 *	������� ����������, ��������������� ������ �������
			 */
			//Gepard::Assembly::MatingRelation *mating_relation;

			/** 
			 *	������� ����, ���� ������� ��������� - ����� ���� ��� ����� ����� =)
			 */
			//bool ShaftBasisSystem;

			/**
			 *	��� ������� - H7/g6 ...
			 */
			std::string Fit_type;

			/**
			 *	�������� ���������� ���� - �������
			 */	
			double shaft_min;

			/**
			 *	�������� ���������� ���� - ��������
			 */	
			double shaft_max;

			/**
			 *	�������� ���������� ��������� - �������
			 */	
			double hole_min;

			/**
			 *	�������� ���������� ��������� - ��������
			 */	
			double hole_max;

			/**
			 *	��������� - ������ �� ������� ����
			 */
			//Gepard::Tolerances::Tolerance *shaft_parent_tolerance;

			/**
			 *	��������� - ������ �� ������� ���������
			 */
			//Gepard::Tolerances::Tolerance *hole_parent_tolerance;

		};

		typedef Fit* FitPtr;
		typedef Gepard::General::basicList<Fit> FitArray;
		typedef Gepard::General::basicList<FitPtr> FitPtrArray;
	}
}