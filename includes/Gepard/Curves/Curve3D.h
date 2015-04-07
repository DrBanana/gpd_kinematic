///////////////////////////////////////////////////////////
//  Curve3D.h
//  Implementation of the Class Curve3D
//  Created on:      13-апр-2010 16:22:43
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
		 * Класс вычисления 3D кривой - методами дифференциальной геометрии
		 */
		class Curve3D : public Gepard::Curves::Curve2D
		{
		public:
			/**
			 * R - координаты начальной точки
			 * E1 - координаты касательного вектора начальной точки
			 * E2 - координаты вектора нормали начальной точки
			 */
			GPDReper A;
			/**
			 * R - координаты конечной точки
			 * E1 - координаты касательного вектора конечной точки
			 * E2 - координаты вектора нормали конечной точки
			 */
			GPDReper B;
			
			Curve3D();
			~Curve3D();
			/**
			 * Расчитать 3D кривую
			 */
			void calcCurve3D(GPDReper a, GPDReper b, bool flag);
			/**
			 * Расчитать 3D кривую
			 */
			void calcCurve3D(GPDVector a, GPDVector b, GPDVector ta, GPDVector tb, GPDVector na, GPDVector nb, bool flag);
		};

	}

}
#endif // !defined(EA_411352F2_01F7_404b_B07D_EBB34BDCB1B9__INCLUDED_)
