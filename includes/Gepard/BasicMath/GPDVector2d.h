///////////////////////////////////////////////////////////
//  GPDVector2d.h
//  ����������	Class GPDVector2d
//  �������:    09-���-2012 12:34:49
//  �����:		Anton
///////////////////////////////////////////////////////////

#if !defined(EA_5DF37002_DBD9_44e3_837E_BFACFE6834FB__INCLUDED_)
#define EA_5DF37002_DBD9_44e3_837E_BFACFE6834FB__INCLUDED_

#include <string>
#include "basicGPDVector2d.h"

namespace Gepard
{
    namespace BasicMath
    {
        class GPDPoint2d;
        /**
         * ����� - ���������� ������
         */		
        class GPDVector2d : public basicGPDVector2d
        {

        public:
            GPDVector2d();
            ~GPDVector2d();			
            GPDVector2d(double u, double v);
            /**
             * �������� ��������� ������������
             */
            double getScalarProduct(GPDVector2d& Vec);
            /**
             * ����� ��������
             */
            void Sum(GPDVector2d &b);
            /**
             * ����� ��������
             */
            GPDVector2d operator+(GPDVector2d &a);
            /**
             * ����� ��������
             */
            void operator+=(GPDVector2d &a);
            /**
             * �������� ��������
             */
            void Difference(GPDVector2d &b);
            /**
             * �������� ��������
             */
            GPDVector2d operator-(GPDVector2d &a);
            /**
             * ��������� ������� �� ������
             */
            void ScalarMulVector(double scalar);
            /**
             * ��������� ������� �� ������
             */
            GPDVector2d operator*(double scalar);
            /**
             * ��������� ����� �������
             */
            double getLength();
            /**
             * ������������ �������
             */
            void Normalize(void);
            /**
             * ������������ �������, ������� ������ �� ��������
             */
            GPDVector2d getNormalized();
            /**
             * ������� ������� � �����
             */
            Gepard::BasicMath::GPDPoint2d toPoint(void);
            /**
             * ������� ������� � ������
             */
            std::string toString(void);
            /**
             * ��������� ���� ����� ��������� 
             */
            double getAngle(GPDVector2d &a);
            /**
             *	������� �������������� �������
             */
            void Invert();
            /**
             *	������� ���������� ��������������� ������
             */
            GPDVector2d getInverted();
        };

    }

}
#endif // !defined(EA_5DF37002_DBD9_44e3_837E_BFACFE6834FB__INCLUDED_)
