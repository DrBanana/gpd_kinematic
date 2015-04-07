///////////////////////////////////////////////////////////
//  basicGPDVector.h
//  ����������	Class basicGPDVector
//  �������:    08-���-2012 21:09:31
//  �����:      Anton
///////////////////////////////////////////////////////////

#if !defined(EA_4CCD46A4_F47C_44bf_A6E0_616F364D8094__INCLUDED_)
#define EA_4CCD46A4_F47C_44bf_A6E0_616F364D8094__INCLUDED_

#include <fstream>

namespace Gepard
{
    namespace BasicMath
    {
        using namespace std;

        /**
         * ������� ����� �������
         */
        class basicGPDVector
        {
        
        public:
            /**
             * ����������
             */
            double x,y,z;

            basicGPDVector();
            basicGPDVector(double X, double Y, double Z);
            ~basicGPDVector();
            /**
             * ����� �� �������
             */
            virtual bool isEquals(basicGPDVector& Vector);
            /**
             * ����� �� ����
             */
            virtual bool isNull();
            /**
             * �� ����� �� �������
             */
            virtual bool operator!=(basicGPDVector& Vector);
            /**
             * ����� �� �������
             */
            virtual bool operator==(basicGPDVector& Vector);
            /**
             * ���������� ����������
             */
            virtual void setCoords(double X, double Y, double Z);
            /**
             * ���������� ����������
             */
            virtual void setCoords(basicGPDVector& Vector);
            /**
             * ��������
             */
            virtual void setNull();

            /**
             *  �������� ���������� �� �������
             */
            double operator[](int i);

        };

    }

}
#endif // !defined(EA_4CCD46A4_F47C_44bf_A6E0_616F364D8094__INCLUDED_)
