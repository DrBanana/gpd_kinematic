///////////////////////////////////////////////////////////
//  GPDToroidalSurface.h
//  ���������� Class GPDToroidalSurface
//  �������:      15-���-2012 17:35:18
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_A768939B_C49D_4b97_A871_8F761854C2D1__INCLUDED_)
#define EA_A768939B_C49D_4b97_A871_8F761854C2D1__INCLUDED_

#include "GPDSurface.h"

namespace Gepard
{
    namespace Surfaces
    {
        /**
         * ������������ �����������
         */
        class GPDToroidalSurface : public Gepard::Surfaces::GPDSurface
        {

        public:
            GPDToroidalSurface();
            GPDToroidalSurface(double _R, double _r);
            virtual ~GPDToroidalSurface();

            /**
             *	������ ������
             */
            double R;

            /**
             *	������ ������
             */
            double r;

            /**
             * ��������� ����������� � ���������� ����������� ��������
             */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0) override;

             /**
             *  ������ 3� ����� ����������� �� �� 2� ����������
             */
            void CalcSurfacePoint( Gepard::BasicMath::GPDPoint2dRef p2d,
                                   Gepard::BasicMath::GPDPointRef P3D ) override;

            /**
             *	������ 2� ����� �� ����� �� �� 3� �����������
             */
            void CalcMapPoint(Gepard::BasicMath::GPDPointRef P3D, Gepard::BasicMath::GPDPoint2dRef p2d) override;

            /**
             *  ������ �������� ��� ������� �� ����������� (3D)
             */
            void CalcContourNormals( Gepard::Curves::GPDCurve3DPtr curve3DPtr ) override;

            /**
             *  ��������� ����������� � �����
             */
            void saveToFile(std::ostream& os) override;

            /**
             *  ��������� ����������� �� ������
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
#endif // !defined(EA_A768939B_C49D_4b97_A871_8F761854C2D1__INCLUDED_)
