///////////////////////////////////////////////////////////
//  GPDPlaneSurface.h
//  ���������� Class GPDPlaneSurface
//  �������:      15-���-2012 17:35:17
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_59910F0B_828F_43f9_A79B_D1C3A164949C__INCLUDED_)
#define EA_59910F0B_828F_43f9_A79B_D1C3A164949C__INCLUDED_

#include "GPDSurface.h"

namespace Gepard
{
    namespace Surfaces
    {
        /**
         * ���������
         */
        class GPDPlaneSurface : public Gepard::Surfaces::GPDSurface
        {

        public:
            GPDPlaneSurface(double _Width, double _Height);
            GPDPlaneSurface();
            ~GPDPlaneSurface();

            /**
             *	��������� �����������: ����� �� E1
             */
            double Width;
            /**
             *	��������� �����������: ������ �� E2
             */
            double Height; 
            
            /**
             * ��������� ����������� � ���������� ����������� ��������
             */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0) override;

            /**
             *	������ 2� ����� �� ����� �� �� 3� �����������
             */
            void CalcMapPoint(Gepard::BasicMath::GPDPointRef P3D, Gepard::BasicMath::GPDPoint2dRef p2d) override;

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
#endif // !defined(EA_59910F0B_828F_43f9_A79B_D1C3A164949C__INCLUDED_)
