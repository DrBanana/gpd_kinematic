///////////////////////////////////////////////////////////
//  GPDVector.cpp
//  ���������� 	Class GPDVector
//  �������:   	15-���-2010 16:35:50
//  �����: 		Anton
///////////////////////////////////////////////////////////
#pragma once

#include <string>
#include "basicGPDVector.h"
#include "..\General\basicArray.h"
#include "..\General\basicList.h"

namespace Gepard
{
    namespace BasicMath
    {
        using namespace std;

        class GPDPoint;
        class GPDReper;

        /**
         * ����� �������
         */
        class GPDVector : public basicGPDVector
        {

        public:
            GPDVector();
            ~GPDVector();

            GPDVector(double X, double Y, double Z);
            /**
             * ��������� ������������ ��������
             */
            double getScalarProduct(GPDVector &Vector);
            /**
             * ���������� ������������ ��������
             */
            void CrossProduct(GPDVector &b);
            /**
             * ���������� ������������ ��������
             */
            GPDVector operator*(GPDVector &a);
            /**
             *  ��������� ������������ ��������
             */
            double operator&(GPDVector &a);
            /**
             * ��������� ������������ 3-� ��������
             */
            double getScalarTripleProduct(GPDVector &b, GPDVector &c);
            /**
             * ����� ��������
             */
            void Sum(GPDVector &b);
            /**
             * ����� ��������
             */
            GPDVector operator+(GPDVector &a);
            /**
             * ����� ��������
             */
            void operator+=(GPDVector &a);
            /**
             * �������� ��������
             */
            void Difference(GPDVector &b);
            /**
             * �������� ��������
             */
            GPDVector operator-(GPDVector &a);
            /**
             * ��������� ������� �� ������
             */
            void ScalarMulVector(double scalar);
            /**
             * ��������� ������� �� ������
             */
            GPDVector operator*(double scalar);
            /**
             * �������������� ��������
             */
            bool isColinear(GPDVector &a);
            /**
             * ��������������� ��������
             */
            bool isOrthogonal(GPDVector &a);
            /**
             * �������������� ��������
             */
            bool isComplanar(GPDVector &b, GPDVector &c);
            /**
             * ��������� ����� �������
             */
            double getLength();
            /**
             *  ��������� �������� ����� �������
             */
            double getSqrLength();
            /**
             * ������������ �������
             */
            void Normalize(void);
            /**
             * ������������ �������, ������� ������ �� ��������
             */
            GPDVector getNormalized();
            /**
             * ������� ������� � �����
             */
            Gepard::BasicMath::GPDPoint toPoint(void);
            /**
             * ������� ������� � ������
             */
            std::string toString(void);
            /**
             * ��������� ���� ����� ��������� 
             */
            double getAngle(GPDVector &a);
            /**
             * ������� �������� ������� ������ ��� ������ ������� ������� (������� ������ - ���)
             */
            void Rotate(GPDVector &axis, double angle);
            /**
             * ������� �������� ������� ������ ��� ������ ������� ������� (������� ������ - ���)			 
             */
            GPDVector getRotated(GPDVector &axis, double angle);
            /**
            * ������� �������� ������� �� ����� ������ ��������� � ������. ������� ������ �� ��������
            */
            GPDVector getTransformed(Gepard::BasicMath::GPDReper OLD, Gepard::BasicMath::GPDReper NEW);
            /**
            * ������� �������� ������� �� ����� ������ ��������� � ������. �������� ������� ������
            */
            void Transform(Gepard::BasicMath::GPDReper OLD, Gepard::BasicMath::GPDReper NEW);
            /**
             *	������� �������������� �������
             */
            void Invert();
            /**
             *	������� ���������� ��������������� ������
             */
            GPDVector getInverted();

            /**
            *  ������� ��������� (� ������������ minimumPrecision)
            */
            bool isApproxEquals(GPDVector &v);

            //������������� �������� ������
            friend ostream& operator<<(ostream& os, const GPDVector &gpd_vector)
            {			
                os.write((char *) &gpd_vector, sizeof(GPDVector));
                return os;

            }
            //������������� �������� �����
            friend istream& operator>>(istream& is, GPDVector &gpd_vector)
            {
                is.read((char *) &gpd_vector, sizeof(GPDVector));
                return is;
            }

        };

        typedef GPDVector* GPDVectorPtr;	//��������� �� ������
        typedef GPDVector& GPDVectorRef;	//������ �� ������
        typedef Gepard::General::basicArray<GPDVector> GPDVectorArray;	//������ ��������
        typedef Gepard::General::basicList<GPDVector> GPDVectorList;	//������ ��������
        typedef Gepard::General::basicArray<GPDVectorPtr> GPDVectorPtrArray;	//������ ���������� �� ������ - �� ������ �������! (���� ����).
        typedef Gepard::General::basicList<GPDVectorPtr> GPDVectorPtrList;		//������ ���������� �� ������ - �� ������ �������! (���� ����).

    }

}

