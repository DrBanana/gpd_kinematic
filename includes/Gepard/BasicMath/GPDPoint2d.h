///////////////////////////////////////////////////////////
//  GPDPoint2d.h
//  ���������� Class GPDPoint2d
//  �������:   09-���-2012 11:22:06
//  �����:     Anton
///////////////////////////////////////////////////////////

#if !defined(EA_1FE276CF_DE44_4b60_846E_FCED65E7DEC7__INCLUDED_)
#define EA_1FE276CF_DE44_4b60_846E_FCED65E7DEC7__INCLUDED_

#include "basicGPDVector2d.h"
#include "..\General\basicArray.h"
#include "..\General\basicList.h"

namespace Gepard
{
    namespace BasicMath
    {
        class GPDVector2d;
        class GPDPoint2dn;
        /**
         * ����� ������������� ���������� ����� ��� �������
         */
        class GPDPoint2d : public Gepard::BasicMath::basicGPDVector2d
        {

        public:
            GPDPoint2d();
            ~GPDPoint2d();
            GPDPoint2d(double U, double V);
            /**
             * �������� ���������� ����� �������
             */
            double getLength(const GPDPoint2d &P);

            /**
             *	�������� ������� ���������� ����� �������
             */
            double getSqrLength(const GPDPoint2d &P);

            /**
             * �������� ���������� ����� �������
             */
            double getLength(const GPDPoint2d *P);

            /**
             *	�������� ������� ���������� ����� �������
             */
            double getSqrLength(GPDPoint2d *P);


            /**
             * ������� ����� � ������
             */
            Gepard::BasicMath::GPDVector2d toVector();
            
            /**
             * �������� ����� ������� - � ������ V = P - ���
             */
            Gepard::BasicMath::GPDVector2d toVector(const GPDPoint2d &P);
            
            /**
             * �������� ������ (V = ��� - P)
             */
            Gepard::BasicMath::GPDVector2d operator-(const GPDPoint2d &P);

            /**
             *  �������� ��������� ���� �����
             */
            bool operator==(const GPDPoint2d &P);
            /**
             * ��������
             */
            void setNull();
            /**
             * ��������� ���������
             */
            void setCoords(const GPDPoint2d &P);
            /**
             * ��������� ���������
             */
            void setCoords(const Gepard::BasicMath::GPDPoint2dn &P);

            /**
            * ��������� ���������
            */
            void setCoords(double U, double V);
            /**
            *	������� ����� � ������
            */
            std::string toString(void);
            /**
             * ����� ����������� ����� (� ��������� minimumPrecision*delta)
             */
            bool isApproxEquals(const GPDPoint2d &P, double delta = 1.0);
            /**
             * ����� ����������� ����� (� ��������� minimumPrecision*delta)
             */
            bool isApproxEquals(const GPDPoint2d *P, double delta = 1.0);

        };
        
        typedef GPDPoint2d* GPDPoint2dPtr;	//��������� �� 2D �����
        typedef GPDPoint2d& GPDPoint2dRef;	//������ �� 2D �����
        typedef Gepard::General::basicArray<GPDPoint2d> GPDPoint2dArray; 	//������ 2d �����
        typedef Gepard::General::basicList<GPDPoint2d> GPDPoint2dList;		//������ 2d �����
        typedef Gepard::General::basicArray<GPDPoint2dPtr> GPDPoint2dPtrArray;	//������ ���������� �� 2d �����
        typedef Gepard::General::basicList<GPDPoint2dPtr> GPDPoint2dPtrList;		//������ ���������� �� 2d �����

    }

}
#endif // !defined(EA_1FE276CF_DE44_4b60_846E_FCED65E7DEC7__INCLUDED_)
