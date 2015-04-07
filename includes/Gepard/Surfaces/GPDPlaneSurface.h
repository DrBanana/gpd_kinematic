///////////////////////////////////////////////////////////
//  GPDPlaneSurface.h
//  Реализация Class GPDPlaneSurface
//  Создано:      15-ноя-2012 17:35:17
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_59910F0B_828F_43f9_A79B_D1C3A164949C__INCLUDED_)
#define EA_59910F0B_828F_43f9_A79B_D1C3A164949C__INCLUDED_

#include "GPDSurface.h"

namespace Gepard
{
    namespace Surfaces
    {
        /**
         * Плоскость
         */
        class GPDPlaneSurface : public Gepard::Surfaces::GPDSurface
        {

        public:
            GPDPlaneSurface(double _Width, double _Height);
            GPDPlaneSurface();
            ~GPDPlaneSurface();

            /**
             *	Параметры поверхности: длина по E1
             */
            double Width;
            /**
             *	Параметры поверхности: ширина по E2
             */
            double Height; 
            
            /**
             * Посчитать поверхность с указанными параметрами точности
             */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0) override;

            /**
             *	Расчет 2Д точки на карте по ее 3Д координатам
             */
            void CalcMapPoint(Gepard::BasicMath::GPDPointRef P3D, Gepard::BasicMath::GPDPoint2dRef p2d) override;

            /**
             *  Расчет нормалей для границы на поверхности (3D)
             */
            void CalcContourNormals( Gepard::Curves::GPDCurve3DPtr curve3DPtr ) override;

             /**
             *  Расчет 3Д точки поверхности по ее 2Д координате
             */
            void CalcSurfacePoint( Gepard::BasicMath::GPDPoint2dRef p2d,
                                   Gepard::BasicMath::GPDPointRef P3D ) override;

            /**
             *  Сохранить поверхность в поток
             */
            void saveToFile(std::ostream& os) override;

            /**
             *  Загрузить поверхность из потока
             */
            void readFromFile(std::istream& _is) override;

        private:
            /**
             *	Установка параметров поверхности по умолчанию
             */
            void setDefaultParameters() override;
        };

    }

}
#endif // !defined(EA_59910F0B_828F_43f9_A79B_D1C3A164949C__INCLUDED_)
