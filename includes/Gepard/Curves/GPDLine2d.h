///////////////////////////////////////////////////////////
//  GPDLine2d.h
//  ����������	Class GPDLine2d
//  �������:    09-���-2012 13:11:20
//  �����:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_04D4164D_FF6D_48f1_A237_71DCEF2E75C1__INCLUDED_)
#define EA_04D4164D_FF6D_48f1_A237_71DCEF2E75C1__INCLUDED_

#include "CROSS_LINE_TYPE.h"
#include "CROSS_LINE_POINT_TYPE.h"
#include "../BasicMath/GPDVector2d.h"
#include "../BasicMath/GPDPoint2dn.h"

namespace Gepard
{
    namespace Curves
    {
        /**
         * ����� �����
         */
        class GPDLine2d
        {

        public:
            GPDLine2d();
            GPDLine2d(Gepard::BasicMath::GPDPoint2dn PStart, Gepard::BasicMath::GPDPoint2dn PEnd);
            ~GPDLine2d();

            /**
             * ��������� � �������� �����
             */
            Gepard::BasicMath::GPDPoint2dn P0, P1;

            /**
             * ������ ����� ������
             */
            Gepard::BasicMath::GPDPoint2dnArray Points;

            /**
             * ������� 2d �����
             */
            void createLine2d(unsigned int numPoints);
            /**
             * ��������� ����� �� ����������� �, � ������ �����������, ������� �����
             * �����������.
             */
            CROSS_LINE_TYPE crossLines(GPDLine2d &line2d, Gepard::BasicMath::GPDPoint2dRef crossPoint);

            /**
             * ��������� ����� �� ����������� �, � ������ �����������, ������� �����
             * �����������.
             */
            static CROSS_LINE_TYPE crossLines(	Gepard::BasicMath::GPDPoint2d *A, Gepard::BasicMath::GPDPoint2d *B, 
                                                Gepard::BasicMath::GPDPoint2d *C, Gepard::BasicMath::GPDPoint2d *D, 
                                                Gepard::BasicMath::GPDPoint2dRef crossPoint );
            
            /**
             *	���������������� ����� �� ��������� � ������ ����� (�������)
             */
            CROSS_LINE_POINT_TYPE classifyPoint(Gepard::BasicMath::GPDPoint2d *P);

            /**
             *	���������������� ����� �� ��������� � ������ ����� (�������)
             */
            static CROSS_LINE_POINT_TYPE classifyPoint( Gepard::BasicMath::GPDPoint2d *A, 
                                                        Gepard::BasicMath::GPDPoint2d *B,
                                                        Gepard::BasicMath::GPDPoint2d *P );
            
            /**
             *	������������ �� ��� �����
             */
            bool isCrossLines(GPDLine2d &line2d, Gepard::BasicMath::GPDPoint2dPtr outP = 0);

            /**
             *	������������ �� ��� �����
             */
            static bool isCrossLines( Gepard::BasicMath::GPDPoint2d *A, Gepard::BasicMath::GPDPoint2d *B, 
                                      Gepard::BasicMath::GPDPoint2d *C, Gepard::BasicMath::GPDPoint2d *D, 
                                      Gepard::BasicMath::GPDPoint2dPtr outP = 0);

            /**
             *	����� ��� ����������� �����
             */
            CROSS_LINE_TYPE intersectLines(GPDLine2d &line2d, double &t);

            /**
             *	����� ��� ����������� ����� (AB) � (BC)
             */
            static CROSS_LINE_TYPE intersectLines( Gepard::BasicMath::GPDPoint2d *A, Gepard::BasicMath::GPDPoint2d *B, 
                                                   Gepard::BasicMath::GPDPoint2d *C, Gepard::BasicMath::GPDPoint2d *D,
                                                   double &t );
            
            /**
             *	�������� ���������� �� ����� �� �������
             */
            double getDistance(Gepard::BasicMath::GPDPoint2d *P, Gepard::BasicMath::GPDPoint2d *_outP = 0);

            /**
             *	�������� ���������� �� ����� P �� ������� (_A,_B)
             */
            static double getDistance(  Gepard::BasicMath::GPDPoint2d *_A, Gepard::BasicMath::GPDPoint2d *_B, 
                                        Gepard::BasicMath::GPDPoint2d *_P, Gepard::BasicMath::GPDPoint2d *_outP = 0);



        };

    }

}
#endif // !defined(EA_04D4164D_FF6D_48f1_A237_71DCEF2E75C1__INCLUDED_)
