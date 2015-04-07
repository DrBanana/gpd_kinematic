///////////////////////////////////////////////////////////
//  TDiameter.h
//  ������ �� �������
//  �������:   	03-����-2014
//  �����: 		Anton
///////////////////////////////////////////////////////////

#ifndef TDIAMETER_H
#define TDIAMETER_H

#pragma once

#include "Tolerance.h"

namespace Gepard 
{
    class MathModel;

    namespace Tolerances 
    {
        /**
         *  ������ �� �������
         */
        class TDiameter : public Tolerance
        {
        public:
            TDiameter();

            /**
             *  ���������� ��������� �� �������
             */
            void SetFit(Gepard::Tolerances::Fit *fitPtr);

            /**
             *  �������� ��������� �� �������
             */
            Gepard::Tolerances::Fit* GetFit();
            
        protected:

            /**
             *  ��������� ���������������� ������������ ��� �������
             */
            double calcConfigurationSpaceTol( unsigned int COUNT_CONF_POINTS) override;

            /**
             *  ��������� �������� ������� �� �������� ��������� ����� �.�.
             */
            double calcTolValueByCSParam(CSParam par, double A=0.0, double B=0.0) override;

            /**
            *  �������� ������� ����������� ����� �� �������� ����� ��             
            */
            TModifyPointsFunc GetPointsModificationFunc(CSParam par) override;
           
             /**
             *  �������� �� ������ ����������� ��� ������� �������
             */
            bool CheckFace(Gepard::Topology_Geometry::GPDFacePtr facePtr) override;

            /**
             *  ��������� �������� gamma (��� ������� ������� ������)
             *  �� �������� ������� � ���������� �����������
             */
            double CalcGammaByTolValue(double tolValue) override;

             /**
             *  �������� ����������� ��� ������������ �������
             */
            double GetVisualKoeff() override;

            /**
             *  ������ ����� � ������� ������� (�� �������)
             */
            bool isFit() override;

             /**
             * ���������� � ����
             */
            void saveToFile(std::ostream& os) override;

            /**
             * ������ �� �����
             */
            void readFromFile(std::istream& is, Gepard::MathModel *mathModelPtr) override;

        private:

            /**
             *  ������ ��������� � �������
             */
            bool is_fit;

            /**
             *	��������� �� ������������ �������
             */
            Gepard::Tolerances::Fit *parentFit;

        };

    }//Tolerances
}//Gepard


#endif