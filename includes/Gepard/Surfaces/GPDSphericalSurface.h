///////////////////////////////////////////////////////////
//  GPDSphericalSurface.h
//  ���������� Class GPDSphericalSurface
//  �������:      15-���-2012 17:35:17
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_F6617510_0932_4077_AF03_DB217C93D305__INCLUDED_)
#define EA_F6617510_0932_4077_AF03_DB217C93D305__INCLUDED_

#include "GPDSurface.h"


namespace Gepard
{
    namespace Surfaces
    {
        /**
         * ����������� �����������
         */
        class GPDSphericalSurface : public Gepard::Surfaces::GPDSurface
        {

        public:
            GPDSphericalSurface();
            GPDSphericalSurface(double _Radius);
            virtual ~GPDSphericalSurface();

            /**
             *	������ �����
             */
            double Radius;

            /**
             * ��������� ����������� � ���������� ����������� ��������
             */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0) override;
            
            /**
             *	������ 2� ����� �� ����� �� �� 3� �����������
             */
            void CalcMapPoint(Gepard::BasicMath::GPDPointRef P3D, Gepard::BasicMath::GPDPoint2dRef p2d) override;

            /**
             *  ������ 3� ����� ����������� �� �� 2� ����������
             */
            void CalcSurfacePoint( Gepard::BasicMath::GPDPoint2dRef p2d,
                                   Gepard::BasicMath::GPDPointRef P3D ) override;


            /**
             *  ������ 2� ������� �� ����� �� 3� ������
             */
            void CalcMapContour( Gepard::Curves::GPDCurve3DPtr curve3DPtr,
                                 Gepard::General::basicList<Gepard::BasicMath::GPDPoint2dn> &curve2DRef) override;

            /**
             *  ������ �������� ��� ������� �� ����������� (3D)
             */
            void CalcContourNormals( Gepard::Curves::GPDCurve3DPtr curve3DPtr ) override;
            
            /**
             * ���������� � ����
             */
            void saveToFile(std::ostream& os) override;

            /**
             * ������ �� �����
             */
            void readFromFile(std::istream& _is) override;

            private:
            /**
             *	��������� ���������� ����������� �� ���������
             */
            void setDefaultParameters() override;
            
        };

    }

}
#endif // !defined(EA_F6617510_0932_4077_AF03_DB217C93D305__INCLUDED_)
