///////////////////////////////////////////////////////////
//  GPDConicalSurface.h
//  ���������� Class GPDConicalSurface
//  �������:      15-���-2012 17:35:16
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_08411B53_1A2B_4182_8794_B642913D95A3__INCLUDED_)
#define EA_08411B53_1A2B_4182_8794_B642913D95A3__INCLUDED_

#include "GPDSurface.h"

namespace Gepard
{
    namespace Surfaces
    {
        /**
         * ���������� �����������
         */
        class GPDConicalSurface : public Gepard::Surfaces::GPDSurface
        {

        public:
            GPDConicalSurface();
            GPDConicalSurface(double _Radius, double _Angle, double _Height);
            ~GPDConicalSurface();

            /**
             *	������ ��������� (���������� ������)
             */
            double Radius;
            /**
             *	���� ������� (� ��������)
             */
            double Angle;
            /**
             *	������ ������
             */
            double Height;
          
            /**
             * ��������� ����������� � ���������� ����������� ��������
             */
            void CalcSurface(unsigned int _numU = 0, unsigned int _numV = 0, double _stepU = 0, double _stepV = 0) override;
            /**
             *	��������� ����������� � �������� �������� ��������������� ���������
             */
            void CalcSurface(double u0, double v0, double u1, double v1, 
                                     unsigned int _numU, unsigned int _numV,
                                     Gepard::BasicMath::GPDPointArray &_PointArray) override;
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
             *  ������ �������� ��� ������� �� ����������� (3D)
             */
            void CalcContourNormals( Gepard::Curves::GPDCurve3DPtr curve3DPtr ) override;

            /**
             *  ���������� ��������������� ��� � ������
             */
            void SetInvertAxis(bool invertAxis=true);

            /**
             *  ���������� ����� ��� ���������� ��������� �� ����� - � ������, ���� ���� ������������� ���
             */
            void SetMapPointReper(Gepard::BasicMath::GPDReper _reper);

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
#endif // !defined(EA_08411B53_1A2B_4182_8794_B642913D95A3__INCLUDED_)
