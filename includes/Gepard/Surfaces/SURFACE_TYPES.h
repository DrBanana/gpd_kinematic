///////////////////////////////////////////////////////////
//  SURFACE_TYPES.h
//  ���������� Class SURFACE_TYPES
//  �������:      15-���-2012 17:35:19
//  �����: Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_8342E6E2_1142_46e0_B234_2B5B21FD70D4__INCLUDED_)
#define EA_8342E6E2_1142_46e0_B234_2B5B21FD70D4__INCLUDED_

namespace Gepard
{
    namespace Surfaces
    {
        /**
         * ���� ������������
         */
        enum SURFACE_TYPES
        {
            /**
             * ���������
             */
            ST_PLANE = 1,
            /**
             * �������������� �����������
             */
            ST_CYLINDRICAL = 2,
            /**
             * �����������
             */
            ST_SPHERICAL = 3,
            /**
             * ���
             */
            ST_TOROIDAL = 4,
            /**
             * �����
             */
            ST_CONICAL = 5,
            /**
             * ����������� ��������� �����
             */
            ST_FREEFORM = 6,
            /**
             * B-spline  � ������
             */
            ST_B_SPLINE_WITH_KNOTS = 7,
            /**
             * B-spline ��� �����
             */
            ST_B_SPLINE = 8,
            /**
             * ����������� �����
             */
            ST_BEZIER = 9,
            /**
             * ������������ B_Spline
             */
            ST_RATIONAL_B_SPLINE = 10,
            /**
             *	NURBS
             */
            ST_NURBS = 11
            
        };

    }

}
#endif // !defined(EA_8342E6E2_1142_46e0_B234_2B5B21FD70D4__INCLUDED_)
