///////////////////////////////////////////////////////////
//  GPDSphericalSurface.h
//  Реализация Class GPDSphericalSurface
//  Создано:      15-ноя-2012 17:35:17
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_F6617510_0932_4077_AF03_DB217C93D305__INCLUDED_)
#define EA_F6617510_0932_4077_AF03_DB217C93D305__INCLUDED_

#include "GPDSurface.h"


namespace Gepard
{
    namespace Surfaces
    {
        /**
         * Сферическая поверхность
         */
        class GPDSphericalSurface : public Gepard::Surfaces::GPDSurface
        {

        public:
            GPDSphericalSurface();
            GPDSphericalSurface(double _Radius);
            virtual ~GPDSphericalSurface();

            /**
             *	Радиус сферы
             */
            double Radius;

            /**
             * Посчитать поверхность с указанными параметрами точности
             */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0) override;
            
            /**
             *	Расчет 2Д точки на карте по ее 3Д координатам
             */
            void CalcMapPoint(Gepard::BasicMath::GPDPointRef P3D, Gepard::BasicMath::GPDPoint2dRef p2d) override;

            /**
             *  Расчет 3Д точки поверхности по ее 2Д координате
             */
            void CalcSurfacePoint( Gepard::BasicMath::GPDPoint2dRef p2d,
                                   Gepard::BasicMath::GPDPointRef P3D ) override;


            /**
             *  Расчет 2Д контура на карте по 3Д кривой
             */
            void CalcMapContour( Gepard::Curves::GPDCurve3DPtr curve3DPtr,
                                 Gepard::General::basicList<Gepard::BasicMath::GPDPoint2dn> &curve2DRef) override;

            /**
             *  Расчет нормалей для границы на поверхности (3D)
             */
            void CalcContourNormals( Gepard::Curves::GPDCurve3DPtr curve3DPtr ) override;
            
            /**
             * сохранение в файл
             */
            void saveToFile(std::ostream& os) override;

            /**
             * чтение из файла
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
#endif // !defined(EA_F6617510_0932_4077_AF03_DB217C93D305__INCLUDED_)
