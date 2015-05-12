///////////////////////////////////////////////////////////
//  GPDPoint.cpp
//  ���������� 	Class GPDPoint
//  �������:   	15-���-2010 16:35:48
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

        class GPDVector;
        class GPDReper;

        /**
         * ����� �����
         */
        class GPDPoint : public basicGPDVector
        {

        public:
            GPDPoint();
            ~GPDPoint();
            /**
             * ���������� �������
             */
            double nx;
            /**
             * ���������� �������
             */
            double ny;
            /**
             * ���������� �������
             */
            double nz;

            GPDPoint(double X, double Y, double Z, double NX, double NY, double NZ);
            GPDPoint(double X, double Y, double Z);

            /**
             * �������� ���������� ����� �������
             */
            double getLength(GPDPoint &P);

            /**
             * �������� ������� ���������� ����� �������
             */
            double getSqrLength(GPDPoint &P);

            /**
             *  ���� �� ������� (true - ������, ���)
             */
            bool isNormalNull();

            /**
             *  ����� ��������� (� ������������ minimumPrecision*prec)
             */
            bool isApproxEquals(GPDPoint &P, double prec=1.0);            

            /**
             * ��������� � ������ ������� �����
             */
            Gepard::BasicMath::GPDVector toVector();
            /**
             * �������� ����� ������� - � ������ (V = P - ���)
             */
            Gepard::BasicMath::GPDVector toVector(GPDPoint &P);
            /**
             * ������� ������� ����� � �����
             */
            Gepard::BasicMath::GPDReper toReper();

            /**
             * �������� ������ (V = ��� - P)
             */
            Gepard::BasicMath::GPDVector operator-(GPDPoint &P);
            /**
             * ��������
             */
            void setNull();
            /**
             * ��������� ���������
             */
            void setCoords(GPDPoint &P);
            /**
            * ��������� ���������
            */
            void setCoords(double X, double Y, double Z, double NX, double NY, double NZ);
            /**
            * ��������� ���������
            */
            void setCoords(double X, double Y, double Z);
            /**
             *	��������� ��������� �������
             */
            void setCoordsN(double NX, double NY, double NZ);
            /**
             *	��������� �������
             */
            void setNormal(GPDVector &_normal); 
            /**
            *	������� ����� � ������
            */
            std::string toString(void);
            /**
             * ������� ������� ����� �� ������ ������� ��������� � �����. ������� ����� ��
             * ��������
             */
            GPDPoint getTransformed(Gepard::BasicMath::GPDReper &OLD, Gepard::BasicMath::GPDReper &NEW);
            /**
             * ������� ������� ����� �� ������ ������� ��������� � �����. �������� ������� �����
             */
            void Transform(Gepard::BasicMath::GPDReper &OLD, Gepard::BasicMath::GPDReper &NEW);
            /**
             *	�������� ������ �� ��������� �������
             */
            GPDVector getNormal();
            /**
             *	������� �������������� ������� ��� ������� �����
             */
            void InvertNormal();
            /**
             *  ������������ ������� �����
             */
            void Normalize();

            //������������� �������� ������
            friend ostream& operator<<(ostream& os, const GPDPoint &p)
            {			
                os.write((char *) &p, sizeof(GPDPoint));
                return os;

            }
            //������������� �������� �����
            friend istream& operator>>(istream& is, GPDPoint &p)
            {
                is.read((char *) &p, sizeof(GPDPoint));
                return is;
            }
           
        };

        typedef GPDPoint* GPDPointPtr;	//��������� �� �����
        typedef GPDPoint& GPDPointRef;	//������ �� �����
        typedef Gepard::General::basicArray<GPDPoint> GPDPointArray;	//������ �����
        typedef Gepard::General::basicList<GPDPoint> GPDPointList;		//������ �����
        typedef Gepard::General::basicArray<GPDPointPtr> GPDPointPtrArray;	//������ ���������� �� ����� - �� ������ ������� (���� ����)!
        typedef Gepard::General::basicList<GPDPointPtr> GPDPointPtrList;	//������ ���������� �� ����� - �� ������ ������� (���� ����)!

    };// end namespace
}; //end namespace

