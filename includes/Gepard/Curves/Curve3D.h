///////////////////////////////////////////////////////////
//  Curve3D.h
//  Implementation of the Class Curve3D
//  Created on:      13-���-2010 16:22:43
//  Original author: Pasha
///////////////////////////////////////////////////////////

#if !defined(EA_411352F2_01F7_404b_B07D_EBB34BDCB1B9__INCLUDED_)
#define EA_411352F2_01F7_404b_B07D_EBB34BDCB1B9__INCLUDED_

#include "Curve2d.h"

namespace Gepard
{
	namespace Curves
	{		
		/**
		 * ����� ���������� 3D ������ - �������� ���������������� ���������
		 */
		class Curve3D : public Gepard::Curves::Curve2D
		{
		public:
			/**
			 * R - ���������� ��������� �����
			 * E1 - ���������� ������������ ������� ��������� �����
			 * E2 - ���������� ������� ������� ��������� �����
			 */
			GPDReper A;
			/**
			 * R - ���������� �������� �����
			 * E1 - ���������� ������������ ������� �������� �����
			 * E2 - ���������� ������� ������� �������� �����
			 */
			GPDReper B;
			
			Curve3D();
			~Curve3D();
			/**
			 * ��������� 3D ������
			 */
			void calcCurve3D(GPDReper a, GPDReper b, bool flag);
			/**
			 * ��������� 3D ������
			 */
			void calcCurve3D(GPDVector a, GPDVector b, GPDVector ta, GPDVector tb, GPDVector na, GPDVector nb, bool flag);
		};

	}

}
#endif // !defined(EA_411352F2_01F7_404b_B07D_EBB34BDCB1B9__INCLUDED_)
