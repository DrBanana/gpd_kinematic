///////////////////////////////////////////////////////////
//  GPDCylindricalSurface.h
//  ���������� Class GPDCylindricalSurface
//  �������:   15-���-2012 17:35:16
//  �����:	   Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_E1C5D4A9_4946_4f6e_AA6F_5685AF3883D3__INCLUDED_)
#define EA_E1C5D4A9_4946_4f6e_AA6F_5685AF3883D3__INCLUDED_

#include "GPDSurface.h"

namespace Gepard
{
    namespace Surfaces
    {
        /**
         * �������������� �����������
         */
        class GPDCylindricalSurface : public Gepard::Surfaces::GPDSurface
        {

        public:
            GPDCylindricalSurface();
            GPDCylindricalSurface(double _Radius, double _Height);
            virtual ~GPDCylindricalSurface();

            /**
             *	������
             */
            double Radius;
            /**
             *	������
             */
            double Height;

            /**
             * ������� ����������� � ���������� ����������� ��������
             */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0) override;
           
            /**
             *	������ 2� ����� �� ����� �� �� 3� �����������
             */
            void CalcMapPoint(Gepard::BasicMath::GPDPointRef P3D, 
                              Gepard::BasicMath::GPDPoint2dRef p2d) override;

            /**
             *  ������ �������� ��� ������� �� ����������� (3D)
             */
            void CalcContourNormals( Gepard::Curves::GPDCurve3DPtr curve3DPtr ) override;

            /**
             *  ������ 3� ����� ����������� �� �� 2� ����������
             */
            void CalcSurfacePoint( Gepard::BasicMath::GPDPoint2dRef p2d,
                                   Gepard::BasicMath::GPDPointRef P3D ) override;

             /**
             *  ���������� ������� ����������� ������������� ��������� ����������� fromSurfPtr
             */
            void SetEquivalentParamsFrom(Gepard::Surfaces::GPDSurface* fromSurfPtr) override;

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
#endif // !defined(EA_E1C5D4A9_4946_4f6e_AA6F_5685AF3883D3__INCLUDED_)
