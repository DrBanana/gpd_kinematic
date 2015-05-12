///////////////////////////////////////////////////////////
//  GPDNurbsCurve.h
//  Кривая NURBS
//  Создана:   	12-мар-2015 17:50
//  Автор: 		Dr_Freeman
///////////////////////////////////////////////////////////

#ifndef GPDNURBSCURVE_H
#define GPDNURBSCURVE_H

#include "GPDCurve3D.h"
#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDVector.h"

namespace Gepard 
{

    namespace Curves 
	{
	    /**
		 *    Кривая NURBS
		 */
        class GPDNurbsCurve :  public Gepard::Curves::GPDCurve3D
        {
        public:
            GPDNurbsCurve(int _order, Gepard::BasicMath::GPDPointArray &_cp_array,
                           std::vector<double> &_knots, std::vector<int> &_multiplicities,
                           bool _isClosed, bool _isRational, std::vector<double> &_w);

		    GPDNurbsCurve();
		    ~GPDNurbsCurve();

            /**
            * Построить кривую с заданным числом точек 
            * (кроме случая, когда точки получаются почти равны с точностью precDelta)
            */
            void calcCurve(unsigned int numPoints = 0, bool checkPrec=true) override;

            /**
            *	Установка параметров по умолчанию
            */
            void setDefaultParameters() override;

            /**
            *  Задать параметры для кривой
            */
            void setParameters(int _order, Gepard::BasicMath::GPDPointArray &_cp_array,
                                std::vector<double> &_knots, std::vector<int> &_multiplicities,
                                bool _isClosed, bool _isRational, std::vector<double> &_w);

            /**
             *	Задать число точек для расчета
             */
            void SetResolution(int r);

            /**
            *  Преобразует точки кривой из системы координат oldReper в систему координат newReper
            */
            void ConvertToBasis(Gepard::BasicMath::GPDReper &oldReper,
                                Gepard::BasicMath::GPDReper &newReper) override;
            
            /**
            *  Сохранить данные кривой в поток
            */
            void saveToFile(std::ostream& os) override;
            /**
            *  Загрузить данные из потока
            */
            void readFromFile(std::istream& _is) override;

            /**
            *	Установить крайнюю точку A
            */
            void setPointA(Gepard::BasicMath::GPDPoint _a) override;

            /**
            *	Установить крайнюю точку B
            */
            void setPointB(Gepard::BasicMath::GPDPoint _b) override;

            /**
            *	Кривые совпадают
            */
            bool isEquivalent(Gepard::Curves::GPDCurve3DPtr curve3dPtr) override;

        private:

            /**
             *	Расчитать массив контрольных точек с учетом весовых коэффициентов
             */
            void CalcControlPointsW();

            /**
             *	Порядок сплайна
             */
            int order;

            /**
             *	Количество точек
             */
            int Resolution; 

            /**
             *	Узловой вектор
             */
            std::vector<double> Knots;

            /**
             *	Контрольные точки
             */
            Gepard::BasicMath::GPDPointArray ControlPoints;

            /**
             *	Весовые коэффициенты
             */
            std::vector<double> weights;

            /**
             *	Рациональная ли кривая (если нет - веса не учитываются)
             */
            bool isRational;

            /**
             *	Контрольные точки, умноженные на вес
             */
            Gepard::BasicMath::GPDPointArray control_points_w;

            /**
             *	Массив весовых коэффициентов в виде массива точек
             */
            Gepard::BasicMath::GPDPointArray w_array;

		};
	
	}//Curves
}//Gepard


#endif