///////////////////////////////////////////////////////////
//  GPDCylindricalSurface.h
//  Реализация Class GPDCylindricalSurface
//  Создано:   15-ноя-2012 17:35:16
//  Автор:	   Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_E1C5D4A9_4946_4f6e_AA6F_5685AF3883D3__INCLUDED_)
#define EA_E1C5D4A9_4946_4f6e_AA6F_5685AF3883D3__INCLUDED_

#include "GPDSurface.h"

namespace Gepard
{
    namespace Surfaces
    {
        /**
         * Цилиндрическая поверхность
         */
        class GPDCylindricalSurface : public Gepard::Surfaces::GPDSurface
        {

        public:
            GPDCylindricalSurface();
            GPDCylindricalSurface(double _Radius, double _Height);
            virtual ~GPDCylindricalSurface();

            /**
             *	Радиус
             */
            double Radius;
            /**
             *	Высота
             */
            double Height;

            /**
             * Создать поверхность с указанными параметрами точности
             */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0) override;
           
            /**
             *	Расчет 2Д точки на карте по ее 3Д координатам
             */
            void CalcMapPoint(Gepard::BasicMath::GPDPointRef P3D, 
                              Gepard::BasicMath::GPDPoint2dRef p2d) override;

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
             *  Установить текущей поверхности эквивалентные параметры поверхности fromSurfPtr
             */
            void SetEquivalentParamsFrom(Gepard::Surfaces::GPDSurface* fromSurfPtr) override;

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
#endif // !defined(EA_E1C5D4A9_4946_4f6e_AA6F_5685AF3883D3__INCLUDED_)
