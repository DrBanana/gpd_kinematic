///////////////////////////////////////////////////////////
//  
//  ���������� 	Class TOLERANCE_TYPE
//  �������:   	16-���-2010 15:48:58
//  �����: 		Anton
///////////////////////////////////////////////////////////

#pragma once

namespace Gepard
{
	namespace Tolerances
	{
		/**
		 * ���� ��������
		 */
		enum TOLERANCE_TYPE
		{			
			/**
			 *	�� ������
			 */
			TT_UNKNOWN,
			/**
			 *	���������������
			 */
			TT_STRAIGHTNESS,
			/**
			 * �������������
			 */
			TT_FLATNESS,
			/**
			 * ���������
			 */
			TT_ROUNDNESS,
			/**
			 * ��������������
			 */
			TT_CYLINDRICITY,
			/**
			 *	������� ����������� �������
			 */
			TT_LONGITUDINAL_SECTION_PROFILE,
			/**
			 * ��������������
			 */
			TT_PARALLELITY,
			/**
			 * ���������������
			 */
			TT_PERPENDICULARITY,
			/**
			 * ������ �������
			 */
			TT_ANGULARITY,
			/**
			 * �� ���������
			 */
			TT_COAXILITY,
			/**
			 * ��������������
			 */
			TT_SYMMETRY,
			/**
			 * �����������
			 */
			TT_POSITIONING,
			/**
			 *	����������� ����
			 */
			TT_CROSS_AXES,
			/**
			 * ���������� ������
			 */
			TT_RADIAL_RUNOUT,
			/**
			 * �������� ������
			 */
			TT_FACE_RUNOUT,
// 			/**
// 			 *	������ � �������� �����������
// 			 */
// 			TT_DIRECTION_RUNOUT,
// 			/**
// 			 *	������ ���������� ������
// 			 */
// 			TT_TOTAL_RADIAL_RUNOUT,
// 			/**
// 			 *	������ �������� ������
// 			 */
// 			TT_TOTAL_FACE_RUNOUT,
			/**
			 *	������ ����� ��������� �������
			 */
			TT_PROFILE_FORM,
			/**
			 *	������ ����� �������� �����������
			 */
			TT_SURFACE_FORM,
			/**
			 * ������ �� �������
			 */
			TT_DIAMETER,
			/**
			 * ������ �� �������� ������
			 */
			TT_LINEAR,
			/**
			 * ������ ���������������
			 */
			TT_CONCENTRICITY,
			/**
			 * ��������� ���������� �� ������-��/�����-��
			 */
			TT_SUM_PARALLELITY_FLATNESS,
			/**
			 * ��������� ���������� �� �������-��/�����-��
			 */
			TT_SUM_PERPENDICULARITY_FLATNESS,
			/**
			 * ���������� �� �������-�� ��� �������. �����-��
			 */
			TT_PERPENDICULARITY_TO_PLANE,
			/**
			 * ������ �����
			 */
			TT_FORM

			};

	}

}

