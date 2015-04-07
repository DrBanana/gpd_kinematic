///////////////////////////////////////////////////////////
//  GPDPoint2dn.h
//  ����������	Class GPDPoint2dn
//  �������:    09-���-2012 12:10:31
//  �����:		Dr_Freeman
///////////////////////////////////////////////////////////

#if !defined(EA_9CE44084_A907_4688_BD8C_167CD498E2A1__INCLUDED_)
#define EA_9CE44084_A907_4688_BD8C_167CD498E2A1__INCLUDED_

#include "GPDPoint2d.h"
#include "..\General\basicArray.h"
#include "..\General\basicList.h"

namespace Gepard
{
    namespace BasicMath
    {
        class GPDVector2d;
        /**
         * ����� ���������� ����� � 2D ��������
         */
        class GPDPoint2dn : public Gepard::BasicMath::GPDPoint2d
        {

        public:
            /**
             *	������� � �����
             */
            double nu,nv;

            GPDPoint2dn();
            ~GPDPoint2dn();
            GPDPoint2dn(GPDPoint2d &P);
            GPDPoint2dn(double U, double V);
            GPDPoint2dn(double U, double V,	double NU, double NV);

            /**
             * �������� �������
             */
            Gepard::BasicMath::GPDVector2d getNormal();

            /**
             *  ������������ �������
             */
            void Normalize();

            /**
             *  ������� �������������� �������
             */
            void InvertNormal();

        };
        typedef GPDPoint2dn* GPDPoint2dnPtr;	//��������� �� 2D �����
        typedef GPDPoint2dn& GPDPoint2dnRef;	//������ �� 2D �����
        typedef Gepard::General::basicArray<GPDPoint2dn> GPDPoint2dnArray; 	//������ 2d �����
        typedef Gepard::General::basicList<GPDPoint2dn> GPDPoint2dnList;		//������ 2d �����
        typedef Gepard::General::basicArray<GPDPoint2dnPtr> GPDPoint2dnPtrArray;	//������ ���������� �� 2d �����
        typedef Gepard::General::basicList<GPDPoint2dnPtr> GPDPoint2dnPtrList;		//������ ���������� �� 2d �����


    }

}
#endif // !defined(EA_9CE44084_A907_4688_BD8C_167CD498E2A1__INCLUDED_)
