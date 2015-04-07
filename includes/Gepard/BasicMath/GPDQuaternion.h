///////////////////////////////////////////////////////////
//  GPDQuaternion.cpp
//  ���������� 	Class GPDQuaternion
//  �������:   	15-���-2010 16:35:49
//  �����: 		Anton
///////////////////////////////////////////////////////////
#pragma once

#include <string>
#include "basicGPDVector.h"

namespace Gepard
{
    namespace BasicMath
    {
        class GPDVector;

        /**
         *	����� �����������
         */
        class GPDQuaternion : public Gepard::BasicMath::basicGPDVector
        {

        public:
            GPDQuaternion();
            ~GPDQuaternion();
            double R;

            /**
             * ����� ������������
             */
            GPDQuaternion getSum(GPDQuaternion &Q);
            /**
             * ����� ������������
             */
            GPDQuaternion operator+(GPDQuaternion &Q);
            /**
             * ������������ �� ������
             */
            GPDQuaternion getScalarProduct(double scalar);
            /**
            * ������������ �� ������
            */
            GPDQuaternion operator *(double scalar);
            /**
             * ������������ ������������
             */
            GPDQuaternion getProduct(GPDQuaternion &Q);
            /**
             * ������������ ������������
             */
            GPDQuaternion operator*(GPDQuaternion &Q);
            /**
             * ����������� ����������
             */
            GPDQuaternion getConjugated();

            /**
             *	�������� ����������� ����������
             */
            GPDQuaternion operator--();

            /**
             * �������� ����� �����������
             */
            double getNormalized();
            /**
            * ������� ����������� � ������
            */
            GPDVector toVector();
            /**
             * ������� ����������� � ������
             */
            std::string toString();
            /**
             * ��������
             */
            void setNull();
            /**
             * �������� �� �����
             */
            bool isNull();
            /**
             * ����� �� ��� �����������
             */
            bool isEquals(GPDQuaternion &Q);
            /**
             * ����� �� ��� �����������
             */
            bool operator==(GPDQuaternion &Q);
            /**
            * ��������� �����������
            */
            void setQuaternion(GPDQuaternion &Q);
            /**
            * ��������� �����������
            */
            void operator=(GPDQuaternion &Q);
            /**
            * ��������� �����������
            */
            void operator=(GPDVector &V);
            /**
            * ��������� �����������
            */
            void setQuaternion(double r, double X, double Y, double Z);
            /**
            * ��������� �����������
            */
            void setQuaternion(double r, GPDVector &V);

            /**
             *	������� ���������� �������� �����������
             *	������: (--QTarget)*QAxis*QTarget
             */
            static void FastRotateQuaternionA(GPDQuaternion &QAxis, GPDQuaternion &QTarget, GPDQuaternion &QResult);
            /**
             *	������� ���������� �������� �����������
             *	������: QTarget*QAxis*(--QTarget)
             */
            static void FastRotateQuaternionB(GPDQuaternion &QAxis, GPDQuaternion &QTarget, GPDQuaternion &QResult);

            /**
             *	������� ������������ ������������
             */
            static void FastProduct(GPDQuaternion &A, GPDQuaternion &B, GPDQuaternion &QResult);

        };

        typedef GPDQuaternion* GPDQuaternionPtr;	//��������� �� ����������
        typedef GPDQuaternion& GPDQuaternionRef;	//������ �� ����������

    }

}

