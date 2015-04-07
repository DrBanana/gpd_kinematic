///////////////////////////////////////////////////////////
//  GPDToroidalSurface.h
//  Реализация Class GPDToroidalSurface
//  Создано:      15-ноя-2012 17:35:18
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_A768939B_C49D_4b97_A871_8F761854C2D1__INCLUDED_)
#define EA_A768939B_C49D_4b97_A871_8F761854C2D1__INCLUDED_

#include "GPDSurface.h"

namespace Gepard
{
    namespace Surfaces
    {
        /**
         * Тороидальная поверхность
         */
        class GPDToroidalSurface : public Gepard::Surfaces::GPDSurface
        {

        public:
            GPDToroidalSurface();
            GPDToroidalSurface(double _R, double _r);
            virtual ~GPDToroidalSurface();

            /**
             *	первый Радиус
             */
            double R;

            /**
             *	второй Радиус
             */
            double r;

            /**
             * Посчитать поверхность с указанными параметрами точности
             */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0) override;

             /**
             *  Расчет 3Д точки поверхности по ее 2Д координате
             */
            void CalcSurfacePoint( Gepard::BasicMath::GPDPoint2dRef p2d,
                                   Gepard::BasicMath::GPDPointRef P3D ) override;

            /**
             *	Расчет 2Д точки на карте по ее 3Д координатам
             */
            void CalcMapPoint(Gepard::BasicMath::GPDPointRef P3D, Gepard::BasicMath::GPDPoint2dRef p2d) override;

            /**
             *  Расчет нормалей для границы на поверхности (3D)
             */
            void CalcContourNormals( Gepard::Curves::GPDCurve3DPtr curve3DPtr ) override;

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
#endif // !defined(EA_A768939B_C49D_4b97_A871_8F761854C2D1__INCLUDED_)
