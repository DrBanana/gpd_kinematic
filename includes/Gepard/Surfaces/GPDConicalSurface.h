///////////////////////////////////////////////////////////
//  GPDConicalSurface.h
//  Реализация Class GPDConicalSurface
//  Создано:      15-ноя-2012 17:35:16
//  Автор: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_08411B53_1A2B_4182_8794_B642913D95A3__INCLUDED_)
#define EA_08411B53_1A2B_4182_8794_B642913D95A3__INCLUDED_

#include "GPDSurface.h"

namespace Gepard
{
    namespace Surfaces
    {
        /**
         * Коническая поверхность
         */
        class GPDConicalSurface : public Gepard::Surfaces::GPDSurface
        {

        public:
            GPDConicalSurface();
            GPDConicalSurface(double _Radius, double _Angle, double _Height);
            ~GPDConicalSurface();

            /**
             *	Радиус основания (наименьший радиус)
             */
            double Radius;
            /**
             *	Угол наклона (в радианах)
             */
            double Angle;
            /**
             *	Высота конуса
             */
            double Height;
          
            /**
             * Посчитать поверхность с указанными параметрами точности
             */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0) override;
            /**
             *	Посчитать поверхность в заданном сегменте параметрической плоскости
             */
            void CalcSurface(double u0, double v0, double u1, double v1, 
                                     unsigned int _numU, unsigned int _numV,
                                     Gepard::BasicMath::GPDPointArray &_PointArray) override;
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
             *  Расчет нормалей для границы на поверхности (3D)
             */
            void CalcContourNormals( Gepard::Curves::GPDCurve3DPtr curve3DPtr ) override;

            /**
             *  Установить инвертированную ось у конуса
             */
            void SetInvertAxis(bool invertAxis=true);

            /**
             *  Установить репер для вычисления координат на карте - в случае, если была инвертирована ось
             */
            void SetMapPointReper(Gepard::BasicMath::GPDReper _reper);

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
#endif // !defined(EA_08411B53_1A2B_4182_8794_B642913D95A3__INCLUDED_)
