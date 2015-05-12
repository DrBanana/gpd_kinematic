///////////////////////////////////////////////////////////
//  GPDReper.cpp
//  ���������� 	Class GPDReper
//  �������:   	15-���-2010 16:35:49
//  �����: 		Anton
///////////////////////////////////////////////////////////

#pragma once

#include "GPDVector.h"
#include "..\General\basicArray.h"
#include "..\General\basicList.h"

namespace Gepard
{
    namespace BasicMath
    {
        using namespace std;

        class GPDVector;
        class GPDPoint;

        /**
         * ����� �����
         */
        class GPDReper
        {		
        public:
            GPDReper();
            ~GPDReper();
            GPDReper(Gepard::BasicMath::GPDVector e1, Gepard::BasicMath::GPDVector e2, Gepard::BasicMath::GPDVector e3, Gepard::BasicMath::GPDVector r);			
            /**
             * ������ ������
             */
            Gepard::BasicMath::GPDVector E1,E2,E3,R;
                        
            /**
             * �������� ���������� �����
             */
            static GPDReper getGlobalReper();
            /**
             * �������� ���������� ����� ��������
             */
            double getLength(GPDReper Rep);
            /**
             * ������� �������� ������ �� ������ ������� ��������� � �����. ������� ����� ��
             * ��������, ���� rewritecurrent=false
             */
            GPDReper getTransformed(GPDReper &OLD, GPDReper &NEW, bool rewriteCurrent=false);
            /**
             * ������� �������� ������ �� ������ ������� ��������� � �����. �������� ������� �����
             */
            void Transform(GPDReper &OLD, GPDReper &NEW);
            /**
             * ������� ������ � ������
             */
            std::string toString();
            /**
             * ������� ������ (������� r) � �����
             */
            Gepard::BasicMath::GPDPoint toPoint();
            /**
             * �������� �����
             */
            void setNull();
            /**
             * ���������� ������
             */
            void setReper(GPDReper Rep);
            /**
             * ���������� ������
             */
            void operator=(GPDReper Rep);
            /**
             * ����� ��
             */
            bool isEquals(GPDReper Rep);
            /**
             * ����� ��
             */
            bool operator==(GPDReper Rep);

            /**
             *  ������������� ��� ������
             */
            void InvertAxes();

            /**
            * �������������� ������ �� ���� ����� � ��� ������
            * ������� ���������:
            * vector_index - ������, ������� ����� ����������� � ������� ������ (E1,E2,E3)
            * n - ��� (� ���������� �����������), �� ������� ������ ���������� fi psi
            * ���� fi � psi (������� � �������� ��������������)
             */
            void morphByAngleAndReperAxis(GPDVector n, int vector_index, double fi, double psi);

            /**
            * �������������� ������ �� ���� ����� � ��� ������
            * ������� ���������:
            * vector_index - ������, ������� ����� ����������� � ������� ������ (E1,E2,E3)
            * vector_index ��� �� �������� ����, �� ������� ����� ������ ����������
            * ���� fi � psi (������� � �������� ��������������)
             */
            void morphByAngleAndReperAxis(int vector_index, double fi, double psi);

            /**
            * ������� ������ �� ������ ������ �������� �����
            * ������� ���������:
            * ����� E={f0, f1, f2, f3} , ������� ���� ���������
            * ����� A  � ���������� �����������!
            * ����� B  � ���������� �����������!
            * (�.�. AB - ������, �� ������� ���� ��������� �����������)
            * ����� O1'  � ���������� �����������!
            * O1' - �����, ������ ������� ������������
            */
            //void morphByVectorAroundPoint(GPDPoint A, GPDPoint B, GPDPoint O1);

            /**
            ������� ��������� ����� �� ������
            */
            void moveOnVector(GPDVector Vec);

            /**
             * �������������� ������ �� ���� ����� � ���
             * ������� ���������:
             * n - ��� � ���������� �����������, ������������ ������� ����� ����������� �����
             * ���� fi
             */
            void morphByAngleAndAxis(GPDVector N, double fi);

        private:
            /**
            * ������ ������������ ������� - ����� ��� getTransformed
            */
            inline double CalcDeterminant(double Matr[3][3]){
                double d1, d2;
                d1=Matr[0][0]*Matr[1][1]*Matr[2][2];
                d1+=Matr[0][2]*Matr[1][0]*Matr[2][1];
                d1+=Matr[0][1]*Matr[1][2]*Matr[2][0];

                d2=Matr[0][2]*Matr[1][1]*Matr[2][0];
                d2+=Matr[2][1]*Matr[1][2]*Matr[0][0];
                d2+=Matr[1][0]*Matr[0][1]*Matr[2][2];

                return d2-d1;
            }
        public:

            //������������� �������� ������
            friend ostream& operator<<(ostream& os, const GPDReper &reper)
            {				
                os.write((char *)&reper,sizeof(GPDReper));
                return os;

            }
            //������������� �������� �����
            friend istream& operator>>(istream& is, GPDReper &reper)
            {
                is.read((char *)&reper,sizeof(GPDReper));
                return is;
            }


        };		
        typedef GPDReper* GPDReperPtr;	//��������� �� �����
        typedef GPDReper& GPDReperRef;	//������ �� �����
        typedef Gepard::General::basicArray<GPDReper> GPDReperArray; //������ �������
        typedef Gepard::General::basicList<GPDReper> GPDReperList;	 //������ �������
        typedef Gepard::General::basicArray<GPDReperPtr> GPDReperPtrArray;	//������ ���������� �� �����. �� ������ �������! (���� ����).
        typedef Gepard::General::basicList<GPDReperPtr> GPDReperPtrList;	//������ ���������� �� �����. �� ������ �������! (���� ����).

    };//end namespace

};//end namespace

