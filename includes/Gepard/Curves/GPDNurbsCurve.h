///////////////////////////////////////////////////////////
//  GPDNurbsCurve.h
//  ������ NURBS
//  �������:   	12-���-2015 17:50
//  �����: 		Dr_Freeman
///////////////////////////////////////////////////////////

#ifndef GPDNURBSCURVE_H
#define GPDNURBSCURVE_H

#include "GPDCurve3D.h"
#include "../BasicMath/GPDPoint.h"
#include "../BasicMath/GPDVector.h"

namespace Gepard 
{

    namespace Curves 
	{
	    /**
		 *    ������ NURBS
		 */
        class GPDNurbsCurve :  public Gepard::Curves::GPDCurve3D
        {
        public:
            GPDNurbsCurve(int _order, Gepard::BasicMath::GPDPointArray &_cp_array,
                           std::vector<double> &_knots, std::vector<int> &_multiplicities,
                           bool _isClosed, bool _isRational, std::vector<double> &_w);

		    GPDNurbsCurve();
		    ~GPDNurbsCurve();

            /**
            * ��������� ������ � �������� ������ ����� 
            * (����� ������, ����� ����� ���������� ����� ����� � ��������� precDelta)
            */
            void calcCurve(unsigned int numPoints = 0, bool checkPrec=true) override;

            /**
            *	��������� ���������� �� ���������
            */
            void setDefaultParameters() override;

            /**
            *  ������ ��������� ��� ������
            */
            void setParameters(int _order, Gepard::BasicMath::GPDPointArray &_cp_array,
                                std::vector<double> &_knots, std::vector<int> &_multiplicities,
                                bool _isClosed, bool _isRational, std::vector<double> &_w);

            /**
             *	������ ����� ����� ��� �������
             */
            void SetResolution(int r);

            /**
            *  ����������� ����� ������ �� ������� ��������� oldReper � ������� ��������� newReper
            */
            void ConvertToBasis(Gepard::BasicMath::GPDReper &oldReper,
                                Gepard::BasicMath::GPDReper &newReper) override;
            
            /**
            *  ��������� ������ ������ � �����
            */
            void saveToFile(std::ostream& os) override;
            /**
            *  ��������� ������ �� ������
            */
            void readFromFile(std::istream& _is) override;

            /**
            *	���������� ������� ����� A
            */
            void setPointA(Gepard::BasicMath::GPDPoint _a) override;

            /**
            *	���������� ������� ����� B
            */
            void setPointB(Gepard::BasicMath::GPDPoint _b) override;

            /**
            *	������ ���������
            */
            bool isEquivalent(Gepard::Curves::GPDCurve3DPtr curve3dPtr) override;

        private:

            /**
             *	��������� ������ ����������� ����� � ������ ������� �������������
             */
            void CalcControlPointsW();

            /**
             *	������� �������
             */
            int order;

            /**
             *	���������� �����
             */
            int Resolution; 

            /**
             *	������� ������
             */
            std::vector<double> Knots;

            /**
             *	����������� �����
             */
            Gepard::BasicMath::GPDPointArray ControlPoints;

            /**
             *	������� ������������
             */
            std::vector<double> weights;

            /**
             *	������������ �� ������ (���� ��� - ���� �� �����������)
             */
            bool isRational;

            /**
             *	����������� �����, ���������� �� ���
             */
            Gepard::BasicMath::GPDPointArray control_points_w;

            /**
             *	������ ������� ������������� � ���� ������� �����
             */
            Gepard::BasicMath::GPDPointArray w_array;

		};
	
	}//Curves
}//Gepard


#endif